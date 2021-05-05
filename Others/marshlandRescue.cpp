/*

  https://open.kattis.com/problems/marshlandrescues
*/
#include <bits/stdc++.h>
#define PI 3.14159265358979323846

using namespace std;
const int MAXN = 10005;
typedef long double ld;
int n;
ld yMin = 100001, yMax = -100001, xMax  = -100001, xMin= 100001;
struct Point
{
    ld x, y;
    Point() {}
    Point(ld _x, ld _y) : x(_x), y(_y) {}
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    ld cross(const Point& p) const { return x * p.y - y * p.x; }
    ld cross(const Point& a, const Point& b) const { return (a - *this).cross(b - *this); }
}points[MAXN];

//distance from Point a to the segment line given by b and c
ld distancia(const Point &a, const Point &b, const Point &c){
    ld A, B, C;
    // Ax + By + C = 0
    // vector director  (c.x - b.x, c.y - b.y)
    // normal vector (c.y - b.y, -(c.x - b.x)) = (A, B)
    A = c.y - b.y;
    B = -(c.x - b.x);
    C = -A*c.x - B*c.y;
    return abs(A*a.x + B*a.y + C)/sqrt(A*A + B*B);
}

ld distR(ld x, ld y){
    ld dist = 300000;
    Point aux = {x,y};
    for(int i = 0; i < n; i++){
        dist = min(dist, distancia(aux, points[i],points[(i+1)%n]));
    }
    return dist;
}
Point lineLineIntersection(Point A, Point B, Point C, Point D)
{
    Point resp;
    // Line AB represented as a1x + b1y = c1
    ld a1 = B.y - A.y;
    ld b1 = A.x - B.x;
    ld c1 = a1*(A.x) + b1*(A.y);

    // Line CD represented as a2x + b2y = c2
    ld a2 = D.y - C.y;
    ld b2 = C.x - D.x;
    ld c2 = a2*(C.x)+ b2*(C.y);

    ld determinant = a1*b2 - a2*b1;


    ld x = (b2*c1 - b1*c2)/determinant;
    ld y = (a1*c2 - a2*c1)/determinant;
    resp = {x,y};
    return resp;

}

bool inter1(ld a, ld b, ld c, ld d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

int sgn(const ld& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool check_inter(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

pair<ld,ld> minMaxY(ld valueX){
    pair<ld,ld> resp = make_pair(yMin, yMax); // first = yMaximo, second = yMinimo
    for(int i = 0; i < n; i++){
        if(check_inter(points[i], points[(i+1)%n], {valueX, yMax+1}, {valueX, yMin-1})){
            Point inter = lineLineIntersection(points[i], points[(i+1)%n], {valueX, yMax+1}, {valueX, yMin-1});
            resp.first = max(resp.first, inter.y);
            resp.second = min(resp.second, inter.y);
        }
    }
    return resp;
}

ld ternarySearchY(ld x){
    ld mid1, mid2;
    pair<ld,ld> limits = minMaxY(x); // first = yMaximo, second = yMinimo
    ld ini = limits.second, fin = limits.first;
    int times = 0;
    while(times <= 65){
        mid1 = ini + (fin - ini)/ 3;
        mid2  = fin - (fin-ini)/ 3;

        if(distR(x,mid1) < distR(x,mid2)){
            ini = mid1;
        }else
            fin = mid2;
        times++;
    }
    return ini;
}
ld ternarySearchX(){
    ld mid1, mid2;
    ld ini = xMin,  fin = xMax;
    ld y1, y2;
    int times = 0;
    while(times <= 65){
        mid1 = ini + (fin - ini)/ 3;
        mid2  = fin - (fin-ini)/ 3;
        y1 = ternarySearchY(mid1);
        y2 = ternarySearchY(mid2);
        if(distR(mid1,y1) < distR(mid2,y2)){
            ini = mid1;
        }else
            fin = mid2;
        times++;
    }
    return distR(ini,ternarySearchY(ini));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> points[i].x >> points[i].y;
        xMin = min(xMin, points[i].x);
        xMax = max(xMax, points[i].x);
        yMin = min(yMin, points[i].y);
        yMax = max(yMax, points[i].y);
    }
    cout << setprecision(9)<< fixed << ternarySearchX() << '\n';
    return 0;
}
