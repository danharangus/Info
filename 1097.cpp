#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

ifstream fin("placare.in");
ofstream fout("placare.out");

int a[301][301],ap[101];
int main()
{
    int n,m,j,k,i,start=1,cate,p,l=1,s=0,neg=0;
    fin>>n>>m;
    for(i=1; fin>>p; i++)
    {
        if(p<0)
        {
            start++;
            neg++;
        }
        else
        {
            cate=p;
            while(cate)
            {
                for(j=start; cate; j++)
                {
                    a[l][j]=p;
                    cate--;
                }
            }
            if(start==m)
            {
                start=neg;
                l++;
            }
            else
            start+=p;
        }
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=10; j++)
        {
            fout<<a[i][j]<<" ";
        }
        fout<<"\n";
    }


}
