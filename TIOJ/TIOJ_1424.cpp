#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, ans = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        pq.push(a);
    }
    while(pq.size() > 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    cout << ans << '\n';
    return 0;
}