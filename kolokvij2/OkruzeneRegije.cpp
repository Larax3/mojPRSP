// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> safe(n, vector<bool>(m, false));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int,int>> q;

    // Mark all 'O's on the border and connected to border as safe
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 'O' && !safe[i][j]){
                safe[i][j] = true;
                q.push({i,j});
                while(!q.empty()){
                    auto [x,y] = q.front(); q.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                            if(grid[nx][ny] == 'O' && !safe[nx][ny]){
                                safe[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }

    // Convert all non-safe 'O' to 'X'
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'O' && !safe[i][j]){
                grid[i][j] = 'X';
            }
        }
    }

    // Print the result
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j];
            if(j < m-1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
