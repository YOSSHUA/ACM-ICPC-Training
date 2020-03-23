/// Link of the problem https://omegaup.com/arena/problem/super-nieves-bros/#problems
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 53;
char mapa[MAXN][MAXN];
short vis[MAXN][MAXN];
struct coord{
    int r,c;
};
int row, col, obj_r , obj_c;
queue<coord> cola;
bool valid(int r, int c){
    if(r >= 1 && r <= row && c  >= 1 && c <= col && !vis[r][c] && mapa[r][c] == 'X')
        return true;
    return false;
}
bool possible(int tam){
    coord act, aux;
    bool flag = false;
    for(int i = 1; i <= col && !flag; i++){
        vis[row][i] = 1;
        cola.push({row,i});
        if(row == obj_r && i == obj_c)
            flag = true;
    }
    while(!cola.empty() && !flag){
        act = cola.front(); cola.pop();
        if(act.r == obj_r && act.c == obj_c){
            flag = true;
            break;
        }
        for(int i = 1; i<= tam; i++){
            if(valid(act.r + i, act.c)){
                vis[act.r + i][act.c] = 1;
                cola.push({act.r + i, act.c});
            }
            if(valid(act.r - i, act.c)){
                vis[act.r - i][act.c] = 1;
                cola.push({act.r - i, act.c});
            }
        }
        if(valid(act.r, act.c+1)){
                vis[act.r][act.c+1] = 1;
                cola.push({act.r , act.c+1});
        }
        if(valid(act.r, act.c-1)){
                vis[act.r][act.c-1] = 1;
                cola.push({act.r , act.c-1});
        }
    }
    return flag;
}
void cleanM();
int binSearch(){
    int ini = 0, fin = row;
    while(ini != fin){
        cleanM();
        int m = (ini+fin)/2;
        if(possible(m))
            fin = m;
        else
            ini = m + 1;
    }
    return fin;
}
void cleanM(){
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            vis[i][j] = 0;
    while(!cola.empty())
        cola.pop();
}
int main()
{
    cin >> row >> col;
    cin >> obj_r >> obj_c;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            cin >> mapa[i][j];
    cout << binSearch() << '\n';

    return 0;
}
