#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int timee = 0;

void dfs1(vector<set<int>> &edges, vector<bool> &visited, vector<int> &timeOut, int v)
{
    timee++;
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
    timee++;
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

    vector<set<int>> edges(2 * n);
    vector<set<int>> edgesTrans(2 * n);

    vector<bool> visited(2 * n, false);
    vector<int> timeOut;
    vector<int> numberOfKomp(2 * n, -1);
    map<string, int> names;
    vector<string> numberOfNames(n);

    for(int i = 0; i < n; i++)
    {
        string tempName;
        cin >> tempName;
        names[tempName] = i;
        numberOfNames[i] = tempName;
    }

    for(int i = 0; i < m; i++)
    {
        string in, out, shl;
        cin >> in >> shl >> out;
        if(in[0] == '+')
        {
            if(out[0] == '+')
            {
                edges[names[in.substr(1)]].insert(names[out.substr(1)]);
                edgesTrans[names[out.substr(1)]].insert(names[in.substr(1)]);

                edges[names[out.substr(1)] + n].insert(names[in.substr(1)] + n);
                edgesTrans[names[in.substr(1)] + n].insert(names[out.substr(1)] + n);
            }
            else
            {
                edges[names[in.substr(1)]].insert(names[out.substr(1)] + n);
                edgesTrans[names[out.substr(1)] + n].insert(names[in.substr(1)]);

                edges[names[out.substr(1)]].insert(names[in.substr(1)] + n);
                edgesTrans[names[in.substr(1)] + n].insert(names[out.substr(1)]);
            }
            continue;
        }

        if(in[0] == '-')
        {
            if(out[0] == '+')
            {
                edges[names[in.substr(1)] + n].insert(names[out.substr(1)]);
                edgesTrans[names[out.substr(1)]].insert(names[in.substr(1)] + n);

                edges[names[out.substr(1)] + n].insert(names[in.substr(1)]);
                edgesTrans[names[in.substr(1)]].insert(names[out.substr(1)] + n);
            }
            else
            {
                edges[names[in.substr(1)] + n].insert(names[out.substr(1)] + n);
                edgesTrans[names[out.substr(1)] + n].insert(names[in.substr(1)] + n);

                edges[names[out.substr(1)]].insert(names[in.substr(1)]);
                edgesTrans[names[in.substr(1)]].insert(names[out.substr(1)]);
            }
        }
    }

    for(int i = 0; i < 2 * n; i++)
    {
        if(!visited[i])
        {
            dfs1(edges, visited, timeOut, i);
        }
    }

    reverse(timeOut.begin(), timeOut.end());

    for(int i = 0; i < 2 * n; i++)
    {
        visited[i] = false;
    }

    int result = 0;

    for(int i = 0; i < 2 * n; i++)
    {
        if(!visited[timeOut[i]])
        {
            result++;
            dfs2(edgesTrans, visited, timeOut[i], result, numberOfKomp);
        }
    }


    vector<bool> res(n, false);

    int number = 0;


    for(int i = 0; i < n; i++)
    {
        if(numberOfKomp[i] > numberOfKomp[i + n])
        {
            res[i] = true;
            number++;
        }
        else
        {
            if(numberOfKomp[i] == numberOfKomp[i + n])
            {
                cout << -1;
                exit(0);
            }
            res[i] = false;
        }
    }

    cout << number << "\n";

    for(int i = 0; i < n; i++)
    {
        if(res[i])
        {
            cout << numberOfNames[i] << "\n";
        }
    }
}