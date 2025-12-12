#include <iostream>
#include <ctime>

int main() {
    clock_t start = clock();
    
    // 你的主要代码放在这里
    // 模拟耗时操作
    for (long long i = 0; i < 1000000000; i++) {
        // 空循环模拟耗时
    }
    
    clock_t end = clock();
    double elapsed_seconds = double(end - start) / CLOCKS_PER_SEC;
    
    if (elapsed_seconds > 3) {
        std::cout << 3 << std::endl;
    } else if (elapsed_seconds > 2) {
        std::cout << 2 << std::endl;
    } else if (elapsed_seconds > 1) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << "时间不足1秒" << std::endl;
    }
    
    return 0;
}