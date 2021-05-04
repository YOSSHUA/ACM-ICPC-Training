/**
https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int n = s.size();    
    vector<int> bucket(35,0);
    for(int i = 0; i < n; i++){
        bucket[s[i]-'a']++;
    }
    int difCero = 0;
    for(int i = 0;i <= 'z'-'a'; i++){
        if(bucket[i] != 0)
            difCero++;
    }
    if(difCero == 1 || n ==1)
        return "YES";
    int i = 0;
    while (i <= 'z'-'a' && bucket[i] == 0) 
        i++;
    int cant = bucket[i];
    int diff = 0;
    i++;
    while (i <= 'z'-'a'){ 
        if(bucket[i] != 0 && bucket[i] != cant)
            diff++;        
        i++;
    }
    return diff <= 1? "YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
