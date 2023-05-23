#include <iostream>

using namespace std;

int fatorial(int n){
	int fat=1;
	
	if (n < 2){
		return 1;
	}else {
		while (n > 1){
			fat = fat*(n);
			n= n-2;
		}
	}
	return fat;
}

int main() {
	int n;
	
	cin >> n;
	
	cout << fatorial(n) << endl;
	
	return 0;
}

