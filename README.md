# SetThreadName

A simple cross-platform C++ library for setting thread names. This helps with debugging and identifying threads in multi-threaded applications.
一个简单的跨平台 C++ 设置线程名称的工具库。有助于在多线程应用程序中进行调试和识别线程。

## Supported Platforms / 支持的平台

- **Windows**: `SetThreadDescription` (Requires Windows 10 version 1607+ / 需要 Windows 10 1607+ 版本)
- **Linux**: `pthread_setname_np` (Limited to 15 characters / 限制 15 个字符)
- **macOS**: `pthread_setname_np` (Only supports setting the current thread's name / 仅支持设置当前线程名称)

## Usage / 用法

```cpp
#include "SetThreadName.h"
#include <thread>

int main() {
    // Set the name of the current thread
    // 设置当前线程的名字
    SetCurrentThreadName("MainThread");

    // Set the name of a specific std::thread
    // 设置指定的 std::thread 名字
    std::thread worker([]() {
        // worker logic...
    });
    SetThreadName(worker, "WorkerThread");
    
    worker.join();
    return 0;
}
```
