#include <iostream>
#include <cstring>

using namespace std;

int ap[7];

char c[100001];

bool isAnagram(int poz)
{
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
            }
            else if(c[i] == 'D' || c[i] == 'd')
            {
                ap[1]++;
            }
            else if(c[i] == 'O' || c[i] == 'o')
            {
                ap[2]++;
            }
            else if(c[i] == 'B' || c[i] == 'b')
            {
                ap[3]++;
            }
            else if(c[i] == 'E' || c[i] == 'e')
            {
                ap[4]++;
            }
        }
        else if(strchr("+-*", c[i]))
        {
            for(j = 0; j < 5; j++)
            {
                if(c[i] == '*' && !ap[j])
                {
                    ap[j]++;
                }
                else if(c[i] == '+' && (j == 2 || j == 3) && !ap[j])
                {
                    ap[j]++;
                }
                else if(c[i] == '-' && j != 2 && j !=3 && !ap[j])
                {
                    ap[j]++;
                }
            }
        }
        else
        {
            return false;
        }
    }

    for(i = 0; i < 5; i++)
    {
        if(ap[i] != 1)
        {
            return false;
        }

    }

    return true;
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
        }
    }

    cout<<nr;

    return 0;

}
