#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e4 + 5;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll c, c1;
    cin >> n >> c;
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll l = 0, r = 3e9 + 1, mid;
    while(l < r){
        c1 = c;
        mid = (l + r) >> 1;
        for(int i = 0; i < n; ++i){
            if(a[i] < mid) c1 -= (mid - a[i]) * (mid - a[i]);
            if(c1 < 0) break;
        }
        if(c1 < 0) r = mid;
        else l = mid + 1;
    }
    cout << r - 1 << '\n';
    return 0;
}