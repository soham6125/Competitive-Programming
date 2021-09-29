#include <bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define loopr(a,b,i)     for(long long int i=a;i>=b;i--)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
#define sz(x)            (ll)((x).size())
#define endl             "\n"
#define lb               lower_bound
#define ub               upper_bound
#define f                first
#define se               second
#define vll              vector<ll>
#define pll              pair<ll,ll>
#define vpll             vector< pair<ll,ll> >
#define all(x)           x.begin(),x.end()
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const ll mod = 1e9 + 7;
const ll MAX  = 8000000000000000064LL;
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

const ll dx[] = {-1,1,0,0,1,1,-1,-1};
const ll dy[] = {0,0,1,-1,-1,1,-1,1};

const ll N = 50;
vll adj[N+1], par(N+1), leaf;
vector<bool> vis(N+1);

void dfs(ll x,ll parent)
{
    vis[x] = true;
    par[x] = parent;
    bool ok = false;
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            ok = true;
            dfs(it,x);
        }
    }
    if(!ok) leaf.pb(x);
}

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    
    int tc = 1;
    cin>>tc; 
    loop(0,tc,q)
    {
        cout<<"Case #"<<q+1<<": ";
        loop(0,N+1,i)
        {
            adj[i].clear();
            vis[i] = false;
            par[i] = -1;
        }
        leaf.clear();
        ll n; cin>>n;
        vll c(n+1);
        loop(1,n+1,i) cin>>c[i];
        loop(0,n-1,i)
        {
            ll x,y; cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1LL,-1);
        vector<pll> ans;
        unordered_map<ll,ll> m;
        for(auto it:leaf)
        {
            ll sum = 0, x = it;
            while(x != -1)
            {
                sum += c[x];
                x = par[x];
            }
            m[it] = sum;
        }
        for(auto it:m) ans.pb({it.se,it.f});
        ll res = 0, mx = 0;
        if(sz(ans)==1)
        {
            cout<<ans[0].f<<endl; cn;
        }
        loop(0,sz(ans),i)
        {
            mx = max(mx,ans[i].f);
            loop(0,sz(ans),j)
            {
                if(i==j) cn;
                loop(0,N+1,i) vis[i] = false;
                ll a = ans[i].se, b = ans[j].se;
                bool ok = true;
                while(a!=1) 
                {
                    vis[a] = true;
                    a = par[a];
                }
                while(b!=1)
                {
                    if(vis[b]) 
                    {
                        ok = false;
                        break;
                    }
                    vis[b] = true;
                    b = par[b];
                }
                if(ok) res = max(res , ans[i].f + ans[j].f - c[1LL] );
            }
        }
        if(res!=0) cout << res << endl;
        else cout << mx << endl;
    }   

cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
