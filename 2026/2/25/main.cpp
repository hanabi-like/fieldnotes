#include "unique_pointer.h"
#include "shared_pointer.h"
#include <utility>

void func()
{
    UniquePointer<int> uptrT(new int(10));
    SharedPointer<int> sptrT(new int(15));
}

int main()
{
    UniquePointer<int> uptrA(new int(5));
    SharedPointer<int> sptrA(new int(20));
    std::cout << *uptrA << " " << uptrA.get() << std::endl;
    std::cout << *sptrA << " " << sptrA.get() << std::endl;
    func();
    UniquePointer<int> uptrB = std::move(uptrA);
    // uptA.ptr = nullptr;
    // std::cout << *uptrA << " " << uptrA.get() << std::endl;
    std::cout << *uptrB << " " << uptrB.get() << std::endl;
    SharedPointer<int> sptrB(sptrA);
    std::cout << sptrB.use_count() << std::endl;
    SharedPointer<int> sptrC(std::move(sptrA));
    std::cout << sptrC.use_count() << std::endl;
    return 0;
}