/*You will be given a list of integrs and a single integer . 
You must create an array of length k from elements of  such that its unfairness is minimized. Call that array a. Unfairness of an array is calculated as
unf = max(arr) - min(arr)
Where:
- max denotes the largest integer in 
- min denotes the smallest integer in */

#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int ans = INT_MAX;
    for(int i = 0; i+k-1 < n; i++){
        ans = min(ans, arr[i+k-1]-arr[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
