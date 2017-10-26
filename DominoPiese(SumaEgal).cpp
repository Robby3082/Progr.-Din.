//Jocul domino. In ac joc se fol piese dreptungh de ac dim. Fata unei piese e imp printr-o linie in 2 patrate marcate printr-un nr de pct de la 0 la 6
//Se considera un sir de n piese de domino. El se considera bine aranjat daca pt oricare 2 piese asezate consecutiv patratele lor alaturate sunt
//marcate fie cu ac nr de pct fie suma ac e egala cu 6. daca se paote obt sir bine ord avand voie sa rotiti piesele dar nu si locu in cadru sirului
// afis sirul ord sau msj impos
#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("piese.in");
ofstream g ("piese.out");
struct domino
{
 int x,y;
}v[100];

int main()
{
    int n;
    f>>n;
    int l[50];
    for(int i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    l[n]=1;
    int OK=1;
    int k=n-1;
    while(k>=1 && OK==1)
    {
        if(v[k].y+v[k+1].x == 6 or v[k].y==v[k+1].x)
            l[k]=l[k+1]+1;
        else if(v[k].x+v[k+1].x == 6 or v[k].y==v[k+1].x)
        {
            swap(v[k].x,v[k].y);
            l[k]=l[k+1]+1;
        }
        else OK=0;
        k--;
    }
    if(OK==1)
        for(int i=1;i<=n;i++)
        g<<v[i].x<<" "<<v[i].y<<endl;
        else g<<"Esti pe langa total";
}

/*
piese.in:
4
2 3
4 5
6 5
0 3
piese.out:
3 2
4 5
5 6
0 3
*/
