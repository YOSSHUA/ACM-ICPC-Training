/// link https://omegaup.com/arena/problem/agresivos/#problems
#include <bits/stdc++.h>

using namespace std;
vector<long long int> cubiculos;
int N, P,mini;
bool posible(int distancia){
    int i=1,j=2, usados=1;
    while(j <= N){
        int dist = cubiculos[j] - cubiculos[i];
        if(dist < distancia){
            j++;
        }else{
            usados++;
            i=j;
        }
    }
    if(usados >= P){
        return true;
    }
    return false;
}
int binsearch(int ini, int fin){
    int mitad = (ini + fin)/2 + 1;
    if(ini==fin){
        return ini;
    }
    if(posible(mitad)){
        return binsearch(mitad, fin);
    }else{
        return binsearch(ini,mitad-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> P;
    cubiculos.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> cubiculos[i];
    }
    sort(cubiculos.begin() + 1, cubiculos.end());

    cout << binsearch(0,cubiculos[N]) << "\n";
    return 0;
}
