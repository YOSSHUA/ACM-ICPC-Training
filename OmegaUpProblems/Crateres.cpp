///link https://omegaup.com/arena/problem/crateres/#problems
#include <bits/stdc++.h>

using namespace std;
int crateres[503][503];
int F, C;
int busqueda(int i, int j){
int val=0;
if(i>=1 && i<=F && j>=1 && j<=C){
if(crateres[i][j]>0){
    val+=crateres[i][j];
    crateres[i][j]=0;
    val+=busqueda(i+1, j);
     val+=busqueda(i, j+1);
    val+=busqueda(i-1, j);
    val+=busqueda(i, j-1);
}
}
    return val;
}
int main(){
ios_base::sync_with_stdio(0);cin.tie(0);
cin >> F>> C;
for(int i = 1; i <= F; i++){
 for(int j=1; j <= C; j++ ){
cin >> crateres[i][j];
}
}
    int crater_mayor=0, crateractual, posicion=1, pos;
    for(int i = 1; i <= C; i++){
 for(int j=1; j <= F; j++ ){
if (crateres[j][i]>0){
        crateractual=busqueda(j,i);
        if(crateractual>crater_mayor){
    crater_mayor=crateractual;
                    pos=posicion;
}
posicion++;
    }
}
}
    if(crater_mayor==0){
    cout << 0 << " "<< 0;
}else{
    cout << pos << " " << crater_mayor;
}
    return 0;

}
