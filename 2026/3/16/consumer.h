#ifndef CONSUMER_H
#define CONSUMER_H

#include <iostream>
#include <thread>

#include "observer.h"

class Consumer : public Observer
{
public:
    void update(int value) override
    {
        std::cout << "consumer received value: " << value << " from id: " << std::this_thread::get_id() << std::endl;
    }
};

#endif