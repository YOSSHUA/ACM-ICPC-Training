/*
https://omegaup.com/arena/problem/cuadrado_maximo/#problems
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
stack< pair<int, long> > extiende;
pair<long, long> alturas[MAXN][MAXN];
int table[MAXN][MAXN];
int row, col, aux, maxi = 0;


long agrega(int h_i){
	long como = 0;
	while(!extiende.empty() && h_i <= extiende.top().first){
		como += extiende.top().second + 1;
		extiende.pop();
	}
	extiende.push(make_pair(h_i, como));
	return como;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>> row >> col;
	for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> table[i][j];
            table[i][j] += table[i][j] == 0? 0: table[i-1][j];
        }
	}

	long como;
	for(int r = 1; r <= row; r++){
        extiende = stack< pair<int,long> >();
        for(int i = 1; i <= col; i++){
            como = agrega(table[r][i]);
            alturas[r][i] = make_pair(table[r][i], como+1);
        }
	}
	for(int r = 1; r <= row; r++){
        extiende = stack< pair<int,long> >();
        for(int i = col; i > 0; i--){
            como = agrega(alturas[r][i].first);
            aux = min(alturas[r][i].first , (como + alturas[r][i].second));
            if(aux > maxi)
                maxi = aux;
        }
	}
	cout<<maxi<<'\n';
	return 0;
}
