/**
Determine the minimum cost to provide library access to all citizens of HackerLand. There are  cities numbered from  to . 
Currently there are no libraries and the cities are not connected. Bidirectional roads may be built between any city pair listed in . 
A citizen has access to a library if:

-Their city contains a library.
-They can travel by road from their city to a city containing a library.
*/
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+5;
short vis[MAXN];
int n;
vector<vector<int>> adj(MAXN);
int bfs(int ini){
    queue<int> cola;
    int ans = 0;
    cola.push(ini);
    while(!cola.empty()){
        int cur = cola.front();cola.pop();
        if(!vis[cur]){
            vis[cur] = 1;
            ans++;
            for(int son:adj[cur]){
                cola.push(son);
            }
        }
    }
    return ans;
}
void clean(){
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        adj[i].clear();
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> q;
    int m, c_lib, c_road;
    for(int j = 0; j < q; j++){
        cin >> n >> m >> c_lib >> c_road;
        clean();
        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int64_t cost = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                int aux = bfs(i);
                if(c_lib < c_road)
                    cost+=(aux*c_lib);
                else if(c_lib>c_road)
                    cost+=((aux-1)*c_road+c_lib);
                else
                    cost+=(aux*c_lib);
            }
        }
        cout << cost << '\n';
    }

    return 0;
}
