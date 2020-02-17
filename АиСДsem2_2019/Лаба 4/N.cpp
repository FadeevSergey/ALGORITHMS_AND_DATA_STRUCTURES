//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//struct line
//{
//    string key;
//    string value;
//
//    line* prev = nullptr;
//    line* next = nullptr;
//
//};
//
//line* last = nullptr;
//
//class HashTable
//{
//public:
//    HashTable()
//    {
//        mTableSize = 5000000;
//        for(size_t i = 0; i < mTableSize; ++i)
//        {
//            mHashTable.emplace_back();
//        }
//    }
//
//    void put(string& key, string& value)
//    {
//        size_t indexInTable = hashFunction(key);
//        int size = mHashTable[indexInTable].size();
//
//        for(int i = 0; i < size; i++)
//        {
//            if (mHashTable[indexInTable][i].key == key)
//            {
//                mHashTable[indexInTable][i].value = value;
//                return;
//            }
//        }
//
//        mHashTable[indexInTable].push_back({key, value, last, nullptr});
//
//        if(last != nullptr)
//        {
//            last->next = & mHashTable[indexInTable][mHashTable[indexInTable].size() - 1];
//        }
//
//        last = & mHashTable[indexInTable][mHashTable[indexInTable].size() - 1];
//
//    }
//
//    string get(string& key)
//    {
//        size_t indexInTable = hashFunction(key);
//        for (auto& i : mHashTable[indexInTable])
//        {
//            if (i.key == key)
//            {
//                return i.value;
//            }
//        }
//        return "none";
//    }
//
//    void deletee(string& key)
//    {
//        int indexInTable = hashFunction(key);
//        int size = mHashTable[indexInTable].size();
//        for(int i = 0; i < size; i++)
//        {
//            if(mHashTable[indexInTable][i].key == key)
//            {
//                //////////////////////////////////////////////
//                line* prev = mHashTable[indexInTable][i].prev;
//                line* next = mHashTable[indexInTable][i].next;
//                //////////////////////////////////////////////
//
//                if(last == & mHashTable[indexInTable][i])
//                {
//                    last = prev;
//                }
//
//                if(prev != nullptr)
//                {
//                    prev->next = next;
//                }
//
//                if(next != nullptr)
//                {
//                    next->prev = prev;
//                }
//                //mHashTable[indexInTable][i].key = "1234567544234567654anime";
//                mHashTable[indexInTable].erase(mHashTable[indexInTable].begin() + i);
//
//                return;
//            }
//        }
//    }
//
//    string prev(string& key)
//    {
//        int indexInTable = hashFunction(key);
//        for(auto & i : mHashTable[indexInTable])
//        {
//            if(i.key == key)
//            {
//                if(i.prev != nullptr)
//                {
//                    return i.prev->value;
//                }
//                else
//                {
//                    return "none";
//                }
//            }
//        }
//        return "none";
//    }
//
//    string next(string& key)
//    {
//        int indexInTable = hashFunction(key);
//        for(auto & i : mHashTable[indexInTable])
//        {
//            if(i.key == key)
//            {
//                if(i.next != nullptr)
//                {
//                    return i.next->value;
//                }
//                else
//                {
//                    return "none";
//                }
//            }
//        }
//        return "none";
//    }
//
//    void kol()
//    {
//        for(int i = 0; i < mTableSize; i++)
//        {
//            if(mHashTable[i].size() >= 2)
//            {
//                while(true);
//            }
//        }
//    }
//
//
//private:
//
//    int mTableSize;
//    std::vector<std::vector<line>> mHashTable;
//
//    int hashFunction(string& key)
//    {
//        long long k = 0;
//        int cur = 0;
//        for(char ch : key)
//        {
//            k += ch * (int)pow(11, cur);
//            k %= mTableSize;
//            cur++;
//        }
//        return (int)abs(k % mTableSize);
//    }
//};
//
//int main()
//{
//#ifndef ONLINE_JUDGE
//    freopen("linkedmap.in", "r", stdin);
//    freopen("linkedmap.out", "w", stdout);
//#endif
//
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    HashTable set;
//    string tempStr;
//    string tempKey;
//    string tempValue;
//    while(cin >> tempStr)
//    {
//        if(tempStr == "put")
//        {
//            cin >> tempKey >> tempValue;
//            set.put(tempKey, tempValue);
//            continue;
//        }
//        if(tempStr == "get")
//        {
//            cin >> tempKey;
//
//            cout <<  set.get(tempKey) << "\n";
//            continue;
//        }
//        if(tempStr == "delete")
//        {
//            cin >> tempKey;
//            set.deletee(tempKey);
//            continue;
//        }
//        if(tempStr == "next")
//        {
//            cin >> tempKey;
//            cout <<  set.next(tempKey) << "\n";
//        }
//        if(tempStr == "prev")
//        {
//            cin >> tempKey;
//            cout << set.prev(tempKey) << "\n";
//        }
//    }
//    set.kol();
//}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct line
{
    string key;
    string value;

    int prevF = -1;
    int prevS = -1;

    int nextF = -1;
    int nextS = -1;

};

class HashTable
{
public:
    HashTable()
    {
        mTableSize = 3000001;
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
            if (mHashTable[indexInTable][i].key == key)
            {
                mHashTable[indexInTable][i].value = value;

                return;
            }
        }

        mHashTable[indexInTable].push_back({key, value, predF, predS});

