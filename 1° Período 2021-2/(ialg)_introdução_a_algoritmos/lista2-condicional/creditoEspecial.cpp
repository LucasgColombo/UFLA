#include <iostream>
#include <iomanip>

using namespace std;

int main (){
	float saldo, credito;
	
	cin >> saldo;
	
	if ((saldo >= 0) and (saldo < 200)){
		credito = saldo * 0.1;
		cout << saldo << endl;
		cout << setprecision(4) << credito << endl;
	}else if ((saldo >= 200) and (saldo < 400)){
		credito = saldo * 0.15;
		cout << saldo << endl;
		cout << setprecision(4) << credito << endl;
	}else if ((saldo >= 400) and (saldo < 800)){
		credito = saldo * 0.2;
		cout << saldo << endl;
		cout << setprecision(4) << credito << endl;
	}else if ((saldo >= 800) and (saldo < 1600)){
		credito = saldo * 0.25;
		cout << saldo << endl;
		cout << setprecision(4) << credito << endl;
	}else if (saldo >= 1600){
		credito = saldo * 0.3;
		cout << saldo << endl;
		cout << setprecision(4) << credito << endl;
	}
	
	return 0;
}

