//this code shit

//Fadeev Sergey. 2019
//D - Опекуны карнотавров
//https://codeforces.com/group/CYMPFXi8zA/contest/243321/problem/D

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int M = 200000;
int logg = log2(M);

vector<int> d(M +  1, 0);
vector<bool> cond(M + 1, true);
vector<int> p(M + 1, -1);
vector<vector<int>> dp(M + 1, vector<int>(logg + 1, 0));

int realParent(int first)
{
    if(!cond[p[first]])
    {
        p[first] = realParent(p[first]);
    }
    return p[first];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> M;
    dp[1][0] = 1;
    p[1] = 1;
    int numDin = 1;
    for (int j = 0; j < logg; ++j)
    {
        dp[1][j] = 1;
    }
    for(int o = 0; o != M; ++o)
    {
        int first = 0;
        int second = 0;
        char operation;
        cin >> operation;
        if(operation == '+')
        {
            ++numDin;
            cin >> first;
            d[numDin] = d[first] + 1;
            p[numDin] = first;
            dp[numDin][0] = first;
            for (int j = 1; j <= logg; ++j)
            {
                dp[numDin][j] = dp[dp[numDin][j - 1]][j - 1];
            }
            continue;
        }
        if(operation == '-')
        {
            cin >> first;
            cond[first] = false;
            continue;
        }

        if(operation == '?')
        {
            cin >> first >> second;
            if (d[second] > d[first]) {
                swap(first, second);
            }
            int del = d[first] - d[second];
            while (d[first] != d[second]) {
                int temp = log2(del);
                del = del - pow(2, temp);
                first = dp[first][temp];
            }
            if (first == second)
            {
                if (!cond[first])
                {
                    first = realParent(first);
                }
                cout << first << "\n";
                continue;
            }
            while (dp[first][0] != dp[second][0])
            {
                int tempMax = -1;
                for (int j = 0; j <= logg; j++) {
                    if (dp[first][j] != dp[second][j]) {
                        tempMax = j;
                    }
                }
                first = dp[first][tempMax];
                second = dp[second][tempMax];
            }
            int result = dp[first][0];
            if (!cond[dp[first][0]])
            {
                result = realParent(dp[first][0]);
            }
            cout << result << "\n";
        }
    }
    return 0;
}