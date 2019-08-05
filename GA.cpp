#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include "GA.h"
using namespace std;

void Sort();

long double mut(long double n);

long double cross(long double a, long double b);

long double funkcja(long double x, long double y);

void ruh(unsigned int i, unsigned int q);

void generuj(unsigned int t);

void sprawdz();

void tablica(unsigned int i, unsigned int q);

//void ruh(unsigned int i, unsigned int q);

void cross(unsigned int a, unsigned int b, unsigned int c);

bool mut(bool ne);

unsigned int k = 2;   // długość genu
unsigned int n = 3;   // ile osobników
int how = 500;   // ile generacji
unsigned int ztab[4][4][20];
int score[20];
bool x[20][10], y[20][10]; //serien[nr_tablicy][ciag]

char Op::skyr(Tablica tab[4][4])
{
    for (int i=0; i < k; i++)
    {
        for (int j=0; j <= 3; j++)
        {
            for (int l=0; l <= 3; l++)
            {
                ztab[j][l][i] = tab[j][l].w;
            }
        }
    }


    for(int i = 0; i < k; i++)
        score[i] = 0;

    srand(time(NULL));
    for (int i=0; i < k; i++)
    {
        for (int j = 0; j < n ;j++)
        {
            x[j][i] = rand()%2;
            //cout << x[j][i] << endl;
            y[j][i] = rand()%2;
            //cout << y[j][i] << endl;

            unsigned int f = x[j][i] + (2*y[j][i]);
            ruh(i, f);
        }


        //for (int j = 0; j <= k-1; j++)
        //{
        //    for (int r1 = 0; r1 < 4; r1++)
        //    {
        //        for (int r2 = 0; r2 < 4; r2++)
        //        {
        //            score[i] += log2(ztab[r1][r2][i]);
        //        }
        //    }
        //}
    }



    for(int i = 0; i < how; i++)
    {
        Sort();


        for(int j = k/2; j <= n-1 ; j++)
        {
            int t1 = rand()%(n/2);
            int t2 = rand()%(n/2);
            cross(t1,t2,j);
        }

    }

    Sort();
    char znak;

    if (x[0][0]+(2*y[0][0])==0) znak = 'w';
    if (x[0][0]+(2*y[0][0])==1) znak = 's';
    if (x[0][0]+(2*y[0][0])==2) znak = 'a';
    if (x[0][0]+(2*y[0][0])==3) znak = 'd';
    //cout << " " << znak << " ";
    //getchar();
    return znak;
}

void generuj(unsigned int t, unsigned int q)
{
    /*int a, b;
    //system ("cls");

    //cout << " Gra 2048 \n ";


    int biggest = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if(ztab[x][y][t] > biggest)
                {
                    biggest = ztab[x][y][t];
                }
        }
    }
    //int l = 0;
    //for(;  biggest >= 1; l++)
    //   biggest=biggest/10;


    for (int y = 0; y < 4; y++)
    {
        //for (int i=0; i<=2; i++)
            //cout << endl;
        //cout << "     ";
        for (int x = 0; x < 4; x++)
        {
            //cout << ztab[x][y][t];

            b = ztab[x][y][t];
            for(a = 0;  b >= 1; a++)
                b=b/10;

            //cout << a;

            //for (int i=0; i<=5-a; i++)
            //    cout <<"";
            //if (ztab[x][y][t] != 0)
            //    cout <<"";
        }
    }
    //cout << "";//endl << endl;
    //sprawdz();
    //cout <<" Sterowanie: \n W - gora \n S - dol \n A - lewo \n D - prawo \n R - reset \n";
    */
    ruh(t, q);
}

