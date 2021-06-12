#include <bits/stdc++.h>
/// https://www.spoj.com/problems/QTREE2/
/// El problema te pide dos tipos de query.
/// DIST A B - Costo de ir de A a B.
/// KTH A B K - Kth elemento en la ruta de A a B. Te aseguran que
///             el kth está en el tamaño de la ruta.
///             De lo contrario tendríamos que calcular la dist.
///             y ver si es posible.
using namespace std;
const int MAXN = 1e4+5;
const int logN =  15;
struct edge{
    int node, cost;
};
vector<vector<edge> > adj(MAXN);
int64_t cost[MAXN];
int depth[MAXN];
int parents[MAXN][logN];
int n;
void dfs(int node, int parent){
    parents[node][0] = parent;
    for(edge son: adj[node]){
        if(son.node != parent){
            cost[son.node] = cost[node] + son.cost;
            depth[son.node] = depth[node]+1;
            dfs(son.node, node);
        }
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = logN - 1; i >= 0; i --) {
        if (depth[u] >= depth[v] + (1 << i)) {
            u = parents[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = logN - 1; i >= 0; i --) {
        if (parents[u][i] != 0 && parents[u][i] != parents[v][i]) {
            u = parents[u][i];
            v = parents[v][i];
        }
    }
    return parents[u][0];
}
void binaryLifting(){
    for (int i = 1; i < logN; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (parents[j][i - 1] != 0) {
                parents[j][i] = parents[parents[j][i - 1]][i - 1];
            }
        }
    }
}
void clean(){
    for (int i = 0; i < logN; i ++)
        for (int j = 0; j <= n; j ++)
            parents[j][i] = 0;
    for(int i = 0; i <= n; i++){
        adj[i].clear();
        cost[i] = 0;
        depth[i] = 0;
    }
}
int getKth(int node, int kth){
    for(int i = logN-1; i >= 0; i--)
        if(kth&(1<<i))
            node = parents[node][i];
    return node;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,k, c;
    int t ;
    string aux;
    cin >> t;
    for(int j = 0; j < t; j++){
        cin >> n;
        clean();
        for(int i = 1; i <= n-1; i++){
            cin >> a >> b >> c;

            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        dfs(1, 1);
        binaryLifting();
        string type;
        while(cin >> type){
            if(type == "DONE")
                break;
            if(type == "DIST"){
                cin >> a >>b;
                cout << cost[a] + cost[b] - 2*cost[lca(a,b)]<< "\n";
            }else{
                cin >>a >> b >> k ;
                int lca_ = lca(a,b);
                int ans;
                if(depth[a]-depth[lca_] + 1 >= k){
                    /// Lado izquierdo
                    /// Sería el kth ancestro de a
                    /// Para ello le quitamos 1, pues el binary lifting comienza a partir de
                    /// de 2^0. Entonces, si k = 0 -> queremos a "a". Y por la forma
                    /// en que calculamos el kth ancestro, nunca se actualiza a.
                    ans = getKth(a, k-1);
                }else{
                    /// Lado derecho
                    /// Sería el kth ancestro de b.
                    /// k - (depth[a]-depth[lca_]+1) = kth elemento del lca a b.
                    /// Pero, nosotros queremos calcularlo como si fuera el kth de b al lca.
                    /// Entonces, calculamos lo que mide el camino de b al lca (depth[b] - depth[lca_])
                    /// y le restamos el kth del lca-b.
                    ans = getKth(b, depth[b]-depth[lca_]  - ( k - (depth[a]-depth[lca_]+1) ) );
                }
                cout << ans << "\n";
            }

        }
        cout << "\n";
    }
    return 0;
}
