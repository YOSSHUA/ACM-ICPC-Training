/**
https://codeforces.com/contest/600/problem/E
Problem related to DSU


You are given a rooted tree with root in vertex 1. Each vertex is coloured in some colour.

Let's call colour c dominating in the subtree of vertex v if there are no other colours that appear in the subtree of vertex v more times than colour c. 
So it's possible that two or more colours will be dominating in the subtree of some vertex.

For each vertex v find the sum of all dominating colours in the subtree of vertex v.
*/
#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 1e5+5;
vector<vector<int>> adj(MAXN);
int col[MAXN];
int maxT[MAXN];
long long sum[MAXN];
map<int,int> * cont[MAXN];
void dfs(int v, int p){
 
    int biggerSon  = -1;
    int biggerSize = -1;
    for(int u: adj[v]){
        if(u != p){
            dfs(u, v);
            int t = (*cont[u]).size();
            if(t > biggerSize)
                biggerSize = (*cont[u]).size(), biggerSon = u;
        }
    }
    if(biggerSon == -1)
        cont[v] = new map<int,int>(), maxT[v] = 0, sum[v] = 0;
    else
        cont[v] = cont[biggerSon], maxT[v] =maxT[biggerSon], sum[v]=sum[biggerSon];
    (*cont[v])[col[v]]++;
    if((*cont[v])[col[v]] == maxT[v])
        sum[v] += (long long)col[v];
    else if((*cont[v])[col[v]] > maxT[v])
        sum[v] = (long long)col[v], maxT[v] = (*cont[v])[col[v]];
 
    for(int u:adj[v]){
        if(u != p && u != biggerSon){
            for(auto it: *cont[u]){
                (*cont[v])[it.first] +=it.second;
                if((*cont[v])[it.first] == maxT[v])
                    sum[v]+=(long long)it.first;
                else if((*cont[v])[it.first] > maxT[v])
                    sum[v] =(long long) it.first, maxT[v] = (*cont[v])[it.first];
            }
        }
    }
 
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> col[i];
    }
    for(int i = 1; i <= n-1; i++){
        int a ,b;
        cin >>  a  >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    for(int i = 1; i <= n; i++)
        cout << sum[i] << " ";
    return 0;
}
