#include <iostream>

using namespace std;

int main(){
	int*** matrix;
	int X=2, Y=2, Z=3;
	int busca;
	bool encontrado = false;
 
	matrix = new int**[X];
	for (int i=0; i<X; i++) {
		matrix[i] = new int*[Y];
		for (int j=0; j<Y; j++) {
			matrix[i][j] = new int[Z];
			for (int k=0; k<Z; k++) {
                matrix[i][j][k] = k;
                cin >> matrix[i][j][k];
			}
		}
	}
	
	cin >> busca;
	
	for (int i=0; i<X; i++) {
		for (int j=0; j<Y; j++) {
			for (int k=0; k<Z; k++) {
				if(busca == matrix[i][j][k]){
					encontrado = true;
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}
	
	if (encontrado == false)
		cout << -1 << endl;
		
	delete[] matrix;
	
	return 0;
}
