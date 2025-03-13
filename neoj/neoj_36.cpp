#include <bits/stdc++.h>
using namespace std; // 36. stack 練習

const int N = 1e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> sk;
	int t, x;
	cin >> t;
	while(t--){
		cin >> x;
		if(x == 1){
			cin >> x;
			sk.push(x);
		}
		else{
			if(sk.empty()){
				cout << "empty!\n";
			}
			else{
				cout << sk.top() << '\n';
				sk.pop();
			}
		}
	}
	return 0;
}