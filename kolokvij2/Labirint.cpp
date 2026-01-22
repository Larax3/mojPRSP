// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[1005][1005];
pair<int,int> parent[1005][1005];
char move_dir[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n);

    int sx, sy, ex, ey;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                sx = i; sy = j;
            }
            if(grid[i][j] == 'B'){
                ex = i; ey = j;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!visited[nx][ny] && grid[nx][ny] != '#'){
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    move_dir[nx][ny] = dir[d];
                    q.push({nx, ny});
                }
            }
        }
    }

    if(!visited[ex][ey]){
        cout << "NO\n";
        return 0;
    }

    // Rekonstrukcija puta
    string path;
    int x = ex, y = ey;
    while(x != sx || y != sy){
        char c = move_dir[x][y];
        path.push_back(c);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
