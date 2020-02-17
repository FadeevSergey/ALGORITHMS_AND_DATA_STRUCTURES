#include <iostream>
#include <vector>
using namespace std;

void col(vector<vector<int>> &redges, vector<int> &color, int s, int nodeColor)
{
    if(color[s] == nodeColor){return;}
    if(color[s] == 100){color[s] = nodeColor;}
    if(color[s] != nodeColor){color[s] = -1;}

    for(int i : redges[s])
    {
        if(color[s] == 1)
            col(redges, color, i, 0);
        else if(color[s] == 0)
            col(redges, color, i, 1);
        else
            col(redges, color, i, -1);
    }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> edges(n);
    vector<vector<int>> redges(n);
    vector<int> color(n, 100);

    for(int i = 0; i < m; i++)
    {
        int in, out;
        cin >> in >> out;
        in--; out--;
        edges[in].push_back(out);
        redges[out].push_back(in);
    }

    for(int i = 0; i < n; i++)
    {
        if(edges[i].empty())
        {
            col(redges, color, i, 0);
        }
    }

    cout << (color[s]  ? "First player wins" : "Second player wins");

    return 0;
}
