#ifndef SE7_WIN32_TCHAR
#define SE7_WIN32_TCHAR

#include <string>
#include <string_view>
#include <iterator>
#include <tchar.h>

namespace SE7 {
	namespace win32 {
		class tstring {
		private:
			std::basic_string<TCHAR> value;
		public:
			tstring(std::basic_string_view<TCHAR> str) : value(str) {}

			std::basic_string<TCHAR> &get_internal_string() { return this->value; }

			const TCHAR &operator[](const size_t n) const {
				return this->value.at(n);
			}

			size_t length() const { return this->value.length(); }
			bool empty() const { return this->value.empty(); }

			std::basic_string<TCHAR>::iterator begin() {
				return this->value.begin();
			}

			std::basic_string<TCHAR>::iterator end() {
				return this->value.end();
			}

			std::basic_string<TCHAR>::const_iterator begin() const {
				return this->value.begin();
			}

			std::basic_string<TCHAR>::const_iterator end() const {
				return this->value.end();
			}

			std::basic_string<TCHAR>::reverse_iterator rbegin() {
				return this->value.rbegin();
			}

			std::basic_string<TCHAR>::reverse_iterator rend() {
				return this->value.rend();
			}

			std::basic_string<TCHAR>::reverse_iterator crbegin() const {
				return this->value.crbegin();
			}

			std::basic_string<TCHAR>::reverse_iterator crend() const {
				return this->value.crend();
			}

			operator const TCHAR *() const { return this->value.c_str(); }
			operator std::basic_string<TCHAR> &() { return this->value; }
			operator std::basic_string_view<TCHAR>() { return this->value; }
		};
	}
}

#endif // !SE7_WIN32_TCHAR
