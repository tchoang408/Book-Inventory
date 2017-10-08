//
//  List.hpp
//  My_Profolios
//
//  Created by Goat on 7/26/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>
using namespace std;

class List
{
private:
	struct Node
	{
		string author;
		string title;
		string genre;
		string price;
		string date;
		Node *next;
		Node *previous;
		Node():author(""), title(""), genre(""), price(0),
					 date(""){}
		Node(string a, string t, string g, string p,
				 string d):author(a),title(t), genre(g),price(p),
			   date(d){}
		
	};
	Node *head;
	Node *tail;
	Node *nodePtr;
public:
	List();
	~List();
	void appendNode(vector<string>);
	void insertNode();
	void deleteNode();
	void searchTitle();
	void printNode();
	
	
	
	
};
#endif /* List_hpp */
