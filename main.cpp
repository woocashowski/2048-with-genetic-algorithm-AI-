#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<conio.h>
#include "GA.h"

using namespace std;



Tablica tab[4][4];
void tablica();
void generuj();
void ruch();
void sprawdz();

int main()
{
    srand(time(NULL));

    //Inicjacja tablicy
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            tab[j][i].w = 0;
        }
    }

    tablica();
}

void tablica()
{
    int a, b, c, d;

    d = 0;

    for (;d == 0;)
    {
        a = rand()%4;
        b = rand()%4;
        c = rand()%2;
        if(tab[a][b].w==0)
        {
            tab[a][b].w = (c+1)*2;

            d = 1;
        }
    }
    generuj();
}


void generuj()
{
    int a, b;
    system ("cls");

    cout << " Gra 2048 \n ";


    int biggest = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if(tab[x][y].w > biggest)
                {
                    biggest = tab[x][y].w;
                }
        }
    }
    int l = 0;
    for(;  biggest >= 1; l++)
       biggest=biggest/10;


    for (int y = 0; y < 4; y++)
    {
        for (int i=0; i<=2; i++)
            cout << endl;
        cout << "     ";
        for (int x = 0; x < 4; x++)
        {
            cout << tab[x][y].w;

            b = tab[x][y].w;
            for(a = 0;  b >= 1; a++)
                b=b/10;

            //cout << a;

            for (int i=0; i<=5-a; i++)
                cout <<" ";
            if (tab[x][y].w != 0)
                cout <<" ";
        }
    }
    cout << endl << endl;
    sprawdz();
    cout <<" Sterowanie: \n W - gora \n S - dol \n A - lewo \n D - prawo \n R - reset \n";
    ruch();
}

