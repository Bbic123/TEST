#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool f;
    int n, q, k, r;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    while(q--){
        cin >> k;
        f = r = 0;
        for(int l = 0; l < n; ++l){
            while(a[l] - a[r] > k) ++r;
            if(a[l] - a[r] == k){
                f = true;
                break;
            }
        }
        cout << (f ? "YES\n" : "NO\n");
    }
}
