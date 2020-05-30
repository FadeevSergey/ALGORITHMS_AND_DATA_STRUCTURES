#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 1'000'001;

void createSieve(vector<int>& sieve) {
    vector<int> prime;

    for (int i = 2; i < SIZE; i++) {
        if(sieve[i] == -1) {
            sieve[i] = i;
            prime.push_back(i);
        }
        for(int j : prime) {
            if(j > sieve[i] || i * j >= SIZE || j > sieve[i]) {
                break;
            }
            sieve[i * j] = j;
        }
    }
}

void printFact(vector<int>& sieve, int number) {
    while(number != 1) {
        cout << sieve[number] << " ";
        number /= sieve[number];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(SIZE, -1);
    createSieve(sieve);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int newNumber;
        cin >> newNumber;

        printFact(sieve, newNumber);
    }
}