#include <iostream>

using namespace std;

int tribonacci (int n){
	int soma=0;
	
	if (n == 1){
		return 1;
	}else if (n == 2){
		return 1;
	}else if (n == 3){
		return 2;
	}else{
		return soma = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
	}

}

int main (){
	int n, i=1;
	
	cin >> n;
	
	while (i <= n){
		cout << tribonacci(i) << endl; 
		i++;
	}
	
	return 0;
}

