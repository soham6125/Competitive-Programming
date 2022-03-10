#include <bits/stdc++.h>
using namespace std;
#define int                 long long
#define rep(i,a,b)          for(int i=a;i<b;++i)
#define sep(i,a,b)          for(int i=a;i>=b;--i)
#define mem1(a)             memset(a,-1,sizeof(a))
#define mem0(a)             memset(a,0,sizeof(a))
#define endl                "\n"
#define pb                  push_back
#define ppb                 pop_back
#define pf                  push_front
#define ppf                 pop_front
#define db                  double
#define lb                  lower_bound
#define ub                  upper_bound
#define mp(x,y)             make_pair(x,y)
#define all(a)              a.begin(),a.end()
#define sz(a)               (int)a.size()
#define fr                  first
#define sc                  second
#define pi                  3.14159265358979323846

const int mod = 1000000007;
const int MAX  = 8000000000000000064LL;
const int MIN  = -8000000000000000064LL;
int add(int x, int y) {int res = x + y; return (res >= mod ? res - mod : res);}
int mul(int x, int y) {int res = x * y; return (res >= mod ? res % mod : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + mod : res);}
int power(int x, int y) {int res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
int mod_inv(int x) {return power(x, mod - 2);}
int gcd(int a,int b) {if(b==0)return a; return gcd(b,a%b);}
int lcm(int x, int y) { int res = x / gcd(x, y); return (res * y);}

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

int findDistance (vector <vector <bool>> visited, int n, pair<int, int> st , pair <int, int> ed) {
    queue <pair <int, int>> q;
    q.push(st);
    q.push({-1, -1});
    int ans = 0;
    while (q.size() > 1) {
        pair <int, int> p = q.front();
        q.pop();
        int x = p.fr;
        int y = p.sc;
        if (x == ed.fr && y == ed.sc) {
            return ans;
        }
        if (x == -1) {
            ans++;
            q.push({-1, -1});
            continue;
        }
        rep(i,0,4) {
            int r = x + row[i];
            int c = y + col[i];
            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == false) {
                visited[r][c] = true;
                q.push({r, c});
            }
        }
    }
    return 1000000;
}

void solve() {
    int n;
    cin >> n;
    vector <string> a(n);
    pair<int, int> p1 = {-1, -1};
    pair<int, int> p2 = {-1, -1};
    pair<int, int> g1 = {-1, -1};
    pair<int, int> g2 = {-1, -1};
    vector <vector <bool>> visited(n, vector <bool> (n, false));
    rep(i,0,n) {
        cin >> a[i];
        rep(j,0,n) {
            if (a[i][j] == '^') {
                if (p1.fr == -1) {
                    p1 = {i, j};
                }
                else {
                    p2 = {i, j};
                }
            }

            if (a[i][j] == '*') {
                if (g1.fr == -1) {
                    g1 = {i, j};
                }
                else {
                    g2 = {i, j};
                }
            }

            if (a[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }

    int dis_p1_g1 = findDistance(visited, n, p1, g1);
    int dis_p1_g2 = findDistance(visited, n, p1, g2);
    int dis_p2_g1 = findDistance(visited, n, p2, g1);
    int dis_p2_g2 = findDistance(visited, n, p2, g2);
    int dis_g1_g2 = findDistance(visited, n, g1, g2);

    bool found = false;
    int ans = INT_MAX;
    // Gold1 by p1 and Gold2 by p1
    if (dis_g1_g2 != 100000) {
        if (dis_p1_g1 != 1000000) {
            found = true;
            ans = min(ans, dis_p1_g1 + dis_g1_g2);
        }
        if (dis_p1_g2 != 1000000) {
            found = true;
            ans = min(ans, dis_p1_g2 + dis_g1_g2);
        }
    }

    // Gold1 by p1 and Gold2 by p2
    if (dis_p1_g1 != 1000000 && dis_p2_g2 != 1000000) {
        found = true;
        ans = min(ans, max(dis_p1_g1, dis_p2_g2));
    }

    // Gold1 by p2 and Gold2 by p1
    if (dis_p2_g1 != 1000000 && dis_p1_g2 != 1000000) {
        found = true;
        ans = min(ans, max(dis_p2_g1, dis_p1_g2));
    }

    // Gold1 by p2 and Gold2 by p2
    if (dis_g1_g2 != 100000) {
        if (dis_p2_g1 != 1000000) {
            found = true;
            ans = min(ans, dis_p2_g1 + dis_g1_g2);
        }
        if (dis_p2_g2 != 1000000) {
            found = true;
            ans = min(ans, dis_p2_g2 + dis_g1_g2);
        }
    }


    if (found) {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    else {
        cout << "No" << endl;
    }
}

signed main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin>>t;
    rep(i,0,t) {
        // cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
