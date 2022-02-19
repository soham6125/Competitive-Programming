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

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    
    int tc = 1;
    // cin >> tc; 
    loop(0,tc,Q)
    {   
        // cout<<"Case #"<<q+1<<": ";
        ll n; cin >> n;
        vector<vll> a(n,vll(n-1));
        loop(0,n,i) 
        {
            loop(0,n-1,j) 
            {
                cin >> a[i][j];
            }
        }
        bool ok = true;
        vll ind(n, 0);
        ll ans = 0;
        while(1)
        {
            ll count = 0;
            vector<bool> vis(n,false);
            loop(0,n,i) count += (ind[i] == n-1);
            if(count == n) break; 
            ll cnt = 0;
            loop(0,n,i) 
            {
                if(ind[i] < n-1 and !vis[i]) 
                {
                    ll x = a[i][ind[i]];
                    if(!vis[x-1] and a[x-1][ind[x-1]] == i+1) 
                    {
                        vis[i] = true;
                        vis[x-1] = true;
                        ind[i]++;
                        ind[x-1]++;
                        cnt++;
                    }
                }
            }
            cout << endl;
            cout << endl;
            if(cnt == 0) {
                ok = false;
            }
            else ans++;
        }
        cout << (ok ? (ans*3ll) : -1);
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
Language: C++17
