#pragma once

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ui = unsigned int;

class HashFunction {
public:
    virtual ull calculateHash(const string &str, ui num_buckets) = 0;
    virtual ~HashFunction() = default;
};

class SDBMHashFunction : public HashFunction {
public:
    ull calculateHash(const string &str, ui num_buckets) override {
        ull hash = 0;

        for (unsigned char character : str) {
            hash += character;
        }

        return hash % num_buckets;
    }
};

class HashFunctionFactory {
public:
    static HashFunction *createHashFunction(int hash_function = 1) {
        if (hash_function == 1) {
            return new SDBMHashFunction();
        }

        return nullptr;
    }
};
