#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float comprimento, velocidade;
	
	cin >> comprimento;
	
	velocidade = 14.6 * sqrt(comprimento);
	
	cout << velocidade;
	
    return 0;
}

