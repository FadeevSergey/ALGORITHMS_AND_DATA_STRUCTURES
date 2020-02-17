//Fadeev Sergey. 2019
//Задача B. Выбор заявок

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
#ifndef FLEX
    freopen("request.in", "r", stdin);
    freopen("request.out", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<pair<int, int>> vector;
    int first, second;

    for(int i = 0; i < n; ++i)
    {
        cin >> first >> second;
        vector.emplace_back(second, first);
    }

    sort(vector.begin(), vector.end());

    int last = 0;
    int result = 0;

    for(int i = 0; i < n; i++)
    {
        if(vector[i].second >= last)
        {
            last = vector[i].first;
            result++;
        }
    }

    cout << result;
    return 0;
}