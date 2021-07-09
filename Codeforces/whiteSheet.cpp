#include <bits/stdc++.h>
/// https://codeforces.com/contest/1216/problem/C
using namespace std;
typedef int64_t ll;
struct rect{
    ll x1, y1, x2,y2;
    rect(){}
    rect(ll x1, ll y1, ll x2, ll y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    ll area(){
        return abs(x2-x1)*abs(y2-y1);
    }
};
/// Return vertex of rectangle formed by intersection between two rectangles. 
/// If there is no such intersection it return rectangle with vertex (0,0,0,0)
rect intersection(rect a, rect b){
    ll x1 = max(min(a.x1, a.x2), min(b.x1, b.x2));
    ll y1 = max(min(a.y1, a.y2), min(b.y1, b.y2));
    ll x2 = min(max(a.x1, a.x2), max(b.x1, b.x2));
    ll y2 = min(max(a.y1, a.y2), max(b.y1, b.y2));
    if(x2 <= x1 || y2 <= y1)
        return rect(0,0,0,0);
    return rect(x1,y1,x2,y2);
}
int main()
{
    rect w, b1,b2;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

    rect wb1 = intersection(w,b1);
    rect wb2 = intersection(w,b2);
    rect wb1wb2 = intersection(wb1,wb2);

    if(w.area() > wb1.area() + wb2.area() - wb1wb2.area())
        cout <<"YES\n";
    else
        cout << "NO\n";
    return 0;
}
