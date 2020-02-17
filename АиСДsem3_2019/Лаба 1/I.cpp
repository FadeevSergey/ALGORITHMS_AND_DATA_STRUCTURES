#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> nodes;
    vector<bool> used(n, false);
    vector<double> minEdge(n, 10000001.0);
    vector<int> parent(n, -1);
    minEdge[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nodes.emplace_back(make_pair(x, y));
    }

    double result = 0;
    for(int i = 0; i < n; ++i)
    {
        int tempNode = -1;
        for(int j = 0; j < n; ++j)
        {
            if (!used[j] && (tempNode == -1 || minEdge[j] < minEdge[tempNode]))
            {
                tempNode = j;
            }
        }

        used[tempNode] = true;
        if(parent[tempNode] != -1)
        {
            result += distance(nodes[tempNode].first, nodes[tempNode].second,
                               nodes[parent[tempNode]].first, nodes[parent[tempNode]].second);
        }

        for(int possibleNewNode = 0; possibleNewNode < n; ++possibleNewNode)
        {
            if(distance(nodes[tempNode].first, nodes[tempNode].second,
                        nodes[possibleNewNode].first, nodes[possibleNewNode].second) < minEdge[possibleNewNode])
            {
                parent[possibleNewNode] = tempNode;
                minEdge[possibleNewNode] = distance(nodes[tempNode].first, nodes[tempNode].second,
                                                    nodes[possibleNewNode].first, nodes[possibleNewNode].second);
            }
        }
    }

    printf("%.10f", result);
}