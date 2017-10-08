//
//  List.cpp
//  My_Profolios
//
//  Created by Goat on 7/26/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include "List.hpp"
#include <vector>
List::List():head(NULL){}
List::~List(){};
void List::appendNode(vector<string> infor)
{
	int index = 0;
	while(index < infor.size()){
		Node *newNode = new Node(infor[index],infor[index+1],
														 infor[index+2], infor[index+3],
														 infor[index+4]);
		
		if(!head){
			head = newNode;
			tail = newNode;
			head->next = NULL;
			head->previous = NULL;
		}
		else{
			tail->next = newNode;
			newNode->previous = tail;
			tail = newNode;
			tail->next = NULL;
		}
		index += 5;
		
	}
}
void List::printNode()
{
	cout << "printList"<< endl;
	nodePtr = head;
	while(nodePtr->next != NULL)
	{
		cout<<nodePtr->author << endl;
		cout<<nodePtr->title << endl;
		cout<<nodePtr->genre << endl;
		cout<<nodePtr->price << endl;
		cout<<nodePtr->date<< endl << endl;
		nodePtr = nodePtr->next;
	}
	cout<<nodePtr->author << endl;
	cout<<nodePtr->title << endl;
	cout<<nodePtr->genre << endl;
	cout<<nodePtr->price << endl;
	cout<<nodePtr->date<< endl << endl;
	 
}
void List::insertNode()
{
	string author;
	string title;
	string genre;
	string price;
	string date;
	cout << "Enter book's author(last, first): ";
	getline(cin,author);
	cout << "Enter book's title: ";
	getline(cin,title);
	cout << "Enter book's genre: ";
	getline(cin,genre);
	cout << "Enter book's price: ";
	getline(cin,price);
	cout << "Enter book's date: ";
	getline(cin, date);
	
	Node *newNode = new Node(author,title,genre,price,date);
	tail->next = newNode;
	tail = newNode;
	tail->next = NULL;
}
void List::deleteNode()
{
	string title;
	cout << "Please enter the title to delete: ";
	cin.ignore();
	getline(cin, title);
	nodePtr = head;
	
	while(nodePtr != NULL)
	{
		if(head->title == title)
		{
			head->next->previous = NULL;
			head = head->next;
			delete head;
			cout << title << " had been deleted\n";
			break;
		}
		else if(tail->title == title)
		{
			tail = tail->previous;
			delete tail->next;
			tail ->next = NULL;
			cout << title << " had been deleted\n";
			break;
		}		
		else if(nodePtr->title == title)
		{
			nodePtr->previous->next =  nodePtr->next;
			nodePtr->next->previous = nodePtr->previous;
			delete nodePtr;
			cout << title << " had been deleted\n";
			break;
		}
		nodePtr = nodePtr->next;
	}
	
}
void List::searchTitle()
{
	string title;
	cout << "Enter the title of the book: ";
	cin.ignore();
	getline(cin, title);
	nodePtr = head;
	
	while(nodePtr != NULL)
	{
		if(nodePtr->title == title)
		{
			cout << "The book was found !\n";
			cout << "Title: " << nodePtr->title << endl;
			cout << "Author: " << nodePtr->author << endl;
			cout << "Genre: " << nodePtr->genre << endl;
			cout << "price: " << nodePtr->price <<endl;
			cout << "Date: " << nodePtr->date << endl;
		}
		
		nodePtr = nodePtr->next;
		
		
		
		
	}
	
}

