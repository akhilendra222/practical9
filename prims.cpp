
#include <iostream>
using namespace std;

int main() {
    int n, a[10][10], v[10] = {0}, cost = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    v[0] = 1;

    for (int e = 0; e < n - 1; e++) {
        int min = 999, x = -1, y = -1;

        for (int i = 0; i < n; i++)
            if (v[i])
                for (int j = 0; j < n; j++)
                    if (!v[j] && a[i][j] && a[i][j] < min)
                        min = a[i][j], x = i, y = j;

        if (x == -1) return cout << "No MST", 0;

        cout << x << "-" << y << " : " << min << endl;
        v[y] = 1;
        cost += min;
    }

    cout << "Minimum Cost = " << cost;
}
