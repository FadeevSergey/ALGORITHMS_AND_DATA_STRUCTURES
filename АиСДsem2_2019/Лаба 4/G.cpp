//G. Красивая перестановка
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, r;

inline bool check(vector<int>& array){

    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += array[i] * array[i + 1];
    }
    sum %= r;
    if(sum == 0)
    {
        return true;
    }
    int result = 0;
    int i = 1;
    while(i * i <= sum)
    {
        if(sum % i == 0)
        {
            if(i * i == sum)
            {
                result++;
                break;
            }
            //cout << i <<  "+\n";
            result += 2;
        }
        i++;
    }
    //cout << result << "\n";
    return result % 3 == 0;
}

int main(){

#ifndef FLEX
    freopen("beautiful.in", "r", stdin);
    freopen("beautiful.out", "w", stdout);
#endif

    cin >> n >> r;
    vector<int> arr;
    arr.reserve(n);

    for(int i = 0; i < n; i++){
        arr.push_back(0);
    }

    for (int i = 0; i < n; ++i){
        arr[i] = i + 1;
    }

    int result = 0;
//    for(int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << "\n";
    if(check(arr)){
        result++;
    }
    int siz = 1;
    for (int i = 2; i <= n; ++i){
        siz *= i;
    }
    for (int j = 1; j < siz; ++j){
        int gr = n - 1;
        for (int i = n - 1; i > 0; --i){
            if (arr[i - 1] < arr[i]){
                gr = i - 1;
                break;
            }
        }
        int minn = arr[gr+1];
        int ps = gr + 1;
        for (int i = n - 1; i > gr; --i){
            if (arr[i] < minn && arr[i] > arr[gr]){
                ps = i;
                break;
            }
        }
        swap(arr[gr], arr[ps]);
        for (int i = gr + 1, k = n - 1; i <= (n - (n - gr) / 2) - 1; ++i, --k){
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
//        for(int i = 0; i < n; i++)
//        {
//            cout << arr[i] << " ";
//        }
//        cout << "\n";
        if(check(arr)){
            result++;
        }
    }

    //result *= 2;
    cout << result;
}