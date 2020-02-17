#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int timee = 0;
int maxColor = 0;

void dfs1(vector<set<int>> &vectorIn, vector<bool> &visited, vector<int> &ret, vector<int> &enter, int v, int prev)
{
    timee++;
    enter[v] = timee;
    ret[v] = timee;
    visited[v] = true;
    for(int u : vectorIn[v])
    {
        if(visited[u] && u != prev)
        {
            ret[v] = min(ret[v], enter[u]);
        }
        if(!visited[u])
        {
            dfs1(vectorIn, visited, ret, enter, u, v);
            ret[v] = min(ret[v], ret[u]);
        }
    }
}

void dfs2(vector<set<int>> &vectorIn, vector<map<int, int>> &color, vector<int> &ret,
          vector<int> &enter, int v, int prev, int tempColor, vector<bool> &visited)
{
    visited[v] = true;
    for(int u : vectorIn[v])
    {
        if(u == prev) { continue; }
        if(!visited[u])
        {
            if(ret[u] >= enter[v])
            {

                int newColor = ++maxColor;
                if(color[v][u] == 0)
                {
                    color[v][u] = maxColor;
                    color[u][v] = maxColor;
                }

                dfs2(vectorIn, color, ret, enter, u, v, newColor, visited);
            }
            else
            {
                color[v][u] = tempColor;
                color[u][v] = tempColor;

                dfs2(vectorIn, color, ret, enter, u, v, tempColor, visited);
            }
        }
        else
        {
            if(enter[u] < enter[v])
            {
                color[v][u] = tempColor;
                color[u][v] = tempColor;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> vectorIn(n);

    vector<int> ret(n, -1);
    vector<int> enter(n, INT_MAX - 1);

    vector<bool> visited(n, false);
    vector<map<int, int>> color(2 * m);
    vector<pair<int, int>> edges;

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        in--;
        out--;
        edges.emplace_back(make_pair(in, out));

        vectorIn[out].insert(in);
        vectorIn[in].insert(out);

        color[in][out] = 0;
        color[out][in] = 0;
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
        visited[i] = false;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs2(vectorIn, color, ret, enter, i, -1, maxColor, visited);
        }
    }

    /////////////////////////////////////////////////
    set<int> rest;
    for(pair<int, int> i: edges)
    {
        rest.insert(color[i.first][i.second]);
    }
    int cur = 0;
    map<int, int> resultMap;
    for(int i : rest)
    {
        cur++;
        resultMap[i] = cur;
    }
    cout << rest.size() << "\n";
    for(pair<int, int> i: edges)
    {
        cout << resultMap[color[i.first][i.second]] << " ";
    }
}