#include <iostream>
#include <vector>

int divider(int);
void gcd(long long, long long, long long &, long long &);
long long pow(long long, long long, long long);

int main() {
    int n, e, C;
    std::cin >> n >> e >> C;

    int div = divider(n);
    long long fi = (div - 1) * (n / div - 1);
    long long first, second;
    gcd(e, fi, first, second);
    long long d = (first + fi) % fi;


    std::cout << pow(C, d, n);
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

int divider(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    throw -1;
}

long long mul(long long a, long long n, long long mod) {
    long long result = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result + a) % mod;
        }
        a = (a + a) % mod;
        n /= 2;
    }
    return result;
}

long long pow(long long a, long long n, long long mod) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = mul(result, a, mod);
        }
        a = mul(a, a, mod);
        n /= 2;
    }
    return result;
}