#include <bits/stdc++.h>
#define int               long long int 
const int mod = 998244353;
int add(int x, int y) {int res = x + y; return (res >= mod ? res - mod : res);}
int mul(int x, int y) {int res = x * y; return (res >= mod ? res % mod : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + mod : res);}
int power(int x, int y) {int res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
#define quick            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std; 

int res = 0;
vector<int> v, arr;

void solve(int n,int k)
{
    if(v.size() < k-1)
    {
        for(int i=0;i<=n;i++)
        {
            v.push_back(i);
            solve(n-i, k);
        }
        v.pop_back();
    }
    else
    {
        v.push_back(n);
        int ind = 0;
        int tmp = 1;
        for(auto it:v)
        {
            // cout<<it<<" ";
            tmp = mul(tmp , pow(arr[ind],it));
            ind++;
        }
        res = add(res, tmp);
        v.pop_back(); 
        v.pop_back();
    }
}     

signed main() 
{ quick; 

    int t; cin>>t; 
    while(t--)
    {   
        arr.clear();
        int a,d,n,k; cin >> a >> d >> n >> k;
        for(int i=0;i<k;i++) arr.push_back(a + i*d);
        for(int i=0;i<=n;i++)
        {
            v.clear();
            res = 0;
            solve(i, k);
            cout << res << " ";
        }
        cout << "\n";
    }

return 0;
}
