#include <iostream>

using namespace std;

void simplificacao (int num, int deno){
	int c=1, mdc=1;
	
	while(c < num or c < deno){
        if((num%c == 0) and (deno%c == 0)){
            mdc = c;
		}
        c++;
    }
	
	cout << num/mdc << endl << deno/mdc;
}



int main (){
	int num, deno;
	
	cin >> num >> deno;
	
	simplificacao(num, deno);
	
	return 0;
}

