#include <iostream>

using namespace std;

void ordenacao (int v[], int tam){
	
	int pivo, j;
	
	for(int i=1; i < tam; i++){
		pivo = v[i];
		j = i-1;
		
		while(j >= 0 and pivo > v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = pivo;
	}
}

int main(){
    int tam, quant, soma=0;
    
    cin >> tam;
    
    int v[tam];

	for (int i=0; i < tam; i++){
		cin >> v[i];
	}
	
	cin >> quant;
	
	ordenacao (v, tam);
	
	for (int i=0; i < quant; i++){
		soma += v[i];
	}
	cout << soma;

    return 0;
}
