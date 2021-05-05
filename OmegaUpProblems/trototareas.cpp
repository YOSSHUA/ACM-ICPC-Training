/*
https://omegaup.com/arena/problem/trototareas/#problems
*/

#include <bits/stdc++.h>
using namespace std;
int n,s;
int p[505], t[505];
int dp[505][105];
int f(int pos, int puntos){
	
	if(puntos >= s)
		return 0;
	if(pos == n+1)
		return 500005;
		
	if(dp[pos][puntos] == -1){
		int izq = f(pos+1, puntos + p[pos]) + t[pos];
		int der = f(pos+1, puntos);
		dp[pos][puntos] = min(der, izq);
		
	}
	
	return dp[pos][puntos];
}
int main() {
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
		cin >> p[i] >> t[i];
		
	for(int i = 0; i <= 502; i++ ){
        for(int j = 0; j <= 102; j++){
            dp[i][j] = -1;
        }
    }
    cout<< f(0,0);
	// your code goes here
	return 0;
}
