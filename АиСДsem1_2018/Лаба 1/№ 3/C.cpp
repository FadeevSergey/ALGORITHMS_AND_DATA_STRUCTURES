//https://ru.stackoverflow.com/questions/375825/%D0%A0%D0%B0%D0%B7%D0%B4%D0%B5%D0%BB%D1%8F%D0%B9-%D0%B8-%D0%B2%D0%BB%D0%B0%D1%81%D1%82%D0%B2%D1%83%D0%B9-%D0%BF%D0%BE%D0%B4%D1%81%D1%87%D0%B5%D1%82-%D0%BA%D0%BE%D0%BB%D0%B8%D1%87%D0%B5%D1%81%D1%82%D0%B2%D0%B0-%D0%B8%D0%BD%D0%B2%D0%B5%D1%80%D1%81%D0%B8%D0%B9-%D0%B2-%D0%BC%D0%B0%D1%81%D1%81%D0%B8%D0%B2%D0%B5
//https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D1%81%D0%BB%D0%B8%D1%8F%D0%BD%D0%B8%D0%B5%D0%BC
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr;

long long merge(int left, int right) {
    const int middle = (left + right) / 2;
    vector<int> tempArray(right - left);

    int first = 0;
    int second = 0;

    long long result = 0;

    while (left + first < middle && middle + second < right)
    {
        if (arr[left + first] > arr[middle + second])
        {
            tempArray[first + second] = arr[middle + second];
            second++;
            result += middle - first - left;
        }
        else
        {
            tempArray[first + second] = arr[left + first];
            first++;
        }
    }

    while (left + first < middle)
    {
        tempArray[first + second] = arr[left + first];
        first++;
    }

    while (middle + second < right)
    {
        tempArray[first + second] = arr[middle + second];
        second++;
    }

    for(int i = 0; i < first + second; i++)
    {
        arr[i + left] = tempArray[i];
    }

    return result;
}

long long mergeSort(int left, int right) {
    if (left + 1 >= right)
    {
        return 0;
    }

    long long result = 0;

    int middle = (left + right) / 2;

    result += mergeSort(left, middle);
    result += mergeSort(middle, right);

    result += merge(left, right);

    return result;
}

int main(){
    
    cin >> n;
    int tempNumber;
    for(int i = 0; i < n; i++)
    {
        cin >> tempNumber;
        arr.push_back(tempNumber);
    }

    cout << mergeSort(0, n) << "\n";
    for(int i : arr)
    {
        cout << i << " ";
    }
}
