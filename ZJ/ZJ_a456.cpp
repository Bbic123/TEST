#include<bits/stdc++.h>
using namespace std;

int ans[20], n;

void hehe(int m, int len, int mx){
    for(int i = m + 1; i <= n; ++i){
        if(mx - len + i > n) return;
        ans[len] = i;
        if(len == mx){
            cout << '{' << ans[1];
            for(int j = 2; j <= mx; ++j) cout << ',' << ans[j];
            cout << "}\n";
        }
        if(len < mx) hehe(i, len + 1, mx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << "{0}\n";
        for(int i = 1; i <= n; ++i) hehe(0, 1, i);
        cout << '\n';
    }
    return 0;
}