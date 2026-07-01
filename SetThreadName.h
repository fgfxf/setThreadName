#ifndef SET_THREAD_NAME_H
#define SET_THREAD_NAME_H

#include <string>
#include <thread>

/**
 * @brief 设置当前线程的名字
 * @param name 线程名字，linux 仅支持15个字符
 */
void SetCurrentThreadName(const char* name);

/**
 * @brief 设置指定线程的名字
 * @param thread std::thread 对象
 * @param name 线程名字
 * @note macOS 平台不支持设置其他线程的名字，调用此函数将无效果。
 */
void SetThreadName(std::thread& thread, const char* name);

#endif // SET_THREAD_NAME_H
