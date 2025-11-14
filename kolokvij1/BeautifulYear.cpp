// alias s='g++ -o ./solution solution.cpp && ./solution'
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main () {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int godina;
    cin >> godina;

    while (true)
    {
        godina++;
        string y = to_string(godina);
        if (y[0] != y[1] && y[0] != y[2] && y[0] != y[3] && y[1] != y[2] && y[1] != y[3] && y[2] != y[3]) break;
    }
    cout << godina << endl;

    return 0;
}
