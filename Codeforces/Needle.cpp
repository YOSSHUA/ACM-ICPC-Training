/*
https://codeforces.com/gym/102920/problem/H

Given 3 paralel lines and a set of points in each one with integer coordinates. Find all possible lines that you can form with
one point in each line.
*/
#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846264338327950288
using namespace std;
typedef int64_t ll;
 
const int MAXN = 60005;
typedef complex<double> base;
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
            j += bit;
            if (i < j)
                swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*(M_PI)/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res)
{
    vector<base> fa (a.begin(), a.end()), fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))
        n <<= 1;
    n <<= 1;
    fa.resize (n), fb.resize (n);
    fft (fa, false), fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);
    res.resize (n);
    for (size_t i=0; i<n; ++i)
        res[i] = (int) round(fa[i].real());
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> a(MAXN,0),c(MAXN,0), r,b(MAXN,0);
    int as,bs,cs;
    int a_,b_,c_;
    cin >> as;
    for(int i = 0; i < as; i++){
        cin >>a_;
        a[a_+30000]= 1;
    }
    cin >> bs;
    int bv;
    for(int i = 0; i < bs; i++){
        cin >>b[i];
        b[i]+=30000;
    }
    cin >> cs;
    for(int i = 0; i < cs; i++){
        cin >>c_;
        c[c_+30000] = 1;
    }
    multiply(a,c,r);
    ll ans = 0;
    for(int i = 0; i < bs; i++){
        ans+=r[2*b[i]];
    }
    cout<< ans << '\n';
 
    return 0;
}
