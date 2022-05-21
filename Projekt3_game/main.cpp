#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


bool win(int warunek, int tura, int rozmiar, char **board)
{
    int ile=0;

    if(tura % 2 == 0)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'o')
                    {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            l++;
                            if(l >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa o" << endl;
                                return true;
                            }
                        else
                            ile=0;

                        // //Sprawdzenie pionowo
                        k=i;
                        l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa o" << endl;
                                return true;
                            }
                        else
                            ile=0;


                        // //Sprawdzenie ukos "\"
                        k=i;
                        l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                            l++;
                            if(l >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa o" << endl;
                                return true;
                            }
                        else
                            ile=0;

                        // //Sprawdzenie ukos "/"
                        k=i;
                        l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                            l--;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa o" << endl;
                                return true;
                            }
                        else
                            ile=0;

                    }
            }
            
        }
        
    }
    else
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'x')
                    {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            l++;
                            if(l >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa x" << endl;
                                return true;
                            }
                        else
                            ile=0;

                        // //Sprawdzenie pionowo
                        k=i;
                        l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa x" << endl;
                                return true;
                            }
                        else
                            ile=0;


                        // //Sprawdzenie ukos "\"
                        k=i;
                        l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                            l++;
                            if(l >= rozmiar)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa x" << endl;
                                return true;
                            }
                        else
                            ile=0;

                        // //Sprawdzenie ukos "/"
                        k=i;
                        l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            if(k >= rozmiar)
                                break;
                            l--;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek)
                            {
                                cout << "Wygrywa x" << endl;
                                return true;
                            }
                        else
                            ile=0;

                    }
            }
            
        }
        
    }

    return false;
}

void draw_board(int rozmiar, char **board) //rysuje plansze wraz z oznaczeniami
{
    for(int i = 0; i < rozmiar; i++)
        {
            for(int j = 0; j < rozmiar; j++)
            { 
                if(j == rozmiar - 1)
                    cout<< " " << board[i][j] << "  " << endl;
                else
                    cout<< " " << board[i][j] << " |";
            
            }

            if(i != rozmiar - 1)
            for(int j = 0; j < rozmiar; j++)
            {
                 if(j == rozmiar - 1)
                    cout << "--- " << endl;
                else
                    cout << "--- " ;
            
            }
        }

}

void prepare_board( int rozmiar, char **board)
{
    for(int i=0; i<rozmiar; i++)
        for(int j=0; j<rozmiar; j++)
        {
            board[i][j] = ' ';
        }
}

bool czy_AI_win(int warunek, int tura, int rozmiar, char **board)
{
    int ile = 0;

    if(tura % 2 != 0)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'x')
                    {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        int luka;
                        int dalej;
                        while(l < rozmiar && board[k][l] == 'x') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=l+1;
                            dalej=l+2;
                            if(luka < rozmiar && board[k][luka] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[k][dalej] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k][luka]='x';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            l++;
                        }
                        if(ile == warunek - 1)  
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    board[i][j-1] = 'x';
                                    return true;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        board[i][l] = 'x';
                                        return true;
                                    }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        luka=0;
                        dalej=0;
                        while(k < rozmiar && board[k][l] == 'x') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=k+1;
                            dalej=k+2;
                            if(luka < rozmiar && board[luka][l] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[dalej][l] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[luka][l]='x';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            k++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                        }
                        if(ile == warunek - 1)  //czy tutaj nie "warunek"
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    board[i-1][j] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                       board[k][j] = 'x'; 
                                       return true;
                                    }
                        else    
                            ile=0;

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'x') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l + 1 < rozmiar && board[k+1][l+1] == ' ') //mamy luke do zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l + 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 < rozmiar && board[dalej1][dalej2] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l+1]='x';
                                        return 0;
                                    }
                                    dalej1++;
                                    dalej2++;
                                }
                            }
                            k++;
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    board[i-1][j-1] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'x';
                                    return true;
                                }
                        else
                            ile=0;

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l >= 0 && board[k][l] == 'x') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l - 1 >= 0 && board[k+1][l-1] == ' ') //mamy luke to zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l - 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 >= 0 && board[dalej1][dalej2] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l-1]='x';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2--;
                                }
                            }
                            k++;
                            l--;
                        }
                        ile=0;
                        k=i;
                        l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l--;
                            if(k >= rozmiar)
                                break;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    board[i-1][j+1] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'x';
                                    return true;
                                }
                        else
                            ile=0;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'o')
                {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        int luka;
                        int dalej;
                        while(l < rozmiar && board[k][l] == 'o') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=l+1;
                            dalej=l+2;
                            if(luka < rozmiar && board[k][luka] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[k][dalej] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k][luka]='o';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            l++;
                        }
                        if(ile == warunek - 1)  
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    board[i][j-1] = 'o';
                                    return true;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        board[i][l] = 'o';
                                        return true;
                                    }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        luka=0;
                        dalej=0;
                        while(k < rozmiar && board[k][l] == 'o') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=k+1;
                            dalej=k+2;
                            if(luka < rozmiar && board[luka][l] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[dalej][l] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[luka][l]='o';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            k++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                        }
                        if(ile == warunek - 1)  //czy tutaj nie "warunek"
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    board[i-1][j] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                       board[k][j] = 'o'; 
                                       return true;
                                    }
                        else    
                            ile=0;

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'o') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l + 1 < rozmiar && board[k+1][l+1] == ' ') //mamy luke do zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l + 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 < rozmiar && board[dalej1][dalej2] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l+1]='o';
                                        return 0;
                                    }
                                    dalej1++;
                                    dalej2++;
                                }
                            }
                            k++;
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    board[i-1][j-1] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'o';
                                    return true;
                                }
                        else
                            ile=0;

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l >= 0 && board[k][l] == 'o') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l - 1 >= 0 && board[k+1][l-1] == ' ') //mamy luke to zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l - 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 >= 0 && board[dalej1][dalej2] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l-1]='o';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2--;
                                }
                            }
                            k++;
                            l--;
                        }
                        ile=0;
                        k=i;
                        l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l--;
                            if(k >= rozmiar)
                                break;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    board[i-1][j+1] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'o';
                                    return true;
                                }
                        else
                            ile=0;
                }
            }
        }
    }
    return false;
}

