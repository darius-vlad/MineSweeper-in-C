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

void player_view(int h, int w, char t[h][w], char** s)
{
    int i,j;
    char c;
    printf("    ");
    for(j='A'; j<'A'+w; j++)
    {
        c=j;
        if(j>'Z')
            c=j+'a'-'Z'-1;
        printf("%c",c);
    }
    printf("\n");
    for(i=0; i<h; i++)
    {
        printf("%3d ",i+1);
        for(j=0; j<w; j++)
            if(s[i][j]=='.')
                printf("%c",t[i][j]);
            else printf("%c",s[i][j]);
        printf(" %d\n",i+1);
    }
    printf("    ");
    for(j='A'; j<'A'+w; j++)
    {
        c=j;
        if(j>'Z')
            c=j+'a'-'Z'-1;
        printf("%c",c);
    }
}


void mark(int i, int j, int h, int w, char** s)
{
    if(i<0 || i>=h || j<0 || j>=w)
        return;
    if(s[i][j]=='?')s[i][j]='!';
    else if(s[i][j]=='!')s[i][j]='?';

}


int discover(int i, int j, int h, int w, char t[h][w], char** s)
{
    if(i<0 || j<0 || i>=h || j>=w)
        return -2;
    else if(t[i][j]=='X')
        return -1;
    else if(s[i][j]=='.')
        return 0;
    else if(t[i][j]>'0' && t[i][j]<'9')
    {
        s[i][j]='.';
        return 1;
    }
    else if(t[i][j]=='.')
    {
        s[i][j]='.';
        discover(i-1,j-1,h,w,t,s);
        discover(i-1,j,h,w,t,s);
        discover(i-1,j+1,h,w,t,s);
        discover(i,j-1,h,w,t,s);
        discover(i,j+1,h,w,t,s);
        discover(i+1,j-1,h,w,t,s);
        discover(i+1,j,h,w,t,s);
        discover(i+1,j+1,h,w,t,s);
        return 2;
    }
}


char** init_state(int h,int w)
{
    char** s;
    s=calloc(h,sizeof(char*));
    for(int i=0; i<h; i++)
        s[i]=calloc(w,sizeof(char));

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            s[i][j]='?';

    return s;
}


void print(int h,int w,char t[h][w])
{
    int i,j;
    char c;
    printf("    ");
    for(j='A'; j<'A'+w; j++)
    {
        c=j;
        if(j>'Z')
            c=j+'a'-'Z'-1;
        printf("%c",c);
    }
    printf("\n");
    for(i=0; i<h; i++)
    {
        printf("%3d ",i+1);
        for(j=0; j<w; j++)
            printf("%c",t[i][j]);
        printf(" %d\n",i+1);
    }
    printf("    ");
    for(j='A'; j<'A'+w; j++)
    {
        c=j;
        if(j>'Z')
            c=j+'a'-'Z'-1;
        printf("%c",c);
    }
}


void create(int nr_bombs, char cols[], int rows[], int h, int w, char t[h][w])
{
    int k=0,i,j,aux;

    for(i=0; i<h; i++)
        for(j=0; j<w; j++)
            t[i][j]='0';

    while(nr_bombs)
    {
        i=rows[k]-1;
        if(cols[k]<='Z')j=cols[k]-'A';
        else j=cols[k]-'a'+26;
        t[i][j]='X';
        nr_bombs--;
        k++;
    }

    for(i=0; i<h; i++)
        for(j=0; j<w; j++)
            if(t[i][j]!='X')
            {
                if(t[i-1][j-1]=='X')t[i][j]++;
                if(t[i-1][j]=='X')t[i][j]++;
                if(t[i-1][j+1]=='X')t[i][j]++;
                if(t[i][j-1]=='X')t[i][j]++;
                if(t[i][j+1]=='X')t[i][j]++;
                if(t[i+1][j-1]=='X')t[i][j]++;
                if(t[i+1][j]=='X')t[i][j]++;
                if(t[i+1][j+1]=='X')t[i][j]++;

            }

    for(i=0; i<h; i++)
        for(j=0; j<w; j++)
            if(t[i][j]=='0')
                t[i][j]='.';


}

void run_tests()
{
    FILE* pr = fopen("minesweeper.in","r");
    FILE* pw = fopen("minesweeper.out","w");
    int T,h,w,n,len,nr_elem=0,tmp;
    fscanf(pr,"%d",&T);
    while(T)
    {
        comanda* cmd=calloc(100,sizeof(comanda));
        fscanf(pr,"%d%d%d",&h,&w,&n);
        char sir_coloane_bombe[n],str[1001],c;
        int rand_bomba[n],i,j;
        for(int i=0; i<n; i++)
            fscanf(pr,"%c",&sir_coloane_bombe[i]);

        for(i=0; i<n; i++)
            fscanf(pr,"%d",&rand_bomba[i]);

        i=0;
        while(fscanf(pr,"%c",&c)==1 && c!='\n')
        {
            str[i]=c;
            i++;
        }
        char** s;
        s=init_state(h,w);
        char t[h][w];
        create(n,sir_coloane_bombe,rand_bomba,h,w,t);
        len=strlen(str);
        for(i=0; i<len; i++)
        {
            if(str[i]=='!')
            {
                cmd[nr_elem].tip='!';
                i++;
                cmd[nr_elem].coloana=str[i];
                i++;
                cmd[nr_elem].rand=0;
                while(str[i]>='0' && str[i]<='9')
                {
                    cmd[nr_elem].rand=cmd[nr_elem].rand*10+(str[i]-'0');
                    i++;
                }
                i--;
                nr_elem++;
            }
            else if(str[i]!=' ')
            {
                cmd[nr_elem].tip='.';
                cmd[nr_elem].coloana=str[i];
                i++;
                cmd[nr_elem].rand=0;
                while(str[i]>='0' && str[i]<='9')
                {
                    cmd[nr_elem].rand=cmd[nr_elem].rand*10+(str[i]-'0');
                    i++;
                }
                i--;
                nr_elem++;
            }


        }

        for(i=0; i<nr_elem; i++)
        {
            if(cmd[i].coloana>='A' && cmd[i].coloana<='Z')
                tmp=cmd[i].coloana-'A';
            else tmp=cmd[i].coloana-'a'+26;
            if(cmd[i].tip=='.')

            {
                discover(cmd[i].rand-1,tmp,h,w,t,s);

                if(discover(cmd[i].rand-1,tmp,h,w,t,s)==-1)
                {
                    i=nr_elem;
                    fprintf(pw,"%d",-1);
                }


                else if(cmd[i].tip=='!')
                {
                    mark(cmd[i].rand-1,tmp,h,w,s);

                }

            }

            int ok=1;
            for(i=0; i<h; i++)
                for(j=0; j<w; j++)
                    if(s[i][j]=='?')
                    {
                        ok=-1;
                        i=h;
                        j=w;
                    }
            if(ok==-1)
                fprintf(pw,"%d",0);
            else
                fprintf(pw,"%d",1);



        }

        fprintf(pw,"\n");
        T--;


    }
}
