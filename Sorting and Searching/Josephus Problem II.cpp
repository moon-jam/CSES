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
#define sp << " " <<
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lc idx * 2 + 1
#define rc idx * 2 + 2

int seg[1000006];
int n, k;

//[l,r)
void build(int idx, int l, int r) {
    if (r == l + 1)
        seg[idx] = 1;
    else {
        int mid = (r + l) / 2;
        build(lc, l, mid), build(rc, mid, r);
        seg[idx] = seg[lc] + seg[rc];
    }
}

void del(int idx, int l, int r, int pos) {
    seg[idx]--;
    int mid = (r + l) / 2;
    if (r == l + 1)  return;
    else if (pos >= mid) del(rc, mid, r, pos);
    else del(lc, l, mid, pos);
}

int query(int idx, int l, int r, int sum){
    // cerr << idx sp seg[idx] sp l sp r sp sum <<'\n';
    int mid = (l+r)/2;
    if(r==l+1) return l+sum;
    else if(sum>seg[lc]) return query(rc, mid, r, sum-seg[lc]);
    else return query(lc, l, mid, sum);
}

signed main() {
    ios;
    cin >> n >> k;
    k++;
    build(0, 0, n);
    int idx = 0;
    rev(i, n, 1){
        idx = (idx+(k%i))%i;
        if(idx == 0) idx = i;
        int pos = query(0, 0, n, idx);
        cout <<  pos << " ";
        del(0, 0, n, pos-1);
        idx--;
    }
    return 0;
}