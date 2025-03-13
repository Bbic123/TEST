#include <bits/stdc++.h>
using  namespace std; // 19. 大善人老闆救濟東南亞兒童

stack<int> sk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, num, now;
	cin >> t;
	while(t--){
		now = 1;
		cin >> n;
		for(int i = 1; i <= n; ++i){
			cin >> num;
			while(now <= num){
				sk.push(now);
				++now;
			}
			while(!sk.empty() && sk.top() == num) sk.pop();
		}
		cout << (sk.empty() ? "Yes\n" : "No\n");
		while(!sk.empty()) sk.pop();
	}
	return 0;
}