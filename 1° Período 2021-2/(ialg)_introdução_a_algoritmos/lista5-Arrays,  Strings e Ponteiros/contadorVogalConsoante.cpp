#include <iostream>
#include <cstring>

using namespace std;

int main (){
	char frase[100];
	int vog=0, con=0 ;
	unsigned i;

    cin >> frase;

	for(i=0; i < strlen(frase); i++){
		if((frase[i]=='a') or (frase[i]=='i') or (frase[i]=='e') or (frase[i]=='o') or (frase[i]=='u')){
			vog++;
		}else{
			con++;
		}
	}
	cout << vog << endl << con;
	
	return 0;
}

