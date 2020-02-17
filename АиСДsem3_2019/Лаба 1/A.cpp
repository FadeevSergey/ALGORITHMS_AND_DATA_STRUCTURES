#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> vectorOut(n);
    vector<set<int>> vectorIn(n);
    vector<bool> used(n, false);

    for(int i = 0; i < m; i++)
    {
        int in, out;
        if(in == out)
        {
            continue;
        }
        cin >> in >> out;
        in--;
        out--;
        vectorOut[in].insert(out);
        vectorIn[out].insert(in);
    }
    vector<int> result;

    bool flag = true;

    for(int j = 0; j < n; j++)
    {
        bool tempFlag = false;
        for(int i = 0; i < n; i++)
        {
            if (vectorIn[i].empty() && !used[i])
            {
                result.push_back(i);
                for (int v : vectorOut[i])
                {
                    vectorIn[v].erase(i);
                }
                used[i] = true;
                tempFlag = true;
                if(result.size() == n)
                {
                    for(int v : result)
                    {
                        cout << v + 1 << " ";
                    }
                    exit(0);
                }
            }
        }
        if(!tempFlag && result.size() != n)
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        for(int v : result)
        {
            cout << v + 1 << " ";
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}
