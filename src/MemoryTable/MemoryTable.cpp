//
// Created by Shun Yao on 2022/3/20.
//
#include "MemoryTable.hpp"

std::map<int, Value> MemoryTable::clear() {
    std::map<int, Value> res;
    res.insert(this->map.begin(), this->map.end());
    this->map.clear();
    return res;
}

std::map<int, Value> & MemoryTable::getMap() {
    return map;
}

void MemoryTable::put(int key, Value value) {
    // insert will not override old value will be override by new value in map
    // this->map.insert(pair<int, Value>(key, value));
    this->map[key] = value;
}

Value MemoryTable::query(int key) {
    bool isKey = this->map.count(key) == 1;
    if (isKey) {
        return this->map[key];
    } else {
        return Value(false);
    }
}

std::map<int, Value> MemoryTable::range_query(int min_key, int max_key) {
    auto low_position = map.lower_bound(min_key);
    auto high_position = map.upper_bound(max_key);
    // The range we need is  [low, high]
    std::map<int, Value> ret;
    for(auto iter = low_position; iter != high_position; iter++) {
        int key = iter->first;
        Value val = iter->second;
        ret[key] = val;
    }
    return ret;
}


