#include <bits/stdc++.h>
// https://leetcode.com/problems/the-skyline-problem/#
using namespace std;
struct point{
    int x, h;
    char type;
    const bool operator<(const point &otro){
        if(x == otro.x)
            return h < otro.h;
        return x < otro.x;
    }
};
struct ans{
    int x, h;
};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    multiset<int> active;
    int n;
    cin >> n;
    vector<point> points(2*n);
    for(int i = 0; i< n ; i++){
        int xL, xR, h;
        cin >> xL >> xR >> h;
        points[2*i] = {xL,h,'L'};
        points[2*i+1] = {xR,h,'R'};
    }
    sort(points.begin(), points.end());
    int actHeight = 0;
    active.insert(0);
    int i = 0;
    vector<ans> result;
    for(int i = 0; i < 2*n; i++){
        int curX = points[i].x;
        while(i < 2*n && points[i].x == curX){
            if(points[i].type == 'R'){
                auto it = active.find(points[i].h);
                active.erase(it);
            }else{
                active.insert(points[i].h);
            }
            i++;
        }
        i--;
        int curH = *--active.end(); /// Biggest height at x
        if(curH != actHeight){
            result.push_back({curX, curH});
            //cout << curX << " " << curH << '\n';
            actHeight = curH;
        }

    }
    int t = result.size();
    for(int i = 0; i < t; i++)
        cout << result[i].x << " " << result[i].h << "\n";
    return 0;
}
