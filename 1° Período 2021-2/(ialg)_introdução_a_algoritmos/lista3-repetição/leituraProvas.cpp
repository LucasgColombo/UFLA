#include <iostream>

using namespace std;

int main (){
	int a, b, c, d, e, n=1;
	
	while(n != 0 ){
		
		cin >> n;
		int i=0;
		
		while(i < n){
			int alternativa=0;
			
			cin >> a >> b >> c >> d >> e;
			
			if (a <= 127){
				a=1;
				alternativa++;
			}else{
				a=0;
			}
			
			if (b <= 127){
				b=1;
				alternativa++;
			}else{
				b=0;
			}
			
			if (c <= 127){
				c=1;
				alternativa++;
			}else{
				c=0;
			}
			
			if (d <= 127){
				d=1;
				alternativa++;
			}else{
				d=0;
				
			}if (e <= 127){
				e=1;
				alternativa++;
			}else{
				e=0;
			}
			
			
			if (alternativa == 1){
                if (a == 1){
                    cout << "A" << endl;
                }else if (b == 1){
                    cout << "B" << endl;
                }else if (c == 1){
                    cout << "C" << endl;
                }else if (d == 1){
                    cout << "D" << endl;
                }else if (e == 1){
                    cout << "E" << endl;
                }
            }
            else{
				cout << "*" << endl;
               }
			i++;
		}
		
	}

	return 0;
}
