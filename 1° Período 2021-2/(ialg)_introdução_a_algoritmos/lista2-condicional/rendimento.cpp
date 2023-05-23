#include <iostream>

using namespace std;

int main (){
	float tipo, investimento, rendimento, valorMes;
	
	cin >> tipo >> investimento;
	
	if(tipo == 1){
		rendimento = investimento * 0.005;
		valorMes = rendimento + investimento;
		cout << valorMes << endl;
	}else if(tipo == 2){
		rendimento = investimento * 0.03;
		valorMes = (rendimento + investimento) - 30;
		cout << valorMes << endl;
	}
		
	return 0;
}

