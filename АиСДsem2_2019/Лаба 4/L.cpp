#include <iostream>
#include <fstream>
#include <vector>
#include <list>

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
    
    void insert(const int number)
    {
        if(!exists(number))
        {
            mHashTable[hashFunction(number)].push_back(number);
        }
    }
    
    bool exists(const int element)
    {
        size_t indexInTable = hashFunction(element);
        bool tableContainsElement = false;
        if(indexInTable < mTableSize)
        {
            for (int i : mHashTable[indexInTable])
            {
                if (i == element)
                {
                    
                    tableContainsElement = true;
                    break;
                }
            }
        }
        return tableContainsElement;
    }
    
    void deletee(int number)
    {
        int position = 0;
        int indexInTable = hashFunction(number);
        for(int i : mHashTable[indexInTable])
        {
            if(i == number)
            {
                mHashTable[indexInTable].erase(mHashTable[indexInTable].begin() + position);
                break;
            }
            position++;
        }
    }
    
private:
    size_t mTableSize;
    std::vector<std::vector<int>> mHashTable;
    
    size_t hashFunction(const int element)
    {
        return ((9999830011 * element + 4798669) % 97643212667) % mTableSize;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    HashTable set;
    string tempStr;
    int tempInt;
    while(cin >> tempStr)
    {
        if(tempStr == "insert")
        {
            cin >> tempInt;
            set.insert(tempInt);
            continue;
        }
        if(tempStr == "exists")
        {
            cin >> tempInt;
            cout << (set.exists(tempInt) ? "true" : "false") << "\n";
            continue;
        }
        if(tempStr == "delete")
        {
            cin >> tempInt;
            set.deletee(tempInt);
            continue;
        }
    }
}
