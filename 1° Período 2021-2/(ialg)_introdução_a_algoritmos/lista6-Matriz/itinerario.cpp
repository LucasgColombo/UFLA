 #include <iostream>
using namespace std;
int main() {
	float custo[4][4];
	int quantCidades;

	for (int i=0; i < 4; i++){
		for (int j=0; j < 4; j++){
			cin >> custo[i][j];
		}
	}
	
	cin >> quantCidades;
	
	int id_cidade[quantCidades];
	
	for(int i=0; i < quantCidades; i++){
		cin >> id_cidade[i];
	}
	
	float Total=0;
	
	for(int i=0; i < quantCidades-1; i++){
		Total += custo[id_cidade[i]][id_cidade[i+1]];
	}
	
	cout << Total;

}

