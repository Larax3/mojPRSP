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
        int k;
        cin >> k;
        int candy;
        int jedinice = 0, dvojke = 0;

        for (int i = 0; i < k; i++)
        {
            cin >> candy;

            if (candy == 1) jedinice++;
            else dvojke++;
        }
        if ((jedinice == 0 && dvojke % 2 == 0) || (jedinice % 2 == 0 && jedinice != 0)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
