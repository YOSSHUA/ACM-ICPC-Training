/// Problem link https://omegaup.com/arena/problem/RiceHub/#problems
#include <bits/stdc++.h>
#define optimizar ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long int ll;
const int MAXS = 100002;
ll R,B;
int L, nums[MAXS];

bool posible(int sizeA){
    int left, right, delta;
    ll sum = 0;
    delta = sizeA/2;
    left = 1;
    right = sizeA;
    for(int i = left; i <= right; i++){
        sum += abs(nums[left+delta]-nums[i]);
    }
    while(right < R){
        if(sum <= B)
            break;
        else{
            sum-= (nums[left+delta] - nums[left]); ///Aportacion de izquierda al centro
            sum+=((nums[left+delta+1]-nums[left+delta])*(delta-1)); /// Puente entre todas las anteriores y el  nuevo
            sum-= (right-delta-left-1)*(nums[left+delta+1]-nums[left+delta]); ///Aportacion extra de los de la derecha
            left++;
            sum+=( nums[++right]-nums[left+delta]); ///Aportacion del nuevo elemento
        }
    }
    return sum <= B ? 1:0;
}
int binSearch(int ini, int fin){
    if (ini == fin)
        return ini;
    int mid = (ini + fin)/2 +1;
    if(posible(mid))
        return binSearch(mid, fin);
    else
        return binSearch(ini, mid-1);
}
int main()
{
    optimizar;
    cin >> R >> L>> B;
    for(int i = 1; i <= R; i++)
        cin >> nums[i];
    cout << binSearch(1, R) << '\n';

    return 0;
}
