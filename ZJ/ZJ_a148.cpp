#include <iostream>
using namespace std;

int main(){
	int n, ans, m;
	while(cin >> n){
		ans = 0;
		for(int i = 0; i < n; ++i){
			cin >> m;
			ans += m;
		}
		if(ans > 59 * n)
			cout << "no\n";
		else
			cout << "yes\n";
	}
	return 0;
}