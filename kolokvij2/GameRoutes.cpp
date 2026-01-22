// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1e9+7;

vector<int> graf[MAXN];
vector<int> topo;
int indegree[MAXN];
int dp[MAXN];

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graf[a].push_back(b);
        indegree[b]++;
    }

    // topološki poredak (Kahn's algorithm)
    queue<int> q;
    for(int i=1;i<=n;i++) if(indegree[i]==0) q.push(i);

    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v: graf[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }

    dp[1] = 1; // start level

    for(int u : topo){
        for(int v: graf[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}
