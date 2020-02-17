#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HashTable
{
public:
    HashTable()
    {
        mTableSize = 100001;
        for(size_t i = 0; i < mTableSize; ++i)
        {
            mHashTable.emplace_back();
        }
    }

    void put(const string& key, const string& value)
    {
        size_t indexInTable = hashFunction(key);
        int size = mHashTable[indexInTable].size();
        for(int i = 0; i < size; i++)
        {
            if (mHashTable[indexInTable][i].first == key)
            {
                mHashTable[indexInTable][i].second = value;
                return;
            }
        }
        mHashTable[indexInTable].push_back({key, value});
    }

    string get(const string& key)
    {
        size_t indexInTable = hashFunction(key);
        int size = mHashTable[indexInTable].size();
        for (int i = 0; i < size; i++)
        {
            if (mHashTable[indexInTable][i].first == key)
            {
                return mHashTable[indexInTable][i].second;
            }
        }
        return "none";
    }

    void deletee(const string& key)
    {
        int position = 0;
        int indexInTable = hashFunction(key);
        int size = mHashTable[indexInTable].size();
        for(int i = 0; i < size; i++)
        {
            if(mHashTable[indexInTable][i].first == key)
            {
                mHashTable[indexInTable].erase(mHashTable[indexInTable].begin() + i);
                break;
            }
        }
    }

private:
    size_t mTableSize;
    std::vector<std::vector<pair<string, string>>> mHashTable;

    int hashFunction(const string& key)
    {
        int k = 0;
        int cur = 0;
        for(char ch : key)
        {
            //k += ch;
            k += ch * (int)pow(13, cur);
            cur++;
        }
        return k % mTableSize;
        //return ((9999830011 * k + 4798669) % 97643212667) % mTableSize;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    HashTable set;
    string tempStr;
    string tempKey;
    string tempValue;
    while(cin >> tempStr)
    {
        if(tempStr == "put")
        {
            cin >> tempKey >> tempValue;
            set.put(tempKey, tempValue);
            continue;
        }
        if(tempStr == "get")
        {
            cin >> tempKey;
            cout << set.get(tempKey) << "\n";
            continue;
        }
        if(tempStr == "delete")
        {
            cin >> tempKey;
            set.deletee(tempKey);
            continue;
        }
    }
}

