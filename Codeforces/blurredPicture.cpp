/**
Problem B of 2018-2019 ICPC Southwestern European Regional Programming Contest (SWERC 2018)

https://codeforces.com/gym/102465/problem/B

The output should consist of a single line, whose content is an integer,
the length of the largest square composed of non-blurred pixels inside the picture.
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000+5;
pair<int,int> range[MAXN];
int n;
bool possible(int ls){
	for(int i = 0; i+ls-1 < n; i++){
		int l = max(range[i].first, range[i+ls-1].first);
		int r = min(range[i].second, range[i+ls-1].second);
		if(r-l+1 >= ls)
			return true;
	}
	return false;
}
 
int binSearch(){
	int ini = 1, fin = n;
	int mid;
	while(ini != fin){
		mid = (ini+fin+1)/2;
		if(possible(mid)){
			ini = mid;
		}else{
			fin = mid-1;
		}
	}
	return ini;
}
 
int main() {
	cin >> n;
	int l,r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		range[i] = make_pair(l,r);
	}
	cout << binSearch() << '\n';
	return 0;
}
