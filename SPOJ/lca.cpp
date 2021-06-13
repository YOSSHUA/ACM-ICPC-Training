/// For q queries, get the lowest common ancestor (LCA) of a and b
/// https://www.spoj.com/problems/LCASQ/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
const int logN =  15;

vector<vector<int> > adj(MAXN);
int depth[MAXN];
int parents[MAXN][logN];
int t;
void dfs(int node, int parent){
    parents[node][0] = parent;
    for(int son: adj[node]){
        if(son!= parent){
            depth[son] = depth[node]+1;
            dfs(son, node);
        }
    }
}
int lca(int u, int v) {
    /// Keep the deepest value in u
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    /// Make them of the same height
    for (int i = logN - 1; i >= 0; i --) {
        if (depth[u] >= depth[v] + (1 << i)) {
            u = parents[u][i];
        }
    }
    /// If they are the same its because we are
    /// in the lca
    if (u == v) {
        return u;
    }
    /// If don't reach the son of the lca
    for (int i = logN - 1; i >= 0; i --) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    /// We are in the son of lca, then return its father.
    return parents[u][0];
}
void binaryLifting(){
    for (int i = 1; i < logN; i ++) {
        for (int j = 1; j <= t; j ++) {
            if (parents[j][i - 1] != 0) {
                parents[j][i] = parents[parents[j][i - 1]][i - 1];
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, n;
    cin >> t;
    for(int j = 0; j < t; j++){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a ;
            adj[a].push_back(j);
            adj[j].push_back(a);
        }
    }
    dfs(0, 0);
    binaryLifting();
    int q,c,d;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> c >>d;
        cout << lca(c,d) <<"\n";
    }
    return 0;
}
