#include <iostream>
#include <string>

using namespace std;

int main (){
	int n;
	
	cin >> n;
	
	int i=1;
	
	while((i <= n) and (n < 27)){
		int c=1;
		while(c <= i){
			cout << char (c + 96) << " ";
			c++;
		}
		i++;
		cout << endl;
	}

	return 0;
}