void Pick_Ai(int warunek, int tura, int rozmiar, char **board)
{
    cout<<"wybor"<<endl;
    int wiersz = rand() % rozmiar;
    int kolumna = rand() % rozmiar;
    
    if(board[wiersz][kolumna] == ' ')
    {
        if(tura % 2 == 0)
            board[wiersz][kolumna]='o';

        if(tura % 2 != 0)
            board[wiersz][kolumna]='x';    
    }
    else
    {
        cout<<"zajete"<<endl<<endl;
        Pick_Ai(warunek, tura, rozmiar, board);
    }

}

void Pick_Ai_2(int warunek, int tura, int rozmiar, char **board, int *koniec_ciagu)
{
    cout<<"wybor"<<endl;
    int wiersz = rand() % rozmiar;
    int kolumna = rand() % rozmiar;

    int srodek = rozmiar/2;

    if (board[srodek][srodek] == ' ')
        {   
            wiersz=srodek;
            kolumna=srodek;
        }   
    
    if(koniec_ciagu[0] != -1 && koniec_ciagu[1] != -1)
    {
        wiersz=koniec_ciagu[0];
        kolumna=koniec_ciagu[1];
    }

    if(board[wiersz][kolumna] == ' ')
    {
        if(tura % 2 == 0)
            board[wiersz][kolumna]='o';

        if(tura % 2 != 0)
            board[wiersz][kolumna]='x';    
    }
    else
    {
        cout<<"zajete"<<endl<<endl;
        Pick_Ai(warunek, tura, rozmiar, board);
    }

}

