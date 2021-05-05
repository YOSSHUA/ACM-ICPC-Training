
/**
https://omegaup.com/arena/problem/Mejorando-Vias/#problems
*/
#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
const int MAXN = 100005;

struct edge{
    ll u, w;
};
ll m[MAXN][2], m1[MAXN];
bool visM[MAXN][2], visM1[MAXN];
vector<edge> adj[MAXN];
int fathers[MAXN], cantH[MAXN];
int n;

ll sum(int u);

ll f(int current, short united){
    if(cantH[current] == 0) /// soy hoja
        return united ? 0 : -100000;

    if(!visM[current][united]){
        visM[current][united] = 1;
        if(united){ /// Estoy unido a mi padre

                ll maxi = -100000;
                ll s = sum(current);
                for(edge v : adj[current]){
                    if(v.u != fathers[current]){
                        maxi = max(maxi,f(v.u, 1)  + v.w -f(v.u,0));
                    }
                }
                m[current][united] = max(s, maxi + s);

        }else{ /// No estoy unido a mi padre
                ll max1 = -100000, max2 = -100000;
                ll s = sum(current);
                ll aux1;
                int node;
                for(edge v : adj[current]){
                    if(v.u != fathers[current]){
                        aux1 = f(v.u, 1) + v.w - f(v.u,0);
                        if(max1 < aux1){
                            max1 = max(max1, aux1);
                            node = v.u;
                        }
                    }
                }
                for(edge v : adj[current]){
                    if(v.u != fathers[current] && v.u != node){
                        max2 = max(max2, -f(v.u, 0) + v.w + f(v.u,1));
                    }
                }

                m[current][united] = max(s+max1, s+ max1 + max2);

        }
    }
    return m[current][united];
}
ll sum(int u){
    if(!visM1[u]){
        visM1[u] = 1;
        ll s = 0;
        for(edge v : adj[u]){
                if(v.u != fathers[u])
                    s += f(v.u,0);
        }
        m1[u] = s;
    }
    return m1[u];
}
void assignFather(int u, int father){
    for(edge v: adj[u]){
        if(v.u != father){
            fathers[v.u] = u;
            cantH[u]++;
            assignFather(v.u, u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ;
    for(int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    fathers[1] = 1;
    assignFather(1,1);
    cout << f(1,0) << '\n';    

    return 0;
}
