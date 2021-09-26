#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 


signed main() 
{ quick; 
    int t; cin>>t; 
    while(t--)
    {   
        int n; 
        cin>>n;
        double b_count = ((double)sqrt(4 + 4*n) + (-1)*2 );
        b_count /= 2;
        double ans = (n + b_count*b_count) / (1 + b_count);
        int res = ceil((double)ans);
        cout << res << "\n";
    }   
return 0;
}
