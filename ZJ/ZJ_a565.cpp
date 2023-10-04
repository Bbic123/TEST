#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p, pq;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        p = pq = 0;
        for(char i : s){
            if(i == 'q' && p > 0) ++pq, --p;
            else if(i == 'p') ++p;
        }
        cout << pq << '\n';
    }
    return 0;
}
