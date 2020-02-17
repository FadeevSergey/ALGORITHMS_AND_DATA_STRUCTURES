#include <iostream>

using namespace std;

int mas[4][3][7];
int masRes[4][3][100 + 1];

int sum(int i, int j, int n) {
        int res = 0;
        if ((i == 1 && j == 0 ) || (i == 1 && j == 2)) {
            res = (res + masRes[mas[i][j][1]][mas[i][j][2]][n - 1]) % 1000000000;
            res = (res + masRes[mas[i][j][3]][mas[i][j][4]][n - 1]) % 1000000000;
            res = (res + masRes[mas[i][j][5]][mas[i][j][6]][n - 1]) % 1000000000;
        } else {
            res = (res + masRes[mas[i][j][1]][mas[i][j][2]][n - 1]) % 1000000000;
            res = (res + masRes[mas[i][j][3]][mas[i][j][4]][n - 1]) % 1000000000;
        }
        return res;
    }
int main()
{
        ///////////////////////////////////////////////////////////////////////
        masRes[0][0][1] = masRes[0][1][1] = masRes[0][2][1] = masRes[1][0][1] = masRes[1][2][1] =
        masRes[2][0][1] = masRes[2][2][1] = 1;
        masRes[3][1][1] = masRes[2][1][1] = 0;
        mas[0][0][1] = 1; mas[0][0][2] = 2; mas[0][0][3] = 2; mas[0][0][4] = 1; mas[0][1][1] = 2;
        mas[0][1][2] = 0; mas[0][1][3] = 2; mas[0][1][4] = 2; mas[0][2][1] = 1; mas[0][2][2] = 0;
        mas[0][2][3] = 2; mas[0][2][4] = 1; mas[2][0][1] = 0; mas[2][0][2] = 1; mas[2][0][3] = 1;
        mas[2][0][4] = 2; mas[2][1][1] = 0; mas[2][1][2] = 0; mas[2][1][3] = 0; mas[2][1][4] = 2;
        mas[2][2][1] = 1; mas[2][2][2] = 0; mas[2][2][3] = 0; mas[2][2][4] = 1; mas[1][0][1] = 0;
        mas[1][0][2] = 2; mas[1][0][3] = 2; mas[1][0][4] = 2; mas[1][0][5] = 3; mas[1][0][6] = 1;
        mas[1][2][1] = 0; mas[1][2][2] = 0; mas[1][2][3] = 2; mas[1][2][4] = 0; mas[1][2][5] = 3;
        mas[1][2][6] = 1; mas[3][1][1] = 1; mas[3][1][2] = 0; mas[3][1][3] = 1; mas[3][1][4] = 2;
        ////////////////////////////////////////////////////////////////////////
    
        int n;
        cin >> n;
        int resSum = 0;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if (!((j == 1 && k == 1) || (j == 3 && k == 0) || (j == 3 && k == 2)))
                    {
                        masRes[j][k][i] = sum(j, k, i);
                    }
                }
            }
        }
        for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    if ((j == 3 && k == 0) || (j == 3 && k == 2) || (j == 1 && k == 1))
                    {
                        continue;
                    }
                    else
                    {
                        resSum = (resSum + masRes[j][k][n]) % 1000000000;
                    }
                }
            }
        cout << resSum;
        return 0;
}
