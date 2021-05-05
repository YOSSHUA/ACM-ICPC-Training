/*
https://omegaup.com/arena/problem/IOI-1994---El-Castillo/
*/

#include <bits/stdc++.h>
#define optimiza ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
map<int,int> cuarto;
int mapa[105][105], visitados[105][105], mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int fil, col, n_cuarto = 1, hab , maxi = 0;
bool valido(int ren, int cols){

    if(ren >= 1 && ren <= fil && cols >= 1 && cols <= col){
        if(visitados[ren][cols] == 0){
            visitados[ren][cols] = n_cuarto;
            hab++;
            return true;
        }
    }
    return false;
}
void dfs(int f,int c){
    bool arri = 1, aba = 1, der = 1,izq = 1;
    if(valido(f,c)){
    if(mapa[f][c]%2 != 0){
        izq = 0;
    }
    if((mapa[f][c] >=4 && mapa[f][c]<=7)||(mapa[f][c] >=12 && mapa[f][c]<=15)){
        der = 0;
    }
    if(mapa[f][c] == 2 || mapa[f][c] == 3 || mapa[f][c] == 6 || mapa[f][c] == 7 || mapa[f][c] == 10 || mapa[f][c] == 11 || mapa[f][c] == 14 || mapa[f][c] == 15 ){
        arri = 0;
    }
    if(mapa[f][c] >= 8){
        aba=0;
    }
    if(aba){
        dfs(f+1,c);
    }
    if(arri){
        dfs(f-1,c);
    }
    if(der){
        dfs(f,c+1);
    }
    if(izq){
        dfs(f,c-1);
    }
    }
}
void res(){
    int sumax= 0, x,y, c ,d ;
    char dir;
    for(int k =  1; k <= fil; k++){
        for(int l  = 1; l <= col; l++){
            for(int i  = 0 ; i < 4; i++){
                c = k;
                d = l;
                c+=mov[i][0];
                d+=mov[i][1];
                if(visitados[k][l] != visitados[c][d]){
                        if(cuarto[visitados[k][l]] + cuarto[visitados[c][d]] > sumax){
                            sumax = cuarto[visitados[k][l]] + cuarto[visitados[c][d]];
                            x = k;
                            y = l;
                            if(c > k ) dir = 'S';
                            else if(c < k) dir = 'N';
                            else if( d < l ) dir = 'W';
                            else if(d > l) dir =  'E';
                        }
                }
            }
        }
    }
    cout << n_cuarto-1 << " " << maxi << '\n';
    cout << x << " " << y << " " <<dir << '\n';
}
int main()
{
    optimiza
    cin >> fil >> col;
    for(int i =  1; i <= fil; i++){
        for(int j  = 1; j <= col; j++){
            cin >> mapa[i][j];
        }
    }
    for(int i =  1; i <= fil; i++){
        for(int j  = 1; j <= col; j++){
            if(! visitados[i][j]){
                hab = 0;
                dfs(i,j);
                cuarto[n_cuarto] = hab;
                maxi = max(maxi,hab);
                n_cuarto++;
            }
        }
    }
    res();
    return 0;
}