bool Block(int warunek, int tura, int rozmiar, char **board)
{
    int ile = 0;

    if(tura % 2 != 0)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'o')
                    {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        int luka;
                        int dalej;
                        while(l < rozmiar && board[k][l] == 'o') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=l+1;
                            dalej=l+2;
                            if(luka < rozmiar && board[k][luka] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[k][dalej] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k][luka]='x';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            l++;
                        }
                        if(ile == warunek - 1)  
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    board[i][j-1] = 'x';
                                    return true;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        board[i][l] = 'x';
                                        return true;
                                    }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        luka=0;
                        dalej=0;
                        while(k < rozmiar && board[k][l] == 'o') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=k+1;
                            dalej=k+2;
                            if(luka < rozmiar && board[luka][l] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[dalej][l] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[luka][l]='x';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            k++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                        }
                        if(ile == warunek - 1)  //czy tutaj nie "warunek"
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    board[i-1][j] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                       board[k][j] = 'x'; 
                                       return true;
                                    }
                        else    
                            ile=0;

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'o') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l + 1 < rozmiar && board[k+1][l+1] == ' ') //mamy luke do zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l + 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 < rozmiar && board[dalej1][dalej2] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l+1]='x';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2++;
                                }
                            }
                            k++;
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    board[i-1][j-1] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'x';
                                    return true;
                                }
                        else
                            ile=0;

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l >= 0 && board[k][l] == 'o') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l - 1 >= 0 && board[k+1][l-1] == ' ') //mamy luke to zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l - 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 >= 0 && board[dalej1][dalej2] == 'o') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l-1]='x';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2--;
                                }
                            }
                            k++;
                            l--;
                        }
                        ile=0;
                        k=i;
                        l=j;
                        while(board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l--;
                            if(k >= rozmiar)
                                break;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    board[i-1][j+1] = 'x';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'x';
                                    return true;
                                }
                        else
                            ile=0;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'x')
                {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        int luka;
                        int dalej;
                        while(l < rozmiar && board[k][l] == 'x') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=l+1;
                            dalej=l+2;
                            if(luka < rozmiar && board[k][luka] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[k][dalej] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k][luka]='o';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            l++;
                        }
                        if(ile == warunek - 1)  
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    board[i][j-1] = 'o';
                                    return true;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        board[i][l] = 'o';
                                        return true;
                                    }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        luka=0;
                        dalej=0;
                        while(k < rozmiar && board[k][l] == 'x') //o_o
                        {
                            ile++; //mamy 1 z warunku
                            luka=k+1;
                            dalej=k+2;
                            if(luka < rozmiar && board[luka][l] == ' ') //mamy luke to zapelnienia 
                            {   
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej < rozmiar && board[dalej][l] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {   
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[luka][l]='o';
                                        return true;
                                    }
                                    dalej++;
                                }
                            }
                            k++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                        }
                        if(ile == warunek - 1)  //czy tutaj nie "warunek"
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    board[i-1][j] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                       board[k][j] = 'o'; 
                                       return true;
                                    }
                        else    
                            ile=0;

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'x') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l + 1 < rozmiar && board[k+1][l+1] == ' ') //mamy luke do zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l + 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 < rozmiar && board[dalej1][dalej2] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l+1]='o';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2++;
                                }
                            }
                            k++;
                            l++;
                        }

                        ile=0;
                        k=i;
                        l=j;
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    board[i-1][j-1] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'o';
                                    return true;
                                }
                        else
                            ile=0;

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l >= 0 && board[k][l] == 'x') 
                        {
                            ile++; //mamy 1 z warunku
                            if(k + 1 < rozmiar && l - 1 >= 0 && board[k+1][l-1] == ' ') //mamy luke to zapelnienia 
                            {
                                int dalej1 = k + 2;
                                int dalej2 = l - 2;
                                ile++; //mamy luke do wstawienia gdy daje zwyciestwo
                                while(dalej1 < rozmiar && dalej2 >= 0 && board[dalej1][dalej2] == 'x') //sprawdzamy czy dalej mamy znaki 
                                {
                                    ile++;
                                    if(ile == warunek)  //uzupelnij luke
                                    {
                                        board[k+1][l-1]='o';
                                        return true;
                                    }
                                    dalej1++;
                                    dalej2--;
                                }
                            }
                            k++;
                            l--;
                        }
                        ile=0;
                        k=i;
                        l=j;
                        while(board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l--;
                            if(k >= rozmiar)
                                break;
                            if(l < 0)
                                break;
                        }
                        if(ile == warunek - 1)
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    board[i-1][j+1] = 'o';
                                    return true;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    board[k][l] = 'o';
                                    return true;
                                }
                        else
                            ile=0;
                }
            }
        }
    }
    return false;
}

