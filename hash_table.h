//
// Created by rrivas on 23/06/2023.
//

#ifndef PROG3_20231_HASH_TABLE_HASH_TABLE_H
#define PROG3_20231_HASH_TABLE_HASH_TABLE_H

#include <functional>
#include <forward_list>
#include <algorithm>
using namespace std;

template<typename KeyType,
         typename ValueType,
         typename HashType = std::hash<KeyType>
         >
class hash_table {
    using record_t = pair<KeyType, ValueType>;
    using bucket_t = forward_list<record_t>;
    using buckets_t = vector<bucket_t>;

    size_t get_index(const KeyType& key) {
        HashType hash_fn;
        return hash_fn(key) % m;
    }

    size_t m = 11;
    buckets_t buckets;
public:
    hash_table():buckets(m) {}
    bool insert(const record_t& record) {
        auto index = get_index(record.first);
        auto bucket = buckets[index];
        auto find_record =[](const record_t& s, const record_t& t) {
            return s.first == t.first;
        };
        auto it = find_if(begin(bucket), end(bucket), find_record);
        if (it == end(bucket)){
            bucket.push_front(record);
            return true;
        }
        return false;
    }

    pair<ValueType, bool> find(const KeyType& key) {
        auto index = get_index(key);
        auto bucket = buckets[index];
        auto find_record =[](const record_t& s, const record_t& t) {
            return s.first == t.first;
        };
        auto it = find_if(begin(bucket), end(bucket), find_record);
        if (it != end(bucket)) {
            return {*it, true};
        }
        return {{KeyType{},ValueType{}}, false};
    }

    bool erase(const KeyType& key) {
        auto index = get_index(key);
        auto bucket = buckets[index];
        auto find_record =[](const record_t& s, const record_t& t) {
            return s.first == t.first;
        };
        auto it = find_if(begin(bucket), end(bucket), find_record);
        if (it != end(bucket)) {
            std::erase(bucket,key);
            return true;
        }
        return false;
    }

    ValueType& operator[](const KeyType& key) {
        auto [value, status] = find(key);
        if (status == true) {
            return value.second;
        }
        // Insertar un nuevo valor
        return ValueType{};
    }

};

#endif //PROG3_20231_HASH_TABLE_HASH_TABLE_H
