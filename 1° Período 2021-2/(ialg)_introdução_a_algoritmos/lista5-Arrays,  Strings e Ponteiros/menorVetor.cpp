#include <iostream>

using namespace std;

int menorVet (int v[], int p1, int p2, int &menorP){
	if ((p1 >= 0) and (p2 >= 0)){
		if (v[p1] < v[p2]){
			menorP = p1;
			return (menorVet(v, p1, p2-1, menorP));
		}else {
			menorP = p2;
			return (menorVet(v, p2, p2-1, menorP));
		}
	}else {
		return v[menorP];
	}
};

int main (){
	int quant=0;
	
	cin >> quant;
	
	int v[quant];
	
	int posi;
	
	for (int i=0; i < quant; i++){
		cin >> v[i];
	}
	
	posi = quant - 1;
	
	cout << menorVet (v, quant-1, quant-2, posi) << " " << posi << endl; 
	
	return 0;
}
