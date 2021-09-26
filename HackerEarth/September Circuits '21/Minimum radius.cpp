#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

signed main() 
{ quick; 
    int t; cin>>t; 
    while(t--)
    {   
        int n,p; cin >> n >> p;
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++) cin >> a[i].first.first;
        for(int i=0;i<n;i++) cin >> a[i].first.second;
        for(int i=0;i<n;i++) cin >> a[i].second;
        vector<pair<double,int>> rad(n);
        vector<int> pre(n);
        for(int i=0;i<n;i++)
        {
            double x = a[i].first.first;
            double y = a[i].first.second;
            double dist = sqrt(x*x + y*y);
            rad[i].first = dist;
            rad[i].second = i;
        }
        sort(rad.begin(),rad.end());
        pre[0] = a[rad[0].second].second;
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + a[rad[i].second].second;
        int ind = lower_bound(pre.begin(),pre.end(),p) - pre.begin();
        if(ind < n) cout << (int)ceil(rad[ind].first) << "\n";
        else cout << -1 << "\n";
    }
    
return 0;
}
 

