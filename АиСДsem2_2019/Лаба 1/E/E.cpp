#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
    ifstream fin("crypto.in");
    vector<vector<long long>> arr;
    int n = 1;
    int m = 1;
    int mod = 1;
    int newN = 1;

    int leftS(int x)
    {
        int indexLeftS = x;
        while (indexLeftS < newN * 2 - 1)
        {
            indexLeftS = indexLeftS * 2 + 1;
        }
        indexLeftS = (indexLeftS - 1) / 2;
        return indexLeftS;
    }

    int rigthS(int  x)
    {
        int indexRigthS = x;
        while (indexRigthS < newN * 2 - 1)
        {
            indexRigthS = indexRigthS * 2 + 2;
        }
        indexRigthS = (indexRigthS - 1) / 2;
        return indexRigthS;
    }

    void build()
    {
        fin >> mod;
        fin >> n;
        fin >> m;
        newN = 1;
        while (newN < n)
        {
            newN *= 2;
        }
        for (int i = 0; i < 2 * newN - 1; ++i)
        {
            vector<long long> tempVector = {1, 0, 0, 1, i, i};
            arr.push_back(tempVector);
        }

        for (int i = 0; i < n; ++i)
        {
            vector<long long> tempVector;
            long long temp;
            for (long long k = 0; k < 4; ++k)
            {
                fin >> temp;
                tempVector.push_back(temp);
            }
            tempVector.push_back(newN - 1 + i);
            tempVector.push_back(newN - 1 + i);
            arr[newN - 1 + i] = tempVector;
        }
        for (int i = newN - 2; i >= 0; --i)
        {
            arr[i][0] = ((arr[2 * i + 1][0] * arr[2 * i + 2][0]) + (arr[2 * i + 1][1] * arr[2 * i + 2][2])) % mod;
            arr[i][1] = ((arr[2 * i + 1][0] * arr[2 * i + 2][1]) + (arr[2 * i + 1][1] * arr[2 * i + 2][3])) % mod;
            arr[i][2] = ((arr[2 * i + 1][2] * arr[2 * i + 2][0]) + (arr[2 * i + 1][3] * arr[2 * i + 2][2])) % mod;
            arr[i][3] = ((arr[2 * i + 1][2] * arr[2 * i + 2][1]) + (arr[2 * i + 1][3] * arr[2 * i + 2][3])) % mod;
            arr[i][4] = leftS(i);
            arr[i][5] = rigthS(i);
        }

    }
    vector<long long> sum(int l, int r, int parent)
    {
        vector<long long> tempVec;
        if (arr[parent][5] < l || arr[parent][4] > r)
        {
            return {1, 0, 0, 1};
        }
        if (arr[parent][4] >= l && arr[parent][5] <= r)
        {
            return {arr[parent][0], arr[parent][1], arr[parent][2], arr[parent][3]};
        }

        vector <long long> tempVec1 = sum(l, r, parent * 2 + 1);
        vector <long long> tempVec2 = sum(l, r, parent * 2 + 2);

        /*tempVec.push_back(((tempVec1[0] * tempVec2[0]) + (tempVec1[1] * tempVec2[2]))%mod);
        tempVec.push_back(((tempVec1[0] * tempVec2[1]) + (tempVec1[1] * tempVec2[3]))%mod);
        tempVec.push_back(((tempVec1[2] * tempVec2[0]) + (tempVec1[3] * tempVec2[2]))%mod);
        tempVec.push_back(((tempVec1[2] * tempVec2[1]) + (tempVec1[3] * tempVec2[3]))%mod);*/
        //return tempVec;
        return {((tempVec1[0] * tempVec2[0]) + (tempVec1[1] * tempVec2[2]))%mod,
                ((tempVec1[0] * tempVec2[1]) + (tempVec1[1] * tempVec2[3]))%mod,
                ((tempVec1[2] * tempVec2[0]) + (tempVec1[3] * tempVec2[2]))%mod,
                ((tempVec1[2] * tempVec2[1]) + (tempVec1[3] * tempVec2[3]))%mod};
    }

    int main()
    {
        build();
        long long first;
        long long second;
        ofstream fout("crypto.out");
        for (int i = 0; i < m; ++i)
        {
            fin >> first;
            fin >> second;
            vector<long long> tempVector = sum(newN - 2 + first, newN - 2 + second, 0);
            fout << tempVector[0] << " " << tempVector[1] << "\n" << tempVector[2] << " " << tempVector[3] << "\n" << "\n";
        }
        fin.close();
        fout.close();
        return 0;
    }
