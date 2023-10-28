#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int N = 1e5 + 5;
vector<int> eg[N];
bool bobobo[N];
int mx[N];

int dfs(int x){
	for(int i : eg[x]){
		int cnt = dfs(i);
		mx[x] = max(mx[x], cnt + 1);
	}
	return mx[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, a;
	ll ans = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> k;
		for(int j = 0; j < k; ++j){
			cin >> a;
			eg[i].push_back(a);
			bobobo[a] = true;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!bobobo[i]){
			cout << i << '\n';
			dfs(i);
			break;
		}
	}
	for(int i = 1; i <= n; ++i) ans += mx[i];
	cout << ans << '\n';
	return 0;
}