#include <iostream>
using namespace std;

int main(){
	int n, m;
	while(cin >> n >> m){
		int now = 0;
		for(int i = n; 48763; ++i){
			now += i;
			if(now > m){
				cout << i - n + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}