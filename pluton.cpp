#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
ifstream fin("pluton.in");
ofstream fout("pluton.out");
int cod(int x)
{
    int cod=0,i;
    int ap[10]={0};
    while(x)
    {
        ap[x%10]++;
        x/=10;
    }
    for(i=9;i>=0; i--)
    {
        while(ap[i])
        {
            cod=cod*10+i;
            ap[i]--;
        }
    }
    return cod;
}
bool corect(pair<int,int>a, pair<int,int>b)
{
    return(a.second<b.second || a.second==b.second && a.first>b.first);
}
pair<int,int>x[4005];
int main()
{
    int n,i,nrp=1,lcrt,lmax=-1,start,pmax=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x[i].first;
        x[i].second=cod(x[i].first);
    }
    sort(x+1, x+n+1, corect);
    lcrt=1;
    for(i=2; i<=n; i++)
    {
        if(x[i].second==x[i-1].second)
        {
            lcrt++;
        }
        else
        {
            if(lcrt>lmax)
            {
                lmax=lcrt;
                start=i-lcrt;
            }
            nrp++;
            lcrt=1;
        }
    }
    if(lcrt>lmax)
    {
        lmax=lcrt;
        start=i-lcrt;
    }
    lcrt=1;
    for(i=2; i<=n; i++)
    {
        if(x[i].second==x[i-1].second)
        {
            lcrt++;
        }
        else
        {
            if(lcrt==lmax)
            {
                pmax++;
            }
        lcrt=1;
        }
    }
    if(lcrt>lmax)
    {
        lmax=lcrt;
        start=i-lcrt;
    }
    fout<<nrp<<"\n"<<lmax<<"\n"<<pmax<<"\n";
    for(i=start; i<=start+lmax-1; i++)
    {
        fout<<x[i].first<<" ";
    }
}
