// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> graf[MAXN];
vector<int> topo;
int indegree[MAXN];
int n, m;
int dp[MAXN];      // dp[u] = maksimalan broj gradova do u
int parent[MAXN];  // roditelj za rekonstrukciju puta

void topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : graf[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }
}

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        indegree[b]++;
    }

    topological_sort();

    fill(dp, dp + MAXN, -1);
    dp[1] = 1;  // start from city 1

    for (int u : topo) {
        if (dp[u] == -1) continue;
        for (int v : graf[u]) {
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct path
    vector<int> path;
    int cur = n;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    cout << dp[n] << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << (i + 1 == path.size() ? "\n" : " ");
    }

    return 0;
}
