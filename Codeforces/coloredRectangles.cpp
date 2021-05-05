
/**
https://codeforces.com/contest/1398/problem/D
*/
#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 205;
typedef int64_t ll;
ll m[MAXN][MAXN][MAXN];
int vr[MAXN], vg[MAXN],vb[MAXN];
ll dp(int i, int j, int k){
    if((i == 0 && j == 0) or (i == 0 && j == 0) or (k == 0 && j == 0))
        return 0;
    if(m[i][j][k] == -1){
        if(i == 0){
            m[i][j][k] = vg[j]*vb[k] + dp(i,j-1,k-1);
        }else if(j == 0){
            m[i][j][k] = vr[i]*vb[k] + dp(i-1,j,k-1);
        }else if(k ==0){
            m[i][j][k] = vg[j]*vr[i] + dp(i-1,j-1,k);
        }else{
            m[i][j][k] = max(vg[j]*vb[k] + dp(i,j-1,k-1), max(vr[i]*vb[k] + dp(i-1,j,k-1), vg[j]*vr[i] + dp(i-1,j-1,k)));
        }
    }
    return m[i][j][k];
}
void clean(){
    for(int i = 0; i < 202; i++)
        for(int j = 0; j < 202; j++)
            for(int k = 0; k < 202; k++)
                m[i][j][k] = -1;
}
int main()
{
 
    int t;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,g,b;
    cin >> r >> g >> b;
    for(int i = 1; i <= r; i++)
        cin >> vr[i];
    for(int i = 1; i <= g; i++)
        cin >> vg[i];
    for(int i = 1; i <= b; i++)
        cin >> vb[i];
    sort(vr+1, vr+r+1);
    sort(vg+1, vg+g+1);
    sort(vb+1, vb+b+1);
    clean();
    cout << dp(r,g,b) << '\n';
 
 
    return 0;
}
