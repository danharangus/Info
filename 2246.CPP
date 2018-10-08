#include <iostream>
#include <cstring>

using namespace std;

int ap[7];

char c[100001];

bool isAnagram(int poz)
{
    int nrp = 0, nrs = 0, nrm = 0, nrv=0, nrc=0;

    memset(ap, 0, sizeof(ap));

    int i, ifin = poz + 5, j;

    /*for(int j = poz; j < ifin; j++)
    {
        cout<<c[j]<<" ";
    }*/
    //cout<<poz<<" ";
    for(i = poz; i < ifin ; i++)
    {
        if(strchr("adobeADOBE", c[i]))
        {
            if(c[i] == 'A' || c[i] == 'a')
            {
                ap[0]++;
                nrv++;
            }
            else if(c[i] == 'D' || c[i] == 'd')
            {
                ap[1]++;
                nrc++;
            }
            else if(c[i] == 'O' || c[i] == 'o')
            {
                ap[2]++;
                nrv++;
            }
            else if(c[i] == 'B' || c[i] == 'b')
            {
                ap[3]++;
                nrc++;
            }
            else if(c[i] == 'E' || c[i] == 'e')
            {
                ap[4]++;
                nrv++;
            }
        }
        else if(strchr("+-*", c[i]))
        {
            if(c[i] == '+')
            {
                nrp++;
            }
            else if(c[i] == '-')
            {
                nrm++;
            }
            else if(c[i] == '*')
            {
                nrs++;
            }
        }
        else
        {
            return false;
        }
    }

    for(i = 0; i < 5; i++)
    {
        if(ap[i] > 1)
        {
            return false;
        }
    }

    if((nrc + nrv + nrs == 5) || (nrc + nrp + nrs >= 2 && nrv + nrm + nrs >= 3))
    {
        return true;
    }

    return false;
}

int main()
{
    int i, lungime, nr = 0;

    cin>>c;

    lungime = strlen(c);

    for(i = 0; i < lungime - 4; i++)
    {
        if(isAnagram(i))
        {
            nr++;
            for(int j = i; j<= i+4; j++)
            {
                cout<<c[j];
            }
            cout<<endl;
        }
    }

    cout<<nr;

    return 0;

}
