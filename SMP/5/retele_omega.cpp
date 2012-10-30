/*
 * Retele omega 8x8, N etaje
 */
#define MAX_CERERI 20
#include <iostream>
using namespace std;
int main()
{
    int sursa[MAX_CERERI], destinatie[MAX_CERERI], traseu[MAX_CERERI], cate_etaje, cereri_paralele;
    cout<<"Cate etaje vrem sa avem ";
    cin>>cate_etaje;
    cout<<"Cate cereri simultane vrem sa avem? ";
    cin>>cereri_paralele;
    for(int i = 0; i < cereri_paralele; i++) {
        cout<<"De unde vreau sa plec (cererea "<<i<<") : ";
        cin>>sursa[i];
        cout<<"Unde vreau sa ajung (cererea "<<i<<") : ";
        cin>>destinatie[i];
        traseu[i] = sursa[i] xor destinatie[i];
    }

    for (int j = 0; j < cereri_paralele; j++)
    {
        cout<<endl<<"Suntem la cererea paralela numarul "<<j<<endl;
    for (int i = 0; i < cate_etaje; i++)
        {
            int peUndeOIau = (traseu[j] >> (cate_etaje - i - 1));
            cout << "Pasul "<<i<<" ";
            if (peUndeOIau % 2 == 0)
                cout << "Straight "<<endl;
            else
                cout << "Cross "<<endl;
        }
    }

    return 0;
}
