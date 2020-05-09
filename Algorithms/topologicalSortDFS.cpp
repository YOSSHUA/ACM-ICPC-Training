#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000;
struct node{
    vector<int> adjL; /// Adjacent list
};

node graph[MAXN];
bool visited[MAXN];
int n, edges;
///Let's suppose nodes are numbered from 1 to n

stack<int> result;
void topologicalTravel(int v){
    visited[v] = true;
    for(int u: graph[v].adjL){
        if(!visited[u]) ///I haven't visit node u
            topologicalTravel(u);
    }
    result.push(v); /// I have visited all adjacent nodes
}
vector<int> topologicalSort(){
    vector<int> ans;
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            topologicalTravel(i);
        }
    }
    for(int i = 1; i<= n; i++){
        ans.push_back(result.top());
        result.pop();
    }
    return ans;
}

int main()
{
    cin >> n; /// number of nodes
    cin  >> edges; ///number of edges
    int a,b;
    for(int i = 1; i<= edges; i++){  /// Input a --> b
        cin  >> a  >> b;
        graph[a].adjL.push_back(b);
    }
    vector<int>topSort = topologicalSort();
    for(int i = 0; i < n; i++)
        cout << topSort[i] << " ";
    return 0;
}
