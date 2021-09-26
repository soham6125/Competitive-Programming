#include <bits/stdc++.h>
#define int              long long int 
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

const int N = 2000000;
vector<int> v(N+1,0), factor(N+1,0);
map<int,int> mp;
 
void init()
{
    factor[1] = 1;
    for(int i=2;i<=N;i++) factor[i] = i;
    for(int i=4;i<=N;i+=2) factor[i] = 2;
    for(int i=2;i*i<=N;i++)
    {
        if(factor[i] == i)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                if(factor[j]==j) factor[j] = i;
            }
        }
    }
}

int solve(int x)
{
    mp.clear();
    while(x != 1)
    {
        mp[factor[x]]++;
        x /= factor[x];
    }
    return mp.size();
}

signed main() 
{ quick; 

    init();
    v[0] = 0;
    v[1] = 0;
    for(int i=2;i<=N;i++)
    {
        v[i] = solve(i);
    }
    int tc = 1;
    cin>>tc; 
    while(tc--)
    {   
        int n,m; cin>>n>>m;
        int diagonals = n + m - 1;
        int ans = 0;
        for(int i=1;i<=diagonals;i++)
        {
            int tot = min(n,m);
            tot = min(tot , diagonals - i + 1);
            tot = min(tot , i);
            ans += (v[i+1]) * (tot);
        }
        cout << ans << "\n";
    }

cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
