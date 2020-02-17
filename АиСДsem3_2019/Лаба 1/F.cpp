#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void dfs1(vector<set<int>> &edges, vector<bool> &visited, vector<int> &timeOut, int v)
{
    visited[v] = true;
    for(int u : edges[v])
    {
        if(!visited[u])
        {
            dfs1(edges, visited, timeOut, u);
        }
    }
    timeOut.push_back(v);
}

void dfs2(vector<set<int>> &edges, vector<bool> &visited, int v, int result, vector<int> &numberOfKomp)
{
    numberOfKomp[v] = result;
    visited[v] = true;
    for(int u : edges[v])
    {
        if(!visited[u])
        {
            dfs2(edges, visited, u, result, numberOfKomp);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> edges(n);
    vector<set<int>> edgesTrans(n);

    vector<bool> visited(n, false);
    vector<int> timeOut;
    vector<int> numberOfKomp(n, 0);

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        in--;
        out--;
        edges[in].insert(out);
        edgesTrans[out].insert(in);
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs1(edges, visited, timeOut, i);
        }
    }

    reverse(timeOut.begin(), timeOut.end());

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int result = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[timeOut[i]])
        {
            result++;
            dfs2(edgesTrans, visited, timeOut[i], result, numberOfKomp);
        }
    }

    vector<set<int>> edgesInCond(result);

    for(int i = 0; i < n; i++)
    {
        for(int j : edges[i])
        {
            if(numberOfKomp[i] != numberOfKomp[j])
            {
                edgesInCond[numberOfKomp[i] - 1].insert(numberOfKomp[j]);
            }
        }
    }

    int count = 0;

    for(int i = 0; i < result; i++)
    {
        count += edgesInCond[i].size();
    }

    cout << count;

    return 0;
}