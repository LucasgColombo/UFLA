#include <iostream>

using namespace std;

int main(){

    int m[4][4];

    bool k = false;

    for (int i = 0; i < 4; i++)
    {
        int y = 0, x = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> m[i][j];
            if (m[i][j] != 1 and m[i][j] != 0)
                k = true;

            if (m[i][j] != 0)
                x++;
            
            
            if (m[i][j] == 0)
                y++;

            if (x > 1)
                k = true;
            
            if (y > 3)
                k = true;
            
        }
    }
    
            
    if (k == true)
        cout << "nao" << endl;
    else
        cout << "sim" << endl;
    
}
