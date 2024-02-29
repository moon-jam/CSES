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

signed main() {
    ios;
    int n, k, r = 0, l = 0;
    cin >> n >> k;
    vi arr(n);
    for(int &i : arr) cin >> i, r+=i, tomax(l, i);
    while(r>l){
        int mid = (r+l)/2;
        int d = 1, sub_sum = 0;
        for(int i : arr)
            if(sub_sum+i > mid) d++, sub_sum=i;
            else sub_sum+=i;

        if(d<=k) r=mid;
        else l=mid+1;
    }cout << r << '\n';
    return 0;
}