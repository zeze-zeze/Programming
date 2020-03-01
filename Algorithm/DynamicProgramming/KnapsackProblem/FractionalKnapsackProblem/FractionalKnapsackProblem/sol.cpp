# include <iostream>
# include <algorithm>
using namespace std;

struct Item
{
    double w, v, cp;
};

bool compare(const Item &x, const Item &y)
{
    return x.cp > y.cp;
}

int main(){
    int N, W;
    scanf("%d%d", &N, &W);
    Item items[N];
    for(int i=0; i<N; i++)
    {
        scanf("%lf%lf", &items[i].v, &items[i].w);
        items[i].cp = items[i].v / items[i].w;
    }
    sort(items, items+N, compare);
    double answer = 0;
    for(int i=0; i<N; i++)
    {
        if(W >= items[i].w) answer += items[i].v;
        else answer += items[i].cp * (double) W;
        W -= items[i].w;
        if(W <= 0) break;
    }
    printf("%.10lf", answer);
}
