#include <bits/stdc++.h>
using namespace std; 

int main() 
{ 
    long long n; 
	cin >> n;
    vector<long long> arr1(n), arr2(n);
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int i=0; i<n; i++) cin >> arr2[i];
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    reverse(arr2.begin(), arr2.end());
    long long res = 0;
    for(int i=0; i<n; i++) res = res + ( (arr2[i] < arr1[i]) ? arr1[i] - arr2[i] : 0);
    cout << res;
	return 0;
}
