/*
https://omegaup.com/arena/problem/moscas/#problems
*/
#include <iostream>

using namespace std;
int a[60005], flag[60005];
pair <int,int> par[20002];
int main()
{
	int P,mayor=0,j=0;
	cin >> P;
	for(int i = 1; i <= P; i++){
		int ini,fin;
		cin >> ini>>fin;
		flag[ini]++;
		flag[fin]--;
	}
	a[0]=0;
    for(int i = 1; i<= 60000; i++){
		a[i]=a[i-1]+flag[i];
		if(a[i]>mayor){
			mayor=a[i];
		}
    }
    for(int i = 1; i <= 60000; i++){
		if(a[i]==mayor){
			par[j].first=i;
			while(a[i]==mayor){
				i++;
			}
			par[j].second=i;
			j++;
		}
    }
    cout << mayor << endl;
    for(int i = 0; i < j ; i++){
		cout << par[i].first << " " << par[i].second << endl;
    }
    return 0;
}
