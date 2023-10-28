#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, ans;
	priority_queue<int, vector<int>, greater<>> pq;
	while(cin >> n, n){
		for(int i = 0; i < n; ++i){
			cin >> a;
			pq.push(a);
		}
		ans = 0;
		while(pq.size() > 1){
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			pq.push(a + b);
			ans += a + b;
		}
		pq.pop();
		cout << ans << '\n';
	}
	return 0;
}