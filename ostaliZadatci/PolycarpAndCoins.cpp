// alias s='g++ -o ./solution solution.cpp && ./solution'
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main () {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int sum;
        cin >> sum;

        if (sum % 3 == 0) cout << sum / 3 << " " << sum / 3 << endl;
        else if (sum % 3 == 1) cout << (sum / 3) + 1 << " " << sum / 3 << endl;
        else if (sum % 3 == 2) cout << sum / 3 << " " << (sum / 3) + 1 << endl;
    }

    return 0;
}
