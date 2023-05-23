# include <iostream>

using namespace std;

int ricci (int a, int b, int c){
	int i=0;
	
	if (a == 1)
		return b;
		
	else if (a == 2)
		return c;
	
	else
		return i= ricci(a-1, b, c) + ricci(a-2, b, c);
	
}

int main (){
	int a, b, n=1, c=1;
	
	cin >> a >> b >> n;
	
	while(c <= n){
		cout << ricci(c,a,b) << " ";
		c++;
	}
	return 0;
}
