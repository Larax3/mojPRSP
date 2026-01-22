// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,ll>>> graf(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
    }

    vector<vector<ll>> dist(n + 1);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dist[u].size() >= k) continue;

        dist[u].push_back(d);

        for (auto [v, w] : graf[u]) {
            if (dist[v].size() < k) {
                pq.push({d + w, v});
            }
        }
    }

    sort(dist[n].begin(), dist[n].end());

    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << (i + 1 == k ? "\n" : " ");
    }

    return 0;
}
