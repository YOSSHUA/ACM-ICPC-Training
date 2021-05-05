/*

https://omegaup.com/arena/problem/cuentas/#problems
*/
#include <bits/stdc++.h>
#define optimiza ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
vector <int> cuentas;

int main()
{
    optimiza
    int n, val, mini = 100000;
    cin >> val;
    cin >> n;
    cuentas.resize(n*2);
    for(int indice = 1; indice <= n ; indice++){
        cin >> cuentas[indice];
        cuentas[n+indice] = cuentas[indice];
    }
    for( int  ini = 1; ini <= n ;){

        if(cuentas[ini]) ini++;

        if(!cuentas[ini]){

            int negras = 0, perdidas = 0;
            for(int j  = ini; negras <= val ; j++){

                if(cuentas[j])perdidas++;

                if(!cuentas[j]) negras++;

                if(negras == val){
                    mini = min(mini,perdidas);
                    ini++;
                }
            }
        }
    }
    cout << mini <<'\n';
    return 0;
}
