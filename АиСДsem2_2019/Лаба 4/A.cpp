#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cobbler.in");
    ofstream fout("cobbler.out");
    int k;
    int m = 0;
    fin >> k >> m;
    int array[m];
    for (int i = 0; i < m; ++i) {
        fin >> array[i];
    }
    sort(array, array + m);
    int i;
    for (i = 0; k > 0; ++i) {
        k -= array[i];
    }
    if (k < 0) {
        i--;
    }
    fout << i;
    fin.close();
    fout.close();
    return 0;
}
