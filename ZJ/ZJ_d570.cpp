#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		cout << n << '\n';
		n /= 10;
	}
	return 0;
}