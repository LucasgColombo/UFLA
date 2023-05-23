#include <iostream>

using namespace std;

void ordenacao (int v[], int tam){
	
	int i, maior;
	
	for (i=0; i < tam-1; i++) {
		maior = i;
		
		for (int j = i+1; j < tam; j++) {
			if (v[maior] < v[j]){
				maior = j;
			}
		}
		swap(v[maior], v[i]);
		
		for (int i=0; i < tam; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}

int main(){
    int tam;
    
    cin >> tam;
    
    int v[tam];

	for (int i=0; i < tam; i++){
		cin >> v[i];
	}
	
	ordenacao (v, tam);

    return 0;
}

