#include <iostream>
#include <string>
using namespace std;
//sore, prosto interesno zaydet li po vremeni
//ya perepishu
int main()
{
    int arr[100];
    for (int i = 0; i < 100; ++i)
    {
        arr[i] = -2000000000;
    }
    int pos = 0;
    string tempStr;
    int tempInt;
    while (cin >> tempStr)
    {
        if (tempStr == "insert")
        {
            cin >> arr[pos++];
            continue;
        }
        if (tempStr == "delete")
        {
            cin >> tempInt;
            for (int i = 0; i < pos; ++i)
            {
                if (arr[i] == tempInt)
                {
                    arr[i] = -2000000000;
                    continue;
                }
            }
            continue;
        }
        if (tempStr == "exists")
        {
            bool fl = false;
            cin >> tempInt;
            for (int i = 0; i < pos; ++i)
            {
                if (arr[i] == tempInt)
                {
                    fl = true;
                    break;
                }
            }
            cout << (fl ? "true" : "false") << "\n";
        }
        if (tempStr == "next")
        {
            cin >> tempInt;
            int tempNext = 2000000000;
            for (int i = 0; i < pos; ++i)
            {
                if (arr[i] < tempNext && arr[i] > tempInt && arr[i] != -2000000000)
                {
                    tempNext = arr[i];
                }
            }
            if (tempNext > tempInt && tempNext != -2000000000 && tempNext != 2000000000)
            {
                cout << tempNext << "\n";
            }
            else
            {
                cout << "none" << "\n";
            }
            continue;
        }
        if (tempStr == "prev")
        {
            cin >> tempInt;
            int tempNext = -2000000000;
            for (int i = 0; i < pos; ++i)
            {
                if (arr[i] > tempNext && arr[i] < tempInt && arr[i] != -2000000000)
                {
                    tempNext = arr[i];
                }
            }
            if (tempNext < tempInt && tempNext != -2000000000)
            {
                cout << tempNext << "\n";
            }
            else
            {
                cout << "none" << "\n";
            }
        }
    }
    return 0;
}
