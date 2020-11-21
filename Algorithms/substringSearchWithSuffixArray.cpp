/*
    We are going to generate suffix array of a given string s to answer multiple querys 
    to find a string cad in s. 
*/
#include <iostream>    
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int,int> pii;

vector<int> suffix_array(string& s) {
    s.push_back('$');
    int N = s.size();
    vector<int> p(N), c(N);
    {  // k = 0
        vector< pair<char, int> > a(N);
        for (int i = 0; i < N; ++i)
            a[i] = make_pair(s[i], i);
        sort(a.begin(), a.end());
        for (int i = 0; i < N; ++i)
            p[i] = a[i].second;
        for (int i = 1; i < N; ++i)
            c[p[i]] = a[i].first == a[i - 1].first ? c[p[i - 1]] : c[p[i - 1]] + 1;
    }
    for (int k = 0; (1 << k) < N; ++k) {
        for (int i = 0; i < N; ++i)
            p[i] = (p[i] - (1 << k) + N) % N;
        {  // Counting sort
            vector<int> cnt(N), pos(N), p_new(N);
            for (auto x : c)
                cnt[x]++;
            for (int i = 1; i < N; ++i)
                pos[i] = pos[i - 1] + cnt[i - 1];
            for (auto x : p)
                p_new[pos[c[x]]++] = x;
            p = p_new;
        }
        vector<int> c_new(N);
        for (int i = 1; i < N; ++i) {
            pii prev = make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % N]);
            pii now = make_pair(c[p[i]], c[(p[i] + (1 << k)) % N]);
            c_new[p[i]] = now == prev ? c_new[p[i - 1]] : c_new[p[i - 1]] + 1;
        }
        c = c_new;
    }
    s.pop_back();
    return vector<int>(p.begin() + 1, p.end());
}

string s, cad;
int n;
vector<int> suffixA;
bool iguales(int indexS){
    int indexC = 0;
    int tS = s.size();
    int tC = cad.size();
    while(indexC < tC && indexS < tS && cad[indexC] == s[indexS]){
        indexC++;
        indexS++;
    }
    return indexC == tC;
}
string binSearch(){
    int ini = 0, fin = s.size()-1;
    string ans = "";
    while(ini != fin){
        int mitad = (ini+fin)/2;
        /// regresa verdadero si rango 1 es estrictamente menor que el rango 2
        /// s < cad, o bien  cad > s ?
        if(lexicographical_compare(s.begin()+suffixA[mitad], s.end(), cad.begin(),cad.end()) ){
            ini = mitad+1;
        }else{
            fin = mitad;
        }
    }
    return iguales(suffixA[ini]) ? "Yes":"No";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    /// string s - String where we are going to look for matching
    cin >> s;
    suffixA = suffix_array(s);
    cin >> n;
    for(int i = 0; i < n; i++){
        /// string cad - String that we will look for in S.
        cin >> cad;
        /// Print "Yes" if s contains cad else print "No" 
        cout << binSearch() <<'\n';
    }
    return 0;

}

