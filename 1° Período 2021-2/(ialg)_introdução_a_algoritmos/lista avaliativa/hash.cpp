#include <iostream>

using namespace std;

int main (){
	int tam;
	const int UMPRIMO = 37;
	const int M = 15;
	long hash = 0, soma=0;

	cin >> tam;
	
	string v[tam];
	
	for (int i=0; i < tam; i++){
		cin >> v[i];
	}

	for (int i=0; i < tam; i++) {
		hash = 0;
		for (unsigned j=0; j < v[i].size(); j++){
			hash = (UMPRIMO * hash + (int)v[i][j]) % M;   
		}
		
		soma += hash;
		cout << hash << " ";   
	}
	
	cout << soma << endl;
	
	return 0;
}
