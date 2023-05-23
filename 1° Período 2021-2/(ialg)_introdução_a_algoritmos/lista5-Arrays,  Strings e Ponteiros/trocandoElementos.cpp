#include <iostream>
#include <string>

using namespace std;

int main (){
	
	char A[10], B[10];
	int aux, x=0, y=9;
	
	for (int i=0; i < 10; i++){
		cin >> A[i];
	}
	
	for (int i=0; i < 10; i++){
		cin >> B[i];
	}
	
	for (int i=0; i <= 5; i++){
		aux = A[x];
		A[x] = B[y];
		B[y] = aux;
		
		x++;
		y--;
		x++;
	}
	
	for (int i=0; i < 10; i++)
		cout << A[i] << " ";
	
	cout << endl;
	
	for (int i=0; i < 10; i++)
		cout << B[i] << " ";
	
	
	return 0;
}
