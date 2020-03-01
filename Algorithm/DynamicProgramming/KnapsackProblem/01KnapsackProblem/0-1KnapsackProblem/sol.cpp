# include <iostream>
# include <algorithm>

using namespace std;

struct Item
{
    int v, w;
};

int main(){
    int N, W;
    scanf("%d%d", &N, &W);
    Item items[N+1];
    for(int i=1; i<=N; i++) scanf("%d%d", &items[i].v, &items[i].w);
    int table[N+1][W+1];
    for(int i=0; i<=W; i++) table[0][i] = 0;
    for(int i=1; i<=N; i++)
    {
        table[i][0] = 0;
        for(int j=1; j<=W; j++)
        {
            if(j < items[i].w) table[i][j] = table[i-1][j];
            else table[i][j] = max(table[i-1][j], items[i].v + table[i-1][j - items[i].w]);
        }
    }
    printf("%d\n", table[N][W]);
}
