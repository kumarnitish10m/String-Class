#ifndef STRING_H
#define STRING_H

#include <sstream>


class String
{
private:
  
	unsigned int m_size = 0;
	char * m_buf = nullptr;
		
    friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream& , String& );
	
public:
	String(); // default constructor	
	String(const char *  buffer); // one argument constructor
	String(const String & obj); // copy constructor	
	String& operator=(const String & obj) ; // copy assignment 	
	
	String(String && Obj) noexcept ; // move constructor 
	String& operator=(String && Obj) noexcept ; // move assignment
	
	String operator+(const String & obj); 	// Overloading + operator
	String& operator+=(const String& other); // Overloading =+ operator
	
	// concatenation
	String& append(const String &buffer); // To add string at the end
	String concatenate(const String &string1, const String &string2); //Returns with a concatenated string
	
	char& operator[](size_t index);  // overloaded subscript operator
    const char& operator[](size_t index) const;
	
	int compare(const String &str) const ; // Comparing char by char
	int findPos(char ch) const;			// find the position of chara from the string 
	const char& at ( const size_t& pos) const; // return the char at particular position from the string
	
	String& assign(const char *chars);  // assign the string to another string
	
	String& insert(const size_t& pos,const String& s); // Insert the string at a given position 
	String& erase(const size_t& pos,const size_t& n); // Erase the string at a given position pf given length
	void copy(String &string1,const String &string2); // copy from string2 to string 1
	
	unsigned int length() const;     // find the length of the string
	const char *c_str() const;       // converting string to char
	
	
	~String(); // destructor

private:

	void clean();   // clean the memmber variables 
	
	
};


#endif // STRING_H