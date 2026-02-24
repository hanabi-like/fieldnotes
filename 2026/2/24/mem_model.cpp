#include <iostream>

#define MACRO -1 // 内存模型无位置，可以理解为定义了一个新型符号，没有变量使用即没有作用
// 初始化全局变量 -> data
int globalInitVar = 0;
// 未初始化全局变量 -> bss
int globalUninitVar;

int main()
{
    const char *str = "test";   // rodata
    static int statInitVar = 1; // 初始化静态变量 -> data
    static int statUninitVar;   // 未初始化静态变量 -> bss
    const int constInitVar = 2; // stack
    // const int constUninitVar; 常量必须初始化，不存在后续赋值
    int *ptr = new int(3); // heap
    int tempVar = 4;       // stack，地址高于constInitVar，stack内存从高到低增长
    std::cout << "=====memory model=====" << std::endl;
    std::cout << "stack: " << (void *)&tempVar << std::endl;
    std::cout << "stack: " << (void *)&constInitVar << std::endl;
    std::cout << "heap: " << ptr << std::endl;
    std::cout << "bss: " << (void *)&statUninitVar << std::endl;
    std::cout << "bss: " << (void *)&globalUninitVar << std::endl;
    std::cout << "data: " << (void *)&statInitVar << std::endl;
    std::cout << "data: " << (void *)&globalInitVar << std::endl;
    std::cout << "rodata: " << (void *)str << std::endl;
    std::cout << "text: " << (void *)main << std::endl; // 最低地址
    delete ptr;
    return 0;
}