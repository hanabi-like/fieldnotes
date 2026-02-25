#include <iostream>

template <typename T>
class UniquePointer
{
private:
    T *ptr;

public:
    explicit UniquePointer(T *p = nullptr) : ptr(p) {}
    ~UniquePointer()
    {
        if (ptr == nullptr)
        {
            std::cout << "unique_pointer destruct nullptr" << std::endl;
        }
        else
        {
            std::cout << "unique_pointer destruct whose value = " << *ptr << std::endl;
        }
        delete ptr;
    }
    // 禁止拷贝构造和拷贝赋值
    UniquePointer(const UniquePointer &) = delete;
    UniquePointer &operator=(const UniquePointer &) = delete;
    T *get() const
    {
        return ptr;
    }
    T &operator*() const
    {
        return *ptr;
    }
    T *operator->() const
    {
        return ptr;
    }
    UniquePointer(UniquePointer &&other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr; // 确保不要释放有效内存
    }
    UniquePointer &operator=(UniquePointer &&other) noexcept
    {
        if (this != &other)
        {
            ptr = nullptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};