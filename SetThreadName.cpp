#include "SetThreadName.h"

#if defined(_WIN32)
#include <windows.h>
#include <processthreadsapi.h>
#include <codecvt>
#include <locale>
#elif defined(__linux__) || defined(__APPLE__)
#include <pthread.h>
#endif

void SetCurrentThreadName(const char* name) {
    if (!name) return;
#if defined(_WIN32)
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wname = converter.from_bytes(name);
    // 仅在 Windows 10, version 1607 及以上版本有效
    SetThreadDescription(GetCurrentThread(), wname.c_str());
#elif defined(__APPLE__)
    // macOS 仅支持设置当前线程的名字
    pthread_setname_np(name);
#elif defined(__linux__)
    // Linux 支持 16 个字符长度的线程名，包括 '\0'
    std::string shortName(name);
    if (shortName.length() > 15) {
        shortName = shortName.substr(0, 15);
    }
    pthread_setname_np(pthread_self(), shortName.c_str());
#endif
}

void SetThreadName(std::thread& thread, const char* name) {
    if (!name) return;
#if defined(_WIN32)
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wname = converter.from_bytes(name);
    SetThreadDescription((HANDLE)thread.native_handle(), wname.c_str());
#elif defined(__linux__)
    std::string shortName(name);
    if (shortName.length() > 15) {
        shortName = shortName.substr(0, 15);
    }
    pthread_setname_np(thread.native_handle(), shortName.c_str());
#elif defined(__APPLE__)
    // macOS 不支持设置其他线程的名字
    (void)thread;
    (void)name;
#endif
}
