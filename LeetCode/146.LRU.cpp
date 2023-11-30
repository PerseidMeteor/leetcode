#include <list>
#include <iostream>
#include <algorithm>
#include "unordered_map"

using namespace std;
class LRUCache
{
    std::list<int> cache;
    std::unordered_map<int, std::list<int>::iterator> idx;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (idx.count(key) == 0)
            return -1;
        cache.erase(idx[key]);
        cache.emplace_front(key);
        return cache.front();
    }

    void put(int key, int value)
    {
        if (idx.count(key))
        {
            cache.erase(idx[key]);
            cache.emplace_front(key);
            cache.front() = value;
        }
        else
        {
            cache.emplace_front(value);
            idx[key] = cache.begin();
        }
        if (cache.size() > capacity)
        {
            idx.erase(cache.back());
            cache.pop_back();
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(1);
    std::cout << obj->get(0) << std::endl;
    obj->put(2, 1);
    // obj->put(2, 2);
    std::cout << obj->get(2) << std::endl;
    // obj->put(1, 1);
    // obj->put(4, 1);
    // std::cout << obj->get(2) << std::endl;
}