#include <iostream>

using namespace std;

int multi(int n, int n2){
	
	if ((n == 0 ) or (n2 == 0)){
		return 0;
	}
	else if (n2 == 1){
		return n;
	}
	else{
		return n + multi(n, n2 - 1);
	}
}

int main (){
	int n, n2;
	
	cin >> n >> n2;
	
	cout << multi(n, n2); 
	
	return 0;
}
