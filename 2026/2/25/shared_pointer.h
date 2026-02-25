#include <iostream>

template <typename T>
class SharedPointer
{
private:
    T *ptr;
    size_t *count;
    void release()
    {
        if (count)
        {
            --(*count);
            if (*count == 0)
            {
                delete ptr;
                delete count;
                std::cout << "shared_pointer destruct" << std::endl;
            }
        }
        ptr = nullptr;
        count = nullptr;
    }

public:
    explicit SharedPointer(T *p = nullptr) : ptr(p), count(p ? new size_t(1) : nullptr) {}
    ~SharedPointer()
    {
        release();
    }
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
    SharedPointer(const SharedPointer &other) : ptr(other.ptr), count(other.count)
    {
        if (count)
            ++(*count);
    }
    SharedPointer(SharedPointer &&other) : ptr(other.ptr), count(other.count)
    {
        other.ptr = nullptr;
        other.count = nullptr;
    }
    SharedPointer &operator=(const SharedPointer &other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            count = other.count;
            if (count)
                ++(*count);
        }
        return *this;
    }
    SharedPointer &operator=(SharedPointer &&other)
    {
        if (this != &other)
        {
            release();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }
        return *this;
    }
    size_t use_count() const
    {
        return count ? *count : 0;
    }
};