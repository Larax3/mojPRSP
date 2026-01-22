// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Rekonstrukcija puta
    vector<int> path;
    for(int v = n; v != -1; v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(int x : path){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
