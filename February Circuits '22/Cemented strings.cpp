#include <bits/stdc++.h>
using namespace std; 

void add_seg(long long seg[], long long start, long long end, long long current, long long index)
{
    if (index > end or index < start) return;
    if (start == end) {
        seg[current] = 1;
        return;
    }
    long long mid = (start + end) / 2;
    add_seg(seg, start, mid, 2 * current + 1, index);
    add_seg(seg, mid + 1, end, 2 * current + 2, index);
    seg[current] = seg[2 * current + 1] + seg[2 * current + 2];
}
 
long long deleted(long long seg[], long long l, long long r, long long start, long long end, long long current)
{
    if (end < l or start > r) return 0;
    if (start >= l and end <= r) return seg[current];
    long long mid = (start + end) / 2;
    return deleted(seg, l, r, start, mid, 2 * current + 1) + deleted(seg, l, r, mid + 1, end, 2 * current + 2);
}
 
void solve(string s)
{
    long long N = s.size();
    long long x = (long long)(ceil(log2(N)));
    long long seg_size = 2 * (long long)pow(2, x) - 1;
    long long segment[seg_size] = { 0 };
    long long count = 0;
    map<long long, queue<long long> > fre;
    for (long long i = 0; i < N; i++) {
        fre[s[i]].push(i);
    }
    while (fre.empty() == false) {
        auto it = fre.begin();
        if (it->second.empty() == true)
            fre.erase(it->first);
        else {
            long long original_index = it->second.front();
            long long curr_index = deleted(segment, 0, original_index - 1, 0, N - 1, 0);
            long long new_index = original_index - curr_index;
            count += new_index + 1;
            add_seg(segment, 0, N - 1, 0, original_index);
            it->second.pop();
        }
    }
    cout << count << "\n";
}

signed main() 
{
    long long t; cin >> t; 
    while(t--)
    {       
        long long n; cin >> n;
        string s; cin >> s;
        solve(s);
	}

return 0;
}