void ruh(unsigned int i, unsigned int q)
{
    char znak;
    if (q==0) znak = 'w';
    else if (q==1) znak = 's';
    else if (q==2) znak = 'a';
    else if (q==3) znak = 'd';
    int p = 0;
    switch (znak)
    {
    case 'w':
        for (int x = 0; x < 4 ; x++) //wszystkie X
        {
            for (int y = 0; y < 3; y++) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(ztab[x][y][i] == 0)
                {
                    if (ztab[x][y+1][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x][y+1][i];
                            ztab[x][y+1][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y+2][i] != 0 && y < 2)
                        {
                            ztab[x][y][i] = ztab[x][y+2][i];
                            ztab[x][y+2][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y+3][i] != 0 && y < 1)
                    {
                        ztab[x][y][i] = ztab[x][y+3][i];
                        ztab[x][y+3][i] = 0;
                        p++;
                    }
                }

                if (ztab[x][y][i] != 0)
                {
                    if (ztab[x][y][i] == ztab[x][y+1][i]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y+1][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(ztab[x][y][i] == ztab[x][y+2][i] && ztab[x][y+1][i] == 0 && ztab[x][y+2][i] != 0 && y < 2)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y+2][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(ztab[x][y][i] == ztab[x][y+3][i] && ztab[x][y+1][i] == 0 && ztab[x][y+2][i] == 0 && ztab[x][y+3][i] != 0 && y < 1)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y+3][i] = 0;
                        p++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(ztab[x][y][i] == 0)
                {
                    if (ztab[x][y+1][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x][y+1][i];
                            ztab[x][y+1][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y+2][i] != 0 && y < 2)
                        {
                            ztab[x][y][i] = ztab[x][y+2][i];
                            ztab[x][y+2][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y+3][i] != 0 && y < 1)
                    {
                        ztab[x][y][i] = ztab[x][y+3][i];
                        ztab[x][y+3][i] = 0;
                        p++;
                    }
                    else
                    {
                        //cout << "Brak ruchu";
                    }
                }
            }
        }

        if (p >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<p;
            //getchar();
            //getchar();
            //generuj(i, q);
        }

        break;


    case 's':
        for (int x = 0; x < 4 ; x++) //wszystkie X
            for (int y = 3; y > 0; y--) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(ztab[x][y][i] == 0)
                {
                    if (ztab[x][y-1][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x][y-1][i];
                            ztab[x][y-1][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y-2][i] != 0 && y > 1)
                        {
                            ztab[x][y][i] = ztab[x][y-2][i];
                            ztab[x][y-2][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y-3][i] != 0 && y > 2)
                    {
                        ztab[x][y][i] = ztab[x][y-3][i];
                        ztab[x][y-3][i] = 0;
                        p++;
                    }
                }

                if (ztab[x][y][i] != 0)
                {
                    if (ztab[x][y][i] == ztab[x][y-1][i]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y-1][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(ztab[x][y][i] == ztab[x][y-2][i] && ztab[x][y-1][i] == 0 && y > 1)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y-2][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(ztab[x][y][i] == ztab[x][y-3][i] && ztab[x][y-1][i] == 0 && ztab[x][y-2][i] == 0 && y > 2)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x][y-3][i] = 0;
                        p++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(ztab[x][y][i] == 0)
                {
                    if (ztab[x][y-1][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x][y-1][i];
                            ztab[x][y-1][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y-2][i] != 0 && y > 1)
                        {
                            ztab[x][y][i] = ztab[x][y-2][i];
                            ztab[x][y-2][i] = 0;
                            p++;
                        }
                    else if( ztab[x][y-3][i] != 0 && y > 2)
                    {
                        ztab[x][y][i] = ztab[x][y-3][i];
                        ztab[x][y-3][i] = 0;
                        p++;
                    }
                }
            }
            //if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        //else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj(i, q);
        }

        break;


    case 'a':
        for (int x = 0; x < 3 ; x++)
            for (int y = 0; y < 4; y++)
            {
                if(ztab[x][y][i] == 0)
                {
                    if (ztab[x+1][y][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x+1][y][i];
                            ztab[x+1][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x+2][y][i] != 0 && x < 2)
                        {
                            ztab[x][y][i] = ztab[x+2][y][i];
                            ztab[x+2][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x+3][y][i] != 0 && x < 1)
                    {
                        ztab[x][y][i] = ztab[x+3][y][i];
                        ztab[x+3][y][i] = 0;
                        p++;
                    }
                }

                if (ztab[x][y][i] != 0)
                {
                    if (ztab[x][y][i] == ztab[x+1][y][i]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x+1][y][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(ztab[x][y][i] == ztab[x+2][y][i] && ztab[x+1][y][i] == 0 && ztab[x+2][y][i] != 0 && x < 2)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x+2][y][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(ztab[x][y][i] == ztab[x+3][y][i] && ztab[x+1][y][i] == 0 && ztab[x+2][y][i] == 0 && ztab[x+3][y][i] != 0 && x < 1)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x+3][y][i] = 0;
                        p++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(ztab[x][y][i] == 0)
                {
                    if (ztab[x+1][y][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x+1][y][i];
                            ztab[x+1][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x+2][y][i] != 0 && x < 2)
                        {
                            ztab[x][y][i] = ztab[x+2][y][i];
                            ztab[x+2][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x+3][y][i] != 0 && x < 1)
                    {
                        ztab[x][y][i] = ztab[x+3][y][i];
                        ztab[x+3][y][i] = 0;
                        p++;
                    }
                }
            }
            if (p >= 1)
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
            //generuj(i, q);
        }
        break;


    case 'd':
        for (int x = 3; x > 0 ; x--)
            for (int y = 0; y < 4; y++)
            {
                if(ztab[x][y][i] == 0)
                {
                    if (ztab[x-1][y][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x-1][y][i];
                            ztab[x-1][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x-2][y][i] != 0 && x > 1)
                        {
                            ztab[x][y][i] = ztab[x-2][y][i];
                            ztab[x-2][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x-3][y][i] != 0 && x > 2)
                    {
                        ztab[x][y][i] = ztab[x-3][y][i];
                        ztab[x-3][y][i] = 0;
                        p++;
                    }
                }

                if (ztab[x][y][i] != 0)
                {
                    if (ztab[x][y][i] == ztab[x-1][y][i]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x-1][y][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(ztab[x][y][i] == ztab[x-2][y][i] && ztab[x-1][y][i] == 0 && x > 1)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x-2][y][i] = 0;
                        p++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(ztab[x][y][i] == ztab[x-3][y][i] && ztab[x-1][y][i] == 0 && ztab[x-2][y][i] == 0 && x > 2)
                    {
                        ztab[x][y][i] = 2 * ztab[x][y][i];
                        ztab[x-3][y][i] = 0;
                        p++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(ztab[x][y][i] == 0)
                {
                    if (ztab[x-1][y][i] != 0)
                        {
                            ztab[x][y][i] = ztab[x-1][y][i];
                            ztab[x-1][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x-2][y][i] != 0 && x > 1)
                        {
                            ztab[x][y][i] = ztab[x-2][y][i];
                            ztab[x-2][y][i] = 0;
                            p++;
                        }
                    else if( ztab[x-3][y][i] != 0 && x > 2)
                    {
                        ztab[x][y][i] = ztab[x-3][y][i];
                        ztab[x-3][y][i] = 0;
                        p++;
                    }
                }

            }
            //if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        //else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            //generuj(i, q);
        }
        break;

    default:
        cout << "Zly znak, podaj jeszcze raz " << endl;
        ruh(i, q);
    }
    tablica(i, q);
}

