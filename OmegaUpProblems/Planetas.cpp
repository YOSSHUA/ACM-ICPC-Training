/// Link problem https://omegaup.com/arena/problem/Planetas/#problems
#include <bits/stdc++.h>
#define delta 0.00000001
using namespace std;
const int MAXN = 1005;
double pos[MAXN];
int n;

double fuerza(double value){
    int i = 1;
    double sum = 0;
    while(i<= n){
        sum+= 1/(pos[i] - value);
        i++;
    }
    return sum;
}

double binSearch(double ini, double fin){
    double mitad;
    while(abs(fin - ini) > delta){
        mitad = (ini + fin) / 2;
        if(fuerza(mitad) > 0)
            fin = mitad;
        else
            ini = mitad;
    }
    return ini;
}


int main()
{
    vector<double> meteors;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<= n; i++)
        cin >>pos[i];
    sort(pos+1, pos+n+1);
    for(int i = 1; i < n; i++){
        double mPos = binSearch(pos[i], pos[i+1]);
        meteors.push_back(mPos);
    }
    cout << meteors.size() << '\n';
    for(int j = 0; j < meteors.size(); j++)
        cout << setprecision(3) << fixed << meteors[j] << " ";

    return 0;

}
