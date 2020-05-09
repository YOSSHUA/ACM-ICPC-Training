/// link https://omegaup.com/arena/problem/mirBacterias/#problems
/// problem about dynammic programming
#include <bits/stdc++.h>

using namespace std;
int A[102][102],m[102][102],M,n;
int busqueda(int  i, int j){
    if(i==M && j==n){
        return A[i][j];
    }
    if(i>M || j>n){
        return INT_MAX;
    }
    if(m[i][j]==-1){
        m[i][j]=min(busqueda(i+1,j),busqueda(i,j+1))+A[i][j];
    }
    return m[i][j];
}
int main()
{
    cin >>M >>n;

    for(int i=1; i<=M; i++){
        for(int j=1; j<=n; j++){
            cin >> A[i][j];
            m[i][j]=-1;
        }
    }

    cout << busqueda(1,1) << endl;

    return 0;
}
