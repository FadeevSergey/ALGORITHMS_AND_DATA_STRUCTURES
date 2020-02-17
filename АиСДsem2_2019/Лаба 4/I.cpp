#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

std::vector<std::vector<int>> matrix;

bool check(const std::vector<std::vector<int>>& vect)
{
    int tempNumber;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            tempNumber = 0;
            for(int k = 0; k < 4; k++)
            {
                tempNumber += vect[i][k] * vect[k][j];
            }
            tempNumber %= 2;

            if(tempNumber != matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

#ifndef FLEX
    freopen("sqroot.in", "r", stdin);
    freopen("sqroot.out", "w", stdout);
#endif

    matrix = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    for(int i : {0, 1, 2 ,3})
    {
        for(int j : {0, 1, 2, 3})
        {
            cin >> matrix[i][j];
        }
    }
    bool fl;
    std::vector<std::vector<int>> sqrtM = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    for(int i = 0; i < 65536; i++)
    {
        fl = check(sqrtM);

        if(fl)
        {
            break;
        }

        for (int j = 15; j >= 0; --j)
        {
            if (sqrtM[j / 4][j % 4] == 0)
            {
                sqrtM[j / 4][j % 4] = 1;
                break;
            }
            else
            {
                sqrtM[j / 4][j % 4] = 0;
            }
        }
    }

    if(fl)
    {
        for(int i : {0, 1, 2 ,3})
        {
            for(int j : {0, 1, 2, 3})
            {
                cout << sqrtM[i][j] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }
    return 0;
}