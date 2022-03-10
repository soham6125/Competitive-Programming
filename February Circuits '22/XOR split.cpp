#include <bits/stdc++.h>
using namespace std; 
 
bool check(long long x) {
	return x && (!(x&(x-1)));
}
signed main() 
{
    int t; cin >> t; 
    while(t--)
    {       
        long long n; cin >> n;
        if(n == 0) {
			cout << 0 << "\n";
			continue;
		}
		if(check(n)) cout << 0 << "\n";
        else cout << 1 << "\n";
    }

return 0;
}
