/*
  Answer querys of the sum in a rectangle in a matrix. Square with corners in (x1,y1) and (x2,y2)
  Also make updates in position (x,y).
  problem:
  https://www.spoj.com/problems/MATSUM/
*/
#include <bits/stdc++.h>
#define optimizar ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int MAXN = 1030;
long bit2D[MAXN][MAXN];
long values[MAXN][MAXN];
long sum(int i, int j){
    long ans = 0;
    for(int r = i; r > 0; r -= (r&-r))
        for(int c = j; c > 0; c -= (c & -c))
            ans += bit2D[r][c];
    return ans;
}
void update(int i, int j, int value){
    for(int r = i; r < MAXN; r += (r&-r))
        for(int c = j; c < MAXN; c += (c &-c))
            bit2D[r][c] += value;
}
long query(int i1, int j1, int i2, int j2){
    return sum(i2,j2) - sum(i2,j1-1) - sum(i1-1,j2) + sum(i1-1,j1-1);
}
int N;
void clean(){
    for(int i = 0; i <= N+2; i++)
        for(int j = 0; j <= N+2 ; j++){
            bit2D[i][j] = 0;
            values[i][j] = 0;
        }
}
int main()
{
    optimizar
    int t;
    cin >>t;
    for(int i = 0; i < t; i++){
        cin >> N;
        clean();
        bool flag = true;
        while(flag){
            char c;
            int suma = 0;
            while(cin.get(c)){
                if(c =='T')
                    suma = 1;
                if(c =='D')
                    suma = 2;
                if(c ==' ' || c =='D')
                    break;
            }
            if(suma == 0){
                int x1,y1,x2,y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << query(x1+1,y1+1,x2+1,y2+1) << '\n';
            }else if(suma == 1){
                int x,y, v;
                cin >> x >> y >> v;
                x++;y++;
                update(x,y, -values[x][y]);
                values[x][y] = v;
                update(x,y, values[x][y]);
            }else{
                flag = false;
            }
        }
    }
    return 0;
}
