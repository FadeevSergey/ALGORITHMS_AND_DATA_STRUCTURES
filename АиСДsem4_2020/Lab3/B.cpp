//https://e-maxx.ru/algo/assignment_hungary

#include <iostream>
#include <vector>

using namespace std;

void init(int n, int *minv, bool *used) {
    for(int o = 0; o <= n; o++) {
        minv[o] = INT_MAX;
        used[o] = false;
    }
}

void changeMatching(int first, int *way, int *matching) {
    do {
        int j1 = way[first];
        matching[first] = matching[j1];
        first = j1;
    } while (first != 0);
}

void changeMinV(int n, int delta, bool *used, int *matching, int *minv, int *u, int *v) {
    for (int j = 0; j <= n; ++j) {
        if (used[j]) {
            u[matching[j]] += delta;
            v[j] -= delta;
        } else {
            minv[j] -= delta;
        }
    }
}

void minCost() {
    int n;
    cin >> n;

    int matrix[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    int u[n + 1];
    int v[n + 1];
    int matching[n + 1];
    int way[n + 1];

    for(int i = 0; i <= n; i++) { u[i] = 0;  v[i] = 0;  matching[i] = 0; way[i] = 0; }

    for (int i = 1; i <= n; i++) {
        matching[0] = i;
        int first = 0;
        int minv[n + 1];
        bool used[n + 1];

        init(n, minv, used);

        int second;

        do {
            used[first] = true;
            int firstI = matching[first];
            int delta = INT_MAX;
            second = 0;
            for (int j = 1; j <= n; j++) {
                if (!used[j]) {
                    int cur = matrix[firstI][j] - u[firstI] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = first;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        second = j;
                    }
                }
            }
            changeMinV(n, delta, used, matching, minv, u, v);
            first = second;
        } while (matching[first] != 0);

        changeMatching(first, way, matching);

    }

    int answer[n + 1];
    for (int i = 1; i <= n; i++) {
        answer[matching[i]] = i;
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += matrix[i][answer[i]];
    }

    cout << result << "\n";

    for (int i = 1; i <= n; i++) {
        cout << i << " " << answer[i] << "\n";
    }
}

int main() {
    minCost();
}