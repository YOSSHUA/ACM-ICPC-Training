#include <bits/stdc++.h> /// O( V + E) 

using namespace std;

const int MAXN = 1000000;
struct node{
    vector<int> adjL; /// Adjacent list
    int beforeMe; /// How many nodes going to me
};

node graph[MAXN];
int n, edges;
/// Let's suppose that nodes are numbered from 1 to n

queue<int> index, result;

void init(){
    for(int i = 0; i <= n; i++)
        graph[i].beforeMe = 0;
}

int main()
{
    cin >> n; /// number of nodes
    init(); /// initializes with 0 each node

    cin  >> edges;  ///number of edges
    int a,b;
    for(int i = 1; i<= edges; i++){  /// Input a --> b
        cin  >> a  >> b;
        graph[a].adjL.push_back(b);
        graph[b].beforeMe+=1;
    }

    for(int i = 1; i<= n; i++)
        if(graph[i].beforeMe == 0) ///No body is going to node i
            index.push(i);

    while(!index.empty()){
        int curr = index.front();index.pop(); ///current node
        result.push(curr);
        for(int v:graph[curr].adjL){/// foreach of my sons
            graph[v].beforeMe--; /// Less current node
            if(graph[v].beforeMe == 0)
                index.push(v);
        }
    }
    if(result.size() == n){  /// DAG
        for(int i = 1; i <= n; i++){
            cout << result.front() << " ";
            result.pop();
        }
    }else{ /// This is not a DAG
        cout << "There was a cycle in the graph";
    }

    return 0;
}
