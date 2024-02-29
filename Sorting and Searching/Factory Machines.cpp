#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define si set<int>
#define mii map<int, int>
#define F first
#define S second
#define tomin(a,b) (a)=min(a,b)
#define tomax(a,b) (a)=max(a,b)
#define rep(i, a,b) for(int i = a; i<=b; i++)
#define rev(i, a, b) for(int i = a; i>=b; i--)
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define sp << ' ' <<
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

signed main(){
    ios;
    int n, t;
    cin >> n >> t;
    vi k(n);
    for(int &i : k) cin >> i;
    int l=0, r = 1e18+1;
    while(r>l){
        int mid = (r+l)/2;
        int p = 0;
        bool overflow = false;
        for(int i : k) p+=mid/i, overflow = overflow || p<0;
        if(p>=t || overflow) r=mid;
        else l=mid+1;
    }cout << r << '\n';
    return 0;
}