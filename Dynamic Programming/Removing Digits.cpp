#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define rev(i, a, b) for (int i = a; i >= b; --i)
#define tomax(a, b) (a) = max((a), (b))
#define tomin(a, b) (a) = min((a), (b))
#define all(a) a.begin(), a.end()
#define pob pop_back
#define pb push_back
#define eb emplace_back
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int step[1000006];

int get_step(int num) {
    if (num < 10) return 1;
    if (step[num] != INT_MAX) return step[num];
    for (int dig = num % 10, pos = 1; pos <= num;
         pos *= 10, dig = (num % (pos * 10)) / pos) {
        if (num - dig != num) tomin(step[num], get_step(num - dig) + 1);
    }
    return step[num];
}

signed main() {
    ios;
    int n;
    cin >> n;
    fill(step, step + n + 1, INT_MAX);
    cout << get_step(n) << '\n';
    return 0;
}