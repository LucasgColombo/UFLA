#include <iostream>

using namespace std;

int main () {
    float salarioEmReal, salarioEmDolar, salarioEmEuro, salarioEmLibra;

    cin >> salarioEmReal;

    salarioEmDolar = salarioEmReal / 2.13;
    salarioEmEuro = salarioEmReal / 2.84;
    salarioEmLibra = salarioEmReal / 3.34;

    cout << "Valor do salário em Dólar" << salarioEmDolar <<endl;
    cout << "Valor do salário em Dólar" << salarioEmEuro <<endl;
    cout << "Valor do salário em Dólar" << salarioEmLibra <<endl;

    return 0;
}