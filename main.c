#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void gotoxy(short int col,short int row);
 struct account
               { int  messchrges;
                 int  fine;

                 int total;
                 };struct account ac;




struct existg_hostel
                   {
                         int roll;
                         char name[20];
                         char deptt[20];
                         char permntadd[20];
                         int   roomno;
                         struct account ac;
                   };
                           struct existg_hostel eh[20];




struct new_entry
                {

                          char name[20];
                          char deptt[20];
                          char permntadd[20];
                          int   roomno;
                          int  roll;
                          int  security;
                          struct account ac;
                 };
                           struct new_entry nh[20];
      int choice,rol,i=0,flag=0,sd,count=0;

    char ch,nam[20];
        FILE *fp;
int main()


{while(1)
{
    system("cls");
    gotoxy(28,6);
    printf("HOSTEL MANAGEMENT SYSTEM");
    gotoxy(25,10);
    printf("--->>Press '1' for New Entry\n");
   gotoxy(25,12);
    printf("--->>Press '2' for Searching Existing Record\n");
    gotoxy(25,14);
    printf("--->>Press '3' for Deleting Record\n");
    gotoxy(25,16);
    printf("--->>Press '4' for Modifying  Record\n");
    gotoxy(25,18);
    printf("--->>Press '5' to Exit\n");
    gotoxy(25,20);
    printf("Choice you Entered is:");
    scanf("%d",&choice);


    switch(choice)
    {
                   case 1:
                        //new entry
                             system("cls");



                             fp=fopen("hostel_data.txt","a+");
                                 char another='y';
                                  int j=0;
                                   while(fscanf(fp,"%d%s%s%s%d%d%d%d",&eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,&eh[i].roomno,&eh[i].ac.messchrges,&eh[i].ac.fine,&eh[i].ac.total)!=EOF)
                                   {
                                       printf("%d",count);
                                   count++;
                                   }

                              while(another=='y'||another=='Y')
                                   {
                             for(j=0;j<1;j++)
                                   {
                                           gotoxy(25,10);
                                           printf("Enter Name(use underscore for spaces)\t");
                                           scanf("%s",nh[j].name);
                                           gotoxy(25,12);
                                           printf("Enter Department\t");
                                           scanf("%s",nh[j].deptt);
                                           gotoxy(25,14);
                                           printf("Enter Permanent Address\t");
                                           scanf("%s",nh[j].permntadd);
                                           gotoxy(25,16);
                                           printf("Security amount rs.2500\n");
                                              gotoxy(25,18);
                                           printf("Security Deposited(Press 1/0 ::Y/N)\t");

                                           scanf("%d",&sd);
                                   switch(sd)

                                 {

                                  case 1:

                                    rewind(fp);

                                   nh[j].roll=count+1;
                                   nh[j].roomno=count+279;

                                   gotoxy(25,20);
                                   printf("Allotment Details:");
                                   gotoxy(25,22);
                                   printf("Roll Number %d\n",nh[j].roll);
                                   gotoxy(25,24);
                                   printf("Room Number %d\n",nh[j].roomno);
                                   nh[j].ac.messchrges=0;
                                   nh[j].ac.fine=0;
                                   nh[j].ac.total=nh[j].ac.messchrges+nh[j].ac.fine;
                                   fprintf(fp,"%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",nh[j].roll,nh[j].name,nh[j].deptt,nh[j].permntadd,nh[j].roomno,nh[j].ac.messchrges,nh[j].ac.fine,nh[j].ac.total);

                                    gotoxy(25,26);
                                    printf("Entry Successfully Done!!!!\n");
                                    gotoxy(25,28);
                                    printf("%d",j);
                                   break;

                                   case 0:

                                        gotoxy(25,20);
                                        printf("Security Pending");
                                         gotoxy(25,22);
                                         printf("Sorry!Roll Number and Room Number will be allotted on Receiving Security");
                                        gotoxy(25,24);
                                   break;

                                   }
                                   }

                                   gotoxy(25,30);

                                    printf("want to Add Another Record!\t");
                                   fflush(stdin);
                                   scanf("%c",&another);

                                   system("cls");
                                   }
                                fclose(fp);
                                        printf("Press any key to Return to Main Menu");
                                   getch();
                                   break ;




                  case 2:
                       //searching entry
                        system("cls");


                                    fp=fopen("hostel_data.txt","r");
                                    if(fp==NULL)
                                    exit(0);


                                   while(another=='y'||another=='Y')
                                   {gotoxy(25,10);
                                                                     printf("Enter Roll Number:\t");
                                    scanf("%d",&rol);
                                      rewind(fp);
                                    while(fscanf(fp,"%d%s%s%s%d%d%d%d",&eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,&eh[i].roomno,&eh[i].ac.messchrges,&eh[i].ac.fine,&eh[i].ac.total)!=EOF)
                                   { if(rol==eh[i].roll)
                                                                      { gotoxy(25,12);
                                                                       printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,eh[i].roomno,eh[i].ac.messchrges,eh[i].ac.fine,eh[i].ac.total);
                                                                       }

                                                                        }
                                                                       gotoxy(25,14);
                                                                       fflush(stdin);
                                                                        printf("Want to Search Another Entry(press y/n):\t");
                                                                        scanf("%c",&another);
                                                                        system("cls");
                                                                        }

                                                                       gotoxy(25,16);

                                                                        printf("Press any key to Return to Main Menu");
                                                                               getch();
                                                                               break;
                  case 3:
                       //Delete entry
                                                system("cls");
                                                FILE *fn;
                                                  gotoxy(25,10);
                                                  printf("Enter roll no.:\t");
                                                  scanf("%d",&rol);

                                                  fp=fopen("hostel_data.txt","r");
                                                  fn=fopen("hostel_data2.txt","w");
                                                   while(another=='y'||another=='Y')
                                   {

                                                  while(fscanf(fp,"%d%s%s%s%d%d%d%d",&eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,&eh[i].roomno,&eh[i].ac.messchrges,&eh[i].ac.fine,&eh[i].ac.total)!=EOF)
                                                  { if(eh[i].roll==rol)
                                                  flag=1;


                                                  if(eh[i].roll!=rol)
                                                  {fprintf(fn,"%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,eh[i].roomno,eh[i].ac.messchrges,eh[i].ac.fine,eh[i].ac.total);
                                                  }
                                                                        }
                                                                        fclose(  fp);
                                                                            fclose(  fn);
                                                                            remove(  "hostel_data.txt");
                                                                            rename( "hostel_data2.txt", "hostel_data.txt");
                                                                      gotoxy(25,12);
                                                                      if(flag==1)
                                                                       printf("Entry Successfully Deleted");
                                                                       if(flag==0)
                                                                       printf("Not in Record!");
                                                                       gotoxy(25,14);
                                                                      printf("Want to Delete Another Record(press y/n):\t");
                                                                       fflush(stdin);
                                                                        scanf("%c",&another);
                                                                        getch();
                                                                        system("cls");
                                                                        }
                                                                        gotoxy(25,16);
                                                                       printf("Press any key to Return to Main Menu");
                                                                        getch();
                                                                       break;





                  case 4:
                       //modify entry
                       system("cls");
                       FILE *f;
                       gotoxy(25,10);
                       printf("Enter Roll number whose Record is to be modified\t");
                       scanf("%d",&rol);
                       fp=fopen("hostel_data.txt","r");
                       f=fopen("hostel_data3.txt","w");

                        while(another=='y'||another=='Y')
                                   {
                       while(fscanf(fp,"%d%s%s%s%d%d%d%d",&eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,&eh[i].roomno,&eh[i].ac.messchrges,&eh[i].ac.fine,&eh[i].ac.total)!=EOF)
{
                       if(eh[i].roll==rol)
                       {
                                          gotoxy(25,12);
                                          printf("Enter Mess charges");
                                          scanf("%d",&eh[i].ac.messchrges);
                                                        gotoxy(25,14);
                                                         printf("Enter Fine");
                                          scanf("%d",&eh[i].ac.fine);
                                              eh[i].ac.total=eh[i].ac.messchrges+eh[i].ac.fine;
                                           }
                       fprintf(f,"%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",eh[i].roll,eh[i].name,eh[i].deptt,eh[i].permntadd,eh[i].roomno,eh[i].ac.messchrges,eh[i].ac.fine,eh[i].ac.total);


                                                                        }

                                                 fclose(fp);
                                                                            fclose(f);
                                                                            remove(  "hostel_data.txt");
                                                                            rename( "hostel_data3.txt", "hostel_data.txt");

                  gotoxy(25,16);
                  printf("Entry Successfully Modified");
                  gotoxy(25,18);
                      printf("Want to Modify Another Record(press y/n):\t");
                                                                        scanf("%c",&another);
                                                                        system("cls");
                                                                        }
                   gotoxy(25,20);
                  printf("Press any key to Return to Main Menu");
                   getch();
                   break;



                  case 5:
                       {exit(0);
                       }
                }  }
    getch();

}

     void gotoxy(short int x, short int y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


