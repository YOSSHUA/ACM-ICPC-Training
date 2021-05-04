/**
https://www.hackerrank.com/challenges/coin-change/problem
*/
#include <bits/stdc++.h>

using namespace std;
long long int DP[255][55], monedas[55];
long long int Busqueda(int valor_actual, int moneda){
    if(valor_actual<0){
        return 0LL;
    }
    if(valor_actual==0){
        return 1LL;
    }
    if(moneda==0){
        return 0LL;
    }
    if(DP[valor_actual][moneda]!=-1LL){
        return DP[valor_actual][moneda];
    }
    long long int sol = Busqueda(valor_actual-monedas[moneda],moneda)+Busqueda(valor_actual,moneda-1);
    DP[valor_actual][moneda]=sol;
    return sol;
}
int main()
{
    long long int valor, n_monedas;
    cin >> valor >> n_monedas;
    for(int i = 1; i <= n_monedas; i++){
        cin >> monedas[i];
    }
    for(int i = 0; i <= 250; i++){
        for(int j = 0; j<= 50; j++){
            DP[i][j]=-1LL;
        }
    }
    cout << Busqueda(valor, n_monedas) << '\n';
    return 0;
}
