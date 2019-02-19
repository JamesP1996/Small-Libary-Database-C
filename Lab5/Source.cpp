#include<stdio.h> 

#include<stdlib.h> 

#include<string.h> 


//Setting up Type Book Structure
typedef struct

{

	long bookNo;

	char name[30];

	char author[25];

	double price;

}book;


//Setting up Functions for Future use within Main
void printAllBooks(book* lib, int len);
void addBook(book* lib, int len);
void displayBook(book* lib, int len);
void editPrice(book* lib, int len);



void main()

{

	//Creating a Struct Pointer based off Book called Libary 

	book* libary;

	//Variables 

	int i;

	int option = 0, libsize = 0;

	//Intro 

	printf("WELCOME TO THE LIBARY DATABASE APPLICATION \n");

	//Intialize Size of Libary  

	printf("Please Enter How Many Books There is in the Libary \n");

	scanf("%d", &libsize);

	libary = (book*)malloc(libsize * sizeof(book));

	//Intialize all Books to 0
	for (i = 0; i < libsize; i++) {
		(libary + i)->bookNo = 0;
	}

	//Checking that Books With element 0 registered
	printAllBooks(libary, libsize);
	
	//Break Line
	printf("\n");

	//Menu 

	printf("\nPlease Select a Option Below From This List \n");

	printf("Press 1 to :: Search the Number of a Book and View it's member details \n");

	printf("Press 2 to :: Add a new Book to an empty space in the database \n");

	printf("Press 3 to :: Edit a Book's Price based off their bookNo \n");

	printf("Press -1 to :: Exit the Application (!Warning! Books are not Saved on Exit) \n");

	scanf("%d", &option);

	//While User does not press -1 Continue the Application
	while (option != -1)

	{

		//Search for Book Using The Book Number of a Known Book Entered 

		if (option == 1) {

			displayBook(libary, libsize);



		}

		// Add Book to Empty Space within Struct Array 

		else if (option == 2) {


			addBook(libary, libsize);
			printf("\n");


		}

		//Edit Price 

		else if (option == 3) {
			editPrice(libary, libsize);
			printf("\n");


		}
		//Show All Books
		else if (option == 4) {

			printAllBooks(libary, libsize);
			printf("\n");
		}




		// Ending Sentinal While Loop with a Repeat of the beggining menu
		printf("\nPlease Select a Option Below From This List \n");

		printf("Press 1 to :: Search the Number of a Book and View it's member details \n");

		printf("Press 2 to :: Add a new Book to an empty space in the database \n");

		printf("Press 3 to :: Edit a Book's Price based off their bookNo \n");

		printf("Press 4 to :: Show All Books \n");

		printf("Press -1 to :: Exit the Application (!Warning! Books are not Saved on Exit) \n");

		scanf("%d", &option);



	}



}


// Code Provided by Martin To Scan Through Book Structs and Print All Books in it
void printAllBooks(book* lib, int len)

{

	int i;



	for (i = 0; i < len; i++)

	{

		if ((lib + i)->bookNo == 0)

		{
			// If Empty{0}
			printf("The book at element %d is empty\n", i);

		}

		else

		{
			//If has a value print book
			printf("The book at element %d is %ld %s by %s at costs %lf \n", i, (lib + i)->bookNo, (lib + i)->name, (lib + i)->author, (lib + i)->price);

		}

	}

}

// Add a New book In a Empty{0} Slot
void addBook(book* lib, int len) {
	int i;
	for (i = 0; i < len; i++) 
	{
		if ((lib + i)->bookNo == 0) 
		{
			//Asking User to Enter the Book Details with a Added Break Afterwards To Exit The For Loop
			printf("Please Enter in a bookNo, Name, author and price for the book\n");
			scanf("%ld %s %s %lf", &(lib + i)->bookNo, &(lib + i)->name, &(lib + i)->author, &(lib + i)->price);
			break;
		}
		else {
			//Letting User Know when a Space is not Available
			printf("There is more space left for a book in element %d \n",i);
		}
	}

}

//Find a Book 
void displayBook(book* lib, int len) {
	//Variables
	long bookWanted = 0;
	int i;

	//Asking for book number user wishes to search for
	printf("Please Enter the <ISBN>Book Number of the Book You Wish To Search For \n");
	scanf("%ld", &bookWanted);
	//Scan through Array until it finds book with same number
	for (i = 0; i < len; i++) {
		if ((lib + i)->bookNo == bookWanted) {

			//Found book Display Details
			printf("\n The book with ISBN %ld is %s by %s at costs %lf \n", bookWanted, (lib + i)->name, (lib + i)->author, (lib + i)->price);
			break;
		}
		else {

			//Could Not Find Book
			printf("\n A Book with that ISBN Not Found in Element %d \n ",i);
			
		}
	}

}

//Find a Book and Edit it's Price
void editPrice(book* lib, int len) {
	//Variables
	long bookWanted = 0;
	double newprice = 0;
	int i;

	//Asking for book number user wishes to search for and Edit Price of
	printf("Please Enter the <ISBN>Book Number of the Book You Wish To Search For and Edit Price of \n");
	scanf("%ld", &bookWanted);
	//Scan through Array until it finds book with same number
	for (i = 0; i < len; i++) {
		if ((lib + i)->bookNo == bookWanted) {

			//Found book Display Details
			printf("\n The book with ISBN %ld is %s by %s at costs %lf \n", bookWanted, (lib + i)->name, (lib + i)->author, (lib + i)->price);
			
			//Ask for New Price for Book
			printf("Please Enter the New Price of the Book Selected \n");
			scanf("%lf", &newprice);
			(lib + i)->price = newprice;
			//Letting User Know Action was Completed
			printf("\n New Price Added to Book Selected\n");

			break;
		}
		else {

			//Could Not Find Book
			printf("\n A Book with that ISBN Not Found in Element %d \n ", i);

		}
	}
}