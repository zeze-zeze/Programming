# include <iostream>
# include <string>
#include <algorithm>

using namespace std;

int main(){
    int q;
    scanf("%d", &q);
    while(q--)
    {
        string X, Y;
        cin>>X>>Y;
        int table[X.length() + 1][Y.length() + 1];
        for(int i=0; i<Y.length() + 1; i++) table[0][i] = 0;
        for(int i=1; i<X.length() + 1; i++)
        {
            table[i][0] = 0;
            for(int j=1; j<Y.length() + 1; j++)
            {
                if(X[i-1] == Y[j-1]) table[i][j] = table[i-1][j-1] + 1;
                else table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
        printf("%d\n", table[X.length()][Y.length()]);
    }
}
