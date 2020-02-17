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
        arr[i] = min(arr[2 * i + 1], arr[2 * i + 2]);
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

long long min(long long l, long long r, long long parent)
{
    if (rigthS(parent) < l || leftS(parent) > r)
    {
        return 0;
    }
    if (leftS(parent) >= l && rigthS(parent) <= r)
    {
        return arr[parent];
    }
    return min(sum(l, r, parent * 2 + 1), sum(l, r, parent * 2 + 2));
}

static void sett(long long indexf, long long indexS, long long value) {
    if (n == 1)
    {
        arr[index] = value;
        return;
    }
    long long ex = arr[index];
    arr[index] = value;
    do
    {
        index = (index - 1) / 2;
        arr[index] = arr[index] - ex + value;
    }
    while(index > 0);
    return;
}
static void add(long long indexF, long long indexS, long long value)
{

}

int main()
{
    build();
    string str;
    long long first;
    long long second;
    while (cin >> str)
    {
        cin >> first;
        cin >> second;
        if(str == "min")
        {
            cout << min(first + newN - 2, second + newN - 2, 0) << "\n";
        }
        if(str == "add")
        {
            sett(first + newN - 2, second);
        }
    }
    delete arr;
    return 0;
}
