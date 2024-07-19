#include <iostream>
using namespace std;

int main(){
	int n, a, b, c;
	cin >> n;
	while(n--){
		bool f = true; // a flag for had output something or not
		cin >> a >> b >> c;
		for(int i = a + 1; i < b; ++i){
			if(i % c){
				cout << i << ' ';
				f = false;
			}
		}
		if(f)
			cout << "No free parking spaces.";
		cout << '\n';
	}
	return 0;
}