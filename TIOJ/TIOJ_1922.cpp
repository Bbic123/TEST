#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 5;
const int Q = 4e5 + 5;
const int MOD = 1000000007;

int arr[N], QWQ[N], K, cnt[N], ans[Q], QAQ[N];
long long ANS;

struct input{
	int L, R, IDX;
}QQ[Q];

bool cmp(input a, input b){
	return (a.L / K == b.L / K ? a.R < b.R : a.L / K < b.L / K);
}

inline void add(int detail){
	int idx = QAQ[detail];
	detail = arr[detail];
	++cnt[idx];
	ANS = (ANS + (detail * (1ll * cnt[idx] * cnt[idx] - (cnt[idx] - 1) * (cnt[idx] - 1))) % MOD + MOD) % MOD;
	return;
}

inline void sub(int detail){
	int idx = QAQ[detail];
	detail = arr[detail];
	ANS = (ANS + (detail * (1ll * (cnt[idx] - 1) * (cnt[idx] - 1) - cnt[idx] * cnt[idx])) % MOD + MOD) % MOD;
	--cnt[idx];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q, len;
	cin >> n >> q;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		QWQ[i] = arr[i];
	}
	K = n / sqrt(q);
	sort(QWQ, QWQ + n);
	len = unique(QWQ, QWQ + n) - QWQ;
	int l, r;
	for(int i = 0; i < q; ++i){
		cin >> l >> r;
		QQ[i] = {l, r - 1, i};
	}
	for(int i = 0; i < n; ++i) QAQ[i] = lower_bound(QWQ, QWQ + len, arr[i]) - QWQ;
	sort(QQ, QQ + q, cmp);
	l = 0, r = -1;
	for(int i = 0; i < q; ++i){
		while(QQ[i].R < r) sub(r--);
		while(QQ[i].R > r) add(++r);
		while(QQ[i].L < l) add(--l);
		while(QQ[i].L > l) sub(l++);
		ans[QQ[i].IDX] = ANS;
	}
	for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
	return 0;
}
