#include <iostream>
using namespace std;

int main(){
	int n, ans = -1, now = 0, m;
	cin >> n;
	while(n--){
		cin >> m >> m;
		if(m)
			now++;
		else
			now--;
		if(now > ans)
			ans = now;
	}
	cout << ans << '\n';
	return 0;
}