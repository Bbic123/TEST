#include<bits/stdc++.h>
using namespace std;

int nn[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l, r, num;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            cin >> num;
            nn[i] = nn[i - 1] + num;
        }
        while(m--){
            cin >> l >> r;
            cout << nn[r] - nn[l - 1] << '\n';
        }
    }
}
