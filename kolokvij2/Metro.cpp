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
    for (int i = 1; i <= n; i++) cin >> a[i]; // track 1 open
    for (int i = 1; i <= n; i++) cin >> b[i]; // track 2 open

    if(a[1] == 0) { // Bob ne može ući u vlak
        cout << "NO\n";
        return 0;
    }

    if(a[s] == 1) { // Direktno do Alice
        cout << "YES\n";
        return 0;
    }

    // Provjera preko preokrenutog track-a
    bool can = false;
    for(int i = s + 1; i <= n; i++) {
        if(a[i] == 1 && b[i] == 1 && b[s] == 1) {
            can = true;
            break;
        }
    }

    cout << (can ? "YES" : "NO") << "\n";
    return 0;
}
