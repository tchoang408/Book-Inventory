//
//  main.cpp
//  My_Profolios
//
//  Created by Goat on 7/25/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include "readDoc.hpp"
#include <iomanip>
using namespace std;

int main ()
{
	List list1;
	ReadDoc file;
	file.readFile(list1);
	char choice;
	char cont;
	do{
		cout << "----------------------------------------\n";
		cout << left << setw(20) << "1.		Print List" << right <<setw(15)<< "|" << endl;;
		cout << left << setw(20) << "2.		Add Book" << right << setw(15) << "|"  << endl;
		cout << left << setw(20) << "3.		Delete Book" << right <<setw(15)<< "|" << endl;;
		cout << left << setw(20) << "4.		Search Title" << right <<setw(15) << "|" << endl;
		cout << "----------------------------------------\n";
		
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case '1': list1.printNode();
				break;
			case '2': list1.insertNode();
				break;
			case '3': list1.deleteNode();
				break;
			case '4': list1.searchTitle();
				break;
		}
		
		cout << "Would you like to continue?(y/n)";
		cin >> cont;
	}while(cont);
	
	return 0;
}
