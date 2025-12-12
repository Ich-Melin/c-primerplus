#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    bool output1 = false, output2 = false, output3 = false;
    
    while (true) {
        auto current = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(current - start);
        double elapsed_seconds = duration.count();
        
        // 检查并输出1
        if (elapsed_seconds > 1 && !output1) {
            std::cout << 1 << std::endl;
            output1 = true;
        }
        
        // 检查并输出2
        if (elapsed_seconds > 2 && !output2) {
            std::cout << 2 << std::endl;
            output2 = true;
        }
        
        // 检查并输出3
        if (elapsed_seconds > 3 && !output3) {
            std::cout << 3 << std::endl;
            output3 = true;
            break;  // 所有输出完成，退出循环
        }
        
        // 你的主要工作代码可以放在这里
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}