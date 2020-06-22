#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
using namespace std;
#define WINDOWS 1

void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}




int randor()
{
int flag;

flag=rand()%2;
return flag;
}

//to create 1-100 marbles
int randnt()
{
int flag1;

flag1=rand()%(100+1-10+1);
return flag1;
}
//return to menu function
void return_to_menu()
 { 
  void menu();
 printf("Press enter to return to menu\n");
 getch();
 clrscr();
 menu();
}
//how to play option
void htp()
{printf("\t\t\t\t HOW TO PLAY\t\t\t\t\n");
printf("\n\n\n");
printf("\tWE CHOOSE FROM MENU OUR CHOICE THEN PLAY WITH PLAYER OR WITH COMPUTER\n\tAME HAS ONE RULE AND ONE WINNING CONDITION :\n\t\t\t1.NO PLAYER PICKS MORE THAN HALF OF THE MARBLES\n\t\t\1.2.THE PLAYER WHO PICKS UP THE LAST MARBLE LOSES\n");
return_to_menu();
}

//computer stupid mode
int stupid_strat(int m)
{
if(m==1)
 {
  m=0;
}
else
{

m=m-rand()%(m/2+1);
}
return m;
}
//smart mode of computer
int smart_strat(int m)
{int s[101],l=0,j;
 if(m==1)
 {m=0;
 }
 else
 {
  for(int i=0;i<m;i++)
  {
  s[i]=pow(2,i)-1;
   l++;
   }

  for(j=0;j<l;j++)
   {
   if(m==s[j])
   {
   
   m=m-rand()%(m/2+1);
   break;
   }
   else
    {
    if(m-s[j]<=m/2)
    {
    m=s[j];
    break;
    }

       }
    }
  }
  return m;
}
//players chance to play
int player_strat(int m)
 {   int c,z,i;
if(m/2!=0)
printf("YOU ARE ONLY ALLOWED TO PICK %d MARBLES\n",(m/2));
printf("ENTER THE MARBLES YOU WANT\n");
scanf("%d",&c);
if(c>m/2 && (m/2)!=0)
 {
 printf("WRONG ENTRY REPLAY\n");
scanf("%d",&i);
z=m-i;
}
else
  {
  z=m-c;
}
return z;
}
//global variables
int b1, k=-1;
//the player vs computer game
void  game_construct(int g)
 { //int h;
   // h=g;
  while(g>0)
   {
   if(k==-1)
    {
   printf("PLAYER TO PLAY\n");
   g=player_strat(g);
   clrscr();
   }

     else
     {
     printf("COMPUTER  PLAYS\n");
     if(b1==0)
     g=stupid_strat(g);
     else
     g=smart_strat(g);

     }

     printf("THE MARBLES LEFT ARE: %d\n",g);
     k=k*(-1);

     }
     if(k==-1)
     printf("PLAYER WINS  !!!\n");
     else
     printf("COMPUTER WINS!!!\n");

  }
//player vs computer logic
void play_game_comp()
{
int a1,c1 ;
printf("GAME STARTS!!\n");
a1=randnt();
printf("THE NO OF MARBLES ARE: %d\n",a1);
b1=randor();
if(b1==0)
 {
 printf("COMPUTER PLAYING IN STUPID MODE\n");
 c1=randor();
 if(c1==0)
 {
 game_construct(a1);
 }
 else
  {
  k=k*(-1);
  game_construct(a1);
 }
}
else
 {
 printf("COMPUTER PLAYING IN SMART MODE \n");
 c1=randor();
 if(c1==0)
  {
  game_construct(a1);
  }
  else
   {
   k=k*(-1);
   game_construct(a1);

	 }
     }


  return_to_menu();

}
//exit function
void exitit()
 {
 printf("HOPE YOU ENJOYED THE GAME!!!");
}
//global variable
int k1=-1;
//player1 vs player2 game
void game_construct1(int g)
 {
 while(g>0)
  {


    if(k1==-1)
     {
     printf("PLAYER 1 TO PLAY\n");
     g=player_strat(g);
     clrscr();
    }
    else
     {
     printf("PLAYER 2 TO PLAY\n");
     g=player_strat(g);
    }
    printf("MARBLES LEFT ARE : %d\n",g);
    k1=k1*(-1);
    //printf("\n");
 }
 if(k1==-1)
  printf("PLAYER 1 WINS!!!\n");
 else
 printf("PLAYER 2 WINS!!\n");
}
//player vs player mode
void play_play()
 {
 int a2,b2;
 printf("GAME STARTS\n");
 a2=randnt();
 printf("THE NO OF MARBLES ARE: %d\n",a2);
 game_construct1(a2);
 return_to_menu();
 }


//menu of the game
void menu()
{
char c;
printf("\t\t\t\t***********\t\t\t\t");
printf("\t\t\t\t\tMARBLE GAME\t\t\t\t\n");
printf("\t\t\t\t***********\t\t\t\t");
printf("\n\n\n");
printf("\t\t\tCHOOSE FROM:\n\t\t\t1.PLAYER VS PLAYER\n\t\t\t2.COMPUTER VS PLAYER\n\t\t\t3.HOW TO PLAY\n\t\t\t4.EXIT\n\n");
printf("ENTER CHOICE AND PRESS ENTER TWICE:\t");
scanf("%d",&c);
switch(c)
 {

case 1:
       getch();
       clrscr();
       play_play();
       break;
       case 2:
       getch();
       clrscr();
       play_game_comp();
       break;
       case 3:
       getch();
       clrscr();
       htp();
       break;
       case 4:
       getch();
       clrscr();
       exitit();
       break ;
     default:printf("WRONG CHOICE\n");
     break;
  }
}





//main function for excuetion
int main()
{ 
clrscr();
menu();
getch();
return 0;
 }