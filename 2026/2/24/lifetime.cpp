#include <iostream>
#include <string>

int globalInitVar = 0;              // 其他文件可以extern，定义在.c/.cpp，声明在.h
static int externalStatInitVar = 1; // 本文件可见，其他文件不可以extern

void func()
{
    static int innerStatInitVar = 2; // 函数内可见
    int tempVar = 3;
    int *ptr = new int(4);
    std::cout << "innerStatInitVar: " << (void *)&innerStatInitVar << std::endl;
    std::cout << "tempVar: " << (void *)&tempVar << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "func: " << (void *)func << std::endl;
    delete ptr;
}

int main()
{
    std::cout << "externalStatInitVar: " << externalStatInitVar << std::endl;
    // std::cout << "innerStatInitVar: " << (void *)&innerStatInitVar << std::endl; 仅func内部可见
    func();
    int tempVar[5] = {-1, -1, -1, -1, -1};
    int *ptr = new int[5];
    std::cout << "==========" << std::endl;
    func();
    std::cout << "==========" << std::endl;
    std::cout << "globalInitVar: " << (void *)&globalInitVar << std::endl;
    std::cout << "externalStatInitVar: " << (void *)&externalStatInitVar << std::endl;
    std::cout << "main: " << (void *)main << std::endl;
    delete[] ptr;
    return 0;
}