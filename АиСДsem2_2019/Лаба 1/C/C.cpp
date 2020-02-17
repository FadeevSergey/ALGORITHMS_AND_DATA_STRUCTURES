#include <iostream>
#include <string>
using namespace std;

long long *arr;
long long n = 0;
long long newN = 0;

void build()
{
    cin >> n;
    long long result = 1;
    while (result < n)
    {
        result *= 2;
    }
    newN = result;
    arr = new long long[2 * newN - 1];
    for (long long i = 0; i < n; ++i)
    {
        cin >> arr[newN - 1 + i];
    }
    for (long long i = newN - 2; i >= 0; --i)
    {
        arr[i] = arr[2 * i + 1] + arr[2 * i + 2];
    }
}

long long leftS(long long x)
{
    long long indexLeftS = x;
    while (indexLeftS < newN * 2 - 1)
    {
        indexLeftS = indexLeftS * 2 + 1;
    }
    indexLeftS = (indexLeftS - 1) / 2;
    return indexLeftS;
}

long long rigthS(long long  x)
{
    long long indexRigthS = x;
    while (indexRigthS < newN * 2 - 1)
    {
        indexRigthS = indexRigthS * 2 + 2;
    }
    indexRigthS = (indexRigthS - 1) / 2;
    return indexRigthS;
}

int main()
{

}
