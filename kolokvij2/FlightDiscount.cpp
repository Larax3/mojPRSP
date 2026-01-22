// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
    }

    // dist[u][0] = kupon nije iskorišten
    // dist[u][1] = kupon iskorišten
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));

    priority_queue<
        pair<ll, pair<int,int>>,
        vector<pair<ll, pair<int,int>>>,
        greater<>
    > pq;

    dist[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        auto [d, state] = pq.top(); pq.pop();
        int u = state.first;
        int used = state.second;

        if (d > dist[u][used]) continue;

        for (auto [v, w] : graf[u]) {
            // bez korištenja kupona
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], {v, used}});
            }

            // iskoristi kupon (ako još nije)
            if (used == 0) {
                ll nw = d + w / 2;
                if (dist[v][1] > nw) {
                    dist[v][1] = nw;
                    pq.push({nw, {v, 1}});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";
    return 0;
}
