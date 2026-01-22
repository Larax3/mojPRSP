// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;

vector<string> grid;
vector<vector<int>> distM, distA;
vector<vector<pair<int,int>>> parent;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    grid.resize(n);

    for (int i = 0; i < n; i++) cin >> grid[i];

    distM.assign(n, vector<int>(m, INF));
    distA.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int,int>>(m, {-1, -1}));

    queue<pair<int,int>> q;
    pair<int,int> start;

    // 1. BFS od svih monstruma
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                q.push({i, j});
                distM[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && grid[nx][ny] != '#' && distM[nx][ny] == INF) {
                distM[nx][ny] = distM[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 2. BFS od A
    queue<pair<int,int>> qa;
    qa.push(start);
    distA[start.first][start.second] = 0;

    pair<int,int> end = {-1, -1};

    while (!qa.empty()) {
        auto [x, y] = qa.front(); qa.pop();

        // Ako smo na rubu
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            end = {x, y};
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (!inside(nx, ny)) continue;
            if (grid[nx][ny] == '#') continue;
            if (distA[x][y] + 1 >= distM[nx][ny]) continue;
            if (distA[nx][ny] != INF) continue;

            distA[nx][ny] = distA[x][y] + 1;
            parent[nx][ny] = {x, y};
            qa.push({nx, ny});
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    // 3. Rekonstrukcija puta
    string path;
    pair<int,int> cur = end;

    while (cur != start) {
        auto p = parent[cur.first][cur.second];
        for (int d = 0; d < 4; d++) {
            if (p.first + dx[d] == cur.first &&
                p.second + dy[d] == cur.second) {
                path.push_back(dir[d]);
            }
        }
        cur = p;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
