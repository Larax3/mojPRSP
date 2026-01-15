// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int num = 10005;
vector<pair<int,int>> graf[num];
bool visited[num];

int Prim(int n, int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    int total_cost = 0, posjeceno = 0;

    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();

        if(visited[node]) continue;
        visited[node] = true;
        total_cost += cost;
        posjeceno++;

        for(auto [nextcost, susjed] : graf[node]){
            if(!visited[susjed])
                pq.push({nextcost, susjed});
        }
    }

    return (posjeceno == n) ? total_cost : -1;
}

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int gradovi, ceste;
    cin >> gradovi >> ceste;

    for(int i = 0; i < ceste; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({c, b});
        graf[b].push_back({c, a});
    }

    memset(visited, false, sizeof(visited));

    int result = Prim(gradovi, 1); // n = gradovi, start = 1

    if(result == -1){
        cout << "NEMOGUCE\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}
