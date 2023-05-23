#include <iostream>
#include <string>

using namespace std;

int main (){
	int num, lin=0, col=0;
	bool x = false;
	
	cin >> num;
	
	while (lin < num){
		while(col < num){
			if (x == false){
				cout << ".";
				x = true;
			}else if (x == true){
				cout << "#";
				x = false;
			}
			col++;
		}
		cout << endl;
		
		lin ++;
		col = 0;
		
		if (num % 2 == 0){
			if (x == true){
				x = false;
			}else{
				x = true;
			}
		}
	} 
	
	return 0;
}
