#include <iostream>

using namespace std;

int main(){
	int n, posi;
	int p1, p2;
	
	cin >> n;
	
	int v1[n];
	int v2[n];
	
	for (int i=0; i < n; i++){
		cin >> v1[i];
	}
	
	for (int i=0; i < n; i++){
		cin >> v2[i];
	}
	
	cin >> posi;
	
	for (int i=0; i != posi; i++){
		if (v1[i] == posi){
			p1 = i;
		}
	}
	
	
	for (int i=n; i > 0; i--){
		if (v2[i] == posi){
			p2 = i;
		}
	}
	
	for (int i=p1; i <= p2; i++){
		cout << v1[i] << endl;
	}
	
	for (int i=p1; i <= p2; i++){
		cout << v2[i] << endl;
	}
	
	return 0;
}
