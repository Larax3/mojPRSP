// alias s='g++ -o ./solution solution.cpp && ./solution'
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main () {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w;
    cin >> w;

    if (w % 2 == 0 && w > 2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
