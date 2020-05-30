#include <iostream>
#include <vector>

const int SIZE = 20'000'001;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::vector<bool> sieve(SIZE + 1, true);

    for(int i = 2; i <= SIZE; i++) {
        if(sieve[i]) {
            if(i * i <= SIZE) {
                for(int j = i * i; j <= SIZE; j += i) {
                    sieve[j] = false;
                }
            } else {
                break;
            }
        }
    }

    int n;
    std::cin >> n;
    int newNumber;

    for(int i = 0; i < n; i++) {
        std::cin >> newNumber;
        if(sieve[newNumber]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}