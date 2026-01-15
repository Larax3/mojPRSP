// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n+1, false);
    vector<int> reps; // representative nodes of each component

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            reps.push_back(i);
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : adj[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    int k = reps.size() - 1;
    cout << k << "\n";
    for(int i = 1; i < reps.size(); i++){
        cout << reps[i-1] << " " << reps[i] << "\n";
    }

    return 0;
}
