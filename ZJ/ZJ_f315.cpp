#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int BIT[N], arr[N], n;

#define lowbit(x) ((x) & (-x))

void update(int idx){
	while(idx <= n){
		BIT[idx] += 1;
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
	int num, que;
	ll ans = 0;
	cin >> n;
	for(int i = 0; i < (n << 1); ++i){
		cin >> num;
		update(num);
		que = query(num - 1);
		ans += que - (arr[num] << 1);
		arr[num] = que;
	}
	cout << ans << '\n';
	return 0;
}