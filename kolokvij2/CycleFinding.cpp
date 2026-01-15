// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v;
    long long w;
};

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int x = -1;

    // Bellman-Ford
    for(int i = 0; i < n; i++){
        x = -1;
        for(auto e : edges){
            if(dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if(x == -1){
        cout << "NO\n";
    } else {
        // There is a negative cycle
        int y = x;
        for(int i = 0; i < n; i++) y = parent[y]; // move inside the cycle

        vector<int> cycle;
        int cur = y;
        do{
            cycle.push_back(cur);
            cur = parent[cur];
        }while(cur != y);
        cycle.push_back(y);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for(int i = 0; i < cycle.size(); i++){
            cout << cycle[i] << (i+1==cycle.size() ? "\n" : " ");
        }
    }

    return 0;
}
