#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include <stdio.h>

int n, BIT[1000005], a[1000005];

inline int query(int idx){
	int re = 0;
	while(idx){
		re ^= BIT[idx];
		idx -= idx & (-idx);
	}
	return re;
}

inline int input(){
	int re = 0;
	char ch = getchar_unlocked();
	while(ch < '0' || ch > '9') getchar_unlocked();
	while(ch >= '0' && ch <= '9'){
		re = re * 10 + ch - 48;
		ch = getchar_unlocked();
	}
	return re;
}

inline void output(int x){
	if(x >= 10) output(x / 10);
	putchar_unlocked(x % 10 + '0');
	return;
}

int main(){
	int q, l, r, x, v;
	n = input();
	q = input();
	for(int i = 1; i <= n; ++i) a[i] = input();
	{
		int nxt;
		for(int i = 1; i <= n; ++i){
			BIT[i] ^= a[i];
			nxt = i + (i & (-i));
			if(nxt <= n) BIT[nxt] ^= BIT[i];
		}
	}
	do{
		x = input();
		if(!x){
			l = input();
			r = input();
			{
				int ans = query(r) ^ query(l - 1);
				output(ans);
				putchar_unlocked('\n');
			}
		}
		else{
			x = input();
			v = input();
			{
				for(int i = x; i <= n; i += i & (-i)){
					BIT[i] ^= v ^ a[x];
				}
				a[x] = v;
			}
		}
	}while(--q);
	return 0;
}