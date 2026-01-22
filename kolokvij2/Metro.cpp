// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
 
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
 
    if (a[1] == 1 && a[s] == 1) {
        cout << "YES" << endl;
        return 0;
    }
 
    if (a[1] == 1) {
        for (int i = s; i <= n; i++) {
            if (a[i] == 1 && b[i] == 1 && b[s] == 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
 
    cout << "NO" << endl;
    return 0;
}
