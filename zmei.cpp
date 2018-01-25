#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("zmei.in");
ofstream fout("zmei.out");
int x[205];
int nrmax(int x)
{
    int nrmax=INT_MIN,nr1,nr2,maxim;
    if(x/10==0)
    {
        return x;
    }
    else
    {
        while(x)
        {
            nr1=x%10*10 + x/10%10;
            nr2=x/10%10*10 + x%10;
            maxim=max(nr1,nr2);
            if(maxim>nrmax)
            {
                nrmax=maxim;
            }
            x/=10;
        }
        return nrmax;
    }
}
int main()
{
    int i,n,nmax;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x[i];
        x[i]=nrmax(x[i]);
    }
    while(n>1)
    {
        for(i=1; i<=n; i+=2)
        {
            x[i]=x[i]+x[i+1];
            x[i+1]=0;
            if(x[i]==0)
        }
        for(i=1; i<=n; i++)
        {
            fout<<x[i]<<" ";
        }
        for(i=1; i<=n; i++)
        {
            x[i]=nrmax(x[i]);
        }
        n=n/2+(n%2!=0);
        fout<<endl<<endl<<endl;
    }
}
