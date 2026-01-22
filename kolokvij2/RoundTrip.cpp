// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

int start_cycle = -1, end_cycle = -1;

bool dfs(int u, int p) {
    visited[u] = true;
    parent[u] = p;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (visited[v]) {
            start_cycle = v;
            end_cycle = u;
            return true;
        }

        if (!visited[v]) {
            if (dfs(v, u)) return true;
        }
    }
    return false;
}

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) break;
        }
    }

    if (start_cycle == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(start_cycle);

    for (int v = end_cycle; v != start_cycle; v = parent[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(start_cycle);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
    cout << "\n";

    return 0;
}
