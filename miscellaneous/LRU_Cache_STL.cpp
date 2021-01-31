#include <bits/stdc++.h>
using namespace std;


int C;

list<int> cache;  // Stores the real-time snapshot of the keys in cache
unordered_map<int, pair<int, list<int>::iterator>> lookup;  //  key -> {value, pointer of key to list}

void bringNodeToFront(unordered_map<int, pair<int, list<int> :: iterator>> :: iterator itr)
{
    cache.erase(itr->second.second);
    int key = itr->first;
    cache.push_front(key);
    lookup[key] = {itr->second.first, cache.begin()};
}

int get(int key)
{
    if(lookup.find(key) == lookup.end()) return -1;
    else
    {
        auto it = lookup.find(key);
        bringNodeToFront(it);
        return lookup[key].first;
    }
    
}

void put(int key, int value)
{
    if(lookup.find(key) != lookup.end())        // key found in cache
    {
        lookup[key].first = value;
    }

    else                                        // add the key to cache 
    {
        if(cache.size() < C)                    // cache has not reached its limit
        {
            cache.push_front(key);
            lookup[key] = {value, cache.begin()};
        }
        else                                    // Cache is full, evict last visited key 
        {
            lookup.erase(cache.back());
            cache.pop_back();
            cache.push_front(key);
            lookup[key] = {value, cache.begin()};
        }                                      
    }
    
}

int main()
{
    int capacity = 3;
    C=capacity;
    // Test Case : {Get 2, put {1, -2}, put {2, -4}, put {3, -6}, Get 2 Get 6, put {4, -8}, put {5,-10}, Get 2, put {2, -10} Get 2};
    cout << "Get 2 " << get(2) <<endl;
    put(1,-2);
    put(2,-4);
    put(3,-6);
    cout << "Get 2 " << get(2) <<endl;
    cout << "Get 6 " << get(6)<< endl;
    cout << "Get 3 " << get(3) <<endl;
    put(4,-8);
    cout << "Get 1 " << get(1) <<endl;
    put(2, -10);
    cout << "Get 2 " << get(2) <<endl;
}