        if(predF >= 0 && predS >= 0)
        {
            mHashTable[predF][predS].nextF = indexInTable;
            mHashTable[predF][predS].nextS = mHashTable[indexInTable].size() - 1;
        }

        predF = indexInTable;
        predS = mHashTable[indexInTable].size() - 1;
    }

    string get(const string& key)
    {
        size_t indexInTable = hashFunction(key);
        int size = mHashTable[indexInTable].size();
        for (int i = 0; i < size; i++)
        {
            if (mHashTable[indexInTable][i].key == key)
            {
                return mHashTable[indexInTable][i].value;
            }
        }
        return "none";
    }

    void deletee(const string& key)
    {
        int indexInTable = hashFunction(key);
        int size = mHashTable[indexInTable].size();
        for(int i = 0; i < size; i++)
        {
            if(mHashTable[indexInTable][i].key == key)
            {
                //////////////////////////////////////////////
                int prevF = mHashTable[indexInTable][i].prevF;
                int prevS = mHashTable[indexInTable][i].prevS;

                int nextF = mHashTable[indexInTable][i].nextF;
                int nextS = mHashTable[indexInTable][i].nextS;
                //////////////////////////////////////////////

                if(indexInTable == predF && i == predS)
                {
                    predF = prevF;
                    predS = prevS;

                    if(prevF >= 0 && prevS >= 0)
                    {
                        mHashTable[prevF][prevS].nextF = -1;
                        mHashTable[prevF][prevS].nextS = -1;
                    }

                    for(int j = i + 1; j < size; j++)
                    {
                        if(mHashTable[indexInTable][j].prevF >= 0 && mHashTable[indexInTable][j].prevS >= 0)
                        {
                            mHashTable[mHashTable[indexInTable][j].prevF][mHashTable[indexInTable][j].prevS].nextS--;
                        }
                        if(mHashTable[indexInTable][j].nextF >= 0 && mHashTable[indexInTable][j].nextS >= 0)
                        {
                            mHashTable[mHashTable[indexInTable][j].nextF][mHashTable[indexInTable][j].nextS].prevS--;
                        }
                    }



                    mHashTable[indexInTable].erase(mHashTable[indexInTable].begin() + i);

                    return;
                }

                if(prevF >= 0 && prevS >= 0)
                {
                    mHashTable[prevF][prevS].nextF = nextF;
                    mHashTable[prevF][prevS].nextS = nextS;
                }

                if(nextF >= 0 && nextS >= 0)
                {
                    mHashTable[nextF][nextS].prevF = prevF;
                    mHashTable[nextF][nextS].prevS = prevS;
                }

                for(int j = i + 1; j < size; j++)
                {
                    if(mHashTable[indexInTable][j].prevF >= 0 && mHashTable[indexInTable][j].prevS >= 0)
                    {
                        mHashTable[mHashTable[indexInTable][j].prevF][mHashTable[indexInTable][j].prevS].nextS--;
                    }
                    if(mHashTable[indexInTable][j].nextF >= 0 && mHashTable[indexInTable][j].nextS >= 0)
                    {
                        mHashTable[mHashTable[indexInTable][j].nextF][mHashTable[indexInTable][j].nextS].prevS--;
                    }
                }

                mHashTable[indexInTable].erase(mHashTable[indexInTable].begin() + i);

                return;
            }
        }
    }

    string prev(const string& key)
    {
        int indexInTable = hashFunction(key);
        for(int i = 0; i < mHashTable[indexInTable].size(); ++i)
        {
            if(mHashTable[indexInTable][i].key == key)
            {
                if(mHashTable[indexInTable][i].prevF >= 0 && mHashTable[indexInTable][i].prevS >= 0)
                {
                    return mHashTable[mHashTable[indexInTable][i].prevF][mHashTable[indexInTable][i].prevS].value;
                }
                else
                {
                    return "none";
                }
            }
        }
        return "none";
    }

    string next(const string& key)
    {
        int indexInTable = hashFunction(key);
        for(int i = 0; i < mHashTable[indexInTable].size(); ++i)
        {
            if(mHashTable[indexInTable][i].key == key)
            {
                if(mHashTable[indexInTable][i].nextF >= 0 && mHashTable[indexInTable][i].nextS >= 0)
                {
                    return mHashTable[mHashTable[indexInTable][i].nextF][mHashTable[indexInTable][i].nextS].value;
                }
                else
                {
                    return "none";
                }
            }
        }
        return "none";
    }

private:
    size_t mTableSize;
    std::vector<std::vector<line>> mHashTable;

    int predF = -1;
    int predS = -1;

    int hashFunction(const string& key)
    {
        int k = 0;
        int cur = 0;
        for(char ch : key)
        {
            k += ch * (int)pow(11, cur);
            cur++;
        }
        return k % mTableSize;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
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
            cout <<  set.get(tempKey) << "\n";
            continue;
        }
        if(tempStr == "delete")
        {
            cin >> tempKey;
            set.deletee(tempKey);
            continue;
        }
        if(tempStr == "next")
        {
            cin >> tempKey;
            cout <<  set.next(tempKey) << "\n";
        }
        if(tempStr == "prev")
        {
            cin >> tempKey;
            cout << set.prev(tempKey) << "\n";
        }
//        if(tempStr == "print")
//        {
//            cin >> tempKey;
//            set.print(tempKey);
//        }
    }
}
