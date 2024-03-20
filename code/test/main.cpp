#include "../include/String.h"
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>


String toTestMoveConstructor(String s)
{
    return s;
}


using namespace std;

int main()
{
	cout<<endl;
	cout<<endl;
	cout<<"*********Test Case for String class***********"<<endl;	
	cout<<endl;	
	cout<<endl;
	
	// Test the default constructor
	String s1;
	cout<<"TESTING default constructor : ";
	if(s1.length() == 0)
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	
	// Test the conversion constructor
	String s2="MEGA ";
	cout<<endl;
	cout<<endl<<"TESTING conversion constructor : ";
	if(!s2.compare("MEGA "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//Test copy constructor
	String s3(s2);
	cout<<endl<<"TESTING copy constructor : ";
	if(!s3.compare("MEGA "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	
	// copy assignment 
	String   s4;
	s4=s2;	
	cout<<endl<<"TESTING copy assignment operator: ";
	if(!s4.compare("MEGA "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
		
	// Move Constructor
	String   s5("world!");
	String   moved = std::move(s5);
	cout<<endl<<"TESTING Move constructor : ";
	if(!moved.compare("world!"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	// move assignment
	String   s6;
	s6 = std::move(s2);	
	cout<<endl<<"TESTING move assignment operator: ";
	if(!s6.compare("MEGA "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	// concatenation	
	// operator+
	String s7 = s6 + moved;	
	cout<<endl<<"TESTING operator+: ";
	if(!s7.compare("MEGA world!"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	String s18 = s6 + " ";	
	cout<<endl<<"TESTING operator+: ";
	if(!s18.compare("MEGA  "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	// operator+=
	String s8;
	s8 += "MEGA.io nz ";
	cout<<endl<<"TESTING operator+=: ";
	if(!s8.compare("MEGA.io nz "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	// apend
	String s9("Storage ");
	s9.append(s8);
	cout<<endl<<"TESTING append()=: ";
	if(!s9.compare("Storage MEGA.io nz "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//concatenate
	String s10=s1.concatenate(s9,moved);
	cout<<endl<<"TESTING concatenate()=: ";
	if(!s10.compare("Storage MEGA.io nz world!"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//operator[]
	char first = s10[0];
	cout<<endl<<"TESTING operator[]=: ";
	if(!String(&first).compare("S"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//compare
	String s11="MEGA.io nz ";
	cout<<endl<<"TESTING compare()=: ";
	if(!s11.compare("MEGA.io nz "))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//findPos
	cout<<endl<<"TESTING findPos()=: ";
	if(s11.findPos('.') == 4)
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//at
	char ch = s11.at(3);
	cout<<endl<<"TESTING at()=: ";
	if(!String(&ch).compare("A"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//assign
	String s12;
	s12.assign("Nitish Kumar");
	cout<<endl<<"TESTING assign()=: ";
	if(!s12.compare("Nitish Kumar"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//insert
	String s13 = s12.insert(6," Omp ");
	cout<<endl<<"TESTING insert()=: ";
	if(!s13.compare("Nitish Omp  Kumar"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//Erase
	String s14 = s13.erase(6,5);
	cout<<endl<<"TESTING erase()=: ";
	if(!s14.compare("Nitish Kumar"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//Copy
	String s15;
	s15.copy(s15,s14);
	cout<<endl<<"TESTING copy()=: ";
	if(!s15.compare("Nitish Kumar"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//length
	cout<<endl<<"TESTING length()=: ";
	if(s15.length() == 12)
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	
	//c_str
	String s16("Nitish Kumar");
	s1.assign(s16.c_str());
	cout<<endl<<"TESTING c_str()=: ";
	if(!s1.compare("Nitish Kumar"))
		cout<<"PASS"<<endl;
	else
		cout<<"Fail"<<endl;
	cout<<endl;
	cout<<endl;
	
	cout<<"*********Test Case End**********"<<endl;
	cout<<endl;
	cout<<endl;
	
	return 0;
}
