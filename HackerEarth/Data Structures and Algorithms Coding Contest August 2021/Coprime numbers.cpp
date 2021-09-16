#include<bits/stdc++.h>
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
 
const int dx[] = {-1,1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,-1,1,-1,1};
 
ll count(vll a, ll m, ll n)
{
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1 << n);
    for (counter = 1; counter < pow_set_size; counter++) 
    {
        p = 1;
        for (j = 0; j < n; j++) 
        {
            if (counter & (1 << j)) {
                p *= a[j];
            }
        }
        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += (m / p);
    }
 
    return odd - even;
}
signed main() 
{ quick; 
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
 
    int tc = 1;
    cin>>tc; 
    while(tc--)
    {
        ll n; cin>>n;
        ll ans = 0;
        for(ll p=2;p<=sqrt(n);p++)
        {
            if((p*(p+1)) <= n)
            {
                ll tmp = p;
                unordered_map<ll,ll> m;
                while(tmp%2==0)  
                {  
                    m[2]++;
                    tmp /= 2;  
                }  
                for(ll i=3;i*i<=tmp;i+=2)  
                {   
                    while(tmp%i==0)  
                    {  
                        m[i]++;  
                        tmp /= i;  
                    }  
                }  
                if(tmp>2) m[tmp]++;
                vll v;
                for(auto it:m) v.pb(it.f);
                ans += (n/p - p + 1) - (count(v,n/p,sz(v)) - count(v,p-1,sz(v)));
            }
            else break;
        }
        cout << ans << endl;
    }
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
