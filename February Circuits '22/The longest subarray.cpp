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
 
ll solve(vector<ll> a, ll bit) {
    ll val = (1ll << bit);
    ll ans = 0;
    ll i = 0, j = 0;
    ll x = a[0]; 
    ll n = a.size();
    while(i < n and j < n) {
        if(a[i] & val) {
            x &= a[i];
            if(x == val) ans = max(ans, i-j+1ll);
            i++;
        }
        else {
            if(j <= i-1) {
                if(x == val) ans = max(ans, i-j);
                j = i+1;
                i = i+1;
                x = a[i];
            }
            else {
                x = a[i+1];
                j = i+1;
                i++;
            }
        }
    }
    return ans;
}

int main() 
{
    int t; cin >> t; 
    while(t--)
    {       
        ll n; cin >> n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        vector<ll> v(61, 0);
        for(ll i=0; i<61; i++) {
            v[i] = solve(a, i);
        }
        ll q; cin >> q;
        while(q--) {
            ll ans = 0;
            ll l,r; cin >> l >> r;
            for(ll i=l; i<=r; i++) ans = max(ans, v[i]);
            cout << ans << "\n";
        }
    }
return 0;
}
