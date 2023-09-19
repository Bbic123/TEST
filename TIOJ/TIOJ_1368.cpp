#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define hi first // high
#define idx second

const int N = 1e5 + 5;

ll sum[N];
int n, nday[N], r[N], l[N];
stack<pair<int, int>> st;

void R(){
    for(int i = 1; i <= n; ++i){
        while(!st.empty() && st.top().hi > nday[i]){
            r[st.top().idx] = i;
            st.pop();
        }
        st.push(make_pair(nday[i], i));
    }
    while(!st.empty()){
        r[st.top().idx] = n + 1;
        st.pop();
    }
}

void L(){
    for(int i = n; i > 0; --i){
        while(!st.empty() && st.top().hi > nday[i]){
            l[st.top().idx] = i;
            st.pop();
        }
        st.push(make_pair(nday[i], i));
    }
    while(!st.empty()){
        l[st.top().idx] = 0;
        st.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ansR, ansL;
    ll ans, high;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            cin >> nday[i];
            sum[i] = sum[i - 1] + nday[i];
        }
        R();
        L();
        ans = ansR = ansL = -1;
        for(int i = 1; i <= n; ++i){
            high = nday[i] * (sum[r[i] - 1] - sum[l[i]]);
            if(high > ans){
                ans = high;
                ansR = r[i] - 1;
                ansL = l[i] + 1;
            }
        }
        cout << ans << '\n' << ansL << ' ' << ansR << '\n';
        for(int i = 1; i <= n; ++i) sum[i] = 0;
    }
}