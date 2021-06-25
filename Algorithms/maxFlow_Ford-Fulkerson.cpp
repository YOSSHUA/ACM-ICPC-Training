#include <bits/stdc++.h>
#define INF 1e5
using namespace std;
const int MAXN = 1e5+5;
map< pair<int, int>, int> edges;
set<int> visited;
int parent[MAXN];
int source, sink;
vector< vector<int> > adjL(MAXN);
/// Get minimum capacity in a path between source and sink
int getMinCapacity(){
    int cur = sink, prev;
    int ans = INF;
    while(cur != source){
        prev = parent[cur];
        ans = min(ans,  edges[make_pair(prev, cur)]);
        cur = prev;
    }
    return ans;
}
/// Get a route between source and sink if possible and then return the maximum possible
/// flow. Otherwise return 0;
int bfs(){
    int ans = 0;
    queue<int> q;
    q.push(source);
    visited.clear();
    visited.insert(source);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == sink){
            ans = getMinCapacity();
            break;
        }
        for(int son: adjL[cur]){
            /// I have visited son ------
            if(visited.find(son) != visited.end() || edges[make_pair(cur, son)]==0)
                continue;
            /// I haven't visited son and there is a capacity bigger than 0 ------

            /// Mark my parent to get route
            parent[son] = cur;
            visited.insert(son);
            q.push(son);
        }

    }
    return ans;
}
/// Get max flow in a network with Ford-Fulkerson algorithm
int getMaxFlow(){
    int maxFlow = 0;
    int flow = bfs();
    while(flow > 0 ){
        maxFlow += flow;
        int cur = sink, prev;
        while(cur != source){
            prev = parent[cur];

            /// I will quit use the flow from prev -> cur
            edges[make_pair(prev, cur)]-= flow;

            /// I will add the flow from cur -> prev
            edges[make_pair(cur,prev)]+= flow;

            cur = prev;
        }
        flow = bfs();
    }
    return maxFlow;
}
int main()
{
    int n, a, b, c;
    cin>> n >> source >> sink;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        adjL[a].push_back(b);
        adjL[b].push_back(a);
        /// Add flow from a to b
        /// If there is no path between b to a, we make it's flow 0.
        edges[make_pair(a,b)] = c;

        if(edges.find(make_pair(b,a)) == edges.end())
            edges[make_pair(b,a)] = 0;

    }
    cout << getMaxFlow();
    /**
    Input:
        N_edges , source, sink(biggest node)
        N-lines with three numbers: a, b, c
        There is a path from a -> b with flow c

    Input:
        10 0 5
        0 1 16
        0 2 13
        1 2 10
        2 1 4
        1 3 12
        3 2 9
        2 4 14
        4 3 7
        3 5 20
        4 5 4
    Maxflow = 23

    Input:
        6 0 4
        0 1 2
        0 2 3
        2 1 1
        1 4 3
        2 3 1
        3 4 3
    Max flow = 4

    Input:
        11 0 6
        0 1 3
        1 2 4
        2 0 3
        0 3 3
        2 3 1
        2 4 2
        3 4 2
        4 1 1
        3 5 6
        5 6 9
        4 6 1
    Max flow = 5


    */
    return 0;
}
