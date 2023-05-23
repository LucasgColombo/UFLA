#include <iostream>

using namespace std;

void preenche(int n, int **p) {
	p[0][0] = 1;
	for (int i = 1; i < n; i++) {
		p[i][0] = 1;
		p[i][i] = 1;
		
		for (int j = 1; j < i; j++) {
			p[i][j] = p[i-1][j] + p[i-1][j-1];
		}
	}
}

void imprime(int n, int **p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout <<  p[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int n, **p;

	cin >> n;

	p = (int **) malloc(n*sizeof(int *));

	for (int i = 0; i < n; i++) 
	p[i] = (int *) malloc((i+1)*sizeof(int));

	preenche(n,p);
	imprime(n,p);

  return 0;
}
