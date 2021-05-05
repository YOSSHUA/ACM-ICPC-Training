#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int>T;
vector<pair<int,int> >amistades;
int main(){
    cin >> n >> m;
    amistades.resize(m+2);
    for(int i = 1; i<= m; i++){
        int a,b;
        cin>>a>>b;
        amistades[i].first = min(a,b)+1;
        amistades[i].second = max(a,b)+1;
    }
    T.resize(n+2);
    sort(amistades.begin()+1, amistades.begin()+1+m);
    for(int i = 1; i <= n; i++){
        T[i]=i-1;
    }
    for(int i = m; i>=1; i--){
        if(T[amistades[i].second]==amistades[i].first){
            T[amistades[i].second]=amistades[i].first-1;
        }
    }
    int ini=1, fin=1,distance=0;
    while(ini<=fin and fin<=n){
        if(T[fin] < ini){
            distance=max(distance,(fin-ini)+1);
            fin++;
        }else{
            ini=T[fin]+1;
        }
    }
    cout << distance << '\n';
    return 0;
}
