#include <iostream>
#include <string>

using namespace std;

int main() {
    float mat, natu, lingua, red, human, media;
    
    cin >> mat >> natu >> lingua >> red >> human;
    
    if (red < 200){
		cout << "-1";
	}else{
		media = (mat*3 + natu*2 + lingua*2 + red*2 + human*1) / (3+2+2+2+1);
		cout << media << endl;
	}
			
    return 0;
}
