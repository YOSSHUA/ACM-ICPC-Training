#include <bits/stdc++.h>
/// Bellman-Ford is an algorithm to find shortest path from
/// origin to end in a graph with costs.
/// There's also Dijkstra, but it doesn't work with negative values, but B-F works with that.
/// B-F can't get minimum path if there is a negative cycle (the minimum path is always decreasing)
using namespace std;
const int MAXN = 1005;
const int MAXE= 449500; /// nCr(1000, 2)
struct edge{
    int a, b, w; /// a -> b with $w
};
int n, n_edges, origin; /// Nodes are numbered from 1 to n
int dist[MAXN];
edge edges[MAXE];
int parents[MAXN];
bool cycle;
void bellmanFord(){
    cycle = false;
    for(int i = 0; i <= n; i++)
        dist[i] = MAXE;

    dist[origin] = 0;
    parents[origin] = origin;

    for(int j = 1; j<= n; j++){
        for(int i = 1; i <= n_edges; i++){
            if(dist[edges[i].a] + edges[i].w < dist[edges[i].b]){ /// Less cost from a to b
                dist[edges[i].b] = dist[edges[i].a] + edges[i].w;
                parents[edges[i].b] = edges[i].a;
            }
        }
    }

    for(int i = 1; i <= n_edges; i++){
        if(dist[edges[i].a] + edges[i].w < dist[edges[i].b]){
            cycle =  true;
        }
    }

}
int main()
{
    cin  >> n >> n_edges;
    int x,y, weight;
    for(int i = 1; i <= n_edges; i++){
        cin >> x >> y >> weight; /// a-> b with $weight
        edges[i] = {x,y,weight};
    }
    cin  >> origin;
    bellmanFord();
    if(!cycle)
        for(int i = 1; i <= n; i++){
            cout <<"Cost from " << origin << " to " << i << " " << dist[i] << '\n';
        }
    else
        cout << "There is a negative cycle in the graph\n";
    return 0;
}
