/*
https://omegaup.com/arena/problem/Tejidos/#problems
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2005;
int suma[MAXN][MAXN];
char mat[MAXN][MAXN];
int n;
int t;
bool valido(int r, int c){
    int i = 0;
    while( (c + i <= n)  && (suma[r][c+i] == i+1))
        i++;
    if(i+c == n+1 || (i == 1 && suma[r][c+i] < i+1))
        return false;
    if(suma[r][i+c] > (i+1))
        i++;
    int j = i-1;
    t = j*2+1;
    while(c+i <= n && suma[r][c+i] == j && j > 0){
        i++;
        j--;
    }
    return j == 0;

}
bool cerosOk(int r, int c){
    int m = t/2;
    for(int i =0; i < m; i++){
        for(int j = 0; j < m - i; j++){
            if(suma[r-m+i][c+j] != 0 || suma[r+m-i][c+j] != 0 || suma[r-m+i][c+t-1-j] != 0 ||  suma[r+m-i][c+t-1-j] != 0){
                return false;
            }
        }
    }
    return true;
}
bool good(int r, int c){
    int m = t/2;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= t-2*i; j++){
            if(suma[r+i][c+j + i - 1] != suma[r+i-1][c+j+i-1] + 1)
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
            if(i != 1){
                if(mat[i][j] == 'O')
                    suma[i][j] = suma[i-1][j]+1;
            }else{
                if(mat[i][j] == 'O')
                    suma[i][j] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(suma[i][j] == 1 && suma[i-1][j] == 0 && suma[i+1][j] == 0){
                if(valido(i,j)){
                    if(cerosOk(i,j)){
                        if(good(i,j)){
                            ans = max(ans, t);
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
