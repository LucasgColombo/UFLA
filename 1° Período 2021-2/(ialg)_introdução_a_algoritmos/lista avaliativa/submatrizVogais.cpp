#include <iostream>

using namespace std;

bool Vogal (char letra){
	bool x = false;
	if (letra == 'A' or letra == 'E' or letra == 'I' or letra == 'O' or letra == 'U'){
		x = true;
	}
	return x;
}

int main (){
	int quant;
	bool encontrado = false;
	
	cin >> quant;
	
	char M[quant][quant] = {};
	char V[2][2] = {};
	
	for (int i=0; i < quant; i++){
		for (int j=0; j < quant; j++){
			cin >> M[i][j];
		}
	}
	
	for (int i=0; i < quant; i++){
		for (int j=0; j < quant; j++){
				if (Vogal(M[i][j]) and i != quant - 1 and j != quant - 1){
					if(Vogal(M[i][j+1]) and Vogal(M[i+1][j]) and Vogal(M[i+1][j+1])){	
						encontrado = true;
						V[0][0] = M[i][j];
						V[0][1] = M[i][j+1];
						V[1][0] = M[i+1][j];
						V[1][1] = M[i+1][j+1];
					}	
				}
		}
	}
	
	if (encontrado == true){
		for (int i=0; i < 2; i++){
			for (int j=0; j < 2; j++){
				cout << V[i][j] << " ";
			}
			cout << endl;
		}
	}else{
		cout << "submatriz nao encontrada" << endl;
	}
	
	return 0;
}
