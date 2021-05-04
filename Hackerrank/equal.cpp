#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10005;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int c[MAXN];
    while(t--){
        int n;
        cin >>n;
        int posMin = 0;
        for(int  i = 0; i < n; i++){
            cin >> c[i];
            if(c[i] < c[posMin])
                posMin = i;
        }
        /**
            We want to make a[0] = a[1] = .... = a[n-1]
            For that, we can add 1, 2 or 5 to all but one entry.
            For example a[i] =  a[i]+1, for i != n-1, but we can choose who we will avoid.
            So, we notice that its relative the same approach as reducing just one entry each time
            to make them equal.
            So, we can use a greddy approach, subtracting the most of 5, 2 or 1, because we want
            to minimize steps.
            But, there is a problem, there are cases where we don't get the best answer.
            For example.
            0 4 4 -> we get 4 steps, but the best is 3 steps.
            Instead of subtracting 2 twice to 4's, we subtract 5 to each 4 and then subtract 1 to 1.
            So, to use our approach, we need to "move it" one unit to solve  1 5 5 an then
            we get 3 steps.
            Other sample is 0 3 3 ->  we get 4 steps, but the best is 3 steps.
            In this case we need to add 2 to each entry. Then we solve 2 5 5 and we get 3 steps.
            We can try with 4 but it doesn't improve our answer.
            So, we need to try adding 1 or 2. Our base case is adding "0".

        */
        int sum;
        int ans = INT_MAX;
        for(int add = 0; add < 3; add++){
            sum = 0;
            for(int  i = 0; i < n; i++){
                int diff = c[i] + add - c[posMin];
                sum+= (diff/5 + (diff%5)/2 +((diff%5)%2)/1 );
            }
            ans = min(ans, sum);
        }
        cout << ans  << '\n';

    }
    return 0;
}