int * Connect(int warunek, int tura, int rozmiar, char **board, int *koniec_ciagu)
{
    int ile = 0;
    int max=0;

    if(tura % 2 == 0)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'o')
                    {
                        int k=i;
                        int l=j;

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile >= max)
                        {
                            max=ile;
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j-1;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    koniec_ciagu[0]=k;
                                    koniec_ciagu[1]=l;
                                }
                        }

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l>=0 && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                            l--;
                        }
                        if(ile >=max)
                        {
                            max=ile;
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j+1;
                                }
                            else
                                if(k < rozmiar && l >= 0 && board[k][l] == ' ')
                                {
                                    koniec_ciagu[0]=k;
                                    koniec_ciagu[1]=l;
                                }
                        }

                        //Sprawdzenie poziomo
                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            l++;
                        }
                        if(ile >= max) 
                        { 
                            max=ile; 
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    koniec_ciagu[0]=i;
                                    koniec_ciagu[1]=j-1;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        koniec_ciagu[0]=i;
                                        koniec_ciagu[1]=l;
                                    }
                        }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        while(k < rozmiar && board[k][l] == 'o')
                        {
                            ile++;
                            k++;
                        }
                        if(ile >= max)  //czy tutaj nie "warunek"
                        {   
                            max=ile;
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                        koniec_ciagu[0]=k;
                                        koniec_ciagu[1]=j;
                                    }
                        }

                        
                    }
            }
        }
    }
    else
    {
        for (int i = 0; i < rozmiar; i++)
        {
            for (int j = 0; j < rozmiar; j++)
            {
                if(board[i][j] == 'x')
                    {
                        //Sprawdzenie poziomo
                        int k=i;
                        int l=j;
                        max=0;
                        ile=0;
                        k=i;
                        l=j;
                        while(l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            l++;
                        }
                        if(ile >= max) 
                        { 
                            max=ile; 
                            if(j - 1 >= 0 && board[i][j-1] == ' ')  //_oo
                                {
                                    koniec_ciagu[0]=i;
                                    koniec_ciagu[1]=j-1;
                                }
                            else
                                if(l < rozmiar && board[i][l] == ' ')   //oo_
                                    {
                                        koniec_ciagu[0]=i;
                                        koniec_ciagu[1]=l;
                                    }
                        }
                        else
                            ile=0;

                        //Sprawdzenie pionowo
                        k=i;                        //o
                        l=j;                        //_ 
                        ile=0;                      //o
                        while(k < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                        }
                        if(ile >= max)  //czy tutaj nie "warunek"
                        {   
                            max=ile;
                            if(i - 1 >= 0 && board[i-1][j] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j;
                                }
                            else
                                if(k < rozmiar && board[k][j] == ' ')
                                    {
                                        koniec_ciagu[0]=k;
                                        koniec_ciagu[1]=j;
                                    }
                        }

                        //Sprawdzenie ukos "\"
                        ile=0;                 //o
                        k=i;                   //   _
                        l=j;                   //       o
                        while(k < rozmiar && l < rozmiar && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l++;
                        }
                        if(ile >= max)
                        {
                            max=ile;
                            if(i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j-1;
                                }
                            else
                                if(k < rozmiar && l < rozmiar && board[k][l] == ' ')
                                {
                                    koniec_ciagu[0]=k;
                                    koniec_ciagu[1]=l;
                                }
                        }

                        //Sprawdzenie ukos "/"
                        ile=0;                  //    o
                        k=i;                    //  _
                        l=j;                    //o
                        while(k < rozmiar && l>=0 && board[k][l] == 'x')
                        {
                            ile++;
                            k++;
                            l--;
                        }
                        if(ile >=max)
                        {
                            max=ile;
                            if(i - 1 >= 0 && j + 1 < rozmiar && board[i-1][j+1] == ' ')
                                {
                                    koniec_ciagu[0]=i-1;
                                    koniec_ciagu[1]=j+1;
                                }
                            else
                                if(k < rozmiar && l >= 0 && board[k][l] == ' ')
                                {
                                    koniec_ciagu[0]=k;
                                    koniec_ciagu[1]=l;
                                }
                        }
                }
            }
        }
    }
    return koniec_ciagu;
}

