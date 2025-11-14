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
    long int a, b;

    while (t--)
    {
        cin >> a >> b;

        long int razlika = abs(a - b);

        cout << (razlika + 9) / 10 << endl;
    }

    return 0;
}
