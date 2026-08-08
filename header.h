#ifndef header_H_
#define header_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    char Username[20];
    char password[20];
} User;
typedef struct
{
    int room_number;
    char room_availability[30];
    char room_view[20];
    float room_price;
} Rooms;
typedef struct
{
    int reservation_ID;
    int roomnumber;
    char room_reservation_Status[30];
    char customer_name[100];
    char customer_national_ID[30];
    int number_ofnights;
    char date[15];
    char customer_email[50];
    char mobile_number[20];
} reservations;

void sort(reservations a[], int count);
void load_reservations(FILE *f3);
void menue(FILE *f1, FILE *f2, FILE *f3);
int generateID(FILE *f3);
void Room_Reservation(int usedBefore, FILE *f2, FILE *f3);
void Check_in(int reservationID, const char *reservationFile, const char *roomsFile);
void CancelReservation(int usedBefore, const char *reservationFile, const char *roomsFile);
void editReservation(const char *reservationFile, const char *roomsFile);
void Tracking_Rooms_Availability(FILE *f2);
void View_Customer_Details(const char *reservationsFile);
void Check_Out(const char *reservationsFile, const char *roomsFile);
void UpdateRoomStatus(const char *roomsFile);
void SEARCH(const char *reservationsFile, const char *roomsFile);
void REPORT(FILE *f3);
void QUIT();
#endif
