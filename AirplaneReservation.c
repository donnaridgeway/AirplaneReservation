/* Donna Ridgeway & Montira Polk
CIS215 - Term Project*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct name{
	char fullName[50];
};

//functions
void flyPlane();
void getTicket (int seatClass, int seatNum, int chooseFirst[], int choosePreferred[], int chooseEconomy[], char mealChoice, struct name names[], char addTicket);
void drawFirstClass (int chooseFirst[]);
void drawPreferred(int choosePreferred[]);
void drawEconomy(int chooseEconomy[]);
int checkSeats (int seatClass, int chooseFirst[], int choosePreferred[], int chooseEconomy[]);

int main()
{
	
	
	//declare variables
	struct name names[16];
	int chooseFirst[7]={0}; //seats in first class
	int choosePreferred[5]={0}; //seats in preferred
	int chooseEconomy[7]={0}; //seats in economy
	float mealCost, ticketPrice;
	int seatClass, seatNum, counter, j=1000, yesNo;
	char addTicket, mealChoice;
	char passName[50] = {""};

	system("color 0b");

    //airplane graphic
	for (counter=0; counter < 50; counter++){
	printf("\t");
    flyPlane();
    for (counter=0; counter < 50; counter++) {
        usleep(j);
        j = (int)(j * 0.9);
        printf("\t");
    	}
	}	
	printf("Thank you for booking your flight with Code Flight Airlines.\n");
	printf("\n");

	//function called to run program
	getTicket (seatClass, seatNum, chooseFirst, choosePreferred, chooseEconomy, mealChoice, names, addTicket);
	system("Pause");
    return 0;
}

//function created to display airplane graphic
void flyPlane(){
	printf("\n");
	printf(" 		    -=\\`\\\n");
	printf(" 		 \\ ____\\_\\_______\n");
	printf(" 		-=\\\\ CF Airlines \\`) \n");
	printf("  		  `~~~~~/ /~~~~~` \n");
	printf("    	           -==/ /  \n ");
	printf("	  	     '-'    \n");
}

//function created to allow user to reserve seat on plane
void getTicket(int seatClass, int seatNum, int chooseFirst[], int choosePreferred[], int chooseEconomy[], char mealChoice, struct name names[], char addTicket){
	
	//declare variables in function
	int counter = 1, yesNo;
	
	//user inputs 1,2,3 to select seat class on plane
	printf("\nPlease select the class you'd like to be seated in\n");
	printf("First = 1, Preferred = 2, Economy = 3: ");

	fflush(stdin);
	scanf("%d", &seatClass);
	//output displays graphic of seats on plane depending on which class was selected
		if (seatClass == 1){
			drawFirstClass(chooseFirst);
		}
			else if (seatClass == 2){
				drawPreferred(choosePreferred);
			}
				else {
				drawEconomy(chooseEconomy);
				}

	//output confirms choice and checks for available seats.
	//if no available seats are in the section, user can select from another class
	if (seatClass == 1) {
		printf("You have selected a seat in First Class.\n");
		seatNum=checkSeats(seatClass, chooseFirst, choosePreferred, chooseEconomy);
			if (seatNum == -1) {
				printf("Sorry, First class is full. Would you like to choose another class (y/n)? ");
				scanf("%d", &yesNo);
					if(yesNo == 'y'){ 
						getTicket(seatClass, seatNum, chooseFirst, choosePreferred, chooseEconomy, mealChoice, names, addTicket);	
					} else { 
						printf("\n\nThe next flight leaves in 3 hours."); 
						system("pause");
						return;	
					}
			}	
	} else if (seatClass == 2) {
		printf("\nYou have selected a seat in Preferred.\n");
		seatNum=checkSeats(seatClass, chooseFirst, choosePreferred, chooseEconomy);
			if (seatNum == -1) {
				printf("Sorry, Preferred class is full. Would you like to choose another class (y/n)? ");
				scanf("%d", &yesNo);
					if(yesNo == 'y'){ 
						getTicket (seatClass, seatNum, chooseFirst, choosePreferred, chooseEconomy, mealChoice, names, addTicket);	
					} else { 
						printf("\n\nThe next flight leaves in 3 hours."); 
						system("pause"); 
						return; 
					}			
			}
	} else {
		printf("\nYou have selected a seat in Economy.\n");
		seatNum=checkSeats(seatClass, chooseFirst, choosePreferred, chooseEconomy);
			if (seatNum == -1) {
				printf("Sorry, Economy class is full. Would you like to choose another class (y/n)? ");
				scanf("%d", &yesNo);
					if(yesNo == 'y'){ 
						getTicket (seatClass, seatNum, chooseFirst, choosePreferred, chooseEconomy, mealChoice, names, addTicket);
					} else {
						printf("\n\nThe next flight leaves in 3 hours."); 
						system("pause"); 
						return; 
					}
			}
	}
		
	//user has option to add a meal plan to their ticket for an additional $10
	printf("\n");
	printf("Would you like to add a $10 meal plan to your ticket (y/n)? ");
	fflush(stdin);
	scanf("%c", &mealChoice);
	//output lets user know the cost will be added to their ticket, if they choose no, they can proceed to booking their ticket
	if (mealChoice == 'y'){
		printf("\nThe meal plan will be added to your ticket. \n\n");
	}
	else{
		printf("\nThank you. Please proceed to booking your ticket. \n\n");
	}

	//user inputs passenger's name
	printf("What is the name of the passenger (first and last)? ");
	scanf("%s", names[counter].fullName);

	//user has the option to book another ticket
	printf("\nDo you want to book another ticket (y/n)? ");
	fflush(stdin);
	scanf("%c", &addTicket);
	
	counter++;
	//function is called to book additional tickets
	if (addTicket == 'y'){
	getTicket (seatClass, seatNum, chooseFirst, choosePreferred, chooseEconomy, mealChoice, names, addTicket);
	}
		//boarding pass prints to show Passenger Name, Seat Class, Seat Number, if a meal plan was selected, and Ticket Price
		else{
		printf("\n**Boarding Pass** \n");
		printf("Enjoy your flight! \n\n");
		
		//output shows passenger's name
		printf("Passenger Name: %s \n", names[counter].fullName);
		
		//output shows seat class selected
		if (seatClass == 1){
			printf("Seat Class: First Class \n");
		}
		else if (seatClass == 2){
			printf("Seat Class: Preferred \n");
		}
		else{
			printf("Seat Class: Economy \n");
		}
	}
		// output shows seat number based on available seats
		printf("Seat Number: %d \n", seatNum);
			
		//output shows if meal plan was selected
		printf("Meal Plan? %s \n", mealChoice == 'n' ? "No" : "Yes");
		
		//output shows ticket price	
		if (mealChoice == 'y' && seatClass == 1){
			printf("Ticket Price: $510.00 \n");
		}
		else if (mealChoice == 'y' && seatClass == 2){
			printf("Ticket Price: $360.00 \n");			
		}
		else if (mealChoice == 'y' && seatClass == 3){
			printf("Ticket Price: $210.00 \n");			
		}
		else if (mealChoice == 'n' && seatClass == 1){
			printf("Ticket Price: $500.00\n");
		}
		else if (mealChoice == 'n' && seatClass == 2){
			printf("Ticket Price: $350.00 \n");			
		}
		else if (mealChoice == 'n' && seatClass == 3){
			printf("Ticket Price: $200.00 \n");			
		}
		
		printf("-------------------------------\n");		
	
}

//function shows seat map of first class
void drawFirstClass(int chooseFirst[]){
	printf("           | First Class |\n");
	printf("           |   %d     %d   |\n", chooseFirst[1],chooseFirst[2]);
	printf("           |             |\n");
	printf("           |   %d     %d   |\n", chooseFirst[3],chooseFirst[4]);
	printf("           |             |\n");
	printf("          /|___%d_____%d___|\\\n", chooseFirst[5],chooseFirst[6]);
}

//function shows seat map of preferred class
void drawPreferred(int choosePreferred[]){
	printf("         / |  Preferred  | \\\n");
	printf("        /  |   %d    %d    |  \\\n", choosePreferred[1],choosePreferred[2]);
	printf("       /   |             |   \\\n");
	printf("      /   /|___%d ___%d __ |\\   \\\n", choosePreferred[3],choosePreferred[4]);
}

//function shows seat map of economy class
void drawEconomy(int chooseEconomy[]){
	printf("     /   / |   Economy   | \\   \\\n");
	printf("    /   /  |   %d     %d   |  \\   \\\n", chooseEconomy[1],chooseEconomy[2]);
	printf("   /___/   |             |   \\___\\\n");
	printf("           |   %d     %d   |\n", chooseEconomy[3],chooseEconomy[4]);
	printf("           |             |\n");
	printf("           |   %d     %d   |\n", chooseEconomy[5],chooseEconomy[6]);
}

//function to change 0 to 1 when class is selected from user on seat map
int checkSeats (int seatClass, int chooseFirst[], int choosePreferred[], int chooseEconomy[]){
	int counter;
	
	switch (seatClass) {
		case 1:
			for (counter=1;counter<7;counter++){
				if (chooseFirst[counter]==0){
					chooseFirst[counter]=1;
					return counter;
				}
			}
			return -1;
		case 2:
			for (counter=1;counter<5;counter++){
				if (choosePreferred[counter]==0){
					choosePreferred[counter]=1;
					return counter+6;
				}
			}
			return -1;			
		case 3:
			for (counter=1;counter<7;counter++){
				if (chooseEconomy[counter]==0){
					chooseEconomy[counter]=1;
					return counter+10;
				}
			}		
		}
	}

	


