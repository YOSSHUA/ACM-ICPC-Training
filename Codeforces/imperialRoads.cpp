/// Problem I of  2017-2018 ACM-ICPC Latin American Regional 
/// Problem of LCA, MST and sparse table
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
const int logN =  18;
/// For adjacent list
struct edge{
    int node, cost;
};
/// For MST with kruskal
struct edgeIn{
    int a, b, cost;
    const bool operator<(const edgeIn &otro)const{
        return cost < otro.cost;
    }
};

vector<edgeIn> edges; /// Kruskal
vector< vector<edge> > adj(MAXN); /// For the tree of MST
int depth[MAXN];
int64_t cost[MAXN];
int parents[MAXN][logN]; /// Sparse table where parents[i][j] is the 2^j ancestor of i
int maxEdge[MAXN][logN]; /// Sparse table where maxEdge[i][j] represents the max ancestor of i until 2^j
int father[MAXN];  /// For union find algorithm
int n;
int64_t MST = 0;
map< pair<int,int> , int > bucket;
/// Pre processing for LCA
void dfs(int node, int parent){
    parents[node][0] = parent;
    for(edge son: adj[node]){
        if(son.node!= parent){
            depth[son.node] = depth[node]+1;
            maxEdge[son.node][0] = son.cost;
            cost[son.node] = cost[node] + son.cost;
            dfs(son.node, node);
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
        if ( parents[u][i] != 0  && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    /// We are in the son of lca, then return its father.
    return parents[u][0];
}
void binaryLifting(){
    for (int i = 1; i < logN; i ++) {
        for (int j = 1; j <= n; j ++) {
            parents[j][i] = parents[parents[j][i - 1]][i - 1];
            maxEdge[j][i] = max(maxEdge[ parents[j][i-1] ][i-1], maxEdge[j][i-1]);
        }
    }
}
/// Kruskal
void init(){
    for(int i = 0; i <= n+1; i++){
        father[i] = i;
    }
}
int findComp(int u){
    if(u == father[u])
        return u;
    return father[u] = findComp(father[u]);
}
void join(edgeIn a){
    int ra = findComp(a.a), rb = findComp(a.b);
    if(ra != rb){
        MST+= a.cost;
        adj[a.a].push_back({a.b, a.cost});
        adj[a.b].push_back({a.a, a.cost});
        father[rb] = ra;
    }
}

/// Get the edge with maximum cost between a and b in the MST
int getMax(int a, int b){
    int ans = 0;
    int lca_= lca(a,b);
    int k = depth[a]- depth[lca_];
    for(int i = logN-1; i>=0; i--){
        if(k &(1<<i)){
            ans = max(maxEdge[a][i], ans);
            a = parents[a][i];
        }
    }
    k = depth[b]-depth[lca_];
    for(int i = logN-1; i>=0; i--){
        if(k &(1<<i)){
            ans = max(maxEdge[b][i], ans);
            b = parents[b][i];
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b, r;
    cin >> n >> r;
    edgeIn aux;
    edges.resize(r);
    for(int j = 0; j < r; j++){
        cin >> aux.a >> aux.b >> aux.cost;
        edges[j] = aux;
        bucket[aux.a < aux.b ? make_pair(aux.a, aux.b):make_pair(aux.b, aux.a) ] = aux.cost;
    }
    /// Kruskal
    init();
    sort(edges.begin(), edges.end());
    for(int i = 0; i < r; i++){
        join(edges[i]);
    }
    /// LCA and sparse table of max cost in paths
    dfs(1, 1);
    binaryLifting();
    /// Queries
    int q;
    cin >> q;
    for(int i =0; i< q; i++){
        cin >> a >> b;
        int c = bucket[a < b ? make_pair(a, b):make_pair(b, a) ];
        int64_t ans;
        ans = MST + c - getMax(a,b);
        cout << ans << "\n";
    }
    /*for (int j = 1; j <= n; j ++) {
        for (int i = 1; i < logN; i ++){
            cout << maxEdge[j][i] << " ";
        }
        cout <<"\n";
    }*/
    return 0;
}
