#include <iostream>

using namespace std;

int main(){
	string m[3][3];
	bool z = false;
	
	for (int i=0; i < 3; i++){
		for (int j=0; j < 3; j++){
			cin >> m[i][j];
		}
	}
	//LINHAS DE X
	if (m[0][0] == "X" and m[0][1] == "X" and m[0][2] == "X"){
		cout << "X" << endl << "0 0" << endl << "0 1" << endl << "0 2" << endl;
		z = true;
	}
	else if (m[1][0] == "X" and m[1][1] == "X" and m[1][2] == "X"){
		cout << "X" << endl << "1 0" << endl << "1 1" << endl << "1 2" << endl;
		z = true;
	}
	else if (m[2][0] == "X" and m[2][1] == "X" and m[2][2] == "X"){
		cout << "X" << endl << "2 0" << endl << "2 1" << endl << "2 2" << endl;
		z = true;
	}
	//COLUNAS DE X
	else if (m[0][0] == "X" and m[1][0] == "X" and m[2][0] == "X"){
		cout << "X" << endl << "0 0" << endl << "1 0" << endl << "2 0" << endl;
		z = true;
	}
	else if (m[0][1] == "X" and m[1][1] == "X" and m[2][1] == "X"){
		cout << "X" << endl << "0 1" << endl << "1 1" << endl << "2 1" << endl;
		z = true;
	}
	else if (m[0][2] == "X" and m[1][2] == "X" and m[2][2] == "X"){
		cout << "X" << endl << "0 2" << endl << "1 2" << endl << "2 2" << endl;
		z = true;
	}
	//DIAGONAIS DE X
	else if (m[0][0] == "X" and m[1][1] == "X" and m[2][2] == "X"){
		cout << "X" << endl << "0 0" << endl << "1 1" << endl << "2 2" << endl;
		z = true;
	}
	else if (m[0][2] == "X" and m[1][1] == "X" and m[2][0] == "X"){
		cout << "X" << endl << "0 2" << endl << "1 1" << endl << "2 0" << endl;
		z = true;
	}
	//LINHAS DE O
	if (m[0][0] == "O" and m[0][1] == "O" and m[0][2] == "O"){
		cout << "O" << endl << "0 0" << endl << "0 1" << endl << "0 2" << endl;
		z = true;
	}
	else if (m[1][0] == "O" and m[1][1] == "O" and m[1][2] == "O"){
		cout << "O" << endl << "1 0" << endl << "1 1" << endl << "1 2" << endl;
		z = true;
	}
	else if (m[2][0] == "O" and m[2][1] == "O" and m[2][2] == "O"){
		cout << "O" << endl << "2 0" << endl << "2 1" << endl << "2 2" << endl;
		z = true;
	}
	//COLUNAS DE X
	else if (m[0][0] == "O" and m[1][0] == "O" and m[2][0] == "O"){
		cout << "O" << endl << "0 0" << endl << "1 0" << endl << "2 0" << endl;
		z = true;
	}
	else if (m[0][1] == "O" and m[1][1] == "O" and m[2][1] == "O"){
		cout << "O" << endl << "0 1" << endl << "1 1" << endl << "2 1" << endl;
		z = true;
	}
	else if (m[0][2] == "O" and m[1][2] == "O" and m[2][2] == "O"){
		cout << "O" << endl << "0 2" << endl << "1 2" << endl << "2 2" << endl;
		z = true;
	}
	//DIAGONAIS DE X
	else if (m[0][0] == "O" and m[1][1] == "O" and m[2][2] == "O"){
		cout << "O" << endl << "0 0" << endl << "1 1" << endl << "2 2" << endl;
		z = true;
	}
	else if (m[0][2] == "O" and m[1][1] == "O" and m[2][0] == "O"){
		cout << "O" << endl << "0 2" << endl << "1 1" << endl << "2 0" << endl;
		z = true;
	}
	// CASO DER "VELHA"
	
	else {
		if (z == false){
			cout << -1;
		}
	}
	
	return 0;
}
