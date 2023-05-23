#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int num, tam=0, capTam, numTr, prim, ult;
	
	cin >> num;
	
	capTam = num;
	prim = num%10;
	
	while (capTam != 0){
		ult = capTam%10;
		capTam /= 10;
		tam++;
	}
	
	numTr = num - pow(10, tam-1) * ult;
	numTr -= prim;
	numTr += ult;
	
	numTr = numTr + pow(10, tam-1) * prim;
	
	cout << numTr;
	
	return 0;
}
