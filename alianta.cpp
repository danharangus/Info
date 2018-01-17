#include <fstream>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
ifstream fin("alianta.in");
ofstream fout("alianta.out");
int z[1005],x[1005],y[1005],d[1005],v[1005];
int main()
{
    int i,j,n,dij,cate=0,minim=INT_MAX;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x[i]>>y[i]>>z[i];

    }
    for(i=1; i<=n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            dij=(x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
            if(dij>d[i])
            {
                d[i]=dij;
            }
            if(dij>d[j])
            {
                d[j]=dij;
            }
        }
        if(d[i]<minim)
        {
            minim=d[i];
            cate=0;
        }
        if(d[i]==minim)
        {
            cate++;
            v[cate]=z[i];
        }
    }
    sort(v+1, v+cate+1);
    fout<<minim<<"\n"<<cate<<"\n";
    for(i=1; i<=cate; i++)
    {
        fout<<v[i]<<" ";
    }
}
