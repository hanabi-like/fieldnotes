#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <mutex>

#include "observer.h"

class Subject
{
private:
    std::vector<Observer *> objs;
    std::mutex mtx;
    int state;

public:
    void attach(Observer *obj)
    {
        std::lock_guard<std::mutex> lock(mtx);
        objs.emplace_back(obj);
    }
    void setState(int value)
    {
        std::lock_guard<std::mutex> lock(mtx);
        state = value;
        notify();
    }
    void notify();
};

void Subject::notify()
{
    for (auto obj : objs)
    {
        obj->update(state);
    }
}

void producer(Subject &s);

#endif