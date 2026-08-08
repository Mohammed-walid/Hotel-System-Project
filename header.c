#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void sort(reservations a[], int count)
 {

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int day1, month1, year1, day2, month2, year2;
            sscanf(a[i].date, "%d-%d-%d", &day1, &month1, &year1);
            sscanf(a[j].date, "%d-%d-%d", &day2, &month2, &year2);

            if (year1 > year2 || (year1 == year2 && month1 > month2) ||
                (year1 == year2 && month1 == month2 && day1 > day2)) {
                reservations temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void load_reservations(FILE *f3)
 {
    char ques[10];
    char line[500];
    reservations a[100];
    int count = 0;

    f3 = fopen("reservations.txt", "r");

    if (f3 == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }


    while (fgets(line, sizeof(line), f3)) {
        char *s;
        reservations currentReservation;

        s = strtok(line, ",");
        if (s != NULL)
            currentReservation.reservation_ID = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            currentReservation.roomnumber = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.room_reservation_Status, s, sizeof(currentReservation.room_reservation_Status) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_name, s, sizeof(currentReservation.customer_name) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_national_ID, s, sizeof(currentReservation.customer_national_ID) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            currentReservation.number_ofnights = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.date, s, sizeof(currentReservation.date) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_email, s, sizeof(currentReservation.customer_email) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.mobile_number, s, sizeof(currentReservation.mobile_number) - 1);


        a[count++] = currentReservation;
    }
    fclose(f3);

    sort(a, count);


    for (int i = 0; i < count; i++) {
        printf("Reservation ID: %d\n", a[i].reservation_ID);
        printf("Room Number: %d\n", a[i].roomnumber);
        printf("Status: %s\n", a[i].room_reservation_Status);
        printf("Name: %s\n", a[i].customer_name);
        printf("National ID: %s\n", a[i].customer_national_ID);
        printf("Number of Nights: %d\n", a[i].number_ofnights);
        printf("Date: %s\n", a[i].date);
        printf("Email: %s\n", a[i].customer_email);
        printf("Phone: %s\n", a[i].mobile_number);
        printf("\n");
    }

    printf("Do you want to go back to the menu? If yes, then type 'yes': ");
    scanf("%s", ques);

    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}

int generateID(FILE *f3)
{
    int reservation_ID;
    int s[1000];
    int count = 0;
    f3 = fopen("reservations.txt", "r");
    if (f3 != NULL)
    {
        while (fscanf(f3, "%d", &s[count]) == 1)
        {
            count++;
        }
        fclose(f3);
    }
    srand(time(NULL));
    int w; //here w checks if the id unique or no
    do
    {
        w = 1;
        reservation_ID = rand() % 1000000;

        for (int i = 0; i < count; i++)
        {
            if (reservation_ID == s[i])
            {
                w = 0;
                break;
            }
        }
    }
    while (!w);

    return reservation_ID;
}
void Room_Reservation(int usedBefore, FILE *f2, FILE *f3)
{
    char namee[20], emaill[30], roomcat[20], checkdate[20], mobilephone[20], nationalid[30];
    int nonights;
    char ques[3],qwq[10];
    Rooms availableRooms[6];
    int Count = 0;
    int counttt=0;
    reservations newReservation;

    printf("Enter customer name: ");
    getchar();
    gets(namee);
for (int i = 0; namee[i] != '\0'; i++) {
        if (isdigit(namee[i])) {
            printf("Enter valid input.\n");
           printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
    printf("Enter customer email: ");
    gets(emaill);
for (int i = 0; emaill[i] != '\0'; i++) {
        if (emaill[i] == '@') {
            counttt++;
        }
        if (isdigit(emaill[i])) {
             printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
        if(counttt!=1)
        {printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
    }}
    printf("Enter customer's national ID: ");
    gets(nationalid);
for (int i = 0; nationalid[i] != '\0'; i++) {
        if (!isdigit(nationalid[i])) {
            printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
    printf("Enter customer's phone number: ");
    gets(mobilephone);
for (int i = 0; mobilephone[i] != '\0'; i++) {
        if (!isdigit(mobilephone[i])) {
            printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
    printf("Enter number of nights: ");
    scanf("%d", &nonights);
    getchar();
    printf("Enter check-in date d-m-y: ");
    gets(checkdate);

    printf("Enter room category ('Seaview', 'Lakeview', or 'Gardenview'): ");
    gets(roomcat);


    for (int i = 0; roomcat[i]; i++)
    {
        if (roomcat[i] >= 'A' && roomcat[i] <= 'Z')
        {
            roomcat[i] += 'a' - 'A';
        }
    }

    f2 = fopen("room.txt", "r");
    if (f2 == NULL)
    {
        printf("Error opening file room.txt\n");
        exit(1);
    }

    while (fscanf(f2, "%d %s %s %f", &availableRooms[Count].room_number,
                  availableRooms[Count].room_availability,
                  availableRooms[Count].room_view,
                  &availableRooms[Count].room_price) == 4)
    {
        for (int i = 0; availableRooms[Count].room_view[i]; i++)
        {
            if (availableRooms[Count].room_view[i] >= 'A' && availableRooms[Count].room_view[i] <= 'Z')
            {
                availableRooms[Count].room_view[i] += 'a' - 'A';
            }
        }
        if (strcmp(availableRooms[Count].room_availability, "Available") == 0 &&
                strcmp(availableRooms[Count].room_view, roomcat) == 0)
        {
            Count++;
        }
    }
    fclose(f2);

    if (Count == 0)
    {
        printf("No rooms available in the selected category.\n");
        menue("users.txt", "room.txt", "reservations.txt");
    }

    int assignedRoom = availableRooms[0].room_number;
    int reservationID = generateID(f3);

    newReservation.reservation_ID = reservationID;
    newReservation.roomnumber = assignedRoom;
    strcpy(newReservation.room_reservation_Status, "Unconfirmed");
    strcpy(newReservation.customer_name, namee);
    strcpy(newReservation.customer_national_ID, nationalid);
    newReservation.number_ofnights = nonights;
    strcpy(newReservation.date, checkdate);
    strcpy(newReservation.customer_email, emaill);
    strcpy(newReservation.mobile_number, mobilephone);


    printf("Do you want to save this reservation? Type 'yes': \n");
    scanf(" %s",qwq);

    if (strcmp(qwq,"yes")==0)
    {
        f3 = fopen("reservations.txt", "a");
        if (f3 == NULL)
        {
            printf("Error opening file reservations.txt\n");
            exit(1);
        }
        fprintf(f3, "%d,%d,%s,%s,%s,%d,%s,%s,%s\n",
                newReservation.reservation_ID, newReservation.roomnumber,
                newReservation.room_reservation_Status, newReservation.customer_name,
                newReservation.customer_national_ID, newReservation.number_ofnights,
                newReservation.date, newReservation.customer_email, newReservation.mobile_number);
        fclose(f3);

        printf("Reservation saved successfully!\n");
         printf("Reservation ID: %d\n", reservationID);

    }
    else
    {
        printf("Reservation not saved.\n");
    }
    printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void Check_in(int reservationID, const char *reservationFile, const char *roomsFile)
{
    char ques[3];
    FILE *reservationPtr = fopen(reservationFile, "r+");
    if (reservationPtr == NULL)
    {
        printf("Error opening reservation file.\n");
        return;
    }

    FILE *tempReservation = fopen("temp_reservation.txt", "w");
    if (tempReservation == NULL)
    {
        printf("Error creating temporary reservation file.\n");
        fclose(reservationPtr);
        return;
    }

    char line[500];
    reservations currentReservation;
    int found = 0;

    while (fgets(line, sizeof(line), reservationPtr))
    {

        sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]",
               &currentReservation.reservation_ID, &currentReservation.roomnumber,
               currentReservation.room_reservation_Status, currentReservation.customer_name,
               currentReservation.customer_national_ID, &currentReservation.number_ofnights,
               currentReservation.date, currentReservation.customer_email, currentReservation.mobile_number);

        if (currentReservation.reservation_ID == reservationID)
        {
            found = 1;

            printf("Reservation found:\n");
            printf("Reservation ID: %d\n", currentReservation.reservation_ID);
            printf("Room number: %d\n", currentReservation.roomnumber);
            printf("Reservation status: %s\n", currentReservation.room_reservation_Status);
            printf("Customer name: %s\n", currentReservation.customer_name);
            printf("National ID: %s\n", currentReservation.customer_national_ID);
            printf("Number of nights: %d\n", currentReservation.number_ofnights);
            printf("Check-in date: %s\n", currentReservation.date);
            printf("Email: %s\n", currentReservation.customer_email);
            printf("Phone number: %s\n", currentReservation.mobile_number);

            time_t now = time(NULL);
            struct tm *currentDate = localtime(&now);
            char today[15];
            strftime(today, sizeof(today), "%d-%m-%Y", currentDate);

            int day, month, year;
            sscanf(currentReservation.date, "%d-%d-%d", &day, &month, &year);
            struct tm rDate = {0};
            rDate.tm_year = (year) - 1900;
            rDate.tm_mon = (month) - 1;
            rDate.tm_mday = (day);

            if (!(mktime(&rDate) > mktime(today)))
            {
                printf("Check-in date has not arrived yet. Cannot confirm reservation.\n");
                fclose(reservationPtr);
                fclose(tempReservation);
                remove("temp_reservation.txt");
                printf("do you want to go back to the menu? if yes then type 'yes' \n" );
                scanf("%s",ques);
                if(strcmp(ques,"yes")==0)
                    menue("users.txt", "room.txt", "reservations.txt");
                else
                    exit(0);
            }

            if (strcmp(currentReservation.room_reservation_Status, "confirmed") == 0)
            {
                printf("Reservation is already confirmed!\n");
                fclose(reservationPtr);
                fclose(tempReservation);
                remove("temp_reservation.txt");
                printf("Do you want to go back to the menu? If yes, type 'yes' \n");
                scanf("%s", ques);
                if (strcmp(ques, "yes") == 0)
                    menue("users.txt", "room.txt", "reservations.txt");
                else
                    exit(0);
            }

            char confirmation;
            printf("Do you want to confirm this reservation? (y/n): ");
            scanf(" %c", &confirmation);

            if (confirmation == 'y')
            {
                strcpy(currentReservation.room_reservation_Status, "confirmed");
                printf("Reservation confirmed successfully!\n");

                FILE *roomsPtr = fopen(roomsFile, "r");
                if (roomsPtr == NULL)
                {
                    printf("Error opening rooms file.\n");
                    fclose(reservationPtr);
                    fclose(tempReservation);
                    printf("Do you want to go back to the menu? If yes, type 'yes' \n");
                    scanf("%s", ques);
                    if (strcmp(ques, "yes") == 0)
                        menue("users.txt", "room.txt", "reservations.txt");
                    else
                        exit(0);
                }

                FILE *tempRooms = fopen("temp_rooms.txt", "w");
                if (tempRooms == NULL)
                {
                    printf("Error creating temporary rooms file.\n");
                    fclose(reservationPtr);
                    fclose(tempReservation);
                    fclose(roomsPtr);
                    printf("Do you want to go back to the menu? If yes, type 'yes' \n");
                    scanf("%s", ques);
                    if (strcmp(ques, "yes") == 0)
                        menue("users.txt", "room.txt", "reservations.txt");
                    else
                        exit(0);
                }

                char roomLine[500];
                while (fgets(roomLine, sizeof(roomLine), roomsPtr))
                {
                    int roomNum;
                    char availability[30], view[20];
                    float price;

                    sscanf(roomLine, "%d %s %s %f", &roomNum, availability, view, &price);
                    if (roomNum == currentReservation.roomnumber)
                    {
                        fprintf(tempRooms, "%d reserved %s %.2f\n", roomNum, view, price);
                    }
                    else
                    {
                        fputs(roomLine, tempRooms);
                    }
                }

                fclose(roomsPtr);
                fclose(tempRooms);
                remove(roomsFile);
                rename("temp_rooms.txt", roomsFile);
                printf("Room status updated successfully!\n");
            }
            else
            {
                printf("Reservation confirmation canceled.\n");
            }
        }

        fprintf(tempReservation, "%d,%d,%s,%s,%s,%d,%s,%s,%s\n",
                currentReservation.reservation_ID, currentReservation.roomnumber,
                currentReservation.room_reservation_Status, currentReservation.customer_name,
                currentReservation.customer_national_ID, currentReservation.number_ofnights,
                currentReservation.date, currentReservation.customer_email, currentReservation.mobile_number);
    }

    fclose(reservationPtr);
    fclose(tempReservation);

    if (found)
    {
        remove(reservationFile);
        rename("temp_reservation.txt", reservationFile);
    }
    else
    {
        printf("Reservation ID not found.\n");
        remove("temp_reservation.txt");
    }

    printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void CancelReservation(int usedBefore, const char *reservationFile, const char *roomsFile)
{
    char IDorROOMN[2];
    int reservationID;

    printf("Do you want to provide reservation ID (1) or room number (2)?");
    getchar();
    fgets(IDorROOMN, 2,stdin);
    IDorROOMN[1] = '\0';
    if (strcmp(IDorROOMN , "1") ==0) {

        printf("Please enter reservation ID: ");
        scanf("%d", &reservationID);
    }
    else if(strcmp(IDorROOMN , "2") ==0) {
        int roomNumber;
        printf("Please enter room number: ");
        scanf("%d", &roomNumber);
        FILE *reservationPtr = fopen(reservationFile, "r");
        char temp[500];
        reservations currentReservation;
        int foundReservation = 0;
        while (fgets(temp, sizeof(temp), reservationPtr)) {
            sscanf(temp, "%d,%d,%19[^,],%99[^,],%19[^,],%d,%19[^,],%99[^,],%19[^,]",
                   &currentReservation.reservation_ID, &currentReservation.roomnumber,
                   currentReservation.room_reservation_Status, currentReservation.customer_name,
                   currentReservation.customer_national_ID, &currentReservation.number_ofnights,
                   currentReservation.date, currentReservation.customer_email,
                   currentReservation.mobile_number);
            if (currentReservation.roomnumber == roomNumber) {
                reservationID = currentReservation.reservation_ID;
                foundReservation = 1;
            }
        }
        if(!foundReservation) {
            char userChoice[10];

            perror("Error finding reservation.");
            fclose(reservationPtr);
            fclose(reservationPtr);
            printf("Do you want to go back to the menu? Type 'yes' to return: ");
            scanf("%s", userChoice);
            if (strcmp(userChoice, "yes") == 0)
                menue("users.txt", "rooms.txt", "reservations.txt");
            else
                exit(EXIT_FAILURE);
        }
        fclose(reservationPtr);
    }
    else {
        char userChoice[10];

        perror("Error: Please enter valid input!");

        printf("Do you want to go back to the menu? Type 'yes' to return: ");
        scanf("%s", userChoice);
        if (strcmp(userChoice, "yes") == 0)
            menue("users.txt", "rooms.txt", "reservations.txt");
        else
            exit(EXIT_FAILURE);
    }
    char userChoice[10];
    char reservationLine[500], roomLine[500];
    reservations currentReservation;
    Rooms currentRoom;
    int reservationFound = 0;


    FILE *reservationPtr = fopen(reservationFile, "r");
    FILE *roomsPtr = fopen(roomsFile, "r");
    if (reservationPtr == NULL || roomsPtr == NULL)
    {
        perror("Error opening files");
        printf("Do you want to go back to the menu? Type 'yes' to return: ");
        scanf("%s", userChoice);
        if (strcmp(userChoice, "yes") == 0)
            menue("users.txt", "rooms.txt", "reservations.txt");
        else
            exit(EXIT_FAILURE);
    }


    FILE *tempRes = fopen("tempres.txt", "w");
    FILE *tempRoom = fopen("temproom.txt", "w");
    if (tempRes == NULL || tempRoom == NULL)
    {
        perror("Error creating temporary files");
        fclose(reservationPtr);
        fclose(roomsPtr);
        printf("Do you want to go back to the menu? Type 'yes' to return: ");
        scanf("%s", userChoice);
        if (strcmp(userChoice, "yes") == 0)
            menue("users.txt", "rooms.txt", "reservations.txt");
        else
            exit(EXIT_FAILURE);
    }


    while (fgets(reservationLine, sizeof(reservationLine), reservationPtr)) {
        sscanf(reservationLine, "%d,%d,%19[^,],%99[^,],%19[^,],%d,%19[^,],%99[^,],%19[^,]",
               &currentReservation.reservation_ID, &currentReservation.roomnumber,
               currentReservation.room_reservation_Status, currentReservation.customer_name,
               currentReservation.customer_national_ID, &currentReservation.number_ofnights,
               currentReservation.date, currentReservation.customer_email,
               currentReservation.mobile_number);

        if (currentReservation.reservation_ID == reservationID) {
            reservationFound = 1;

            if (strcmp(currentReservation.room_reservation_Status, "confirmed") == 0 && usedBefore != 1)
            {
                printf("Reservation is confirmed and cannot be cancelled!\n");
                fclose(reservationPtr);
                fclose(roomsPtr);
                fclose(tempRes);
                fclose(tempRoom);
                remove("tempres.txt");
                remove("temproom.txt");
                menue("users.txt", "rooms.txt", "reservations.txt");
            }

            printf("Reservation with ID %d is being cancelled.\n", reservationID);


            rewind(roomsPtr);
            while (fgets(roomLine, sizeof(roomLine), roomsPtr))
            {
                sscanf(roomLine, "%d %19s %49[^ ] %f", &currentRoom.room_number,
                       currentRoom.room_availability, currentRoom.room_view, &currentRoom.room_price);

                if (currentRoom.room_number == currentReservation.roomnumber)
                {
                    fprintf(tempRoom, "%d Available %s %.2f\n",
                            currentRoom.room_number, currentRoom.room_view, currentRoom.room_price);
                }
                else
                {
                    fputs(roomLine, tempRoom);
                }
            }
        }
        else
        {
            fputs(reservationLine, tempRes);
        }
    }


    if (!reservationFound)
    {
        printf("Reservation ID %d not found.\n", reservationID);
        fclose(reservationPtr);
        fclose(roomsPtr);
        fclose(tempRes);
        fclose(tempRoom);
        remove("tempres.txt");
        remove("temproom.txt");
        menue("users.txt", "rooms.txt", "reservations.txt");
    }



    fclose(reservationPtr);
    fclose(roomsPtr);
    fclose(tempRes);
    fclose(tempRoom);

    if (remove(reservationFile) != 0 || rename("tempres.txt", reservationFile) != 0)
        perror("Error updating reservation file");
    if (remove(roomsFile) != 0 || rename("temproom.txt", roomsFile) != 0)
        perror("Error updating room file");

    printf("Reservation cancelled successfully!\n");

    if (usedBefore != 1)
    {
        printf("Do you want to go back to the menu? Type 'yes' to return: ");
        scanf("%s", userChoice);
        if (strcmp(userChoice, "yes") == 0)
            menue("users.txt", "rooms.txt", "reservations.txt");
        else
            exit(EXIT_SUCCESS);
    }
    else
            exit(EXIT_SUCCESS);
}
void editReservation(const char *reservationFile, const char *roomsFile)
{ int counttt=0;
    char IDorROOMN[2];
    int reservationID;

    printf("Do you want to provide reservation ID (1) or room number (2)?");
    getchar();
    fgets(IDorROOMN, 2,stdin);
    IDorROOMN[1] = '\0';
    if (strcmp(IDorROOMN , "1") ==0) {

        printf("Please enter reservation ID: ");
        scanf("%d", &reservationID);
    }
    else if(strcmp(IDorROOMN , "2") ==0) {
        int roomNumber;
        printf("Please enter room number: ");
        scanf("%d", &roomNumber);
        FILE *reservationPtr = fopen(reservationFile, "r");
        char temp[500];
        reservations currentReservation;
        int foundReservation = 0;
        while (fgets(temp, sizeof(temp), reservationPtr)) {
            sscanf(temp, "%d,%d,%19[^,],%99[^,],%19[^,],%d,%19[^,],%99[^,],%19[^,]",
                   &currentReservation.reservation_ID, &currentReservation.roomnumber,
                   currentReservation.room_reservation_Status, currentReservation.customer_name,
                   currentReservation.customer_national_ID, &currentReservation.number_ofnights,
                   currentReservation.date, currentReservation.customer_email,
                   currentReservation.mobile_number);
            if (currentReservation.roomnumber == roomNumber) {
                reservationID = currentReservation.reservation_ID;
                foundReservation = 1;
            }
        }
        if(!foundReservation) {
            char userChoice[10];

            perror("Error finding reservation.");
            fclose(reservationPtr);
            fclose(reservationPtr);
            printf("Do you want to go back to the menu? Type 'yes' to return: ");
            scanf("%s", userChoice);
            if (strcmp(userChoice, "yes") == 0)
                menue("users.txt", "rooms.txt", "reservations.txt");
            else
                exit(EXIT_FAILURE);
        }
        fclose(reservationPtr);
    }
    else {
        char userChoice[10];

        perror("Error: Please enter valid input!");

        printf("Do you want to go back to the menu? Type 'yes' to return: ");
        scanf("%s", userChoice);
        if (strcmp(userChoice, "yes") == 0)
            menue("users.txt", "rooms.txt", "reservations.txt");
        else
            exit(EXIT_FAILURE);
    }
    char userChoice[20];
    FILE *reservationPtr = fopen(reservationFile, "r");
    if (reservationPtr == NULL)
    {
        printf("Error opening reservation file.\n");
        return;
    }

    FILE *tempReservation = fopen("temp_reservation.txt", "w");
    if (tempReservation == NULL)
    {
        printf("Error creating temporary reservation file.\n");
        fclose(reservationPtr);
        return;
    }

    char line[500];
    reservations currentReservation;
    int found = 0;

    while (fgets(line, sizeof(line), reservationPtr))
    {
        sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]",
               &currentReservation.reservation_ID, &currentReservation.roomnumber,
               currentReservation.room_reservation_Status, currentReservation.customer_name,
               currentReservation.customer_national_ID, &currentReservation.number_ofnights,
               currentReservation.date, currentReservation.customer_email,
               currentReservation.mobile_number);

        if (currentReservation.reservation_ID == reservationID)
        {
            found = 1;

            printf("Editing reservation:\n");
            printf("Reservation ID: %d\n", currentReservation.reservation_ID);

            char confirmation;

            // Edit room category
            printf("Do you want to edit the room category? (y to confirm, new reservation required): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                fclose(reservationPtr);
                fclose(tempReservation);
                remove(tempReservation);
                char reservationLine[500], roomLine[500];
                reservations currentReservation;
                Rooms currentRoom;
                int reservationFound = 0;


                FILE *reservationPtr = fopen(reservationFile, "r");
                FILE *roomsPtr = fopen(roomsFile, "r");
                if (reservationPtr == NULL || roomsPtr == NULL)
                {
                    perror("Error opening files");
                    printf("Do you want to go back to the menu? Type 'yes' to return: ");
                    scanf("%s", userChoice);
                    if (strcmp(userChoice, "yes") == 0)
                        menue("users.txt", "rooms.txt", "reservations.txt");
                    else
                        exit(EXIT_FAILURE);
                }


                FILE *tempRes = fopen("tempres.txt", "w");
                FILE *tempRoom = fopen("temproom.txt", "w");
                if (tempRes == NULL || tempRoom == NULL)
                {
                    perror("Error creating temporary files");
                    fclose(reservationPtr);
                    fclose(roomsPtr);
                    printf("Do you want to go back to the menu? Type 'yes' to return: ");
                    scanf("%s", userChoice);
                    if (strcmp(userChoice, "yes") == 0)
                        menue("users.txt", "rooms.txt", "reservations.txt");
                    else
                        exit(EXIT_FAILURE);
                }


                while (fgets(reservationLine, sizeof(reservationLine), reservationPtr))
                {
                    sscanf(reservationLine, "%d,%d,%19[^,],%99[^,],%19[^,],%d,%19[^,],%99[^,],%19[^,]",
                           &currentReservation.reservation_ID, &currentReservation.roomnumber,
                           currentReservation.room_reservation_Status, currentReservation.customer_name,
                           currentReservation.customer_national_ID, &currentReservation.number_ofnights,
                           currentReservation.date, currentReservation.customer_email,
                           currentReservation.mobile_number);

                    if (currentReservation.reservation_ID == reservationID)
                    {
                        reservationFound = 1;

                        if (strcmp(currentReservation.room_reservation_Status, "confirmed") == 0)
                        {
                            printf("Reservation is confirmed and cannot be cancelled!\n");
                            fclose(reservationPtr);
                            fclose(roomsPtr);
                            fclose(tempRes);
                            fclose(tempRoom);
                            remove("tempres.txt");
                            remove("temproom.txt");
                            return;
                        }

                        printf("Reservation with ID %d is being cancelled.\n", reservationID);


                        rewind(roomsPtr);
                        while (fgets(roomLine, sizeof(roomLine), roomsPtr))
                        {
                            sscanf(roomLine, "%d %19s %49[^ ] %f", &currentRoom.room_number,
                                   currentRoom.room_availability, currentRoom.room_view, &currentRoom.room_price);

                            if (currentRoom.room_number == currentReservation.roomnumber)
                            {
                                fprintf(tempRoom, "%d Available %s %.2f\n",
                                        currentRoom.room_number, currentRoom.room_view, currentRoom.room_price);
                            }
                            else
                            {
                                fputs(roomLine, tempRoom);
                            }
                        }
                    }
                    else
                    {
                        fputs(reservationLine, tempRes);
                    }
                }


                if (!reservationFound)
                {
                    printf("Reservation ID %d not found.\n", reservationID);
                    fclose(reservationPtr);
                    fclose(roomsPtr);
                    fclose(tempRes);
                    fclose(tempRoom);
                    remove("tempres.txt");
                    remove("temproom.txt");
                    return;
                }



                fclose(reservationPtr);
                fclose(roomsPtr);
                fclose(tempRes);
                fclose(tempRoom);

                if (remove(reservationFile) != 0 || rename("tempres.txt", reservationFile) != 0)
                    perror("Error updating reservation file");
                if (remove(roomsFile) != 0 || rename("temproom.txt", roomsFile) != 0)
                    perror("Error updating room file");

                printf("Reservation cancelled successfully!\n");
                //reserve new room.
                FILE *f2,*f3;
                char namee[20], emaill[30], roomcat[20], checkdate[20], mobilephone[20], nationalid[30];
                int nonights;
                char ques[3];
                Rooms availableRooms[6];
                int Count = 0;
                reservations newReservation;

                printf("Enter customer name: ");
                gets(namee);
for (int i = 0; namee[i] != '\0'; i++) {
        if (isdigit(namee[i])) {
            printf("Enter valid input.\n");
           printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
                printf("Enter customer email: ");
    gets(emaill);
for (int i = 0; emaill[i] != '\0'; i++) {
        if (emaill[i] == '@') {
            counttt++;
        }
        if (isdigit(emaill[i])) {
             printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
        if(counttt!=1)
        {printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
    }}
                printf("Enter customer's national ID: ");
                gets(nationalid);
for (int i = 0; nationalid[i] != '\0'; i++) {
        if (!isdigit(nationalid[i])) {
            printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
                printf("Enter customer's phone number: ");
                gets(mobilephone);
for (int i = 0; mobilephone[i] != '\0'; i++) {
        if (!isdigit(mobilephone[i])) {
            printf("Enter valid input.\n");
            printf("Do you want to go back to the menu? If yes, type 'yes' \n");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
        }
    }
                printf("Enter number of nights: ");
                scanf("%d", &nonights);

                getchar();
                printf("Enter check-in date d-m-y: ");
                gets(checkdate);

                printf("Enter room category ('Seaview', 'Lakeview', or 'Gardenview'): ");
                gets(roomcat);


                for (int i = 0; roomcat[i]; i++)
                {
                    if (roomcat[i] >= 'A' && roomcat[i] <= 'Z')
                    {
                        roomcat[i] += 'a' - 'A';
                    }
                }

                f2 = fopen("room.txt", "r");
                if (f2 == NULL)
                {
                    printf("Error opening file room.txt\n");
                    exit(1);
                }

                while (fscanf(f2, "%d %s %s %f", &availableRooms[Count].room_number,
                              availableRooms[Count].room_availability,
                              availableRooms[Count].room_view,
                              &availableRooms[Count].room_price) == 4)
                {
                    for (int i = 0; availableRooms[Count].room_view[i]; i++)
                    {
                        if (availableRooms[Count].room_view[i] >= 'A' && availableRooms[Count].room_view[i] <= 'Z')
                        {
                            availableRooms[Count].room_view[i] += 'a' - 'A';
                        }
                    }
                    if (strcmp(availableRooms[Count].room_availability, "Available") == 0 &&
                            strcmp(availableRooms[Count].room_view, roomcat) == 0)
                    {
                        Count++;
                    }
                }
                fclose(f2);

                if (Count == 0)
                {
                    printf("No rooms available in the selected category.\n");
                    menue("users.txt", "room.txt", "reservations.txt");
                }

                int assignedRoom = availableRooms[0].room_number;
                int reservationID = generateID(f3);

                newReservation.reservation_ID = reservationID;
                newReservation.roomnumber = assignedRoom;
                strcpy(newReservation.room_reservation_Status, "Unconfirmed");
                strcpy(newReservation.customer_name, namee);
                strcpy(newReservation.customer_national_ID, nationalid);
                newReservation.number_ofnights = nonights;
                strcpy(newReservation.date, checkdate);
                strcpy(newReservation.customer_email, emaill);
                strcpy(newReservation.mobile_number, mobilephone);

                f3 = fopen("reservations.txt", "a");
                if (f3 == NULL)
                {
                    printf("Error opening file reservations.txt\n");
                    exit(1);
                }
                fprintf(f3, "%d,%d,%s,%s,%s,%d,%s,%s,%s\n",
                        newReservation.reservation_ID, newReservation.roomnumber,
                        newReservation.room_reservation_Status, newReservation.customer_name,
                        newReservation.customer_national_ID, newReservation.number_ofnights,
                        newReservation.date, newReservation.customer_email, newReservation.mobile_number);
                fclose(f3);

                printf("Your reservation is confirmed!\n");
                printf("Reservation ID: %d\n", reservationID);

                printf("Do you want to go back to the menu? If yes, type 'yes': ");
                scanf("%s", ques);
                if (strcmp(ques, "yes") == 0)
                    menue("users.txt", "room.txt", "reservations.txt");
                else
                    exit(0);


            }

            // Edit customer name
            printf("Do you want to edit the customer name? (y to confirm): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                printf("Enter new customer name: ");
                fgets(currentReservation.customer_name, sizeof(currentReservation.customer_name), stdin);
                currentReservation.customer_name[strcspn(currentReservation.customer_name, "\n")] = '\0';
            }

            // Edit mobile number
            printf("Do you want to edit the mobile number? (y to confirm): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                printf("Enter new mobile number: ");
                fgets(currentReservation.mobile_number, sizeof(currentReservation.mobile_number), stdin);
                currentReservation.mobile_number[strcspn(currentReservation.mobile_number, "\n")] = '\0';
            }

            // Edit email address
            printf("Do you want to edit the email address? (y to confirm): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                printf("Enter new email address: ");
                fgets(currentReservation.customer_email, sizeof(currentReservation.customer_email), stdin);
                currentReservation.customer_email[strcspn(currentReservation.customer_email, "\n")] = '\0';
            }

            // Edit number of nights
            printf("Do you want to edit the number of nights? (y to confirm): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                printf("Enter new number of nights: ");
                scanf("%d", &currentReservation.number_ofnights);
            }

            // Edit reservation date
            printf("Do you want to edit the reservation date? (y to confirm): ");
            scanf(" %c", &confirmation);
            getchar();
            if (confirmation == 'y')
            {
                int day, month, year;
                printf("Enter new reservation date (DD MM YYYY): ");
                scanf("%d %d %d", &day, &month, &year);
                snprintf(currentReservation.date, sizeof(currentReservation.date), "%02d-%02d-%04d", day, month, year);
            }
        }

        fprintf(tempReservation, "%d,%d,%s,%s,%s,%d,%s,%s,%s\n",
                currentReservation.reservation_ID, currentReservation.roomnumber,
                currentReservation.room_reservation_Status, currentReservation.customer_name,
                currentReservation.customer_national_ID, currentReservation.number_ofnights,
                currentReservation.date, currentReservation.customer_email,
                currentReservation.mobile_number);
    }

    fclose(reservationPtr);
    fclose(tempReservation);

    if (found)
    {
        remove(reservationFile);
        rename("temp_reservation.txt", reservationFile);
        printf("Reservation updated successfully.\n");
    }
    else
    {
        printf("Reservation ID not found.\n");
        remove("temp_reservation.txt");
    }

    char ques[3];
    printf("Do you want to go back to the menu? If yes, type 'yes': ");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
    {
        menue("users.txt", "room.txt", "reservations.txt");
    }
    else
    {
        exit(0);
    }
}



void Tracking_Rooms_Availability(FILE *f2)
{
    char ques[3];
    char c;

    f2=fopen("room.txt","r");
    while((c=fgetc(f2))!=EOF)
    {
        printf("%c",c);
    }
    fclose(f2);
    printf("do you want to go back to the menu? if yes then type 'yes' \n" );
    scanf("%s",ques);
    if(strcmp(ques,"yes")==0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void View_Customer_Details(const char *reservationsFile)
{
    int searchChoice;
    char ques[10];
    printf("Search customer details by:\n");
    printf("1. Reservation ID\n");
    printf("2. Room Number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &searchChoice);
    getchar();

    FILE *f3 = fopen(reservationsFile, "r");
    if (f3 == NULL)
    {
        printf("Error opening %s\n", reservationsFile);
        return;
    }

    char line[500];
    reservations currentReservation;
    int found = 0;
    if (searchChoice == 1)
    {
        int reservationID;
        printf("Enter Reservation ID: ");
        scanf("%d", &reservationID);
        getchar();

        while (fgets(line, sizeof(line), f3))
        {
            if (sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,]",
                       &currentReservation.reservation_ID,
                       &currentReservation.roomnumber,
                       currentReservation.room_reservation_Status,
                       currentReservation.customer_name,
                       currentReservation.customer_national_ID,
                       &currentReservation.number_ofnights,
                       currentReservation.date,
                       currentReservation.customer_email,
                       currentReservation.mobile_number) == 9 &&
                    currentReservation.reservation_ID == reservationID)
            {
                found = 1;
                break;
            }
        }
    }
    else if (searchChoice == 2)
    {
        int roomNumber;
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);
        getchar();

        while (fgets(line, sizeof(line), f3))
        {
            if (sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,]",
                       &currentReservation.reservation_ID,
                       &currentReservation.roomnumber,
                       currentReservation.room_reservation_Status,
                       currentReservation.customer_name,
                       currentReservation.customer_national_ID,
                       &currentReservation.number_ofnights,
                       currentReservation.date,
                       currentReservation.customer_email,
                       currentReservation.mobile_number) == 9 &&
                    currentReservation.roomnumber == roomNumber)
            {
                found = 1;
                break;
            }
        }
    }
    fclose(f3);

    if (found)
    {
        printf("\nCustomer Details:\n");
        printf("Name: %s\n", currentReservation.customer_name);
        printf("Email: %s\n", currentReservation.customer_email);
        printf("Mobile: %s\n", currentReservation.mobile_number);
        printf("National ID: %s\n", currentReservation.customer_national_ID);
        printf("Room Number: %d\n", currentReservation.roomnumber);
        printf("Check-in Date: %s\n", currentReservation.date);
        printf("Number of Nights: %d\n", currentReservation.number_ofnights);
        printf("Reservation Status: %s\n", currentReservation.room_reservation_Status);
    }
    else
    {
        printf("No customer found with the given criteria.\n");
    }

    printf("\nDo you want to go back to the menu? If yes, type 'yes': ");
    fgets(ques, sizeof(ques), stdin);
    if (strncmp(ques, "yes", 3) == 0) menue("users.txt", "room.txt", "reservations.txt");
    else exit(0);
}
void Check_Out(const char *reservationsFile, const char *roomsFile)
{
    int reservationID;
    int targetRoomNumber;
    int targetNumberOfNights;
    printf("Enter Reservation ID for Check-Out: ");
    scanf("%d", &reservationID);
    getchar();

    FILE *fRes = fopen(reservationsFile, "r");
    if (fRes == NULL)
    {
        printf("Error opening reservations file.\n");
        return;
    }

    FILE *tempRes = fopen("temp_reservations.txt", "w");
    if (tempRes == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(fRes);
        return;
    }

    char line[500];
    reservations currentReservation;
    int found = 0;
    float totalBill = 0.0;

    while (fgets(line, sizeof(line), fRes))
    {
        int n = sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]",
                       &currentReservation.reservation_ID,
                       &currentReservation.roomnumber,
                       currentReservation.room_reservation_Status,
                       currentReservation.customer_name,
                       currentReservation.customer_national_ID,
                       &currentReservation.number_ofnights,
                       currentReservation.date,
                       currentReservation.customer_email,
                       currentReservation.mobile_number);

        if (n == 9 && currentReservation.reservation_ID == reservationID)
        {
            found = 1;
            targetRoomNumber = currentReservation.roomnumber;
            struct tm tm1 = {0};
            int year, month, day;

            sscanf(currentReservation.date,"%2d-%2d-%4d", &day, &month, &year);
            tm1.tm_mon = month -1;
            tm1.tm_year = year -1900;
            tm1.tm_mday = day;
            mktime(&tm1);

            time_t time1;
            time1 = mktime(&tm1);
            time_t time_now = time(NULL);
            char current_date_str[11];
            struct tm *current_tm = localtime(&time_now);
            strftime(current_date_str, sizeof(current_date_str), "%d-%m-%Y", current_tm);

            double difference = difftime(time_now, time1);
            targetNumberOfNights =(difference / (60 * 60 * 24));
            if (strcmp(currentReservation.room_reservation_Status, "confirmed") != 0)
            {
                printf("Error: Only confirmed reservations can be checked out.\n");
                fclose(fRes);
                fclose(tempRes);
                remove("temp_reservations.txt");
                return;
            }
        }
        else
        {
            fprintf(tempRes, "%s", line);
        }
    }

    if (!found)
    {
        printf("Reservation ID not found.\n");
        fclose(fRes);
        fclose(tempRes);
        remove("temp_reservations.txt");
        return;
    }

    FILE *fRooms = fopen(roomsFile, "r");
    FILE *tempRooms = fopen("temp_rooms.txt", "w");
    if (!fRooms || !tempRooms)
    {
        printf("Error opening room files.\n");
        fclose(fRes);
        fclose(tempRes);
        if (fRooms) fclose(fRooms);
        if (tempRooms) fclose(tempRooms);
        remove("temp_reservations.txt");
        return;
    }

    char roomLine[500];
    while (fgets(roomLine, sizeof(roomLine), fRooms))
    {
        int roomNum;
        char availability[30], view[20];
        float price;

        sscanf(roomLine, "%d %s %s %f", &roomNum, availability, view, &price);

        if (roomNum == targetRoomNumber)
        {
            totalBill = price * targetNumberOfNights;
            fprintf(tempRooms, "%d Available %s %.2f\n", roomNum, view, price);
        }
        else
        {
            fprintf(tempRooms, "%s", roomLine);
        }
    }

    fclose(fRooms);
    fclose(tempRooms);
    fclose(fRes);
    fclose(tempRes);

    remove(reservationsFile);
    rename("temp_reservations.txt", reservationsFile);
    remove(roomsFile);
    rename("temp_rooms.txt", roomsFile);

    printf("\nCheck-out successful!\n");
    printf("Total Bill: %.2f\n", totalBill);
    printf("Room %d is now available.\n", targetRoomNumber);
    printf("Do you want to go back to the menu? If yes, type 'yes': \n");
    char ques[10];
    scanf("%s",ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void UpdateRoomStatus(const char *roomsFile)
{
    char ques[3];
    int roomNumber;
    int found = 0;

    FILE *fRooms = fopen(roomsFile, "r");
    if (!fRooms)
    {
        printf("Error opening %s\n", roomsFile);
        return;
    }

    FILE *tempRooms = fopen("temp_rooms.txt", "w");
    if (!tempRooms)
    {
        printf("Error creating temp_rooms.txt\n");
        fclose(fRooms);
        return;
    }


    printf("Enter the room number to update its status (if 'reserved' -> 'Available'): ");
    scanf("%d", &roomNumber);
    getchar();

    char line[200];
    while (fgets(line, sizeof(line), fRooms))
    {
        Rooms current;
        int parsed = sscanf(line, "%d %s %s %f",
                            &current.room_number,
                            current.room_availability,
                            current.room_view,
                            &current.room_price);

        if (parsed == 4 && current.room_number == roomNumber)
        {
            found = 1;
            if (strcmp(current.room_availability, "reserved") == 0 ||
                    strcmp(current.room_availability, "Reserved") == 0)
            {

                strcpy(current.room_availability, "Available");
                printf("Room %d status changed to 'Available'.\n", current.room_number);
            }
            else
            {
                printf("Room %d is not in 'reserved' status.\n", current.room_number);
            }

            fprintf(tempRooms, "%d %s %s %.2f\n",
                    current.room_number,
                    current.room_availability,
                    current.room_view,
                    current.room_price);
        }
        else
        {

            fputs(line, tempRooms);
        }
    }
    fclose(fRooms);
    fclose(tempRooms);

    if (!found)
    {
        printf("Room number %d not found in %s.\n", roomNumber, roomsFile);
        remove("temp_rooms.txt");
    }
    else
    {

        char saveChoice[10];
        printf("Do you want to SAVE these changes? (y/n): ");
        fgets(saveChoice, sizeof(saveChoice), stdin);
        saveChoice[strcspn(saveChoice, "\n")] = '\0';

        if (saveChoice[0] == 'y' || saveChoice[0] == 'Y')
        {

            remove(roomsFile);
            rename("temp_rooms.txt", roomsFile);
            printf("Changes saved!\n");
        }
        else
        {

            remove("temp_rooms.txt");
            printf("Changes discarded.\n");
        }


        char ques[3];
        printf("do you want to go back to the menu? if yes then type 'yes' \n" );
        scanf("%s",ques);
        if(strcmp(ques,"yes")==0)
            menue("users.txt", "room.txt", "reservations.txt");
        else
            exit(0);
    }
}

void SEARCH(const char *reservationsFile, const char *roomsFile)
{
    int searchChoice;
    printf("Search Options:\n");
    printf("1. By Customer Name\n");
    printf("2. By Room Number\n");
    printf("3. By Room Status (Available/Occupied)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &searchChoice);
    getchar();

    if (searchChoice == 1)
    {
        char customerName[100];
        printf("Enter Customer Name: ");
        fgets(customerName, sizeof(customerName), stdin);
        customerName[strcspn(customerName, "\n")] = '\0';
        FILE *fRes = fopen(reservationsFile, "r");
        if (fRes == NULL)
        {
            printf("Error opening reservations file.\n");
            return;
        }

        char line[500];
        reservations currentReservation;
        int found = 0;

        while (fgets(line, sizeof(line), fRes))
        {
            sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]",
                   &currentReservation.reservation_ID, &currentReservation.roomnumber,
                   currentReservation.room_reservation_Status, currentReservation.customer_name,
                   currentReservation.customer_national_ID, &currentReservation.number_ofnights,
                   currentReservation.date, currentReservation.customer_email,
                   currentReservation.mobile_number);

            if (strcmp(currentReservation.customer_name, customerName) == 0)
            {
                printf("\nReservation Details:\n");
                printf("Reservation ID: %d\n", currentReservation.reservation_ID);
                printf("Room Number: %d\n", currentReservation.roomnumber);
                printf("Check-in Date: %s\n", currentReservation.date);
                printf("Status: %s\n", currentReservation.room_reservation_Status);
                printf("National ID: %s\n", currentReservation.customer_national_ID);
                printf("Email: %s\n", currentReservation.customer_email);
                printf("Mobile: %s\n", currentReservation.mobile_number);
                found = 1;
            }
        }
        fclose(fRes);

        if (!found)
        {
            printf("No reservations found for customer: %s\n", customerName);
        }

    }
    else if (searchChoice == 2)
    {
        int roomNumber;
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);

        FILE *fRes = fopen(reservationsFile, "r");
        if (fRes == NULL)
        {
            printf("Error opening reservations file.\n");
            return;
        }

        char line[500];
        reservations currentReservation;
        int found = 0;

        while (fgets(line, sizeof(line), fRes))
        {
            sscanf(line, "%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^\n]",
                   &currentReservation.reservation_ID, &currentReservation.roomnumber,
                   currentReservation.room_reservation_Status, currentReservation.customer_name,
                   currentReservation.customer_national_ID, &currentReservation.number_ofnights,
                   currentReservation.date, currentReservation.customer_email,
                   currentReservation.mobile_number);

            if (currentReservation.roomnumber == roomNumber)
            {
                printf("\nRoom Details:\n");
                printf("Reservation ID: %d\n", currentReservation.reservation_ID);
                printf("Customer Name: %s\n", currentReservation.customer_name);
                printf("Status: %s\n", currentReservation.room_reservation_Status);
                found = 1;
            }
        }
        fclose(fRes);

        if (!found)
        {
            printf("No reservations found for room number: %d\n", roomNumber);
        }

    }
    else if (searchChoice == 3)
    {
        char roomStatus[30];
        printf("Enter Room Status (Available/Occupied): ");
        scanf("%s", roomStatus);

        FILE *fRooms = fopen(roomsFile, "r");
        if (fRooms == NULL)
        {
            printf("Error opening rooms file.\n");
            return;
        }

        char line[500];
        Rooms currentRoom;
        int found = 0;

        while (fgets(line, sizeof(line), fRooms))
        {
            sscanf(line, "%d %s %s %f", &currentRoom.room_number,
                   currentRoom.room_availability, currentRoom.room_view,
                   &currentRoom.room_price);
            if (strcmp(currentRoom.room_availability, roomStatus) == 0)
            {
                printf("\nRoom Details:\n");
                printf("Room Number: %d\n", currentRoom.room_number);
                printf("View: %s\n", currentRoom.room_view);
                printf("Price: %.2f\n", currentRoom.room_price);
                found = 1;
            }
        }
        fclose(fRooms);

        if (!found)
        {
            printf("No rooms found with status: %s\n", roomStatus);
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    char ques[3];
    printf("do you want to go back to the menu? if yes then type 'yes' \n" );
    scanf("%s",ques);
    if(strcmp(ques,"yes")==0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void REPORT(FILE *f3)
{
    char ddate[20];
    printf("Enter the date (DD-MM-YYYY): ");
    getchar();
    fgets(ddate, sizeof(ddate), stdin);
    ddate[strcspn(ddate, "\n")] = 0;

    f3 = fopen("reservations.txt", "r");
    if (f3 == NULL)
    {
        printf("Error opening file: reservations.txt\n");
        return;
    }

    char line[500];
    reservations currentReservation;
    int z=0;

    printf("\nReservations on %s:\n", ddate);
    while (fgets(line, sizeof(line), f3))
    {
        char *s;

        s = strtok(line, ",");
        if (s != NULL)
            currentReservation.reservation_ID = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            currentReservation.roomnumber = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.room_reservation_Status, s, sizeof(currentReservation.room_reservation_Status) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_name, s, sizeof(currentReservation.customer_name) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_national_ID, s, sizeof(currentReservation.customer_national_ID) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            currentReservation.number_ofnights = atoi(s);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.date, s, sizeof(currentReservation.date) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.customer_email, s, sizeof(currentReservation.customer_email) - 1);

        s = strtok(NULL, ",");
        if (s != NULL)
            strncpy(currentReservation.mobile_number, s, sizeof(currentReservation.mobile_number) - 1);


        if (strcmp(ddate, currentReservation.date) == 0)
        {
            printf("Reservation ID: %d\n", currentReservation.reservation_ID);
            printf("Room Number: %d\n", currentReservation.roomnumber);
            printf("Status: %s\n", currentReservation.room_reservation_Status);
            printf("Name: %s\n", currentReservation.customer_name);
            printf("National ID: %s\n", currentReservation.customer_national_ID);
            printf("Number of Nights: %d\n", currentReservation.number_ofnights);
            printf("Email: %s\n", currentReservation.customer_email);
            printf("Phone: %s\n", currentReservation.mobile_number);
            printf("---------------------------------\n");
            z = 1;
        }
    }

    if (!z)
    {
        printf("No reservations found for the given date: %s.\n", ddate);
    }

    fclose(f3);

    char ques[3];
    printf("\nDo you want to go back to the menu? If yes, type 'yes': ");
    scanf("%s", ques);
    if (strcmp(ques, "yes") == 0)
        menue("users.txt", "room.txt", "reservations.txt");
    else
        exit(0);
}
void QUIT()
{
    printf("Logged out successfully! \n");
    exit(0);
}
void menue(FILE *f1, FILE *f2, FILE *f3)
{
    int number;
    printf("1-load \n"); //no
    printf("2-RoomReservation \n");
    printf("3-Check_In \n");
    printf("4-CancelReservation \n");
    printf("5-Edit Reservation \n");
    printf("6-Tracking Rooms Availability \n");
    printf("7-View Customer Details \n");
    printf("8-Check-Out \n");
    printf("9-UpdateRoomStatus \n");
    printf("10-SEARCH \n");
    printf("11-REPORT \n");
    printf("12-QUIT \n");
    printf("what do you want? \n");
    scanf("%d",&number);
    switch (number)
    {
    case 1:
    {
        load_reservations(f3);
        break;
    }
    case 2:
    {
        Room_Reservation(0, f2,f3);
        break;
    }
    case 3:
    {
        int reservationID;
        printf("Enter Reservation ID for Check-in: ");
        scanf("%d", &reservationID);

        Check_in(reservationID, "reservations.txt", "room.txt");
        break;
    }
    case 4:
    {

        CancelReservation(0, "reservations.txt", "room.txt");
        break;
    }

    case 5:
    {

        editReservation( "reservations.txt", "room.txt");
        break;
    }
    case 6:
    {
        Tracking_Rooms_Availability(f2);
        break;
    }
    case 7:
    {
        View_Customer_Details("reservations.txt");
        break;
    }
    case 8:
    {
        Check_Out("reservations.txt", "room.txt");
        break;
    }
    case 9:
    {
        UpdateRoomStatus("room.txt");
        break;
    }
    case 10:
    {

        SEARCH("reservations.txt", "room.txt");
        break;
    }
    case 11:
    {

        REPORT("reservations.txt");
        break;
    }
    case 12:
    {

        QUIT();
        break;
    }
    }

}
