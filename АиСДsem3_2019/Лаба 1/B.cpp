#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int timee = 0;
vector<int> result;

void dfs(vector<set<pair<int, int>>> &vectorIn, vector<bool> &visited, vector<int> &ret, vector<int> &enter, int v, int prev)
{
    timee++;
    enter[v] = timee;
    ret[v] = timee;
    visited[v] = true;
    for(pair<int, int> u : vectorIn[v])
    {
        if(enter[v] > enter[u.first] && prev != u.first)
        {
            ret[v] = min(ret[v], enter[u.first]);
        }
        if(!visited[u.first])
        {
            dfs(vectorIn, visited, ret, enter, u.first, v);
            ret[v] = min(ret[v], ret[u.first]);

            if(ret[u.first] > enter[v])
            {
                result.push_back(u.second + 1);
            }
        }
    }
}



int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<pair<int, int>>> vectorIn(n);
    vector<int> ret(n, -1);
    vector<int> enter(n, 3000000);
    vector<bool> visited(n, false);

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        in--;
        out--;
        vectorIn[out].insert(make_pair(in, i));
        vectorIn[in].insert(make_pair(out, i));
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(vectorIn, visited, ret, enter, i, -1);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(int i : result) { cout << i << " "; }
}