#include<bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define endl             "\n"
#define sz(x)            (ll)((x).size())
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define print(a,n)       for(ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod = 1e9 + 7;
// const ll MAX  = 8000000000000000064LL;
const ll MIN  = -8000000000000000064LL;
ll add(ll x, ll y) {ll res = x + y; return (res >= mod ? res - mod : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= mod ? res % mod : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + mod : res);}
ll power(ll x, ll y) {ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std;
 
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};
 
const int MX = 1000000;
int lp[MX+5], dist[MX+5];
vector<int> d[MX+5], v[MX+5], pr;
vector<vector<int> > e;
 
signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    
    pr.push_back(1);
    for (int i=2;i<=MX;i++)
    {
        if (!lp[i])
        {
            pr.push_back(i);
            for (int j=i;j<=MX;j+=i)
            lp[j]=i;
        }
        d[i]=d[i/lp[i]];
        auto it=find(d[i].begin(),d[i].end(),lp[i]);
        if (it!=d[i].end())
        d[i].erase(it);
        else
        d[i].push_back(lp[i]);
    }
    int tc = 1;
    // cin >> tc; 
    loop(0,tc,Q)
    {   
        // cout<<"Case #"<<q+1<<": ";
        int n, ans=1e9; cin >> n;
        loop(0,n,i)
        {
            int a; cin>>a;
            if(d[a].empty())
            {
                cout << 1;
                return 0;
            }
            if(d[a].size()==1)
            d[a].push_back(1);
            e.push_back({d[a][0],d[a][1]});
            v[d[a][0]].push_back(i);
            v[d[a][1]].push_back(i);
        }
        for (int i:pr)
        {
            if (i*i>MX)
                break;
            for(int j:pr)
                dist[j]=0;
            queue<pair<int,int> > q;
            for(int j:v[i])
            {
                q.push({j,(e[j][0]==i)});
                dist[e[j][0]^e[j][1]^i]=1;
            }
            while(!q.empty())
            {
                auto p = q.front();
                q.pop();
                int node = e[p.first][p.second];
                for(int u:v[node])
                {
                    if(u!=p.first)
                    {
                        pair<int,int> np(u,(e[u][0]==node));
                        int tmp=e[np.first][np.second];
                        if (!dist[tmp] && tmp!=i)
                        {
                            q.push(np);
                            dist[tmp]=dist[node]+1;
                        }
                        else
                        ans = min(ans,dist[node]+dist[tmp]+1);
                    }
                }
            }
        }
        cout << (ans==1e9 ? -1 : ans);
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
Language: C++17
