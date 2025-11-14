// alias s='g++ -o ./solution solution.cpp && ./solution'
#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int main () {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    string izraz;
    cin >> izraz;

    string sorted;

    for (char c : izraz)
    {
        if (c != '+') sorted += c;
    }

    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i];
        if (i != sorted.size() - 1) cout << '+';
    }

    return 0;
}
