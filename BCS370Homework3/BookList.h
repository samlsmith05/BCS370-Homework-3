//****************************************************
// File: BookList.h
//
// Purpose: Contains the class definition for BookList
//
// Written By: Samantha Smith
//
// Compiler: Visual Studio C++ 2017
// 
// Update Information
// ------------------
//
//****************************************************
#ifndef BOOKLIST_H
#define BOOKLIST_H
#define MAX_ITEMS 100	//sets the max number of items to be 100
#include <string>
#include "Book.h"
#include <iostream>
using namespace std;

class BookList
{
	
	private: 
		//NodeType struct
		struct NodeType {
			Book b;
			NodeType *next;
		};
		//Member Variables
		int length;
		NodeType *listData;
	//Member functions
	public:
		BookList();
		~BookList();
		BookList(const BookList& otherList);
		BookList & operator=(BookList& rhs);
		void Clear();
		int Length() const;
		void Add(const Book e);
		void Add(const BookList& otherList);
		bool FindByISBN(string isbn, Book &result) const;
		void Delete(string isbn);

		friend ostream& operator<<(ostream&os, BookList& rhs);
		friend istream& operator>>(istream&is, BookList& rhs);

};

#endif