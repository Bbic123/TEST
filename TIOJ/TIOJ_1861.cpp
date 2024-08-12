#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long ans;
	priority_queue<int, vector<int>, greater<>> pq;
	while(cin >> n){
		ans = 0;
		for(int i = 0, num; i < n; ++i){
			cin >> num;
			pq.push(num);
		}
		int a, b;
		while(pq.size() > 1){
			a = pq.top(), pq.pop();
			b = pq.top(), pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		while(!pq.empty()) pq.pop();
		cout << ans << '\n';
	}
	return 0;
}