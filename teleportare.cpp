#include <fstream>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define MAX 1000000
ifstream fin("teleportare.in");
ofstream fout("teleportare.out");
short ap[10000];
bitset <MAX+1>p;
int main()
{
    int i,j,r,n,m,x,d,putere,cateP,pas,v,maxim=INT_MIN;
    fin>>v>>n>>m;
    r=sqrt(n);
    p[0]=p[1]=1;
    cateP=1;
    for(i=3; i<=r; i+=2)
    {
        if(p[i]==0)
        {
            pas=2*i;
            cateP++;
            for(j=i*i; j<=n; j+=pas)
            {
                p[j]=1;
            }
        }
    }
    r+=(r%2==0);
    for(i=r; i<=n; i+=2)
    {
        if(p[i]==0)
        {
            cateP++;
        }
    }
    for(i=1; i<=m; i++)
    {
        fin>>x;
        d=2;
        while(x>1)
        {
            putere=0;
            while(x%d==0)
            {
                putere++;
                x/=d;
            }
            if(putere!=0)
            {
                ap[d]++;
            }
            if(d*d<=x)
            {
                d++;
            }
            else
            {
                d=x;
            }
        }
    }
    if(v==1)
    {
        if(ap[2]!=0)
        {
            cateP--;
        }
        for(i=3; i<=min(n,10000); i+=2)
        {
            if(ap[i]!=0)
            {
                cateP--;
            }
        }
        fout<<cateP;
    }
    else
    {
        maxim=ap[2];
        for(i=1; i<=min(n,10000); i+=2)
        {
            if(ap[i]>maxim)
            {
                maxim=ap[i];
            }
        }
        if(ap[2]==maxim)
        {
            fout<<2<<" ";
        }
        for(i=1; i<=min(n,10000); i+=2)
        {
            if(ap[i]==maxim)
            {
                fout<<i<<" ";
            }
        }
    }
}
