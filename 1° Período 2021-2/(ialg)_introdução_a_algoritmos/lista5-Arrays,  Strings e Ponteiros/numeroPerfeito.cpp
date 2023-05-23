#include <iostream>

using namespace std;

int numPerf(int n){
    int soma=0;
    bool x = false;

	for(int i = 1; i <= n/2; i++){
		if(n % i == 0){
			soma += i;
		}
	}

	if(soma == n){
		x = true;
		return x;
	}else{
		x = false;
		return x;
	}
}

void imprimeDivisores(int n, int v[], int div){
	int i=0, c=1, a= 0;

	while (a < n){
		if(n % c == 0){
			v[i] = c;
			i++;
		}
		c++;
		a++;
	}
	
	for(int k = 1; k < i; k++){
		cout << v[k-1] << " ";
	}

	cout << endl;
}

int main() {
	int n, aux, div=0;

	cin >> n;

	for(int i = 1; i < n; i++){
		if(n % i == 0){
			div++;
		}
	}
	
	int v[div] = {};

	aux = numPerf(n);

	if(aux == true){
		imprimeDivisores(n, v, div);
	}else{
		cout << "-1";
	}
	
    return 0;
}
