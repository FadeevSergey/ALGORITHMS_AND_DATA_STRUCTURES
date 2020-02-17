#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", n);
    int a[2][n];
    int m = 0;
    for (int i = 0; i < n; ++i)
    {
        int t;
        scanf("%d", t);
        if (t == 3)
        {
        cout << a[1][m - 1] << '\n';
        }
        if (t == 2)
        {
        --m;
        }
        if (t == 1)
        {
        if (m != 0)
        {
        scanf("%d", a[0][m]);
        if (a[0][m] < a[1][m - 1])
        a[1][m] = a[0][m];
        else
        a[1][m] = a[1][m - 1];
        ++m;
        }
        else
        {
        scanf("%d", a[0][m]);
        a[1][m] = a[0][m];
        ++m;
        }
        }
    }
}