int main()
{
    srand (time(NULL));
    int rozmiar = 3;
    int kolumna, wiersz, tura = 0;
    int tura_gracz, tura_ai = 0;
    int *koniec_ciagu=new int [2];
    koniec_ciagu[0]=-1;
    koniec_ciagu[1]=-1;

    cout << "Podaj rozmiar gry (liczba kolumn)" << endl;
    cin >> rozmiar;
    //rozmiar=6;


    if (rozmiar < 3)
    {
        cout << "Zly rozmiar bo mniejszy od 3" << endl;
        return 0;
    }

    int warunek;
    cout << "Podaj warunek konczacy gre (ilosc znakow)" << endl;
    cin >> warunek;
    //warunek=4;

    if (warunek > rozmiar || warunek < 1)
    {
        cout << "Zly warunek" << endl;
        return 0;
    }

    char** board = new char*[rozmiar]; //inicjaca planszy o zadanym rozmiarze
    for (int i = 0; i < rozmiar; ++i)
         board[i] = new char[rozmiar];

    prepare_board(rozmiar, board); //inicjacaj zerami

    int gracz; //wybor gracza
    do{
        cout << "Wybierz gracza 1 lub 2" << endl;
        cin >> gracz;
        //gracz=1;
        if(gracz == 2)
        {
            break;
        }
    }while(gracz != 1);

    if(gracz == 1)
    {
        tura_gracz=1;
        tura_ai=0;
    }
    else
    {
        tura_gracz=0;
        tura_ai=1;
    }

    cout << endl;   
    draw_board(rozmiar, board); // wysiwetlenei planszy
    cout << endl;

    while(tura < rozmiar*rozmiar)
    {   
        cout<<"tura "<<tura+1<<endl;
        cout << endl;

        if(tura_gracz == 1)
        {
            // wiersz = -1;  //wybor wiersza
            // while(wiersz < 0 || wiersz > rozmiar)
            // {
            //     cout << "Podaj w jakim wierszu chcesz wstawic znak?" << endl;
            //     cin >> wiersz;
            // }
        
            // kolumna = -1; //wybor kolumny
            // while(kolumna < 0 || kolumna > rozmiar)
            // {
            //     cout << "Podaj w jakiej kolumnie chcesz wstawic znak?" << endl;
            //     cin >> kolumna;
            // }

            // if(tura % 2 == 0)
            // board[wiersz][kolumna]='o';

            // if(tura % 2 != 0)
            // board[wiersz][kolumna]='x';
            
            //testownaie
            if(czy_AI_win(warunek, tura, rozmiar, board)==false)
            {
                if(Block(warunek, tura, rozmiar, board)==false)
                    {
                        koniec_ciagu=Connect(warunek, tura, rozmiar, board, koniec_ciagu);
                        Pick_Ai_2(warunek, tura, rozmiar, board, koniec_ciagu);
                    }
                else
                    cout<<"blok"<<endl;
            }
            else
            {
                //draw_board(rozmiar, board);
                cout<<endl;
                //cout<<"Wygrywa komputer"<<endl;
                //return 0;
                
            }

            //rand
            //Pick_Ai(warunek, tura, rozmiar, board);

        }

        if(tura_ai == 1)
        {
        //     cout<<"AI"<<endl;
        //     wiersz = -1;  //wybor wiersza
        //     while(wiersz < 1 || wiersz > rozmiar)
        //     {
        //         cout << "Podaj w jakim wierszu chcesz wstawic znak?" << endl;
        //         cin >> wiersz;
        //     }
        //     wiersz = wiersz - 1; //przeskalowanie na indeks tablicy
        
        //     kolumna = -1; //wybor kolumny
        //     while(kolumna < 1 || kolumna > rozmiar)
        //     {
        //         cout << "Podaj w jakiej kolumnie chcesz wstawic znak?" << endl;
        //         cin >> kolumna;
        //     }
        //     kolumna = kolumna - 1; //przeskalowanie na indeks tablicy
            
        //     //ruch AI
        //     //testowanie
        // //     wiersz = rand() % rozmiar;
        // //     kolumna = rand() % rozmiar;

        // //     cout<<"AI   wiersz   "<<wiersz<<endl;
        // //     cout<<"AI   kolumna  "<<kolumna<<endl;
        //     if(board[wiersz][kolumna] != ' ')
        //     {
        //         cout << "pole zajete" << endl;
        //     }
        //     else
        //     {
        //         if(tura % 2 == 0)
        //             board[wiersz][kolumna]='o';

        //         if(tura % 2 != 0)
        //             board[wiersz][kolumna]='x';
        //     }
        
            if(czy_AI_win(warunek, tura, rozmiar, board)==false)
            {
                if(Block(warunek, tura, rozmiar, board)==false)
                    {
                        koniec_ciagu=Connect(warunek, tura, rozmiar, board, koniec_ciagu);
                        Pick_Ai_2(warunek, tura, rozmiar, board, koniec_ciagu);
                    }
                else
                    cout<<"blok"<<endl;
            }
            else
            {
                //draw_board(rozmiar, board);
                cout<<endl;
                //cout<<"Wygrywa komputer"<<endl;
                //return 0;
                
            }
        }

        draw_board(rozmiar, board);

        //system("CLS");
        cout << endl;

        if(win(warunek, tura, rozmiar, board))
        {
            cout<<"koniec gry"<<endl;
            return 0;
        }
        else
            cout << endl << endl << endl;

        if(tura_gracz == 1)
        {   
            tura_gracz = 0;
            tura_ai = 1;
        }
        else
        {
            tura_gracz = 1;
            tura_ai = 0; 
        }
        tura++;
    }
    cout << "mamy remis" << endl;
    return 0;
}