#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include "consumer.h"
#include "subject.h"

void producer(Subject &s)
{
    for (int i = 0; i < 5; ++i)
    {
        s.setState(i);
    }
}

int main()
{
    Subject s;
    Consumer obj1;
    Consumer obj2;
    s.attach(&obj1);
    s.attach(&obj2);
    std::thread t1(producer, std::ref(s));
    std::thread t2(producer, std::ref(s));
    t1.join();
    t2.join();

    return 0;
}