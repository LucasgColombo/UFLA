#include <iostream>

using namespace std;

int main(){
	int m[10][10];
	int lMaior, cMenor, maior;
	
	for (int i=0; i < 10; i++){
		for (int j=0; j < 10; j++)
			cin >> m[i][j];
	}
	
	lMaior = 0;
	cMenor = 0;
	maior = m[0][0];
	
	for (int i=0; i < 10; i++){
		for (int j=0; j < 10; j++)
			if (m[i][j] > maior){
				maior = m[i][j];
				lMaior = i;
			}
	}
	
	int menor = m[lMaior][0];
	
	for (int i=0; i < 10; i++){
		if (m[lMaior][i] < menor){
			menor = m[lMaior][i];
			cMenor = i;
		}
	}
	
	cout << menor << endl << lMaior << " " << cMenor;
	
	
	return 0;
} 
