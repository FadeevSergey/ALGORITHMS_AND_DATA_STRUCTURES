#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<int> snm(n);
    for(int i = 0; i < n; i++)
    {
        snm[i] = i;
    }
    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < m; i++)
    {
        int in, out, w;
        cin >> in >> out >> w;
        in--; out--;
        if(in == out) { continue; }
        edges.emplace_back(make_pair(w, make_pair(in, out)));
    }
    sort(edges.begin(), edges.end());

    int cur = 0;
    long long result = 0;
    for(auto i : edges)
    {
        if(cur == n - 1) { break; }
        int fC = 0, sC = 0;
        int val1 = snm[i.second.first];

        while(val1 != snm[val1])
        {
            fC++;
            val1 = snm[val1];
        }

        int val2 = snm[i.second.second];

        while(val2 != snm[val2])
        {
            sC++;
            val2 = snm[val2];
        }

        if(val1 != val2)
        {

            result += i.first;
            if(sC < fC)
            {
                snm[val2] = val1;
                val2 = snm[i.second.second];
                while(val2 != snm[val2])
                {
                    val2 = snm[val2];
                    if(val2 != snm[val2])
                    {
                        break;
                    }
                    snm[val2] = val1;
                }
            }
            else
            {
                snm[val1] = val2;
                val1 = snm[i.second.first];
                while(val1 != snm[val1])
                {
                    val1 = snm[val1];
                    if(val1 != snm[val1])
                    {
                        break;
                    }
                    snm[val1] = val2;
                }
            }
            cur++;
        }
    }

    cout << result;
    return 0;
}
