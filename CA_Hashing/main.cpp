// CA_Hashing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CA_HashTable.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"CLOSED ADDRESS HASHING:"<<endl<<endl;
	
	CA_HashTable table(7); //size of table is 7 
	
	//1; 2; 3; 4; 5; 6; 7; 8; 9; 10
/*	table.insert(1);
	table.insert(2);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(6);
	table.insert(7);
	table.insert(8);
	table.insert(9);
	table.insert(10);
	table.insert(11);
	table.insert(12);
	table.insert(13);
	table.insert(14);
	table.insert(15);
	table.insert(16);
	table.insert(17);
	*/
	table.insert(7);
	table.insert(14);
	table.insert(21);
	table.insert(28);

	table.print();

	/*bool b = table.search(3);
	if (b == true)
		std::cout << "true";
	else
		std::cout << "false";*/

	//table.remove(8);
	//table.remove(3);
	//table.remove(9);
	
	//table.print();
	int n;
	std::cin >> n;

	
	return 0;
}
