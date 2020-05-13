#include <bits/stdc++.h>
///This algorithm works for directed graphs
/// It solves the problem of finding Strongly connected components
/// It is, that in a sub disjoint of nodes of the graph all nodes are connected
using namespace std;
const int MAXN = 10005;
struct node{
    vector<int>adjL; ///adjacent list
};

node graph[MAXN];
int n, edges;
int order[MAXN]; /// Node level
int lower[MAXN]; /// The least level that I can go up
bool visited[MAXN]; /// False if I haven't visited
bool inStack[MAXN]; /// True if it is in stack
stack<int> nodes;
vector<vector<int>> scc; /// strongly connected components
///Get strongly connected components with Tarjan's Algorithm
void getSCC(int v){
    nodes.push(v); /// add current node to stack
    inStack[v] = true;
    visited[v] = true;  /// to avoid cycles
    lower[v] = order[v];
    for(int u: graph[v].adjL){
        if(!visited[u]){
            order[u] = order[v] + 1;
            getSCC(u);
            lower[v] = min(lower[u], lower[v]); /// Probably one of my children found a path to go back
        }else if(inStack[u]){ /// I found an edge to u that was previously visited and it's in stack.
            lower[v] = min(lower[v], order[u]);
        }
    }
    if(order[v] == lower[v]){ /// I'm part of an SCC
        vector<int> aux;
        int u;
        do{
           u = nodes.top(); nodes.pop();
           inStack[u] = false;
           aux.push_back(u);
        }while(u != v);
        scc.push_back(aux);
    }
}
int main()
{
    cin >> n >> edges;
    int a,b;
    for(int i = 1; i<= edges; i++){
        cin  >> a >> b; /// a -> b
        graph[a].adjL.push_back(b);
    }
    for(int i = 1; i<= n; i++){
        if(!visited[i])
            getSCC(i);
    }
    for(int i = 0; i< scc.size(); i++){
        cout << "Component :" << (i +1) << '\n';
        for(int j = 0; j < scc[i].size(); j++)
            cout << scc[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
