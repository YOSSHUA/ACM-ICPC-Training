/*
https://www.juezguapa.com/problemas/enunciado/fabricating-sculptures
*/

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef int64_t ll;
const int MAXN = 5003;

ll m[MAXN][MAXN], acumF[MAXN][MAXN], acumFi[MAXN][MAXN];

ll sumF(int n, int b);
ll sumFi(int n, int b);
ll f(int n, int b);

ll sumF(int n, int b){
    if(acumF[n][b] == -1){
        acumF[n][b] = f(n-b, b);
        if(b > 1)
            acumF[n][b] = (acumF[n][b] +  sumF(n, b-1)%MOD)%MOD;
    }
    return acumF[n][b];
}
ll sumFi(int n, int b){
    if(acumFi[n][b] == -1){
        acumFi[n][b] = (b*f(n-b, b))%MOD;
        if(b > 1)
            acumFi[n][b] = acumFi[n][b] +  sumFi(n, b-1)%MOD;
    }
    return acumFi[n][b];
}
ll f(int n, int b){
    if(m[n][b] == -1){

        int a = min(n,b);
        m[n][b] = ((b+1)*sumF(n,a)%MOD) - sumFi(n,a);
        if(m[n][b] <0)
            m[n][b] += MOD;

    }
    return m[n][b];
}

int main()
{
    int b,s;
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i = 1; i < MAXN; i++){
        m[0][i] = 1;
        memset(m[i], -1, sizeof m[i]);
        memset(acumF[i], -1, sizeof acumF[i]);
        memset(acumFi[i], -1, sizeof acumFi[i]);
    }
    cin >> s >> b;
    cout << f(b-s, s) << '\n';

    return 0;
}
