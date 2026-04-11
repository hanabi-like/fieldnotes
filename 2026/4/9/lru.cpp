#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

class LRU
{
    int cap;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> umap;

public:
    LRU(int cap) : cap(cap) {}
    int get(int k)
    {
        auto it = umap.find(k);
        if (it == umap.end())
            return -1;
        items.splice(items.begin(), items, it->second);
        return it->second->second;
    }
    void put(int k, int v)
    {
        auto it = umap.find(k);
        if (it != umap.end())
        {
            items.splice(items.begin(), items, it->second);
            it->second->second = v;
            return;
        }
        if (items.size() == cap)
        {
            int lruK = items.back().first;
            umap.erase(lruK);
            items.pop_back();
        }
        items.emplace_front(k, v);
        umap[k] = items.begin();
        return;
    }
};