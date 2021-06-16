/// Problem F of 2017-2018 ACM-ICPC Latin American Regional
/// Problem related to DP, Segment Tree / BIT, and coordinates compression.

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5+5;
struct coord{
    int b,f;
    int64_t d;
    const bool operator < (const coord &otro){
        if(b == otro.b)
            return f > otro.f;
        return b < otro.b;
    }
};
vector<coord> coords;
unordered_map<int, int> coordComp;
set<int> aux;
int64_t ST[4*MAXN];

void update(int index, int l, int r, int pos, int64_t newV){
    if(l == r){
        ST[index] = max(newV, ST[index]);
    }else{
        int mid = (l + r) /2;
        if(pos <= mid){
            update(index*2, l, mid, pos, newV);
        }else{
            update(index*2 + 1, mid+1, r, pos, newV);
        }
        ST[index] = max(ST[index*2], ST[index*2 +1]);
    }
}
int64_t query(int qL, int qR, int l, int r, int index)
{
  if(qL <= l && r <= qR)
    return ST[index];

  if(qR < l || r < qL || l > r)
    return 0;

  int mid = (l + r) / 2;
  return max(query(qL, qR, l, mid, 2*index),
            query(qL, qR, mid+1, r, 2*index+1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    coords.resize(n);
    for(int i = 0; i < n; i++)
        cin >> coords[i].b >> coords[i].f >> coords[i].d;
    sort(coords.begin(), coords.end());
    /// Coordinates compression
    for(int i = 0; i < n; i++){
        //cout << coords[i].b << " " << coords[i].f << " "<< coords[i].d << "\n";
        aux.insert(coords[i].f);
    }
    int j = 1;
    for(int c : aux){
        coordComp[c] = j++;
    }
    /// Dp
    int64_t ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(i < n-1 && coords[i].b == coords[i+1].b && coords[i].f ==  coords[i+1].f)
            coords[i].d += coords[i+1].d;
        /// coordComp[coords[i].f]+1 because we don't want to take in account the same f
        int64_t q = query(coordComp[coords[i].f]+1, n, 1, n, 1);
        ans= max(ans, q+ coords[i].d);
        update(1,1,n, coordComp[coords[i].f], coords[i].d+q);
    }
    cout << ans <<"\n";
    return 0;
}
