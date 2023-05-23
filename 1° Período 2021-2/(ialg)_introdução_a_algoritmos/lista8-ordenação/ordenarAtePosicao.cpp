#include <iostream>

using namespace std;

void ordenacao (int v[], int tam, int posi){
	
	int i, maior, aux=0;
	
	for (i = tam-1; i > 0; i--) {
		maior = 0;
		for (int j = 1; j <= i; j++) {
			if (v[j] < v[maior]){
				maior = j;
			}
		}
		aux = v[maior];
		v[maior] = v[i];
		v[i] = aux;
	}
}

int main(){
    int tam, posi;
    
    cin >> tam;
    
    int v[tam];

	for (int i=0; i < tam; i++){
		cin >> v[i];
	}
	
	cin >> posi;
	
	ordenacao (v, tam, posi);
	
	for (int i=0; i < tam; i++){
		cout << v[i] << " ";
	}

    return 0;
}
