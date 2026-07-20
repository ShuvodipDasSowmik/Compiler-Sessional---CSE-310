#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ui unsigned int

class HashFunction{
    public:
        virtual ull calculateHash(const string &str, ui num_buckets) = 0;
        virtual ~HashFunction() {}
};

class SDBMHashFunction : public HashFunction{
    public:
        ull calculateHash(const string &str, ui num_buckets)
        {
            ui hash = 0;
            ui len = str.length();

            for (ui i = 0; i < len; i++){
                hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
            }

            return hash;
        }
};

class HashFunctionFactory{
    public:
        static HashFunction* createHashFunction(int hash_func = 1)
        {
            if (hash_func == 1)
                return new SDBMHashFunction();
            else
                return nullptr;
        }
};