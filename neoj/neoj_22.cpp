#include <stdio.h>
#include <stack> // 22. 檸檬汽水傳說

struct pii{
	long long F, S;
};

int main(){
	int t;
	scanf("%d", &t);
	for(; t--;){
		int n, m;
		long long ans = 0;
		std::stack<pii> sk;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &m);
			if(sk.empty()){
				sk.push({m, 1});
				continue;
			}
			while(!sk.empty() && sk.top().F < m){
				ans += (2 + 2 + (sk.top().S - 1)) * sk.top().S / 2;
				long long x = sk.top().S;
				sk.pop();
				if(sk.empty())
					ans -= x;
			}
			if(!sk.empty() && sk.top().F == m){
				sk.top().S++;
			}
			else
				sk.push({m, 1});
		}
		while(!sk.empty()){
			long long x = sk.top().S;
			ans += (1 + 1 + x - 1) * x / 2;
			sk.pop();
			if(sk.empty())
				ans -= x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}