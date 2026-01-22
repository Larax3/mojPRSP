// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> graf[MAXN];
vector<int> parent(MAXN, -1);
vector<int> color(MAXN, 0); // 0 = bijelo, 1 = sivo, 2 = crno
vector<int> ciklus;

bool dfs(int u) {
    color[u] = 1; // sivo
    for (int v : graf[u]) {
        if (color[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (color[v] == 1) {
            // Našli smo ciklus
            int cur = u;
            ciklus.push_back(v);
            while (cur != v) {
                ciklus.push_back(cur);
                cur = parent[cur];
            }
            ciklus.push_back(v);
            reverse(ciklus.begin(), ciklus.end());
            return true;
        }
    }
    color[u] = 2; // crno
    return false;
}

int main() {
    freopen("ulaz.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0 && dfs(i)) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ciklus.size() << "\n";
        for (int i = 0; i < ciklus.size(); i++) {
            cout << ciklus[i] << (i + 1 == ciklus.size() ? "\n" : " ");
        }
    }

    return 0;
}
