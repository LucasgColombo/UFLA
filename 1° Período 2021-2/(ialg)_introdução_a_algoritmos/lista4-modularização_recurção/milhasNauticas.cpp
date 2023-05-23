#include <iostream>

using namespace std;

float distMilhas (float dist){
	return dist/1.852;
}

float prevDist (float dist, float velo, float temp){
	return (dist + velo * temp)/1.852;
}

int main(){
	float dist, velo, temp;
	
	cin >> dist;
	
	while (dist >= 0){
		cin >> velo >> temp;
		
		distMilhas(dist);
		prevDist(dist, velo, temp);
		
		cout << distMilhas(dist) << " " << prevDist(dist, velo, temp) << endl;
		
		 cin >> dist;
	}
	
	return 0;
}
