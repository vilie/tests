#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define NUMAR_PROCESOARE 3

using namespace std;
int procese[NUMAR_PROCESOARE];

void afiseaza_stari(int *p)
{
     for (int i = 0; i < NUMAR_PROCESOARE; i++)
     {    
         if(p[i] == 0)
             cout<<"I  ";
         if(p[i] == 1)
             cout<<"E  ";
         if(p[i] == 2)
             cout<<"S  ";
         if(p[i] == 3)
             cout<<"M  ";
     }
     cout<<endl;
}
int main()
{
    int nr_cmd, i, j;
    cout<<"Nr comenzi = ";
    cin>>nr_cmd;
    int p;
    char c;
    
    for (i = 0; i < nr_cmd; i++)
    {
        afiseaza_stari(procese);
        cout<<"(comanda):  ";
        cin>>p>>c;
        
        switch(c)
        {
                 case 'w':
                      for(j = 0; j < NUMAR_PROCESOARE; j++)
                            procese[j] = 0;
                      procese[p-1] = 3;
                      break;
                 case 'r':
                      if (procese[p-1] != 3)
                      {
                         int ki = 0, ke = 0, pe;
                         for(j = 0; j < NUMAR_PROCESOARE; j++)
                         {
                               if (procese[j] == 0)
                                  ki++; 
                               if (procese[j] == 1 || procese[j] == 2 || procese[j] == 3)
                               {
                                  ke++;
                                  pe = j;
                               }
                         }
                         if (ki == 3)
                            procese[p-1] = 1;
                         if (ke != 0)
                         {
                            procese[pe] = 2;
                            procese[p-1] = 2;
                         }
                      }
                      break;
        }
    }
    afiseaza_stari(procese);
    
    cin>>i;
    return 0;
}
