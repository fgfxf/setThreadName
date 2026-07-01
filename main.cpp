#include"SetThreadName.h"
#include<thread>
#include<chrono>

void child_thread(){
    SetCurrentThreadName("test child");
    std::this_thread::sleep_for(std::chrono::seconds(5));

}

int main(){
    std::thread th(child_thread);
    th.join();
    return 0;
}