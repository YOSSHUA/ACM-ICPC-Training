#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;
struct edificio{
    long altura, comidos;
};
stack<edificio> porComer;

int comidos(int altura){
    int come =0;
    while(!porComer.empty() && porComer.top().altura >= altura){
        come+=porComer.top().comidos+1;
        porComer.pop();
    }
    porComer.push({altura,come});
    return come;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >>n;

    vector<long> alturas(n);
    vector<long> comidosIzq(n);
    for(int i = 0; i < n; i++){
        cin >> alturas[i];
        /// calculamos lo que me puedo comer a la izquierda
        comidosIzq[i] = comidos(alturas[i]);
    }
    ///limpio  la pila
    porComer =stack<edificio>();
    /// calculamos lo que me puedo comer a la derecha
    long ans = 0;
    for(int i = n-1; i >= 0 ; i--){
        /// Soy yo mismo más los que me comí a la izquierda más los que me haya podido comer a la derecha
        ans = max( ans, (1+comidosIzq[i] +comidos(alturas[i]))*alturas[i]);
    }
    cout << ans << '\n';
    return 0;
}
