#include <iostream>

using namespace std;

int silnia(int numer);

int main()
{
    cout << "Wprowadz stopien wielomianu: " << endl;
    int stopien;
    cin>>stopien;
    double wspolczynnik[stopien];
    for(int i=0;i<=stopien;i++)
    {
        cout<<"Wprowadz "<<stopien-i<<". wspolczynnik wielomianu"<<endl;
        cin>>wspolczynnik[i];

    }
    for(int i=0;i<=stopien;i++)
    {
        cout<<"WSPOLCZYNNIK "<<stopien-i<<": ";
        cout<<wspolczynnik[i]<<endl;
    }
    double punkt;
    cout<<"Wprowadz punkt, w ktorym bedzie liczona wartosc wielomianu"<<endl;
    cin>>punkt;
    //Wartosc wielomianu w punkcie

    double wynik;
    wynik= wspolczynnik[0];
    int i=1;
    while(i<= stopien)
    {
        wynik= wynik*punkt + wspolczynnik[i];
        i++;
    }
    cout<<"WYNIK: "<<endl;
    cout<<wynik<<endl;
    //Wartosci pochodnych w punkcie
    double wartosciPochodnych[stopien];
    wartosciPochodnych[0]=wspolczynnik[0];

    for(int i=0;i<stopien;i++)
    {
        for(int j=1;j<=stopien-i;j++)
        {
            wartosciPochodnych[i]=wspolczynnik[j]+wspolczynnik[j-1]*punkt;
            wspolczynnik[j]=wartosciPochodnych[i];
        }

    }
    double wartosci[stopien];
    wartosci[stopien]=wspolczynnik[0];
    for(int i=0;i<stopien;i++)
    {
        wartosci[i]=wartosciPochodnych[i];
    }
    for(int i=0;i<=stopien;i++)
    {
        cout<<"Obliczona wartosc ["<<i<<"] "<<wartosci[i]<<endl;
    }

    //Obliczenie wartosci pochodnych wielomianu
    double wynikiP[stopien];

    for(int i=0;i<=stopien;i++)
    {
        wynikiP[i]=wartosci[i]*(silnia(i));
    }

    for(int i=0;i<=stopien;i++)
    {
        cout<< "Wartosc pochodnej "<<i<<"-tego stopnia w punkcie x="<<punkt<<" wynosi: "<<wynikiP[i]<<endl;
    }

    return 0;
}
int silnia(int numer)
{
    int wynikSilnia=1;
    for(int i=numer;i>0;i--)
    {
        wynikSilnia*=i;

    }
    //cout<<"WYNIK SILNI: "<<wynikSilnia<<endl;
    return wynikSilnia;

}
