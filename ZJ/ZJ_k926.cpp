#include <iostream>
using namespace std;

int main(){
	string s1, s2;
	int n;
	cin >> s1 >> s2 >> n;
	char x, y;
	while(n--){
		cin >> x >> y;
		for(int i = 0; i < s1.size(); ++i){
			if(s1[i] == x)
				s1[i] = y;
		}
	}
	int ans = 0;
	for(int i = 0; i < s1.size(); ++i)
		if(s1[i] != s2[i])
			++ans;
	cout << ans << '\n';
	return 0;
}