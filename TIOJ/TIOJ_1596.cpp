#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define I second.first
#define J second.second
#define C first

const int N = 1e5 + 5;
int boss[N];
pair<int, pair<int, int>> input[N];

int query(int a){
	if(a != boss[a]) boss[a] = query(boss[a]);
	return boss[a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, a, b;
	ll ans = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) boss[i] = i;
	for(int i = 0; i < m; ++i) cin >> input[i].I >> input[i].J >> input[i].C;
	sort(input, input + m, greater<>());
	cin >> k;
	for(int i = 0; i < k; ++i){
		cin >> a;
		boss[a] = 0;
	}
	for(int i = 0; i < m; ++i){
		a = query(input[i].I), b = query(input[i].J);
		if(!a && !b) ans += input[i].C;
		else if(!a) boss[b] = 0;
		else if(!b) boss[a] = 0;
		else boss[a] = b; 
	}
	cout << ans << '\n';
	return 0;
}