#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minesweeper.h"
typedef struct
{
    char tip;
    char coloana;
    int rand;

} comanda;

int main()
{
//    int h,w,rows[30]= {2,3};
//    char t[101][53],cols[30]= {'A','A'};
//    int nr_bombs,i,j;
//    char str[1001]="C3 C1 A1 A4 B1 !A2 !A3";
//    int len,tmp;
//    int nr_elem=0;
//    comanda* cmd=calloc(100,sizeof(comanda));
//    puts("Numarul de randuri este:\n");
//    scanf("%d",&h);
//    puts("Numarul de coloane este\n");
//    scanf("%d",&w);
//    puts("Numarul de bombe este\n");
//    scanf("%d",&nr_bombs);
////    puts("Vom incepe de la punctul de coordonate:\n");
////    scanf("%d%d",&i,&j);
//
//    create(nr_bombs,cols,rows,h,w,t);
//    char** s;
//    s=init_state(h,w);
//    //discover(i,j,h,w,t,s);
//
//    //print(h,w,t);
//    printf("\n");
////    for(int i=0; i<h; i++)
////    {
////        for(int j=0; j<w; j++)
////            printf("%c",s[i][j]);
////        printf("\n");
////    }
//
//    //B)Fie str un șir de caractere care reprezintă una sau mai multe comenzi, separate prin 0 sau mai multe spații. Extrageți din string șirul de comenzi. Să salvați aceste comenzi într-un tablou de structuri. Constrângeri: lungimea șirului nu depășește 1000, șirul conține cel mult 100 comenzi. Șirul poate conține și comenzi greșite dar toate comenzile sunt de forma literă și număr, prefixate sau nu cu !. Cele care nu au ! reprezintă comenzi de descoperire.
//
//    len=strlen(str);
//    for(i=0; i<len; i++)
//    {
//        if(str[i]=='!')
//        {
//            cmd[nr_elem].tip='!';
//            i++;
//            cmd[nr_elem].coloana=str[i];
//            i++;
//            cmd[nr_elem].rand=0;
//            while(str[i]>='0' && str[i]<='9')
//            {
//                cmd[nr_elem].rand=cmd[nr_elem].rand*10+(str[i]-'0');
//                i++;
//            }
//            i--;
//            nr_elem++;
//        }
//        else if(str[i]!=' ')
//        {
//            cmd[nr_elem].tip='.';
//            cmd[nr_elem].coloana=str[i];
//            i++;
//            cmd[nr_elem].rand=0;
//            while(str[i]>='0' && str[i]<='9')
//            {
//                cmd[nr_elem].rand=cmd[nr_elem].rand*10+(str[i]-'0');
//                i++;
//            }
//            i--;
//            nr_elem++;
//        }
//
//
//    }
//
//    printf("\n");
    //D)Implementați funcția cu următorul antet care afișează cum vede jucătorul tabla în funcție de starea celulelor. Pe poziții descoperite se arată valorile din tabla t. Pe poziții marcate apare !. Pe poziții nedescoperite apare ?. Să tipăriți lângă tabla și legenda pozițiilor. Se poate adapta funcția print pentru acest scop.

    //player_view(h,w,t,s);


//e) Opțional: Jucați-vă în mod interactiv folosind funcțiile scrise până acum și o buclă care citește comenzile de la utilizator.

//    for(i=0; i<nr_elem; i++)
//    {
//        if(cmd[i].coloana>='A' && cmd[i].coloana<='Z')
//            tmp=cmd[i].coloana-'A';
//        else tmp=cmd[i].coloana-'a'+26;
//        if(cmd[i].tip=='.')
//
//        {
//            discover(cmd[i].rand-1,tmp,h,w,t,s);
//            if(discover(cmd[i].rand-1,tmp,h,w,t,s)==-2)
//                puts("COMANDA INVALIDA\n");
//            else if(discover(cmd[i].rand-1,tmp,h,w,t,s)==-1)
//            {
//                i=nr_elem;
//                puts("AI PIERDUT JOCUL\n");
//            }
//            else puts("Jocul continua\n");
//        }
//
//        else if(cmd[i].tip=='!')
//        {
//            mark(cmd[i].rand-1,tmp,h,w,s);
//            printf("A FOST MARCATA POZITIA %d %d\n",cmd[i].rand-1,tmp);
//        }
//
//        player_view(h,w,t,s);
//        printf("\n");
//
//    }
//    int ok=1;
//    for(i=0;i<h;i++)
//        for(j=0;j<w;j++)
//            if(s[i][j]=='?')
//        {
//            ok=-1;
//            i=h;
//            j=w;
//        }
//    if(ok==-1)
//        puts("JOCUL NU S-A INCHEIAT");
//    else
//        puts("FELICITARI! AI CASTIGAT");

run_tests();



    return 0;
}
