#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define int long long
#define rep(i, a, b) for(int i = a; i<=b; i++ )
#define rev(i, a, b) for(int i = a; i>=b; i-- )
#define tomax(a, b) (a)=max((a), (b))
#define tomin(a, b) (a)=min((a), (b))
#define pb push_back
#define eb emplace_back
using namespace std;

signed main(){
    ios
    string s;
    char res[1000006];
    int ch[30], odd=0;
    fill(ch, ch+27, 0);
    cin >> s;
    for(int i = 0; s[i]; i++)
        ch[s[i]-'A']++;
    for(int i = 0; i<26; i++)
        odd+=ch[i]%2;
    if(odd>0 && s.size()%2==0){cout << "NO SOLUTION\n"; return 0;}
    if(odd!=1 && s.size()%2){cout << "NO SOLUTION\n"; return 0;}
    int idx = 0, n=s.size()-1;
    rep(i, 0, 25){
        if(ch[i]%2) ch[i]--, res[n/2]='A'+i;
        rev(j, ch[i], 1)
            res[idx]=res[n-idx]='A'+i, idx++, j--;
    }rep(i, 0, n) cout << res[i];
    cout << '\n';
    return 0;
}