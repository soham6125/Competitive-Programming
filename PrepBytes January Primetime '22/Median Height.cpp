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
 
multiset<ll> s1;
multiset<ll> s2;

void balance()
{
    if(s1.size() == s2.size() or s1.size() == s2.size() + 1) return;
    if((s1.size() + s2.size())%2)
    {
        ll e = *s2.begin();
        s2.erase(s2.find(e));
        s1.insert(e);
    }
    else
    {
        ll e = *s1.rbegin();
        s1.erase(s1.find(e));
        s2.insert(e);
    }
}

double findMedian() 
{
    if(s1.size() == 0) return -1;
    if(s1.size() == s2.size()) return (*s1.rbegin()*1.0 + *s2.begin())/2;
    else return *s1.rbegin();
}

void addNum(ll num) 
{
    double median = findMedian();
    if(num > median) s2.insert(num);
    else s1.insert(num);
    balance();
}

void deleteNum(ll num)
{
    if(s1.find(num) != s1.end()) {s1.erase(s1.find(num));}
    else s2.erase(s2.find(num));
    balance();
}

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
        // cout << "Case #" << Q+1 << ": ";
        ll n,k; cin >> n >> k;
        vll a(n);
        loop(0,n,i) cin>>a[i];
        vector<double> ans;
        for(int i = 0; i<k; i++) addNum(a[i]);
        for(int i = k; i<a.size(); i++)
        {
            ans.push_back(findMedian());
            addNum(a[i]);
            deleteNum(a[i-k]);
        }
        ans.push_back(findMedian());
        for(auto it:ans) cout << (ll)it << " ";
    }
        
 
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
