/// DP problem
/// https://www.spoj.com/problems/BYTESM2/
#include <bits/stdc++.h>
using namespace std;

int col, fila, t, mayor, r;
int dp[102][102], p[102][102];
void limpiar(){
	for(int i = 0; i < 102; i++){
		for(int j = 0; j < 102; j++){
			dp[i][j] = 0;
		} 
	}
	mayor = 0;
}
void f(){
	int izq,a,d;
	izq = a = d = 0;
	for(int i = fila - 1 ; i >= 0; i--){
		for(int j = col -1; j >= 0; j--){
			if(j-1 >= 0)
				izq = dp[i+1][j-1] + p[i][j];
			if(j + 1 < col)
				d = dp[i+1][j+1] + p[i][j];
			
			a = dp[i+1][j] + p[i][j];
			
			dp[i][j] = max(izq,max(a,d));
			
			izq = a = d = 0;		
		}
	}
	for(int i = 0; i < col; i++)
		mayor = dp[0][i] > mayor ? dp[0][i] : mayor;
}
int main() {
	

	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> fila >> col;
		for(int i = 0; i < fila; i++){
			for(int j = 0; j < col; j++){
				cin >> p[i][j];
			} 
		}
		
		f();
		cout << mayor << '\n';
		limpiar();
	}
	return 0;
}
