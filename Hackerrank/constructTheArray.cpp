/*
https://www.hackerrank.com/challenges/construct-the-array/problem
*/
#include <bits/stdc++.h>

using namespace std;
typedef int64_t ll;
const int MOD = 1e9 + 7;
const int MAXN = 100005;

ll dp[MAXN][2];


int main()
{
    int n, k ,x;
    cin >> n >> k >> x;
    /**
        En dp[i][0] voy a guardar los arreglos que empiezan con uno
        y en dp[i][1] voy a guardar los que no empiezan con 1
    */
    dp[1][0] = 1;
    /// por default el primer valor es 1, entonces tengo un arreglo que empieza con uno
    for(int i = 2; i < n; i++){
        /// los arreglos que ahora van a tener uno
        /// por cada uno de los que no eran uno antes voy a poder poner k-1 (k menos yo mismo) y por regla de la iltiplicacion se sigue
        dp[i][0] = (dp[i-1][1]*(k-1))%MOD;
        /// los arreglos que ahora van a tener algo distinto de 1
        /// Seran los que ya tenan uno + los de antes que no tenan uno
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]*(k-2))%MOD;
        /// Como no puede ser uno porque ya los cont ni l mismo porque tienen que ser
        /// consecutivos diferentes entonces es *(k-2)
    }
    ///finalmente el resultado depende de si puedo poner 1 o no al ltimo
    if(x == 1){ /// SI quiero 1 al final
        dp[n][0] = (dp[n-1][1]*(k-1))%MOD;
        cout << dp[n][0] << '\n';
    }else{ /// NO quiero 1 al final
        dp[n][1] = (dp[n-1][0] + dp[n-1][1]*(k-2))%MOD;
        cout << dp[n][1] << '\n';
    }

    return 0;
}
