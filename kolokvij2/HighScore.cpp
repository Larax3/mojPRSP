// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int a, b;
    long long w;
};

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x}); // negiramo težinu
        adj[a].push_back(b);
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // Bellman-Ford
    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.a] < INF && dist[e.a] + e.w < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
            }
        }
    }

    // Čvorovi koji su dio negativnog ciklusa
    vector<bool> bad(n + 1, false);

    for (auto &e : edges) {
        if (dist[e.a] < INF && dist[e.a] + e.w < dist[e.b]) {
            bad[e.b] = true;
        }
    }

    // BFS iz tih čvorova – može li se doći do n?
    queue<int> q;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (bad[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) {
            cout << -1 << "\n";
            return 0;
        }
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << -dist[n] << "\n";
    return 0;
}
