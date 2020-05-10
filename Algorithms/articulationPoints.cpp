#include <bits/stdc++.h>
/// This algorithm get all articulation points in a undirected graph.
/// An articulation point is such that if you remove it from the graph, its sons lost the connection with the entire graph.
/// It is, there isn't other way to go up from sons without the removed node.
using namespace std;
const int MAXN = 10005;
struct node{
    vector<int>adjL; ///adjacent list
    int parent;
};

node graph[MAXN];  /// Nodes are numbered from 1 to n
int n, edges;
bool artPoint[MAXN];
int order[MAXN]; /// Node level
int lower[MAXN]; /// The least level that I can go up
bool visited[MAXN]; /// False if I haven't visited
/// One node can be art point if 1)Is root and has at least 2 sons 2) It's not root but some of its sons cannot go up V
void getArtPoints(int v, bool isRoot){
    int children = 0;
    visited[v] = true;

    for(int u:graph[v].adjL){
        if(!visited[u]){ ///I haven't been visited
            order[u] = order[v] + 1; /// U is one level more than its father
            lower[u] = order[v] + 1; /// for now the least level that I can go up its my order
            children+=1;
            graph[u].parent = v;
            getArtPoints(u,false);

            if(!isRoot && lower[u] >= order[v]) /// U can't go up without V then V is an art point. Condition 2)
                artPoint[v] = true;

            lower[v] = min(lower[u], lower[v]);  /// V is up to U then if U can go up V, then V can go up itself

        }else if(graph[v].parent != u){ ///if u is not my parent then there is a cycle and I can go up V without V
            lower[v] = min(lower[v], order[u]); /// then the most that I can go up is the min between last and level of U
        }
    }
    if(isRoot && children > 1) ///Condition 1)
        artPoint[v] = true;
}
int main()
{
    int a,b;
    cin >> n >> edges;
    for(int i = 1; i<= edges; i++){
        cin >> a >> b;
        graph[a].adjL.push_back(b);
        graph[b].adjL.push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            getArtPoints(i,true);
    }
    for(int i = 1; i <= n; i++)
        if(artPoint[i])
            cout << i << " ";

    return 0;
}
