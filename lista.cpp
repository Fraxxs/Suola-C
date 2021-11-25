#include <iostream>

using namespace std;

struct numeri
{
    int data;
    numeri* succ;
};

numeri* inserisciTesta(numeri* rif)
{
    numeri* temp = new numeri;

    cout <<"Inserire numero: ";
    cin >> temp -> data;
    cout << endl;

    temp -> succ = rif;
    rif = temp;

    return rif;
}

numeri* inserisciCoda(numeri* rif)
{
    numeri* temp = new numeri;

    cout << "Inserire numero: ";
    cin >> temp -> data;
    cout << endl;

    temp -> succ = NULL;

    if (rif == NULL)
    {
        rif = temp;
    }

    else
    {
        numeri* p = rif;

        while (p -> succ != NULL)
        {
            p = p -> succ;
        }

        p -> succ = temp;
    }

    return rif;
}   

void stampa (numeri* rif)
{
    if (rif == 0)
    {
        cout << "\nLa lista e' vuota.\n\n";
    }

    else
    {
        numeri* temp = rif;
        cout<<endl;
        while (temp != NULL)
        {
            cout << temp -> data << endl;
            temp = temp -> succ;
        }

        cout << endl;
    }
}

int main()
{
    numeri* lista = NULL;

    int scelta;

    while(true)
    {
        cout<<"\n1 - Inserimento a testa.\n2 - Inserimento a coda.\n3 - Mostra lista.\n4 - Termina programma.\n";
        cin >> scelta;

        switch (scelta)
        {
            case 1:
            {
                lista = inserisciTesta(lista);
                break;
            }

            case 2:
            {
                lista = inserisciCoda(lista);
                break;
            }

            case 3:
            {
                stampa(lista);
                break;
            }

            case 4:
            {
                cout << "\nProgramma terminato...\n";
                return false;
            }
        }
    }
}