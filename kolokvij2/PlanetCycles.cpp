// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
int tele[MAXN];
int ans[MAXN];
bool visited[MAXN];

int dfs(int u, vector<int>& path) {
    if(ans[u] != 0) return ans[u]; // već izračunato
    if(visited[u]) {
        // pronađen ciklus
        int idx = find(path.begin(), path.end(), u) - path.begin();
        int cycle_len = path.size() - idx;
        for(int i=idx;i<path.size();i++){
            ans[path[i]] = cycle_len;
        }
        return cycle_len;
    }
    visited[u] = true;
    path.push_back(u);
    int res = 1 + dfs(tele[u], path);
    if(ans[u] == 0) ans[u] = res; // popuni za ove izvan ciklusa
    path.pop_back();
    visited[u] = false;
    return ans[u];
}

int main() {
    freopen("ulaz.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++) cin >> tele[i];

    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            vector<int> path;
            dfs(i,path);
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
