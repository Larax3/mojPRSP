// alias gpp='g++ solution.cpp -o s && ./s'

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int parent[MAXN], sz[MAXN];

int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);
    parent[v] = u;
    sz[u] += sz[v];
}

int main() {
    freopen("ulaz.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }

    int components = n;
    int largest = 1;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);
        if(pa != pb){
            unite(a,b);
            components--;
            largest = max(largest, sz[find(a)]);
        }
        cout << components << " " << largest << "\n";
    }

    return 0;
}
