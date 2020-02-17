//4, 5, 6, 7, 8 - на этом тесте упадет

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

#ifndef FLEX
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> array;
    array.reserve(n);
    for(int i = 0; i < n; i++)
    {
        array.push_back(0);
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    if(sum % 2 == 1)
    {
        cout << -1;
        return 0;
    }
    //sort(array.begin(), array.end(), [](int first, int second){ return first > second;});

    int half1 = 0;
    int half2 = 0;
    vector<pair<int, int>> result1;
    vector<int> result2;

    for(int i = n - 1; i >= 0; i--)
    {
        if(half1 > half2)
        {
            half2 += array[i];
            result2.push_back(array[i]);
        }
        else
        {
            half1 += array[i];
            result1.emplace_back(array[i], i + 1);
        }
    }

    if(half1 == half2)
    {
        sort(result1.begin(), result1.end(),
                [](const pair<int, int>& first, const pair<int, int> second){return first.second < second.second;});

        cout << result1.size() << "\n";
        for(pair<int, int> i : result1)
        {
            cout << i.second << " ";
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}