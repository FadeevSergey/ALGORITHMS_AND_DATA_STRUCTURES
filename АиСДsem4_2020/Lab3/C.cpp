#include <iostream>

int main() {
    long long k1, n1, b1, k2, n2, b2;
    std::cin >> k1 >> n1 >> b1;
    std::cin >> k2 >> n2 >> b2;

    long long k3 = k1 - k2 - b2;
    long long n3 = n1 - n2 - k2;
    long long b3 = b1 - b2 - n2;

    if(n3 > k3) {std::swap(n3, k3);}
    if(b3 > k3) {std::swap(b3, k3);}

    std::cout << (k3 < 0 ? 0 : k3);
}