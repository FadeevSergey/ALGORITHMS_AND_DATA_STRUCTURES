#include <iostream>
#include <vector>

void gcd(long long, long long, long long&, long long&);
long long kto(std::vector<int> &, std::vector<int> &);

int main() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    std::vector<int> kof{a, b};
    std::vector<int> mod{n, m};

    std::cout << kto(kof, mod);
}

long long kto(std::vector<int> &a, std::vector<int> &p) {

    long long minX = 0, mul = 1;

    std::vector<std::vector<long long>> res(2, std::vector<long long>(2));
    std::vector<long long> temp(2);

    long long first, second;
    gcd(p[0], p[1], first, second);
    res[0][1] = (first + p[1]) % p[1]; // if p[1] < 0

    for (int i = 0; i < 2; ++i) {
        temp[i] = a[i];

        for (int j = 0; j < i; ++j) {
            temp[i] -= temp[j];
            temp[i] *= res[j][i];
            temp[i] = (temp[i] + p[i]) % p[i];

            if (temp[i] < 0) {
                temp[i] += p[i];
            }
        }

        minX += mul * temp[i];
        mul *= p[i];
    }
    return minX;
}

void gcd(long long a, long long b, long long &first, long long &second) {
    if (a == 0) {
        first = 0;
        second = 1;
        return;
    }

    long long newFirst = 0, newSecond = 0;

    gcd(b % a, a, newFirst, newSecond);

    first = newSecond - (b / a) * newFirst;
    second = newFirst;
}