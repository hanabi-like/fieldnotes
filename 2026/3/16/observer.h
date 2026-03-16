#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

class Observer
{
public:
    virtual void update(int value) = 0;
    virtual ~Observer() {};
};

#endif