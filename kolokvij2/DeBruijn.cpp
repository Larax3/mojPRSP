// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vis;
string ans;

void dfs(int u, int k) {
    for(int i = 0; i < 2; i++){
        int v = ((u << 1) & ((1 << (k-1)) - 1)) | i;
        int code = (u << 1 | i);
        if(!vis[code]){
            vis[code] = 1;
            dfs(v, k);
            ans.push_back('0' + i);
        }
    }
}

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int total = 1 << n;
    vis.assign(1 << n, 0);
    dfs(0, n);
    reverse(ans.begin(), ans.end());
    ans += string(n-1, '0'); // dodaj početak za wrap-around
    cout << ans << "\n";
    return 0;
}
