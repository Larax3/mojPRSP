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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> team(n+1, 0); // 0 = unassigned, 1 or 2 = team
    bool possible = true;

    for(int i = 1; i <= n; i++){
        if(team[i] == 0){
            team[i] = 1;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : adj[u]){
                    if(team[v] == 0){
                        team[v] = 3 - team[u]; // assign opposite team
                        q.push(v);
                    } else if(team[v] == team[u]){
                        possible = false;
                        break;
                    }
                }
                if(!possible) break;
            }
        }
        if(!possible) break;
    }

    if(!possible){
        cout << "NEMA\n";
    } else {
        for(int i = 1; i <= n; i++){
            cout << team[i] << (i == n ? "\n" : " ");
        }
    }

    return 0;
}
