#include <bits/stdc++.h>
#define int long long int
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

signed main() 
{ quick;

    int tc = 1;
    cin>>tc; 
    while(tc--)
    {   
        int n,x,y; cin>>n>>x>>y;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        multiset<int> st;
        for(int i=0;i<min(n,y);i++) st.insert(a[i]);
        int ans = min(n,y);
        int j = min(n,y);
		    int prev = 0;
        while(j < n)
        {
            if(st.size() < y)
            {
                st.insert(a[j]);
		 j++;
                continue;
            }
            st.insert(a[j]);
            int tot = 0; 
            int sum = 0;
            for(auto it:st)
            {
                if(tot == st.size()-y) break;
                sum += it;
                tot++;
            }
            if(sum > x)
            {
		st.erase(st.find(a[prev]));
		st.erase(st.find(a[j]));
		prev++;
            }
            else
            {
		if((j - prev + 1) > ans) ans = j - prev + 1;
                j++;
            } 
        }
        cout << ans << "\n";
    }

return 0;
}
