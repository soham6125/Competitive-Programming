#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

int solve(int n)
{
    return n*(n+1) / 2;
}

int odd(int n)
{
    if(n%2==0) return n/2;
    else return (n+1)/2;
}

signed main() 
{ quick; 
    int t; cin>>t; 
    while(t--)
    {   
        int n,k; cin>>n>>k;
        int ans = 0;
        vector<pair<int,int>> p(3);
      
		    // a>=n/2 and a<=n-2
        if(n%3==0) p[0] = { n/3 , n-2 };
		    else p[0] = {n/3 + 1, n-2 };
      
		    // a>(n+k)/2
        if((n+k)%2 == 0) p[1] = { (n+k)/2 + 1 , n };
        else p[1] = { (n+k)/2 + 1 , n };
      
		    // a<(n-k)/2
        if((n-k)%2 == 0) p[2] = { 0 , (n-k)/2 - 1 };
        else p[2] = { 0 , (n-k)/2 };
      
        // now calculate min(a,n-a-1) - ceil((n-a)/2) + 1 for each value of a
      
        if(p[2].second >= p[0].first)
        {
            int tot = p[2].second - p[0].first + 1;
            int tmp = 0, tmp1 = 0;
            int start = n - p[2].second;
            int end = n - p[0].first;
            tmp = solve(end) - solve(start-1);
            int odds = odd(end) - odd(start-1);
            tmp = (tmp + odds) / 2;
            if((n-1)/2 >= p[0].first and (n-1)/2 <= p[2].second)
            {
                int new_cnt = p[2].second - (n-1)/2;
                tmp1 = solve((n-1)/2) - solve(p[0].first - 1);
                tmp1 += ((new_cnt*(n-1)) - (solve(p[2].second) - solve((n-1)/2))); 
            }
            else if((n-1)/2 > p[2].second)
            {
                tmp1 = (solve(p[2].second) - solve(p[0].first - 1));
            }
            else if((n-1)/2 < p[0].first)
            {
                tmp1 = ((tot*(n-1)) - (solve(p[2].second) - solve(p[0].first - 1))); 
            }
            ans += (tmp1 - tmp + tot);
        }
      
        if(p[0].second >= p[1].first)
        {
            int tot = p[0].second - p[1].first + 1;
            int tmp = 0, tmp1 = 0;
            int start = n - p[0].second;
            int end = n - p[1].first;
            tmp = solve(end) - solve(start-1);
            int odds = odd(end) - odd(start-1);
            tmp = (tmp + odds) / 2;
            if((n-1)/2 >= p[1].first and (n-1)/2 <= p[0].second)
            {
                int new_cnt = p[0].second - (n-1)/2;
                tmp1 = solve((n-1)/2) - solve(p[1].first - 1);
                tmp1 += ((new_cnt*(n-1)) - (solve(p[0].second) - solve((n-1)/2))); 
            }
            else if((n-1)/2 > p[0].second)
            {
                tmp1 = (solve(p[0].second) - solve(p[1].first - 1));
            }
            else if((n-1)/2 < p[1].first)
            {
                tmp1 = ((tot*(n-1)) - (solve(p[0].second) - solve(p[1].first - 1))); 
            }
            ans += (tmp1 - tmp + tot);
        }
        cout << ans << "\n";
    }

return 0;
}
