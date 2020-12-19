#ifndef SE7_WIN32_HANDLE
#define SE7_WIN32_HANDLE

#include <Windows.h>

#include <stdexcept>
#include <type_traits>

namespace SE7 {
	namespace win32 {
		class handle {
		private:
			HANDLE internal_handle;
		public:
			handle(HANDLE h) {
				if (h == INVALID_HANDLE_VALUE || h == NULL) {
					throw std::invalid_argument("INVALID_HANDLE_VALUE or NULL passed.");
				}

				this->internal_handle = h;
			}

			template<
				class WIN32FUNC,
				class... argv,
				std::enable_if_t<std::is_invocable_r_v<HANDLE, WIN32FUNC, argv...>, int> = 0
			>
				handle(WIN32FUNC win32func, argv... args) {
				if (this->internal_handle == INVALID_HANDLE_VALUE ||
					this->internal_handle == NULL
					) {
					throw std::invalid_argument("The Win32 function returned INVALID_HANDLE_VALUE or NULL.");
				}
			}

			operator HANDLE() const {
				return this->internal_handle;
			}

			HANDLE get_internal_handle() const {
				return this->internal_handle;
			}

			~handle() {
				if (this->internal_handle) {
					CloseHandle(this->internal_handle);
				}
			}
		};
	}
}

#endif // !SE7_WIN32_HANDLE
