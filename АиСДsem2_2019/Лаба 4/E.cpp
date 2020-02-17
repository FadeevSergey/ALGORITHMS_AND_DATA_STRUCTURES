//Fadeev Sergey. 2019
//Задача B. Выбор заявок

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct trip
{
    int first;
    int second;
    int number;
};

int main()
{
#ifndef FLEX
    freopen("apples.in", "r", stdin);
    freopen("apples.out", "w", stdout);
#endif

    int n, s;
    cin >> n >> s;

    vector<pair<int, trip>> vector;
    int first, second;

    for(int i = 1; i <= n; ++i)
    {
        cin >> first >> second;

        vector.push_back({(second - first), {first, second, i}});
    }

    sort(vector.begin(), vector.end(), [](const pair<int, trip>& a, const pair<int, trip>& b){ return a.first > b.first;});
    std::set<int> set;
    int start = 0;

    for(int i = 0; i < vector.size(); ++i)
    {
        if(vector[i].first < 0)
        {
            start = i;
            break;
        }
    }
    if(start != 0)
        sort(vector.begin(), vector.begin() + start - 1,
                [](const pair<int, trip>& a, const pair<int, trip>& b){ return a.second.first < b.second.first;});

    sort(vector.begin() + start, vector.end(),
            [](const pair<int, trip>& a, const pair<int, trip>& b){ return a.second.second > b.second.second;});

    std::vector<int> result;

//    for(int i = 0; i < n; i++)
//    {
//
//    }

    std::vector<std::vector<pair<int, pair<int, int>>>> vec;
    int last = -200000000;
    int size = 0;

    for(int i = 0; i < n; i++)
    {
        if(vector[i].first != last)
        {
            size++;
            last = vector[i].first;
        }
    }

    int arr[size];
    vec.reserve(size);
    for(int i = 0; i < size; i++)
    {
        vec.emplace_back();
    }
    last = -1;
    int cur = -1;

    for(int i = 0; i != n; ++i)
    {
        if(vector[i].first != last)
        {
            last = vector[i].first;
            cur++;
            arr[cur] = last;
            vec[cur].push_back({vector[i].second.first, {vector[i].second.second, vector[i].second.number}});
        }
        else
        {
            vec[cur].push_back({vector[i].second.first, {vector[i].second.second, vector[i].second.number}});
        }
    }

//    for(int i = 0; i < size; ++i)
//    {
//        sort(vec[i].begin(), vec[i].end(),
//                [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){ return a.first < b.first;});
//    }

    while(true)
    {
        bool fl = false;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (!set.count(vec[i][j].second.second))
                {
                    if (vec[i][j].first < s)
                    {
                        fl = true;
                        s += arr[i];
                        set.insert(vec[i][j].second.second);
                        result.push_back(vec[i][j].second.second);
                    }
                }
            }
        }

        if(!fl)
        {
            break;
        }
    }


    if(set.size() == n)
    {
        for(int i : result)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "-1";
    }

    return 0;
}