void ruch()
{
    Op porusz;
    //porusz.skyr(tab);
    char znak = /*pox[0][0]+y[0][0]*/porusz.skyr(tab);//getch();
    int k = 0;
    switch (znak)
    {
    case 'w':
        for (int x = 0; x < 4 ; x++) //wszystkie X
        {
            for (int y = 0; y < 3; y++) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(tab[x][y].w == 0)
                {
                    if (tab[x][y+1].w != 0)
                        {
                            tab[x][y].w = tab[x][y+1].w;
                            tab[x][y+1].w = 0;
                            k++;
                        }
                    else if( tab[x][y+2].w != 0 && y < 2)
                        {
                            tab[x][y].w = tab[x][y+2].w;
                            tab[x][y+2].w = 0;
                            k++;
                        }
                    else if( tab[x][y+3].w != 0 && y < 1)
                    {
                        tab[x][y].w = tab[x][y+3].w;
                        tab[x][y+3].w = 0;
                        k++;
                    }
                }

                if (tab[x][y].w != 0)
                {
                    if (tab[x][y].w == tab[x][y+1].w) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y+1].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y].w == tab[x][y+2].w && tab[x][y+1].w == 0 && tab[x][y+2].w != 0 && y < 2)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y+2].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y].w == tab[x][y+3].w && tab[x][y+1].w == 0 && tab[x][y+2].w == 0 && tab[x][y+3].w != 0 && y < 1)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y+3].w = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y].w == 0)
                {
                    if (tab[x][y+1].w != 0)
                        {
                            tab[x][y].w = tab[x][y+1].w;
                            tab[x][y+1].w = 0;
                            k++;
                        }
                    else if( tab[x][y+2].w != 0 && y < 2)
                        {
                            tab[x][y].w = tab[x][y+2].w;
                            tab[x][y+2].w = 0;
                            k++;
                        }
                    else if( tab[x][y+3].w != 0 && y < 1)
                    {
                        tab[x][y].w = tab[x][y+3].w;
                        tab[x][y+3].w = 0;
                        k++;
                    }
                    else
                    {
                        //cout << "Brak ruchu";
                        //getchar();
                        //getchar();
                        //ruch();
                    }
                }
            }
        }

        if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj();
            ruch();
        }

        break;


    case 's':
        for (int x = 0; x < 4 ; x++) //wszystkie X
            for (int y = 3; y > 0; y--) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(tab[x][y].w == 0)
                {
                    if (tab[x][y-1].w != 0)
                        {
                            tab[x][y].w = tab[x][y-1].w;
                            tab[x][y-1].w = 0;
                            k++;
                        }
                    else if( tab[x][y-2].w != 0 && y > 1)
                        {
                            tab[x][y].w = tab[x][y-2].w;
                            tab[x][y-2].w = 0;
                            k++;
                        }
                    else if( tab[x][y-3].w != 0 && y > 2)
                    {
                        tab[x][y].w = tab[x][y-3].w;
                        tab[x][y-3].w = 0;
                        k++;
                    }
                }

                if (tab[x][y].w != 0)
                {
                    if (tab[x][y].w == tab[x][y-1].w) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y-1].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y].w == tab[x][y-2].w && tab[x][y-1].w == 0 && y > 1)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y-2].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y].w == tab[x][y-3].w && tab[x][y-1].w == 0 && tab[x][y-2].w == 0 && y > 2)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x][y-3].w = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y].w == 0)
                {
                    if (tab[x][y-1].w != 0)
                        {
                            tab[x][y].w = tab[x][y-1].w;
                            tab[x][y-1].w = 0;
                            k++;
                        }
                    else if( tab[x][y-2].w != 0 && y > 1)
                        {
                            tab[x][y].w = tab[x][y-2].w;
                            tab[x][y-2].w = 0;
                            k++;
                        }
                    else if( tab[x][y-3].w != 0 && y > 2)
                    {
                        tab[x][y].w = tab[x][y-3].w;
                        tab[x][y-3].w = 0;
                        k++;
                    }
                    else
                    {

                    }
                }
            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj();
            ruch();
        }

        break;


    case 'a':
        for (int x = 0; x < 3 ; x++)
            for (int y = 0; y < 4; y++)
            {
                if(tab[x][y].w == 0)
                {
                    if (tab[x+1][y].w != 0)
                        {
                            tab[x][y].w = tab[x+1][y].w;
                            tab[x+1][y].w = 0;
                            k++;
                        }
                    else if( tab[x+2][y].w != 0 && x < 2)
                        {
                            tab[x][y].w = tab[x+2][y].w;
                            tab[x+2][y].w = 0;
                            k++;
                        }
                    else if( tab[x+3][y].w != 0 && x < 1)
                    {
                        tab[x][y].w = tab[x+3][y].w;
                        tab[x+3][y].w = 0;
                        k++;
                    }
                }

                if (tab[x][y].w != 0)
                {
                    if (tab[x][y].w == tab[x+1][y].w) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x+1][y].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y].w == tab[x+2][y].w && tab[x+1][y].w == 0 && tab[x+2][y].w != 0 && x < 2)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x+2][y].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y].w == tab[x+3][y].w && tab[x+1][y].w == 0 && tab[x+2][y].w == 0 && tab[x+3][y].w != 0 && x < 1)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x+3][y].w = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y].w == 0)
                {
                    if (tab[x+1][y].w != 0)
                        {
                            tab[x][y].w = tab[x+1][y].w;
                            tab[x+1][y].w = 0;
                            k++;
                        }
                    else if( tab[x+2][y].w != 0 && x < 2)
                        {
                            tab[x][y].w = tab[x+2][y].w;
                            tab[x+2][y].w = 0;
                            k++;
                        }
                    else if( tab[x+3][y].w != 0 && x < 1)
                    {
                        tab[x][y].w = tab[x+3][y].w;
                        tab[x+3][y].w = 0;
                        k++;
                    }
                    else
                    {

                    }
                }
            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj();
            ruch();
        }
        break;


    case 'd':
        for (int x = 3; x > 0 ; x--)
            for (int y = 0; y < 4; y++)
            {
                if(tab[x][y].w == 0)
                {
                    if (tab[x-1][y].w != 0)
                        {
                            tab[x][y].w = tab[x-1][y].w;
                            tab[x-1][y].w = 0;
                            k++;
                        }
                    else if( tab[x-2][y].w != 0 && x > 1)
                        {
                            tab[x][y].w = tab[x-2][y].w;
                            tab[x-2][y].w = 0;
                            k++;
                        }
                    else if( tab[x-3][y].w != 0 && x > 2)
                    {
                        tab[x][y].w = tab[x-3][y].w;
                        tab[x-3][y].w = 0;
                        k++;
                    }
                }

                if (tab[x][y].w != 0)
                {
                    if (tab[x][y].w == tab[x-1][y].w) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x-1][y].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y].w == tab[x-2][y].w && tab[x-1][y].w == 0 && x > 1)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x-2][y].w = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y].w == tab[x-3][y].w && tab[x-1][y].w == 0 && tab[x-2][y].w == 0 && x > 2)
                    {
                        tab[x][y].w = 2 * tab[x][y].w;
                        tab[x-3][y].w = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y].w == 0)
                {
                    if (tab[x-1][y].w != 0)
                        {
                            tab[x][y].w = tab[x-1][y].w;
                            tab[x-1][y].w = 0;
                            k++;
                        }
                    else if( tab[x-2][y].w != 0 && x > 1)
                        {
                            tab[x][y].w = tab[x-2][y].w;
                            tab[x-2][y].w = 0;
                            k++;
                        }
                    else if( tab[x-3][y].w != 0 && x > 2)
                    {
                        tab[x][y].w = tab[x-3][y].w;
                        tab[x-3][y].w = 0;
                        k++;
                    }
                    else
                    {

                    }
                }

            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj();
            ruch();
        }
        break;

    case 'r':
        cout << "Jezeli na pewno chcesz zresetowac wcisnij T: ";
        char reset;
        reset = getch();
        if (reset == 't' || reset == 'T')
        {
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<4; j++)
                {
                    tab[j][i].w = 0;
                }
            }
        tablica();
        }
        else
        {
            generuj();
        }
        break;


    default:
        cout << "Zly znak, podaj jeszcze raz " << endl;
        ruch();
    }
    tablica();
}

void sprawdz()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
            if (tab[x][y].w == 0)
                goto Koniec;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (tab[x][y].w == tab[x+1][y].w && x < 3)
                goto Koniec;
            else if (tab[x][y].w == tab[x][y+1].w && y < 3)
                goto Koniec;
        }
    }

    cout << "Koniec gry" << endl << "Aby zagrac jeszcze raz nacisnij T ";
    char znak;// = getch();
    znak = getch();
    switch (znak)
    {
    case 't' || 'T':
        srand(time(NULL));
        //Inicjacja tablicy
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                tab[j][i].w = 0;
            }
        }
    tablica();
        break;

    default:
        exit(0);
    }

    Koniec:
        cout<<"";
}


