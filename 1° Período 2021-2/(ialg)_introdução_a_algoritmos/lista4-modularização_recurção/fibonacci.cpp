# include <iostream>

using namespace std;

int fib (int n){
	int c=0;
	
	if (n == 0){
		return 0;
	}else if (n == 1){
		return 1;
	}else if (n == 2){
		return 1;
	}else{
		return c = fib(n-1) + fib(n-2);
	}

}

int main (){
	int n, i=0;
	
	cin >> n;
	
	while (i < n){
		cout << fib(i) << " "; 
		i++;
	}
	return 0;
}
