#include <bits/stdc++.h>

using namespace std;
long long int mod = 1000000007;
int m[2][1000005], n;
int dp(int b, int i, int bi){
if(i == n){
if (b && bi )return 0;
return 1;
}
if( b == 0 ){
if(m[b][i] != 0){
 return m[b][i];
}
if(b == 0 && i ==0){
m[b][i] = (dp(0,i+1,1)%mod+ dp(1,i+1,1)%mod+ dp(1,i+1,0)%mod)%mod;
}else{
m[b][i] = (dp(0,i+1,bi)%mod+ dp(1,i+1,bi)%mod)%mod;
}
}
if(b){
if(m[b][i] != 0){
return m[b][i];
}
m[b][i] = dp(0, i+1,bi)%mod;
}
return m[b][i]%mod;
}

int main(){
cin >>n;
cout << dp(0,0,0);
return 0;
}
