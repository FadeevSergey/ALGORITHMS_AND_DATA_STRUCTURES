#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int timee = 0;
set<int> result;

void dfs(vector<set<int>> &vectorIn, vector<bool> &visited, vector<int> &ret, vector<int> &enter, int v, int prev)
{
    timee++;
    enter[v] = timee;
    ret[v] = timee;
    visited[v] = true;
    int count = 0;
    for(int u : vectorIn[v])
    {
        if(visited[u] && u != prev)
        {
            ret[v] = min(ret[v], enter[u]);
        }
        if(!visited[u])
        {
            dfs(vectorIn, visited, ret, enter, u, v);
            ret[v] = min(ret[v], ret[u]);
            count++;

            if(prev != -1 && ret[u] >= enter[v])
            {
                result.insert(v + 1);
            }
        }
    }

    if(count >= 2 && prev == -1)
    {
        result.insert(v + 1);
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

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        in--; out--;
        vectorIn[out].insert(in);
        vectorIn[in].insert(out);
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(vectorIn, visited, ret, enter, i, -1);
        }
    }

    cout << result.size() << "\n";
    for(int i : result) { cout << i << " "; }
}