#include <iostream>

using namespace std;

int main (){
	int v[10] = {}, i, posi, quant, num;

	cin >> quant;
	
	for (i=0; i < quant; i++)
		cin >> v[i];
		
	cin >> num >> posi;

	for (i=9; i > posi; i--)
		v[i] = v[i-1];
		
	v[posi] = num;
		
	for(i=0; i < 10; i++)
		cout << v[i] << " ";

	return 0;
}
