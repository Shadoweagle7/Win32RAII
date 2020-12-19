#ifndef SE7_WIN32_HANDLE
#define SE7_WIN32_HANDLE

#include <Windows.h>

#include <stdexcept>
#include <type_traits>
#include <memory>

namespace SE7 {
	namespace win32 {
		typedef class handle {
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
		} 
		accelerator_handle,
		bitmap_handle,
		brush_handle,
		colorspace_handle,
		conv_handle,
		convlist_handle,
		// cursor_handle --> hicon
		device_context_handle,
		ddedata_handle,
		desktop_handle,
		drop_handle,
		deferred_window_position_handle,
		enhanced_metafile_handle,
		font_handle,
		gdi_object_handle,
		global_handle,
		hook_handle,
		icon_handle,
		instance_handle,
		key_handle,
		kl_handle, // HKL
		local_handle,
		menu_handle,
		metafile_handle,
#if (WINVER >= 0x0500)
		monitor_handle,
#endif
		palette_handle,
		pen_handle,
		region_handle,
		resource_handle,
		dde_string_handle, // HSZ
		window_station_handle,
		window_handle,
		service_control_manager_database_handle, // SC_HANDLE
		service_status_value_handle
		;

#define DEFINE_SHARED_POINTER(type) typedef std::shared_ptr<type> shared_pointer_##type;
#define DEFINE_UNIQUE_POINTER(type) typedef std::unique_ptr<type> unique_pointer_##type;

#define DEFINE_SHARED_AND_UNIQUE_POINTER(type) \
DEFINE_SHARED_POINTER(type)\
DEFINE_UNIQUE_POINTER(type)
		
		DEFINE_SHARED_AND_UNIQUE_POINTER(accelerator_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(bitmap_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(brush_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(colorspace_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(conv_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(convlist_handle)
		// cursor_handle --> hicon
		DEFINE_SHARED_AND_UNIQUE_POINTER(device_context_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(ddedata_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(desktop_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(drop_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(deferred_window_position_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(enhanced_metafile_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(font_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(gdi_object_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(global_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(hook_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(icon_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(instance_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(key_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(kl_handle) // HKL
		DEFINE_SHARED_AND_UNIQUE_POINTER(local_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(menu_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(metafile_handle)
#if (WINVER >= 0x0500)
		DEFINE_SHARED_AND_UNIQUE_POINTER(monitor_handle)
#endif
		DEFINE_SHARED_AND_UNIQUE_POINTER(palette_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(pen_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(region_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(resource_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(dde_string_handle) // HSZ
		DEFINE_SHARED_AND_UNIQUE_POINTER(window_station_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(window_handle)
		DEFINE_SHARED_AND_UNIQUE_POINTER(service_control_manager_database_handle) // SC_HANDLE
		DEFINE_SHARED_AND_UNIQUE_POINTER(service_status_value_handle)

		typedef LARGE_INTEGER large_integer;
		typedef ULARGE_INTEGER unsigned_large_integer;
		// typedef UNICODE_STRING unicode_string; Wtf is wrong here
		typedef SC_LOCK service_control_manager_database;
		typedef	instance_handle module_handle;
		typedef icon_handle cursor_handle;
		typedef HFILE file_handle;
		typedef HRESULT result_handle;
	}
}

#endif // !SE7_WIN32_HANDLE
