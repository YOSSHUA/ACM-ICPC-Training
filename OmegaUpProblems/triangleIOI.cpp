/**

https://omegaup.com/arena/problem/Triangle-IOI-1994/#problems
*/
#include <iostream>

using namespace std;


int d[102][102];
int m[102][102];
int N;
int f(int i,int j){
    int izq, der;
    if (i>N){
       return 0;
    }
    if (m[i][j]==-1){
      izq=f(i+1,j);
      der=f(i+1,j+1);
      m[i][j]=max(izq,der)+d[i][j];
    }
    return m[i][j];

}

void ruta(int i, int j){
    int izq,der;
    if(i>N){
        return;
    }
    cout << d[i][j]<<" ";
    izq=m[i+1][j];
    der=m[i+1][j+1];
    if (der > izq){
        ruta(i+1,j+1);
    }else {
        ruta(i+1,j);
    }


}



int main()
{
    cin >> N;
    for (int i=1; i<=N; i++){
       for (int j=1; j<=i; j++){
           cin >> d[i][j];
           m[i][j]=-1;
       }

    }

    cout << f(1,1)<<"\n";



    return 0;
}