void sprawdz(unsigned int m)
{
    /*
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
            if (ztab[x][y][m] == 0)
                goto Koniec;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (ztab[x][y][m] == ztab[x+1][y][m] && x < 3)
                goto Koniec;
            else if (ztab[x][y][m] == ztab[x][y+1][m] && y < 3)
                goto Koniec;
        }
    }

    cout<<"";


    //cout << "Koniec gry" << endl << "Aby zagrac jeszcze raz nacisnij T ";
    /*char znak;// = getch();
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
                ztab[j][i][m] = 0;
            }
        }
    tablica(m, 1);
        break;

    default:
        exit(0);
    }*/

    //Koniec:
        cout<<"";
}


void tablica(unsigned int i, unsigned int q)
{
    int a, b, c, d;

    d = 0;

    for (;d == 0;)
    {
        a = rand()%4;
        b = rand()%4;
        c = rand()%2;
        if(ztab[a][b][i]==0)
        {   //do usunięcia
            ztab[a][b][i] = (c+1)*2;
            d = 1;
        }
    }
    //generuj(i, q);
}

void Sort()
{
    for(int i = 0; i < n; i++)
    {
        score[i] = 0;
    }


    for (int i = 0; i < n; i++)
        {
            for (int r1 = 0; r1 < 4; r1++)
            {
                for (int r2 = 0; r2 < 4; r2++)
                {
                    score[i] += ((log2(ztab[r1][r2][i])));//*(log2(ztab[r1][r2][i])));
                    if(ztab[r1][r2][i]==0)
                        score[i] *= score[i]*score[i];
                }
            }
        }

    //------------------------


    for (int i=0; i < n; i++)
    {
        unsigned int mini = score[i];
        bool buf1, buf2, buf3, mini2, mini3;
        int m=i;
        for (int j = i; j < k; j++)
        {
            if (mini > score[j])
            {
                mini = score[j];
                m = j;
            }
        }
        buf1 = score [i];
        score[i] = mini;
        score[m] = buf1;
        for (int j=0; j < k; j++)
        {
            buf2 = x[i][j];
            x[i][j] = x[m][j];
            x[m][j] = buf2;

            buf3 = y[i][j];
            y[i][j] = y[m][j];
            y[m][j] = buf3;
        }
        //cout<<tabx[i]<<"\t"<<taby[i]<<"\t"<<fit[i]<<endl;
    }

    //for(int i = 0; i< 3; i++)
    //{
        //cout<<tabx[i]<<"\t"<<taby[i]<<"\t"<<fit[i]<<endl;// = funkcja(tabx[i], taby[i]);

    //}
    //plik << fit[0] <<endl;
    //plik.close();
    //cout<<tabx[0]<<"\t"<<taby[0]<<"\t"<<fit[0]<<endl;

}

bool mut(bool ne)
{
    int hop = rand()%(k*10);
    if(hop == 0)
    {
        if(ne==0)
            return 1;
        else
            return 0;
    }
    else
        return ne;
}

void cross(unsigned int a, unsigned int b, unsigned int c)
//(pierwszy argument, drugi argument, końcowy argument)
{
    int t = rand()%(n);
    for (int i=0; i < t; i++)
    {
        x[c][i]=mut(x[a][i]);
        y[c][i]=mut(y[a][i]);
    }

    for (int i=t; i<k; i++)
    {
        x[c][i]=mut(x[b][i]);
        y[c][i]=mut(y[b][i]);
    }

}










