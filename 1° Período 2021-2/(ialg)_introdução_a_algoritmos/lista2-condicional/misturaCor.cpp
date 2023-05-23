#include <iostream>
#include <string>

using namespace std;

int main() {
    string cor1, cor2;
    
    cin >> cor1;
    cin >> cor2;
    
    if (((cor1 == "azul") and (cor2 == "amarelo")) or ((cor1 == "amarelo") and (cor2 == "azul"))){
		cout << "verde" <<endl;
	}else if (((cor1 == "azul") and (cor2 == "vermelho")) or ((cor1 == "vermelho") and (cor2 == "azul"))){
		cout << "violeta" <<endl;
	}else if (((cor1 == "vermelho") and (cor2 == "amarelo")) or ((cor1 == "amarelo") and (cor2 == "vermelho"))){
		cout << "laranja" <<endl;
	}else if ((cor1 == "azul") and (cor2 == "azul")){
		cout << "azul" << endl;
	}else if ((cor1 == "amarelo") and (cor2 == "amarelo")){
		cout << "amarelo" << endl;
	}else if ((cor1 == "vermelho") and (cor2 == "vermelho")){
		cout << "vermelho" << endl;
	}
    
    return 0;
}

