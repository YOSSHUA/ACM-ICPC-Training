/*
https://omegaup.com/arena/problem/Glifos/#problems
*/

#include <bits/stdc++.h>

using namespace std;
int letW[125], letA[125];
int activos = 0;
int main()
{
    int n,g, veces=0;
    char a;
    string s;
    cin >> g >> n;
    for(int i = 0; i <g; i++){
        cin >> a;
        letW[(int)a]++;
    }
    cin >> s;
    if(g > n){
        cout << 0 << '\n';
    }else{
        int ini = 0, act = 0;
        while(act < g-1){
            if(letW[(int)s[act]] != 0){
                if(letA[(int)s[act]] < letW[(int)s[act]])
                    activos++;
                letA[(int)s[act]]++;
            }
            act++;
        }
        while(act < n){
            if(letW[(int)s[act]] != 0){
                if(letA[(int)s[act]] < letW[(int)s[act]])
                    activos++;
                letA[(int)s[act]]++;
            }
            if(activos == g)
                veces++;
            if(letA[(int)s[ini]] != 0){
                if(letA[(int)s[ini]] <= letW[(int)s[ini]])
                    activos--;
                letA[(int)s[ini]]--;
            }
            ini++;
            act++;
        }
        cout << veces << '\n';
    }
    return 0;
}
