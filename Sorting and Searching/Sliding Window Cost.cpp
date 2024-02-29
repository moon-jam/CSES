#include <bits/stdc++.h>
using namespace std;
/* TYPES  */
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vi vector<int>
#define vii vector<pii>
#define mii map<int, int>
#define si set<int>
/* UTILS */
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define rall(a) (a).rbegin(), (a).rend()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ins insert
#define err(a) cerr << #a << ": " << a << "\n"
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int n, k;
vi arr;
multiset<int> ms[3];
int sum[3];

void ins(int val) {
    if (ms[0].empty()) {
        ms[0].insert(val);
        sum[1] += val;
        return;
    }
    int a = *ms[0].rbegin();
    if (a < val) {
        ms[1].insert(val);
        sum[0] += val;
        if (ms[1].size() > k / 2) {
            sum[1] += *ms[1].begin();
            sum[0] -= *ms[1].begin();
            ms[0].insert(*ms[1].begin());
            ms[1].erase(ms[1].begin());
        }
    } else {
        ms[0].insert(val);
        sum[1] += val;
        if (ms[0].size() > (k + 1) / 2) {
            sum[0] += *ms[0].rbegin();
            sum[1] -= *ms[0].rbegin();
            ms[1].insert(*ms[0].rbegin());
            ms[0].erase(prev(ms[0].end()));
        }
    }
}

void del(int val) {
    if (ms[1].empty()) {
        ms[0].erase(ms[0].find(val)), sum[1] -= val;
        return;
    }
    if (ms[1].find(val) != ms[1].end())
        ms[1].erase(ms[1].find(val)), sum[0] -= val;
    else
        ms[0].erase(ms[0].find(val)), sum[1] -= val;
    if (ms[0].empty()) {
        sum[1] += *ms[1].begin();
        sum[0] -= *ms[1].begin();
        ms[0].insert(*ms[1].begin());
        ms[1].erase(ms[1].begin());
    }
}

signed main() {
    // ios;
    cin >> n >> k;
    arr.resize(n);
    for (int &i : arr) cin >> i;
    for (int i = 0; i < k; i++) ins(arr[i]);
    cout << sum[0] - sum[1] + (k % 2 != 0) * (*ms[0].rbegin()) << ' ';
    for (int i = k; i < n; i++) {
        del(arr[i - k]);
        ins(arr[i]);
        cout << sum[0] - sum[1] + (k % 2 != 0) * (*ms[0].rbegin()) << ' ';
    }
    return 0;
}