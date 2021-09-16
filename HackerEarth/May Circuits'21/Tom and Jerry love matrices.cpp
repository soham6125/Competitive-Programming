#include<bits/stdc++.h>
#define ll               long long int 
#define loop(a,b,i)      for(long long int i=a;i<b;i++)
#define cn               continue;
#define pb               push_back
#define db               double
#define mp               make_pair
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
 
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};

signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
  int tc = 1;
  // cin>>tc;
  while(tc--)
  {
    ll m,n,x,q;
    cin>>m>>n>>x>>q;
    vector<ll> v(m+n-1,0);
    loop(0,m+n-1,i)
    { 
      v[i] = min(i+1,min(((m+n)-i)-1,min(m,n)));
    }    
    while(q--)
    {
      ll val; cin>>val;
      if(val==1 or val==2)
      {
        ll a,b,c; 
        cin >> a >> b >> c;
        a--; b--; c--;
        for(ll k=b;k<=c;k++) v[a+k]--;
      }
      else
      {
        ll k, ans = -1; 
        cin >> k;
        vll mp;
        for(ll i=0;i<m+n-1;i++)
        {
          if(v[i]>0) k = k - v[i];
          if(k<=0)
          {
            ans = i;
            break;
          }
        }
        if(ans!=-1) cout << ans + x + 2 << endl;
        else cout << -1 << endl;
      }
    }
  }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
