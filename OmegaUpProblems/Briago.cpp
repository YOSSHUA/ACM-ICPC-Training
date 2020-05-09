#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005;
typedef int64_t ll;
ll m[MAXN][MAXN][2];
ll values[MAXN];
ll f(short i, short j, short last){
    if(i == j)
        return last? 0 : values[i];
    if(m[i][j][last] == -1){
        if(last){
            m[i][j][last] = min(f(i+1, j, 0), f(i, j-1, 0));
        }else{
            m[i][j][last] = max(values[i] + f(i+1, j, 1), values[j] + f(i, j-1, 1));
        }
    }
    return m[i][j][last];
}
void clean(int n){
    for(int i = 0; i <= n +1 ; i++){
        for(int j = 0; j <= n+1; j++){
            for(int k = 0; k <= 1; k++)
                m[i][j][k] = -1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll sum = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> values[i] ;
        sum += values[i];
    }
    clean(n);
    cout << sum - f(1,n,1) << '\n';

    return 0;
}
