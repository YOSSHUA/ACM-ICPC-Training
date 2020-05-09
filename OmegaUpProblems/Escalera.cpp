/// link https://omegaup.com/arena/problem/escalera/#problems
#include <bits/stdc++.h>

using namespace std;
int i,k,T;
long long int M[10002];
long long int F( int T){
    if(T==0){
        return 1;
    }
    if(T<0){
        return 0;
    }
    if(M[T]== -1){
        long long int suma=0;
        for(int i=1; i<=k; i++){
            suma+= F(T-i);
        }
        M[T]= suma;
    }
    return M[T];
}

int main()
{

    cin >> T >> k;
    for(i=0;i<=T;i++){
        M[i]= -1;
    }
    cout << F(T);
    return 0;
}
