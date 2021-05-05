/*
https://omegaup.com/arena/problem/Chocolates-CIIC-2015/#problems
*/

#include <bits/stdc++.h>

using namespace std;
long long int pre[100000], m;
int n;
bool posible(int val){

    for(int i = 1; i <= n; i++){
        if((pre[i] / val)  < i ){
            return false;
        }
    }
    return true;
}
int binsearch(int ini, int fin){

int mitad = (ini+fin)/2 +1;

if(ini == fin) return ini;

if(posible(mitad)){
    return binsearch(mitad, fin);
}
else{
    return binsearch(ini, mitad-1);
}
}
int main(){
ios_base::sync_with_stdio(0);cin.tie(0);
m = 0;
cin >> n;

for(int i =1; i <= n; i++ ){
    cin >> pre[i];
    m=max(m, pre[i]);
    pre[i]+=pre[i-1];
}

cout << binsearch(0,m);
    return 0;
}
