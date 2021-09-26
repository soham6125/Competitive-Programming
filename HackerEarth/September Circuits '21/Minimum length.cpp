#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 


signed main() 
{ quick; 
    int t; cin>>t; 
    while(t--)
    {   
        // let x be number of a's and (n-x) be the number of b's
        // total number of distinct substrings with only a's is x
        // total number of distinct substrings with only b's is (n-x)
        // total number of distinct substrings with both a's and b's are x*(n-x) 
        // differentiate [x + (n-x) + x*(n-x)]>=sum w.r.t x
        int n; cin>>n;
        double b_count = ((double)sqrt(4 + 4*n) + (-1)*2 );
        b_count /= 2;
        double ans = (n + b_count*b_count) / (1 + b_count);
        int res = ceil((double)ans);
        cout << res << "\n";
    }   
return 0;
}
