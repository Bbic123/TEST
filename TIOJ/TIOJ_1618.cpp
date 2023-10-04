#include<bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
int h[N], b[N];
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, p, q = -2147483648, now = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    for(int i = 1; i <= n; ++i){
        cin >> b[i]; // input bi
        while(!dq.empty() && h[dq.back()] <= h[i]){ // back
            now -= b[dq.back()];
            dq.pop_back();
        }
        dq.push_back(i), now += b[i];
        if(!dq.empty() && dq.front() < i - k + 1){ // front
            now -= b[dq.front()];
            dq.pop_front();
        }
        if(now > q){ // check
            q = now;
            p = i;
        }
    }
    cout << p << ' ' << q << '\n';
    return 0;
}
