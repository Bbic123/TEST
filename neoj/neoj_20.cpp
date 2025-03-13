#include <bits/stdc++.h>
using  namespace std; // 20. 中國人排隊問題

const int N = 1e6 + 5;
int tee[N];
bool in_q[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, tt;
	cin >> t;
	for(int c = 1; c <= t; ++c){
		queue<int> t_q[1005], main_q;
		fill(tee, tee + N, 0);
		fill(in_q, in_q + 1005, 0);
		cout << "Line #" << c << '\n';
		cin >> n;
		for(int i = 1, nn; i <= n; ++i){
			cin >> nn;
			for(int j = 0, u; j < nn; ++j){
				cin >> u;
				tee[u] = i;
			}
		}
		string s;
		cin >> tt;
		while(tt--){
			int n;
			cin >> s;
			if(s[0] == 'E'){
				cin >> n;
				if(!in_q[tee[n]] && tee[n]){
					main_q.push(tee[n]);
					in_q[tee[n]] = true;
					t_q[tee[n]].push(n);
				}
				else if(in_q[tee[n]] && tee[n]){
					t_q[tee[n]].push(n);
				}
				else if(!tee[n]){
					main_q.push(0);
					t_q[0].push(n);
				}
			}
			else{
				int now = main_q.front();
				if(!now){
					cout << t_q[0].front() << '\n';
					main_q.pop();
					t_q[0].pop();
				}
				else{
					cout << t_q[now].front() << '\n';
					t_q[now].pop();
					if(t_q[now].empty()){
						in_q[now] = 0;
						main_q.pop();
					}
				}
			}
		}
	}
	return 0;
}