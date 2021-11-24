// Kino.cpp : Defines the entry point for the application.
//

#include "Kino.h"
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct moviedetails
{
	char name [300];
	int phone = 0;
	int count = 0;
	int id2 = 1000;
	int seat = 0;
} person;




void save(void)
{
	int i, j;
	FILE* filepath;
	fopen_s(&filepath, "C:\\Users\\Martin\\source\\repos\\Kino\\seat beckup.txt","a");
	fprintf(filepath, "%d %d %s %d %d\n ", person.count, person.seat, person.name, person.phone, person.id2); 
	fclose(filepath);
}
void read(void)
{
	FILE* fp = fopen("C:\\Users\\Martin\\source\\repos\\Kino\\seat beckup.txt", "r");
	     if (fp == NULL) {
	        perror("Unable to open file!");
         exit(1);
	
	}
	
	    char chunk[128];
		
	   while (fgets(chunk, sizeof(chunk), fp) != NULL) {
		   char pomocni[32];
		   for (int i = 0; i < 128; i++)
		   {
			   if (isalnum(chunk[i]))
			   {
				  pomocni = chunk[i];
			   }
			}
			   fputs(chunk, stdout);
			   printf_s("\n");
		   }

    fclose(fp);
}
int changeprize(int prize)
{
	char pass[10], pak[10] = "pass";
	printf("na zmenu ceny listka je potrebne zadat heslo: ");
	scanf("%s", &pass);
	if (strcmp(pass, pak) == 0)
	{
		printf("Vložte novú cenu lístka : ");
		scanf("%d", &prize);

	}
	else
		printf("Vlozili ste nespravne heslo.");
	system("CLS");
	return prize;
}

int choice1(void)
{
	int choice;
	printf(" Rezervacny sistem Multikina\n");
	printf("1- Rezervacia listka:\n");
	printf("2- Zrusenie rezervacie:\n");
	printf("3- Uprava ceny listka (vyzaduje heslo):\n");
	printf("4- zobrazenie rezervovanych sedadiel (vyzaduje heslo):\n");
	printf("5- vystupenie zo sistemu:\n");
	printf("  Vlozte svoju Volbu: ");
	scanf("%d", &choice);
	return choice;
}
void cancel(int* array)
{
	int Cseat, i, stop;
	printf("Please enter ID number of ticket: ");
	scanf("%d", &Cseat);
	for (i = 0; i < sizeof(array); i++)
	{
		if (Cseat == person.id2)
		{
			stop = 5;
			printf("%s your seat is %d cancelled", person.name, person.seat);
			array[person.seat] = 0;
			i = 300;
		}
	}
	if (stop != 5)
		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice, char name[10], int id2, int price)
{

	printf("Vas Rezervovany listok");
	printf("\t Cislo Listka: %d \t\t\tPredstavenie: Duna\n", id2+1);
	printf("\t Zakaznik: %s\n", name);
	printf("Datum: 20-11-2021\n");
	printf("Cas Premietania: 20:00\n");
	printf("Sala: 02\n");
	printf("Sedadlo Cislo: %d  \n", choice);
	printf("Cena: %d  \n\n", price);
}
void details(void)
{
	int i;
	char pass[10], pak[10] = "pass";
	printf("Na zobrazenie detailov je potrebne zadat Heslo: ");
	scanf("%s", &pass);
	if (strcmp(pass, pak) == 0)
	{
		for (i = 0; i < person.count; i++)
		{
			printf("Sedadlo Cislo: %d Je rezervovvane  %s Cislo Listka Je %d\n", person.seat, person.name, person.id2);
		}
	}
	else
		printf("Vlozili Ste nespravne heslo \n");
	system("CLS");

}
int movie(void)
{
	int i;
	printf("Na Aky film si chcete rezervovat listok?\n");
	printf("stlacte 1 pre: Duna\n\n");
	printf("Stlacte 2 pre: James Bond:No time to die\n\n");
	printf("press 3 for Spider-Man: Far From Home\n");
	scanf("%d", &i);
	return i;
}
void ticket2(int choice, char name[10], int id2, int price)
{
	printf("\n\n");
	printf("\t-----------------THEATER BOOKING TICKET----------------\n");
	printf("\t Booking ID : %d \t\t\tShow Name :James Bond:No time to die\n", id2);
	printf("\t Customer  : %s\n", name);
	printf("\t\t\t                              Date      : 17-11-2021\n");
	printf("\t                                              Time      : 09:00pm\n");
	printf("\t                                              Hall      : 03\n");
	printf("\t                                              seats No. : %d  \n", choice);
	printf("\t                                              price . : %d  \n\n", price);
	
}
int cmovie(void)
{
	int i;
	printf("\t\t\twhich movie ticket you want to cancel\n");
	printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
	printf("\t\t\tpress 2 for Captain Marvel\n\n");
	printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
	scanf("%d", &i);
	return i;
}
void ticket3(int choice, char name[10], int id2, int price)
{
	printf("\t-----------------THEATER BOOKING TICKET----------------\n");
	printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home \n", id2);
	printf("\t Customer  : %s\n", name);
	printf("\t\t\t                              Date      : 17-12-2021\n");
	printf("\t                                              Time      : 10:00pm\n");
	printf("\t                                              Hall      : 04\n");
	printf("\t                                              seats No. : %d  \n", choice);
	printf("\t                                              price . : %d  \n\n", price);
}
void reservation(int* array, int price, int slection)
{
	int i, j;
	for (i = 1; i <= 100; i++)
	{
		if (array[i] == 0)
			printf("%d\t", i);
		else
			printf("*\t", i);
		if (i % 10 == 0)
			printf("\n\n");
	}
	printf("Please enter your name: ");
	scanf(" %19[^\n]%*[^\n]", &person.name);
	printf("Please enter your phone number: ");
	scanf("%u", &person.phone);
	printf("Which seat number you want? ");
	scanf("%d", &j);
	if (j > 100 || j < 1)
	{
		printf("seat1 number is unavailable in this theater\n");
		printf("Please re-enter seat number: ");
		scanf("%d", &j);
	}
	if (array[j] == 1)
	{
		printf("Sorry, this ticket is already booked! Please choose another seat.\n");
		scanf("%d", &j);
	}
	else
		array[j] = 1;
	if (slection == 1)
		ticket1(j, person.name, person.id2, price);
	else if (slection == 2)
		ticket2(j, person.name, person.id2, price);
	else
		ticket3(j, person.name, person.id2, price);
	person.seat = j;
	person.id2++;
	person.count++;
	save();
}

int main()
{
	read();
	int** seat, choice, price = 500, slection, i;
	seat = (int**)calloc(101, sizeof(int*));
	for (i = 0; i < 3; i++)
		*(seat + i) = (int*)calloc(101, sizeof(int));
	int x=0;
	while (x != 5)
	{
		choice = choice1();
		switch (choice)
		{
		case 3:
			price = changeprize(price);
			break;

		case 1:
			slection = movie();
			reservation(seat[slection - 1], price, slection);
			break;
		case 2:
			slection = cmovie();
			cancel(seat[slection - 1]);
			break;
			case 4:
			details();
			break;
		case 5:
			x = 5;
			break;
		default:
			printf("volba nedostupna\n");
			break;
		}
		
	}
	
	return 0;
}
