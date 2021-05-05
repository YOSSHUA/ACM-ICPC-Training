/*
https://omegaup.com/arena/problem/Fotos/#problems
*/

#include <bits/stdc++.h>

using namespace std;

char mapi[501][501];
int64_t mat[501*501];
int r,c, k;
short ti;
int a;
int binSearchPre(int ini, int fin,long value){
    int aux = ini;

    while (ini != fin) {
        int m = (ini+fin) / 2 +1;
        if (mat[m]-mat[aux] <= value)
            ini = m ;
        else
            fin = m - 1;
    }

    return ini;
}
bool valido(int64_t s){
    int64_t rollos = 0;
    int index = 0;
    while(rollos < k && index < r*c){
        index = binSearchPre(index, r*c, s);
        ++rollos;
    }
    return index >= r*c;
}

int64_t binSearch(int64_t ini, int64_t fin){
	while (ini != fin) {
        int64_t m = (ini +fin) / 2;
        if (!valido(m))
            ini = m + 1;
        else
            fin = m;
    }
    return fin;
}



int main(){

	pair<int,int> arre[21];

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ti = 0;
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> mapi[i][j];
            if(mapi[i][j] == '*'){
                arre[a].first = i;
                arre[a].second = j;
                ++a;
            }
        }
    }

    for(int i = 1; i <= r; ++i){
		if(i & 1)
			for(int j = 1; j <= c; ++j){
				mat[(i-1)*c+j] = mat[(i-1)*c+j-1];
				mat[(i-1)*c+j] += a*1000;
				for(int s = 0; s < a; ++s)
					mat[(i-1)*c+j]-= (abs(arre[s].first - i) + abs(arre[s].second - j));
			}
		else
			for(int j = c; j >= 1; --j){
				mat[i*c-j+1] = mat[i*c-j];
				mat[i*c-j+1] += a*1000;
				for(int s = 0; s < a; ++s)
					mat[i*c-j+1]-= (abs(arre[s].first - i) + abs(arre[s].second - j));
			}
	}

    cout << binSearch(0, mat[r*c]) << '\n';

    return 0;
}
