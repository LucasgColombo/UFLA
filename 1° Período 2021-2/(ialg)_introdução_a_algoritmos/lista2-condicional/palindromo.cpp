#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, num, reverso=0, digito;
    string cor1, cor2;
		
	cin >> num >> cor1 >> cor2;
	
	n = num;
	
	digito = num%10;
	reverso = (reverso*10) + digito;
	num = num/10;
	
	digito = num%10;
	reverso = (reverso*10)+ digito;
	num = num/10;
	
	digito = num%10;
	reverso = (reverso*10)+ digito;
	num = num/10;
	
	digito = num%10;
	reverso = (reverso*10)+ digito;
	num = num/10;
	
	digito = num%10;
	reverso = (reverso*10)+ digito;
	num = num/10;
	
	digito = num%10;
	reverso = (reverso*10)+ digito;
	num = num/10;
	
	
	if (n == reverso){
		cout << cor1 << endl;
	}else{
		cout << cor2 << endl;
	}
	
    return 0;
}
