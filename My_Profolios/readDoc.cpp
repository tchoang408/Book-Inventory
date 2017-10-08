//
//  readDoc.cpp
//  My_Profolios
//
//  Created by Goat on 7/27/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include "readDoc.hpp"
#include "List.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <vector>
#include <ostream>
using namespace std;

ReadDoc::ReadDoc(){}

void ReadDoc::readFile(List &list1){
	// open file and verify that is open properly
	fstream file;
	file.open("bookxml.txt");
	if(file.is_open()){
		cout << "File open sucessfully\n";
	}
	else
		cout << "File open unsucessfully\n";
	
	
	
	// read file and extract data out of it
	
	regex book("<author>");
	regex end_book("</book>");
	regex infor("[^\\s<>][a-zA-Z,.+_\\-#'?0-9\\s]+");
	string line;
	string line1;
	smatch author_match;
	smatch bookInfor_match;
	string author;
	vector<string> bookInfor;
	
	
	
	while(!file.eof())
	{
		getline(file, line);
		if(regex_search(line, book))
		{
			while(!regex_search(line, end_book))
			{
				sregex_iterator it(line.begin(),line.end(),infor);
				sregex_iterator it_end;
				it++;
				bookInfor.push_back(it->str());
				getline(file,line);
			}
		}
	}
	list1.appendNode(bookInfor);
	
}
