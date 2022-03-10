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
#define print(a,n)       for(ll i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
#define pi               3.14159265358979323846
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
const ll mod = 1000000007;
const ll MAX = 8000000000000000064LL;
const ll MIN = -8000000000000000064LL;
int add(int x, int y) {int res = x + y; return (res >= mod ? res - mod : res);}
int mul(int x, int y) {int res = x * y; return (res >= mod ? res % mod : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + mod : res);}
int power(int x, int y) {int res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
int mod_inv(int x) {return power(x, mod - 2);}
ll gcd(ll a,ll b) {if(b==0)return a; return gcd(b,a%b);}
ll lcm(ll x, ll y) { ll res = x / gcd(x, y); return (res * y);}
// ll nCr(ll n,ll r){ll ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}
using namespace std; 
 
const ll dx[] = {-1,1,0,0,1,1,-1,-1};
const ll dy[] = {0,0,1,-1,-1,1,-1,1};

signed main() 
{
    int n; cin >> n;
    vector<int> arr(n), arr1(n), v;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> arr1[i];
    reverse(arr.begin(), arr.end());
    reverse(arr1.begin(), arr1.end());
    int res = 0;
    while(arr.size()) {
        int val = arr1[arr1.size() - 1];
        int ind = 0;
        while(arr[ind] != val) ind++;
        int len = arr.size() - 1 - ind;
        res = res + len;
        v.clear();
        for(int i=(int)arr.size()-len; i<(int)arr.size(); i++) v.push_back(arr[i]);
        for(int i=0; i<(int)arr.size()-len; i++) v.push_back(arr[i]);
        arr = v;
        arr.pop_back();
        arr1.pop_back();
        res++;
    }
    cout << res;
return 0;
}
