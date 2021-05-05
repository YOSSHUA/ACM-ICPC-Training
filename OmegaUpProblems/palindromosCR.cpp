/*
https://omegaup.com/arena/problem/Palindromos-Coding-Rush/#problems
*/

#include <bits/stdc++.h>

using namespace std;

map<int,int> bucket;
map<int,int>::iterator it;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string cad;
    cin >> cad;

    int lenght = cad.size();
    long ways = 0;
    int xi = 0;
    bucket[0] = 1;
    for(int i = 0; i < lenght; i++){
        xi^= 1<<(cad[i]-'a');
       
        it = bucket.find(xi);
        if(it != bucket.end())
            ways += it->second;
        
        for(int j = 0; j < 27; j++){
            it = bucket.find(xi^(1<<j));
            if(it != bucket.end())
                ways += it->second;
        }
        bucket[xi]++;
    }

    cout << ways << '\n';
    return 0;
}
