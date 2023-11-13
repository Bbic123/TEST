#include <iostream>
using namespace std;

int main(){
	int x, n, bigger = 0, smaller = 0, mx = -1000, mn = 1000, now, i;
	cin >> x >> n;
	for(i = 0; i < n; ++i){
		cin >> now;
		if(now > x){
			bigger += 1;
			if(now > mx){
				mx = now;
			}
		}
		else{
			smaller += 1;
			if(now < mn){
				mn = now;
			}
		}
	}
	if(smaller > bigger){
		cout << smaller << ' ' << mn;
	}
	else{
		cout << bigger << ' ' << mx;
	}
	return 0;
}