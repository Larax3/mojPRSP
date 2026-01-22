// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int start, m;
    cin >> start >> m;

    vector<vector<long long>> a(m+1, vector<long long>(m+1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    vector<long long> dist(m+1, INF);
    vector<bool> used(m+1, false);

    dist[start] = 0;

    for(int i = 1; i <= m; i++){
        int v = -1;
        for(int j = 1; j <= m; j++){
            if(!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if(dist[v] == INF) break;
        used[v] = true;

        for(int u = 1; u <= m; u++){
            if(a[v][u] > 0) {
                dist[u] = min(dist[u], dist[v] + a[v][u]);
            }
        }
    }

    for(int i = 1; i <= m; i++){
        if(dist[i] == INF){
            cout << -1 << "\n";
            return 0;
        }
    }

    for(int i = 1; i <= m; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}
