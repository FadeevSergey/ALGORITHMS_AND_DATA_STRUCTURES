#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> tempWeight(n, LONG_MAX);
    tempWeight[0] = 0;
    vector<bool> used(n, false);
    vector<vector<pair<int, int>>> edges(n);
    set<pair<long long, long long>> weight;
    weight.insert(make_pair(tempWeight[0], 0));

    for(int i = 0; i < m; i++)
    {
        int in, out, weight;
        cin >> in >> out >> weight;
        in--;
        out--;

        edges[out].emplace_back(make_pair(in, weight));
        edges[in].emplace_back(make_pair(out, weight));
    }

    while(!weight.empty())
    {
        int v = weight.begin()->second;
        weight.erase(weight.begin());

        for(int j = 0; j < edges[v].size(); j++)
        {
            if (tempWeight[v] + edges[v][j].second < tempWeight[edges[v][j].first])
            {
                tempWeight[edges[v][j].first] = tempWeight[v] + edges[v][j].second;
                weight.insert (make_pair(tempWeight[edges[v][j].first], edges[v][j].first));
            }
        }
    }

    for(int i = 0; i < n; i++) { cout << tempWeight[i] << " "; }

    return 0;
}