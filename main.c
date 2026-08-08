#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("Color 75");
    int l,z;
    int u,count;
    int attempts=5;
    char username[50];
    char password[50];
    char un[80],pw[80];
    User s[5]=
    {
        {"aaa","123a"},
        {"bbb","123b"},
        {"ccc","123c"},
        {"ddd","123d"},
        {"eee","123e"}
    };
    Rooms r[12]=
    {
        {1001, "Available", "Seaview", 2010},
        {1002, "Available", "Seaview", 2020},
        {1003, "Available", "Seaview", 2030},
        {1004, "Available", "Seaview", 2040},
        {1005, "Reserved",  "Seaview", 2050},
        {2001, "Available", "Lakeview", 2100},
        {2002, "Available", "Lakeview", 2200},
        {2003, "Available", "Lakeview", 2300},
        {2004, "Available", "Lakeview", 2400},
        {2005, "Reserved", "Lakeview", 2500},
        {3001, "Reserved", "Gardenview", 1000},
        {3002, "Reserved", "Gardenview", 2050}


    };
    reservations q[4] =
    {
        {143256,3001,"confirmed","Ahmed Mohamed","90022800157646",4,"25-12-2024","Ahmed.khaled@gmail.com","01227653498"},
      {154574,1005,"confirmed","Mohamed Salah","90022800157647",3,"26-12-2024","mohamed.salah@gmail.com","01227653499"},
      {154215,2005,"Unconfirmed","Sara Ahmed","90022800157648",2,"29-12-2024","sara.ahmed@gmail.com","01227653500"},
       {452324,3002,"Unconfirmed","Hana Ibrahim","90022800157649",5,"30-12-2024","hana.ibrahim@gmail.com","01227653501"}
    };
    FILE *f1=fopen("users.txt","wx");
    for(int i=0; i<5; i++)
    {
        fprintf(f1,"%s %s \n",s[i].Username, s[i].password);
    }
    fclose(f1);
    FILE *f2=fopen("room.txt","wx");
    for(int i=0; i<12; i++)
    {
        fprintf(f2,"%d %s %s %f \n",r[i].room_number,r[i].room_availability,r[i].room_view,r[i].room_price);
    }
    fclose(f2);
    FILE *f3=fopen("reservations.txt","wx");
    for (int i = 0; i < 4; i++)
    {
        fprintf(f3, "%d,%d,%s,%s,%s,%d,%s,%s,%s\n",
                q[i].reservation_ID, q[i].roomnumber, q[i].room_reservation_Status,
                q[i].customer_name, q[i].customer_national_ID, q[i].number_ofnights,
                q[i].date, q[i].customer_email, q[i].mobile_number);
    }
    fclose(f3);
    printf("===== Hotel Management System Login =====\n");
    printf("1-Login \n");
    printf("2-Exit \n");
    printf("What do you want to do? \n");
    scanf("%d",&l);
    getchar();

    if (l == 1)
    {
        while (attempts > 0) {
            printf("Enter username: ");
            gets(username);


            printf("Enter password: ");

            gets(password);

            f1 = fopen("users.txt", "r");
            if (f1 == NULL) {
                printf("Error opening file");
                exit(0);
            }


            while (fscanf(f1, "%s %s", un, pw) == 2) {

                 if (strcmp(un, username) == 0 && strcmp(pw, password) == 0) {
                    count = 1;
                    break;
                    }
                }


            fclose(f1);

            if (count) {
                printf("Logged in successfully!\n");
                menue(f1, f2, f3);
                break;
            } else {
                printf("incorrect Password or Username, Try again!\n");
                attempts--;
                printf("attempts left: %d\n", attempts);
            }

            if (attempts == 0) {
                printf("No attempts left! \n");
                exit(0);
            }
        }
    } else {
        printf("Exited successfully!\n");
        exit(0);
    }

    return 0;
}
