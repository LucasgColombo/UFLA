#include <iostream>

using namespace std;

int main() {
	
	int n, a=0, b=1, c, i=0;
	
	cin >> n;
	
	if (n == 1){
		cout << 0 << endl;
	}else if (n == 2){
		cout << 0 << endl;
		cout << 1 << endl;
	}else{
		cout << 0 << endl; 
		cout << 1 << endl; 
		
		while (n - 2 > i){
		c = a + b;
		a=b;
		b=c;
		cout << c << endl;
		i++;
		}
	}
	
	
	
	return 0;
}
