#include <iostream>

using namespace std;

int main() {
    char letra;
    
    cin >> letra;
    
    if ((letra >= 'a') and (letra <= 'z')){
		cout << "MINUSCULA" << endl;
	}else if (((letra >= 'A') and (letra <= 'Z'))){
		cout << "MAIUSCULA" << endl;
	}
	
	
    return 0;
}

