#include <iostream>
#include <string.h>

using namespace std;

int* reajustamento (int *v, int &quant){
		
	int *ajustado = new int[quant + 5];
	
	memcpy (ajustado, v, (sizeof(int) *quant));
	quant = quant + 5;
	
	delete[] v;
	return ajustado;
}

int main (){
	int tam =5;
	int *v = new int [tam];
	int entr, pre, realoc;
	
	pre = -1;
	realoc = 0;
	
	cin >> entr;
	
	while (entr > 0){
		pre++;
		
		if ((pre > 0) and (pre % 5 == 0)){
			v = reajustamento(v, tam);
			realoc++;
		}
		
		v[pre] = entr;
		cin >> entr; 
	}
	
	for (int i=0; i <= pre; i++)
		cout << v[i] << " ";
		
	cout << endl << tam << endl << realoc << endl;
		
	delete[] v;
	
	return 0;
}
