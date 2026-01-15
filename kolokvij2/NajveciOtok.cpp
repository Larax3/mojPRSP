// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int max_area = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                int area = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;

                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();
                    area++;

                    for(int d = 0; d < 4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];

                        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                            if(!visited[nx][ny] && grid[nx][ny] == 1){
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }

                max_area = max(max_area, area);
            }
        }
    }

    cout << max_area << "\n";
    return 0;
}
