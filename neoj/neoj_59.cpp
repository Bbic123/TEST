#include <bits/stdc++.h>
using namespace std; // 59. heap 練習

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> pq;
	int t, n;
	cin >> t;
	for(; t--;){
		cin >> n;
		if(n == 1){
			cin >> n;
			pq.push(n);
		}
		else if(n == 2){
			if(pq.empty()) cout << "empty!\n";
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
	return 0;
}