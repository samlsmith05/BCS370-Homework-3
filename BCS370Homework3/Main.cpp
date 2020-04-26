//****************************************************
// File: Main.cpp
//
// Purpose: Show and utilize all the functions in the Book and BookCollection classes
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//****************************************************

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "BookCollection.h"
#include "BookList.h"
using namespace std;

//****************************************************
// Function: main()
//
// Purpose: entry point for the program
//
// Update Information
// ------------------
//
//****************************************************

int main() {
	Book book1 = Book();			//calls the default constructor
	Book book2 = Book("ABC123", "The Hunger Games", 19.95);		//calls the constructor that takes all member variables
	Book book3 = Book("XYZ789", "To Kill A Mockingbird", 23.75);//calls the constructor that takes all member variables
	Book book4 = Book("JKL456", "Introduction to C++", 163.98); //calls the constructor that takes all member variables
	Book book5 = Book();			//calls the default constructor
	Book book6 = Book(book4);		//calls the copy constructor
	Book book7 = book2;				//calls operator=

	book1.SetIsbn("321EFG");		//calls SetIsbn
	book1.SetPrice(9.99);			//calls SetPrice
	book1.SetTitle("Easy Poems");	//calls SetTitle

	book5.SetIsbn("QRS987");
	book5.SetTitle("Divergent");
	book5.SetPrice(15.99);

	cout << "All books are set " << endl;
	cout << "------------------------------------------------------------" << endl;

	BookList bl1 = BookList();				//calls default constructor

	bl1.Add(book1);							//calls Add(book) 
	bl1.Add(book2);							//calls Add(book)
	
	cout << "Booklist 1 includes: \n" << bl1 << endl;		//calls operator<< 

	cout << "The number of items in Booklist 1 is " << bl1.Length() << endl;	//calls length()
	
	Book resultBook = Book();
	cout << "\nFind isbn success: ";
	bool result = bl1.FindByISBN("ABC123", resultBook);				//calls FindByISBN with a isbn that will work
	if (result == true) {
		cout << "\n" << resultBook << endl;										//prints the Book with the matching isbn
	}
	else {
		cout << "\nThat isbn was not found in the Book Collection" << endl;
	}

	cout << "Find book fail: \n";
	result = bl1.FindByISBN("BYU681", resultBook);						//calls FindByISBN with a isbn that will NOT work
	if (result == true) {
		cout << "\n" << resultBook << endl;										//prints the Book with the matching isbn
	}
	else {
		cout << "That isbn was not found in the Book Collection" << endl << endl;
	}

	BookList bl2 = BookList();
		
	ifstream inFile;
	inFile.open("info.txt");		//opens the file
	while (!inFile.eof()) {
		inFile >> bl2;				//calls operator>>
	}
	
	inFile.close();					//closes the file
	cout << "\nBooklist 2 includes: \n" << bl2 << endl;		//calls operator<< 

	bl2.Delete("YKT984");									//calls Delete()
	cout << "\nBooklist 2 after deleting one of them includes: \n" << bl2 << endl;		//calls operator<< 

	

	bl1.Add(bl2);											//calls Add(BookList)
	cout << "After adding a list to Booklist1, it is: \n" << bl1 << endl;	//calls operator<<


	BookList bl3 = bl1;										//uses operator=
	cout << "Booklist 3 includes: \n" << bl3 << endl;

	bl2.Clear();											//calls Clear()
	cout << "\nBooklist 2 after being cleared includes: \n" << bl2 << endl;		//calls operator<< 

	BookList bl4 = BookList(bl1);							//calls copy constructor
	cout << "Booklist 1 includes: \n" << bl1 << endl;		//calls operator<<
	cout << "Booklist 4 includes: \n" << bl4 << endl;		//calls operator<<

	return 0;
}