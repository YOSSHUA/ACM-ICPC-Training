/*

Problem I of 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)
https://codeforces.com/gym/102465/problem/I
*/

#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 1005;
short vis[MAXN][MAXN];
char m[MAXN][MAXN];
int mov[8][2] ={{0,1}, {1,1},{1,0},{1,-1}, {0, -1}, {-1,-1},{-1,0},{-1,1}};
int w, h;
int la, lb, lc;
void marco(int r, int c){
    if(0 < r && 0 < c && c < w+1 && r < h+1 &&!vis[r][c] && m[r][c] == '#'){
        vis[r][c] = 1;
        for(int i =0; i < 8; i++){
            marco(r+mov[i][0], c+mov[i][1]);
        }
    }
}
int getMaxC(int r, int c){
    while(c <= w && m[r][c] == '#')
        c++;
    return c;
}
int getMaxR(int r, int c){
    while(r <= h && m[r][c] == '#')
        r++;
    return r;
}
pair<int, int> sol(int r, int c){
    ///Si llegué aquí es porque no es orilla ni es ruido.
    int a = getMaxC(r,c);
    int b = getMaxR(r,c);
    a = a - c;
    b = b - r;
    return make_pair(2*a-b, 2*b-3*a);
}
bool checkA(int r, int c, int x, int y){
    return m[r+2*x+2*y][c+x] == '.';
}
bool checkC(int r, int c, int x, int y){
    return m[r+x][c+x+y] == '.';
}
void visMark(int r, int c, int x, int y){
    /// FROM UP TO BOTTOM
    for(int i = r; i < r + 3*x + 2*y; i++){
        for(int j = c; j < c+2*x+y; j++){
            vis[i][j] = 1;
        }
    }
}
bool checkSide(int r, int c, int x, int y){
    bool flag = true;
    /// rows
    for(int i = r-1; i <= r+3*x+2*y && flag; i++){
        if(m[i][c-1] != '.' || m[i][c+2*x+y] != '.')
            flag = false;
    }
    /// cols
    for(int j = c-1; j <= c+2*x + y && flag; j++){
        if(m[r-1][j] != '.' || m[r+3*x+2*y][j] != '.')
            flag = false;
    }
    return flag;
}
void solve(int r, int c){
    auto a = sol(r,c);
    int x = a.first;
    int y = a.second;
    bool ans = checkSide(r,c,x,y);
    if(ans){
        if(checkA(r,c,x,y)){
            la++;
            visMark(r,c,x,y);
        }else if(checkC(r,c,x,y)){
            lc++;
            visMark(r,c,x,y);
        }else{/// its b
            lb++;
            visMark(r,c,x,y);
        }
    }
 
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> w >> h;
    for(int i = 1; i <= h; i++ )
        for(int j = 1; j <= w; j++)
            cin >> m[i][j];
    marco(1,1);
    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            if(!vis[i][j] && m[i][j] == '#'){
                int blancos = 0;
                for(int k = 0; k < 8; k++){
                    if(m[i+mov[k][0]][j+mov[k][1]] == '.')
                        blancos++;
                }
                if(blancos != 8){
                    solve(i,j);
                }
            }
        }
    }
    cout << la << " " <<lb << " " << lc << '\n';
    return 0;
}
