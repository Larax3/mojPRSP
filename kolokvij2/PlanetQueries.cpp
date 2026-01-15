// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30;

int n, q;
int parent[MAXN];  // Store only direct parents
int up[LOG][MAXN]; // Binary lifting table

int jump(int a, long long d) {
    for(int i = 0; i < LOG; i++) {
        if(d & (1LL << i)) {
            a = up[i][a];
        }
    }
    return a;
}

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> parent[i];  // Read direct parent
        up[0][i] = parent[i];
    }

    for(int j = 1; j < LOG; j++) {
        for(int i = 1; i <= n; i++) {
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }

    while(q--) {
        int a;
        long long d;
        cin >> a >> d;
        cout << jump(a, d) << '\n';
    }

    return 0;
}
