#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long arr[100005] = {};
	int n, m, num;
	while(cin >> n >> m){ // EOF
		for(int i = 1; i <= n; ++i){ // 1-base
			cin >> num;
			arr[i] = arr[i - 1] + num;
		}
		int a, b;
		while(m--){
			cin >> a >> b;
			cout << arr[b] - arr[a - 1] << '\n';
		}
	}
	return 0;
}