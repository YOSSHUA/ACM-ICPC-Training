/*
https://www.hackerrank.com/challenges/sherlock-and-cost/problem
*/
#include <bits/stdc++.h>
#define fori(i, ini, fin) for(i = ini; i < fin; i++)
#define for0(i, fin) fori(i,0,fin)
using namespace std;
const int MAXN = 100005;

int dp[MAXN][2];
int b[MAXN];
int main()
{
    /**
       Dado b = [ b1, ..., bn] queremos buscar un arreglo a = [a1, ..., an]  tal que a[i] <= b[i] y que
       S = sum (  abs( a[i] - a[i-1] ) ) de i = 2 a i = n sea MAXIMA.
       Entonces, notamos que los valores mximo se alcanzan con abs(a[i] - 1) o con abs(a[i] - a[i-1]).
       Porque si a[i] >= a[i-1] ->  maximo esta en a[i] - 1
       y si   a[i] < a[i-1] ->  el maximo esta en a[i] - 1  o abs(a[i] - a[i-1])
       entonces,  a[i-1] = b[i-1] o a[i-1] = 1.
       vease caso  b = [1, 3, 4, 1]
       entonces haremos dp[n][2]
       En dp[i][0] se guardara cuando a[i] = 1.
       asi tenemos que para abs(a[i] - a[i-1]) = abs(1 - a[i-1])
       hay dos posibilidades -> abs(1 - 1) (por a[i-1] = 1) o abs(1 - a[i-1])

       y en dp[i][1] se guardara cuando a[i] = a[i]
       asi tenemos que para abs(a[i] - a[i-1])
       hay dos posibilidades -> abs(a[i] - 1) (por a[i-1] = 1) o abs(a[i] - a[i-1])
    */

    int t,i, n, j;
    cin >> t;
    for0(i,t){
        cin >> n;
        for0(j,n){
            cin >> b[j];
        }
        dp[0][0] = dp[0][1] = 0;
        for0(j,n-1){
            /// if a[i+1] = 1 then  abs(a[i+1] - a[i]) = abs(1 - a[i])
            ///-> abs(1 - 1)  or  abs(1 - b[i])
            dp[j+1][0] = max(dp[j][0] + abs(1-1),  dp[j][1] + abs(1 - b[j]));
            /// if a[i+1] = b[i+1] then we have abs(a[i+1] - a[i])
            ///-> abs(b[i+1] - 1)  or  abs(b[i+1] - b[i])
            dp[j+1][1] = max(dp[j][0] +  abs(b[j+1] - 1), dp[j][1] + abs(b[j+1] - b[j]));

        }
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';

    }

    return 0;
}
