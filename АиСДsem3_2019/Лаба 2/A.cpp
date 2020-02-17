#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long weight[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> weight[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                weight[j][k] = min(weight[j][i] + weight[i][k], weight[j][k]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << weight[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}