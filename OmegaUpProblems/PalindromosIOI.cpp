///LINK https://omegaup.com/arena/problem/IOI-2000---Palindromo/#problems
/// Problem about dynamic programming 
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5005;
int dp[MAXN][3];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string cad;
    cin >> n >> cad;
    int a = 0,b = 1,c = 2;
    for(int dist = 2; dist <= n; dist++){
        for(int i = 0; i + dist <= n; i++){
            if(cad[i] == cad[i + dist -1])
                dp[i][c] = dp[i+1][a];
            else
                dp[i][c] = 1 + min(dp[i+1][b], dp[i][b]);
        }
      	a++; b++; c++;
      	a%=3;
      	b%=3;
      	c%=3;
      
    }
    cout << dp[0][n%3] << '\n';
    return 0;
}
