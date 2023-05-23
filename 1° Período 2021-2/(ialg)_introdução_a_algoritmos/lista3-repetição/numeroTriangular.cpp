#include <iostream>

using namespace std;

int main() {
	
	int N, num=0, numTriang;
	
	cin >> N;
	
	while (N > num){
		numTriang = (N*(N+1))/2;
		num++;
	}
	
	cout << numTriang << endl;
	
	return 0;
}
