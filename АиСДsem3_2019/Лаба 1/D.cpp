#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int timee = 0;

set<pair<int, int>> result;


void dfs1(vector<map<int, int>> &vectorIn, vector<bool> &visited, vector<int> &ret, vector<int> &enter, int v, int prev)
{
    timee++;
    enter[v] = timee;
    ret[v] = timee;
    visited[v] = true;
    for(auto u : vectorIn[v])
    {
        if(enter[v] > enter[u.first] && prev != u.first)
        {
            ret[v] = min(ret[v], enter[u.first]);
        }
        if(!visited[u.first])
        {
            dfs1(vectorIn, visited, ret, enter, u.first, v);
            ret[v] = min(ret[v], ret[u.first]);

            if(ret[u.first] > enter[v] && vectorIn[v][u.first] == 1)
            {
                result.insert(make_pair(u.first, v));
            }
        }
    }
}

int res = 0;

void dfs2(vector<map<int, int>> &vectorIn, vector<int> &color, int v,
          int tempColor, vector<int> &ret, vector<int> &enter)
{
    color[v] = tempColor;
    for(auto u : vectorIn[v])
    {
        if(color[u.first] == 0 && (result.count(make_pair(v, u.first)) == 0 && result.count(make_pair(u.first, v)) == 0))
        {
            dfs2(vectorIn, color, u.first, tempColor, ret, enter);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<map<int, int>> vectorIn(n);
    vector<int> ret(n, -1);
    vector<int> enter(n, 3000000);
    vector<bool> visited(n, false);
    vector<int> color(n, 0);

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        if(in == out)
        {
            continue;
        }
        in--;
        out--;
        vectorIn[out][in]++;
        vectorIn[in][out]++;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs1(vectorIn, visited, ret, enter, i, -1);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(color[i] == 0)
        {
            res++;
            dfs2(vectorIn, color, i, res, ret, enter);
        }
    }


    cout << res << "\n";
    for(int i : color)
    {
        cout << i << " ";
    }
}