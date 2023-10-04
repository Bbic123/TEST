#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    while(k--){
        cin >> x;
        int *it = lower_bound(a, a + n, x);
        cout << (*it == x ? (it - a + 1) : 0) << '\n';
    }
    return 0;
}