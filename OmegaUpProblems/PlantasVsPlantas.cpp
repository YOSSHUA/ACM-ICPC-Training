///link https://omegaup.com/arena/problem/plantas-vs-plantas/#problems/plantas-vs-plantas
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000005;
struct p{
    int tam, com;
};
stack<p> pend;
int resp= 0,n;
int num[MAXN];
void agregar(int pi){
    int der = 0;
    while(!pend.empty() && pi > pend.top().tam){
        if(der < pend.top().com)
            der = pend.top().com;
        else
            der++;
        pend.pop();
    }
    resp = max(resp,der);
    pend.push({pi,der});
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<= n; i++)
        cin>>num[i];
    for(int i = n; i>=1; i--)
        agregar(num[i]);
    cout << resp << '\n';
    return 0;
}
