//****************************************************
// File: BookList.cpp
//
// Purpose: Contains all of the function definitions 
//			for the BookList class
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
// 
//*****************************************************
#include "BookList.h"
#include "Book.h"

//****************************************************
// Function: BookList()
//
// Purpose: The default constructor for BookList
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
//
//****************************************************
BookList::BookList(){
	length = 0;		//sets the length to 0
	listData = NULL; 
}

//****************************************************
// Function: BookList(const BookList& otherList)
//
// Purpose: does a deep copy of the member variables 
//			as a copy constuctor
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
//
//****************************************************
BookList::BookList(const BookList& otherList) {
	//set everything to null first
	listData = NULL;
	length = 0;

	NodeType* temp;
	temp = otherList.listData;

	//checks to see if otherList is 0, if so sets the length to 0 and returns
	if (otherList.length == 0) {
		length = 0;
		return;
	}
	//adds otherList to the end of the currentlist
	Add(otherList);
	/*
	//loops through until temp->next is NULL 
	for (temp = otherList.listData; temp != NULL; temp = temp->next) {
		//adds the temp book to the os, but uses the operator<< from Book class
		Add(temp->b);
	}
	*/
}

//***************************************************
// Function: operator=(const BookList& rhs)
//
// Purpose: overloads the assignment operator = and 
//			creates an object like a copy constructor
//
// Big-O Runtime Cost: O(2n) = O(n)
//
// Update Information
// ------------------
// 
//****************************************************
BookList& BookList::operator=(BookList& rhs) {
	//clear out the list first
	Clear();

	NodeType* temp = listData;
	//checks to see if they are already equal
	if (this == &rhs) {
		return *this;
	}
	
	while(temp->next != NULL){
	//for (int i = 0; i < length; i++) {
		Add(temp->b);
		temp = temp->next;
	}
	return *this;
	/*
	//loops through until next is equal to null
	while (rhs.listData->next != NULL) {
		this->listData->b = rhs.listData->b;	//sets the books equal
		this->listData->next = rhs.listData->next;	//sets the next's equal
		listData = rhs.listData->next;				//sets the listData to 
	}
	*/
	
}

//****************************************************
// Function: Clear()
//
// Purpose: clears the current list
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
void BookList::Clear() {
	//creates a temporary NodeType
	NodeType* temp;
	//loops through until listData is equal to NULL
	while (listData != NULL) {
		temp = listData;				//sets temp to listData
		listData = listData->next;		//sets listData to the next node
		delete temp;					//deletes temp
	}
	//sets the whole list's length to 0
	length = 0;
}

//****************************************************
// Function: Length() const
//
// Purpose: returns the number of items in the current list
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
int BookList::Length() const {
	//return length since that is the number of books in the list
	return length;
}

//****************************************************
// Function: Add(const Book e) 
//
// Purpose: adds a book to the list
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
void BookList::Add(const Book e) {
	NodeType* temp = new NodeType;
	//puts the book data into temp's data spot
	temp->b = e;
	//sets temp's next to listData
	temp->next = listData;
	//sets listData to temp since temp is now the head of the list
	listData = temp;
	length++;			//increment the length

	
}

//****************************************************
// Function: Add(const BookList& otherList) 
//
// Purpose: adds a book list to the current book list
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
void BookList::Add(const BookList& otherList) {
	//creates a temporary node
	NodeType* temp;
	temp = otherList.listData;

	//loops through until temp->next is NULL 
	for (temp = otherList.listData; temp != NULL; temp = temp->next) {
		//adds the temp book to the os, but uses the operator<< from Book class
		Add(temp->b);
	}
}

//****************************************************
// Function: FindByISBN(string isbn, Book &result) const
//
// Purpose: finds the book with the given isbn
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
bool BookList::FindByISBN(string isbn, Book &result) const {
	NodeType* temp;
	temp = listData;		//sets temp to point at the same place as listData

	//loops through all of the booklist until temp->next is null
	while (temp->next != NULL) {
		//if the current book's isbn matches the given isbn
		if ((temp->b.GetIsbn()).compare(isbn) == 0 ) {
			result = temp->b;		//sets the result book to the one with the same isbn
			return true;
		}
		//otherwise we go to the next one
		else {
			temp = temp->next;		//sets temp to the to the next one in the list
		}
	}
	
	return false;	//returns false if it doesn't match any of the isbn's	
}

//****************************************************
// Function: Delete(string isbn) 
//
// Purpose: deletes a book from the list
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
void BookList::Delete(string isbn) {

	//checks to see if the list is empty to avoid a null pointer error
	if (length == 0) {
		return;
	}

	NodeType* temp = listData;
	NodeType* tempLocation;
	
	//checks to see if the target is at the first node
	if ((temp->b.GetIsbn()).compare(isbn) == 0) {
		listData = listData->next;		//moves the head to the next node
		delete temp;	//deletes the node located at temp
		length--;	//decrement the length
		return;
	}
	
	//loops through all of the booklist while temp is not equal to null and the given isbn is not equal to the next node's data
	while ((temp->next != NULL) && isbn != (temp->next)->b.GetIsbn()) {
		temp = temp->next;		//sets temp to the to the next one in the list
	}

	//target is not in the list since it looped through and we are now at the last node and it is not equal to the given isbn
	if (temp->next == NULL) {
		return;
	}
	
	tempLocation = temp->next;		//sets tempLocation to the node of the target
	temp->next = (temp->next)->next;//sets temp's next to the target's next
	delete tempLocation;			//deletes node at tempLocation
	length--;						//decrement the length
}

//****************************************************
// Function: operator<<(ostream& os, BookList& rhs)
//
// Purpose: prints the values of all member variables 
//			on the given ostream
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
ostream& operator<<(ostream&os, BookList& rhs) {
	//creates a temporary node
	BookList::NodeType* temp;
	temp = rhs.listData;
	
	//loops through until temp->next is NULL 
	for (temp = rhs.listData; temp != NULL; temp = temp->next) {
		//adds the temp book to the os, but uses the operator<< from Book class
		os << temp->b << endl;
	}
	
	return os;
}

//****************************************************
// Function: operator>>(istream& is, BookList& rhs)
//
// Purpose: reads the values of all member variables 
//			from the given istream
//
// Big-O Runtime Cost: O(1)
//
// Update Information
// ------------------
// 
//****************************************************
istream& operator>>(istream&is, BookList& rhs) {
	//creates a temporary node
	BookList::NodeType* temp = new BookList::NodeType;
	
	//uses Book.cpp's operator>> to extract into b
	is >> temp->b;
	//adds temp->b into rhs
	rhs.Add(temp->b);

	delete temp;
	return is;
}

//****************************************************
// Function: ~BookList()
//
// Purpose: Destructor for BookList
//
// Big-O Runtime Cost: O(n)
//
// Update Information
// ------------------
// 
//****************************************************
BookList::~BookList(){
	//calls clear
	Clear();
	//delete the listData pointer 
	delete listData;
	cout << "Destructor called" << endl;
}
