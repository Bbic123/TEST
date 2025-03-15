#include <bits/stdc++.h>
using namespace std; // 23. 更不能輸給暴風雨

stack<int> R, L;
int where[5005];

void solve(int N,int order[]){
	int N_top = 1;
	for(int i = 0; i < N; i++){
		if(where[order[i]] == 0){
			while(N_top != order[i]){
				push_train();
				R.push(N_top);
				where[N_top] = 1;
				N_top++;
			}
			push_train();
			move_station_1_to_2();
			pop_train();
			N_top++;
		}
		else if(where[order[i]] == 1){
			while(R.top() != order[i]){
				move_station_1_to_2();
				L.push(R.top());
				where[R.top()] = 2;
				R.pop();
			}
			R.pop();
			move_station_1_to_2();
			pop_train();
		}
		else if(where[order[i]] == 2){
			while(L.top() != order[i]){
				move_station_2_to_1();
				R.push(L.top());
				where[L.top()] = 1;
				L.pop();
			}
			L.pop();
			pop_train();
		}
		where[order[i]] = 3;
	}
	return;
}