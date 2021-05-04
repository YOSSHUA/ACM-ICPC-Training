/*
https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int t = s.size();
    map<string,int> m;
    for(int i = 0; i < t; i++){
        for(int j = 0; j+i < t; j++){
            string aux = s.substr(j , i+1);
            sort(aux.begin(), aux.end());
            m[aux]++;
        }
    }
    int ans = 0;
    for(pair<string,int> cur:m){
        ans+= cur.second*(cur.second-1)/2;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
