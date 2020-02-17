#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//struct trip
//{
//    int in = -1;
//    int out = -1;
//    int weight;
//};

int main() {
    int n;
    cin >> n;

    vector<int> parents(n, -1);
    vector<int> weight(n, 1);
    set<pair<int, pair<int, int>>> edges;
    int hochuSpat;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int tempWeight;
            cin >> tempWeight;
            if(tempWeight != 100000)
            {
                edges.insert(make_pair(i, make_pair(j, tempWeight)));
            }
        }
    }

    for(auto i : edges)
    {
        weight[i.first] = 0;
        break;
    }

    for(int o = 0; o < n; o++)
    {
        hochuSpat = INT_MIN;
        for(auto i : edges)
        {
            if(weight[i.second.first] > weight[i.first] + i.second.second)
            {
                weight[i.second.first] = weight[i.first] + i.second.second;
                parents[i.second.first] = i.first;
                hochuSpat = i.second.first;
            }
        }
    }

    if(hochuSpat == INT_MIN)
    {
        cout << "NO";
        return 0;
    }

    int prev = hochuSpat;

    for(int i = 0; i < n; i++) // to cycle
    {
        prev = parents[prev];
    }

    vector<int> way;
    int tempNode = prev;
    while(tempNode != prev || way.size() <= 1)
    {
        way.push_back(tempNode);
        tempNode = parents[tempNode];
    }
    reverse(way.begin(), way.end());
    cout << "YES" << "\n" << way.size() << "\n";
    for(int i : way)
    {
        cout << i + 1 << " ";
    }
}