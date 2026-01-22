// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ulaz.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> f(n+1);
    for(int i=1;i<=n;i++) cin >> f[i];

    for(int i=1;i<=n;i++){
        int a = i;
        int b = f[a];
        int c = f[b];
        if(f[c] == a && a != b && b != c && a != c){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
