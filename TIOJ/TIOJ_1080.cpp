#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int input[N], arr[N], BIT[N], n;

#define lowbit(x) ((x) & (-x))

void update(int idx, int num){
	while(idx <= n){
		BIT[idx] += num;
		idx += lowbit(idx);
	}
	return;
}

int query(int idx){
	int re = 0;
	while(idx){
		re += BIT[idx];
		idx -= lowbit(idx);
	}
	return re;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ca = 0, len, now;
	ll ans;
	while(cin >> n, n){
		cout << "Case #" << ++ca << ": ";
		ans = 0;
		for(int i = 1; i <= n; ++i){
			cin >> input[i];
			arr[i] = input[i];
		}
		sort(arr + 1, arr + n + 1);
		len = unique(arr + 1, arr + n + 1) - (arr + 1);
		for(int i = 1; i <= n; ++i){
			now = lower_bound(arr + 1, arr + len + 1, input[i]) - arr;
			update(now, 1);
			ans += i - query(now);
		}
		cout << ans << '\n';
		for(int i = 1; i <= n; ++i) input[i] = arr[i] = BIT[i] = 0;
	}
	return 0;
}