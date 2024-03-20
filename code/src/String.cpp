#include "String.h"
#include <iostream>
#include <cstring>
#include <exception>


String::String() :  m_size(0), m_buf(nullptr){ }

String::String(const char *  buffer) : m_size(buffer ? strlen(buffer): 0), 
									   m_buf(new char[m_size + 1])     // constructor
{	
	memcpy(m_buf, buffer, m_size + 1);
	m_buf[m_size] = '\0';
	
}

String::String(const String & obj) :  m_size(obj.m_size), m_buf(new char[m_size +1]) // copy constructor
{
	if(obj.m_size !=0)             // to take care of assigment of empty string ex: String s("");
		memcpy(m_buf, obj.m_buf, obj.m_size + 1);

}

String& String::operator=(const String & obj)  //  assignment operator
{
	if (this == &obj) 
		return *this;
	 
	clean(); 		// cleanup any existing data

	m_size = obj.m_size;	
	m_buf = new char[m_size +1];
	memcpy(m_buf, obj.m_buf, obj.m_size + 1);
	
	return *this;
}

String::String(String && Obj) noexcept  :  m_size(Obj.m_size), m_buf(Obj.m_buf) // move constructor
{
	Obj.m_buf = nullptr;
    Obj.m_size = 0;	
}

String& String::operator=(String && Obj) noexcept // move assignment
{
	if (this ==&Obj) 
		 return *this;
	clean(); // cleanup any existing data

	m_size = Obj.m_size;  // Copy data from the incoming object	
	m_buf = Obj.m_buf;   // Transfer ownership of underlying char buffer from incoming object to this object
	
	Obj.m_buf = nullptr;	
	Obj.m_size = 0;
	
	return *this;
}

String String:: operator+(const String & obj) // concatenation
{
	String resultString; 
	resultString.m_size = m_size + obj.m_size;
	
	resultString.m_buf = new char[resultString.m_size +2];	
	
	memcpy(resultString.m_buf, m_buf, m_size );
	
	memcpy(resultString.m_buf + m_size, obj.m_buf, obj.m_size ); // copying the object buffer
	
	return resultString;
}

String& String :: operator+=(const String& str)
{
	String resultString;
    if (m_size == 0 && str.m_size == 0)  // to handle the empty empty string 
    {
		resultString.m_size = 0;
		resultString.m_buf = nullptr;
    }
    else
    {
		resultString.m_size = m_size + str.m_size;
		resultString.m_buf = new char[resultString.m_size];
		
		memcpy(resultString.m_buf, m_buf, m_size );
		memcpy(resultString.m_buf + m_size, str.m_buf, str.m_size ); 	
    }
    clean();           // cleanup any existing data
    m_buf=new char[resultString.m_size ];
    m_size=resultString.m_size;
    
    memcpy(m_buf, resultString.m_buf, resultString.m_size );
    return *this;
}
// Return String as this->string + buffer->string
String& String::append(const String &buffer)
{
	char *resultBuf = new char[m_size + buffer.m_size + 2]; // creating enough buffer 

	memcpy(resultBuf, m_buf, m_size);	
	delete[] m_buf;
	
	memcpy(resultBuf + m_size, buffer.m_buf, buffer.m_size );
	
	m_buf = resultBuf;
	m_size += buffer.m_size;
	
	return *this; 
	
}

// Return with a concatenated string
String String::concatenate(const String &string1, const String &string2)
{
	String concatString;
	concatString.m_size = string1.length() + string2.length();
	concatString.m_buf = new char[concatString.m_size + 1];

	memcpy(concatString.m_buf, string1.m_buf, string1.m_size );
	memcpy(concatString.m_buf + string1.m_size, string2.m_buf, string2.m_size ); 
	concatString.m_buf[concatString.m_size] = '\0';
	
	return concatString;
}
	
// Return char at the given index
char& String::operator[](size_t index) 
{
	
	if (index >= m_size) 
	{
		throw std::out_of_range("Index out of range");
	}
	return m_buf[index];
	    
}

const char& String::operator[](size_t index) const 
{
	if (index >= m_size) 
	{
		throw std::out_of_range("Index out of range");
	}
	return m_buf[index];
	    
}
// compare char by char and return 0 if both the string are same otherwise non zero
int String::compare(const String &str) const 
{
	char *pbuf = m_buf;
	const char *qbuf = str.c_str();
	while(*pbuf != '\0' && *qbuf != '\0')
	{
		if(*pbuf != *qbuf)
		{
			return *pbuf - *qbuf;
		}
		else 
		{
			pbuf++;
			qbuf++;
		}
	}
	return *pbuf - *qbuf;
}

// Return position of the char in the given string otherwise return -1
int String::findPos(char ch) const 
{
	char *pbuf = m_buf;
	unsigned int i = 0;
	while(pbuf[i] != '\0')
	{
		if(ch == pbuf[i])
		{
			return i ;
		}
		else
		{
			i++;
		}
	}
	return -1;
}

// Return char at the given position if the position is within the index range otherwise raise the error
const char& String :: at ( const size_t& pos) const
{
	if(pos > m_size-1)
		std::cerr << "out_of_range exception: pos= "<< pos <<std::endl;
	return m_buf[pos];
}

//Return string this string after the assigment
String& String::assign(const char *chars)
{
	m_size = strlen(chars);
	
	delete [] m_buf;
	m_buf = new char[m_size+1];

	memcpy(m_buf, chars, m_size+1);
	//m_size = len;
	return *this;
}

// insert the string at given position 
String& String::insert(const size_t& pos,const String& str)
{
	String insertedString(m_buf);	
		
	m_size = str.m_size + insertedString.m_size;	
	delete [] m_buf;	
	m_buf=new char[m_size];	
	
	memcpy(m_buf, insertedString.m_buf, pos);	
	memcpy(m_buf + pos, str.m_buf, str.m_size);
		
	memcpy(m_buf + str.m_size + pos, insertedString.m_buf + pos, insertedString.m_size);
		
	return *this;
}
// Erase the string at given position till the given length
String& String::erase(const size_t& pos,const size_t& n)
{
	
	String erasedString(m_buf);
	
	m_size=erasedString.m_size-n;
	delete [] m_buf;
	m_buf = new char[m_size];
	
	memcpy(m_buf, erasedString.m_buf, pos);
	memcpy(m_buf + pos, erasedString.m_buf + pos + n, erasedString.m_size);
		
	return *this;
}
// copy string2 to stinrg1 using copy constructor
void String::copy(String &string1,const String &string2)
{
	string1 = string2; // using assigment operator
}

unsigned int String::length() const
{
	return m_size;
}

const char* String:: c_str() const
{
	return m_buf;
}

void String::clean()
{
	if (m_buf != nullptr)
	{
		delete[] m_buf;
	}
	m_buf =nullptr;
	m_size = 0;
}

String :: ~String() // destructor
{
	clean();
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	if (obj.c_str() != nullptr)
		return os << obj.c_str();
	else
	{
		String s("");        // to print object created using default constructor ex: String s;
		return os<<s.c_str();
	}
		
}

std::istream& operator>>(std::istream& is, String& obj)
{
    is>>obj.m_buf;
    int sz = 0;
    while(obj.m_buf[sz]!='\0')
		sz++;
    obj.m_size=sz;
    return is;
}