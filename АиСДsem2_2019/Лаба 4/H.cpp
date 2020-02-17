#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool check(const vector<int>& vect)
{
    for(int i = 1; i < vect.size(); i++)
    {
        if(vect[i - 1] == 1 && vect[i] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
#ifndef FLEX
    freopen("vectors2.in", "r", stdin);
    freopen("vectors2.out", "w", stdout);
#endif
    std::vector<std::vector<int>> result;
    int len;
    cin >> len;
    int n = pow(2, len);
    std::vector<int> vect;
    vect.reserve(len);
    for(int i = 0; i < len; i++)
    {
        vect.push_back(0);
    }
    for (int i = 0; i < n; ++i)
    {
        if(check(vect))
        {
            result.push_back(vect);
        }
        for (int j = len - 1; j >= 0; --j)
        {
            if (vect[j] == 0)
            {
                vect[j] = 1;
                break;
            }
            else
            {
                vect[j] = 0;
            }
        }
    }

    cout << result.size() << "\n";

    for(const auto& i : result)
    {
        for(int j = 0; j < len; j++)
        {
            cout << i[j];
        }
        cout << "\n";
    }
}