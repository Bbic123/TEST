#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int, vector<int>, greater<>> p1;
	priority_queue<int> p2;
	int q, a, x;
	cin >> q;
	while(q--){
		cin >> a;
		if(a == 1){
			cin >> x;
			if(p1.empty() || x > p1.top()) p1.push(x);
			else p2.push(x);
			if(p2.size() > p1.size()){
				p1.push(p2.top());
				p2.pop();
			}
			else if(p1.size() > p2.size() + 1){
				p2.push(p1.top());
				p1.pop();
			}
		}
		else cout << p1.top() << '\n';
	}
	return 0;
}
