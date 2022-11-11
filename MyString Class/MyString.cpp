#include "MyString.h"

//default constructor
MyString::MyString()
{
	length = 10;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = '0';   //setting all elements to zero
	str[length] = '\0';
	//cout << "Default constructor was called..." << endl;
}

//parameterized constructor
MyString::MyString(const char* c)
{
	int l;
	for (l = 0; c[l] != '\0'; l++);
	length = l;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = c[i];
	str[length] = '\0';
	//cout << "Parameterized constructor was called..." << endl;
}

//destructor
MyString::~MyString()
{
	if (str)
	{
		delete[]str;
		str = NULL;
	}
	//cout << "Destructor was called..." << endl;
}

//display string
void MyString::display() const
{
	cout << str << endl;
}

//returns length of the string 
int MyString::getLength() const
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

//copy constructor
MyString::MyString(const MyString& c)
{
	length = c.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = c.str[i];
	str[length] = '\0';
}

//overloading assignment operator
const MyString& MyString::operator=(const MyString& c)
{
	delete[]str;      //deleting the previous contents
	length = c.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = c.str[i];
	str[length] = '\0';
	return *this;
}

//overloading + operator
MyString MyString::operator+(const MyString& c) const
{
	MyString c2;
	c2.length = this->length + c.length;
	c2.str = new char[c2.length + 1];
	for (int i = 0; i < this->length; i++)
	{
		c2.str[i] = str[i];
	}
	int j = this->length;
	for (int i = 0; i < c.length; i++)
	{
		c2.str[j++] = c.str[i];
	}
	c2.str[c2.length] = '\0';
	return c2;
}

//overloading == operator
bool MyString::operator==(const MyString& c) const
{
	if (c.length != this->length)
		return false;
	else
	{
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != c.str[i])
				return false;
		}
	}
	return true;
}

//overloading < operator
bool MyString::operator<(const MyString& c) const
{
	int great_length;
	if (this->length > c.length) great_length = this->length;
	else great_length = c.length;
	bool equal_flag = false;
	for (int i = 0; i < great_length; i++)
	{
		if (this->str[i] > c.str[i])
			return false;
		else if (this->str[i] != c.str[i])
		{
			equal_flag = true;
			break;
		}
	}
	if (equal_flag == false) return false;
	else return true;
}

//overloading <= operator
bool MyString::operator<=(const MyString& c) const
{
	if (c.length != this->length)
	{
		int great_length;
		if (this->length > c.length) great_length = this->length;
		else great_length = c.length;
		bool equal_flag = false;
		for (int i = 0; i < great_length; i++)
		{
			if (this->str[i] > c.str[i])
				return false;
			else if (this->str[i] != c.str[i])
			{
				equal_flag = true;
				break;
			}
		}
		if (equal_flag == false) return false;
		else return true;
	}
	else 
	{
		for (int i = 0; i < c.length; i++)
		{
			if (this->str[i] != c.str[i] && this->str[i] > c.str[i])
				return false;
		}
		return true;
	}
}

//overloading += operator
const MyString& MyString::operator+=(const MyString& c)
{
	char* temp = new char[(length + c.length) + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	int j = length;
	for(int i = 0; i < c.length; i++)
	{
		temp[j++] = c.str[i];
	}
	temp[j] = '\0';
	length = length + c.length;
	delete[]str;
	str = temp;
	return *this;
}

//set data member of instance
void MyString::setStr(const char* c)
{
	int l;
	for (l = 0; c[l] != '\0'; l++);
	length = l;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = c[i];
	str[length] = '\0';
}

//for conversion from 'MyString' to 'int' operator
MyString::operator int()
{
	int num = 0;
	//For negative values
	if (str[0] == '-')
	{
		//Validation
		for (int i = 1; i < length; i++)
		{
			if (!(str[i] >= 48 && str[i] <= 57))
			{
				cout << "Invalid Conversion... Returning -1" << endl;
				return -1;
			}
		}
		//Conversion
		for (int i = 1; i < length; i++)
		{
			num = num * 10 + (str[i] - 48);
		}
		num *= -1;
	}
	//For positive values
	else
	{
		//Validation
		for (int i = 0; i < length; i++)
		{
			if (!(str[i] >= 48 && str[i] <= 57))
			{
				cout << "Invalid Conversion... Returning -1" << endl;
				return -1;
			}
		}
		//Conversion
		for (int i = 0; i < length; i++)
			num = num * 10 + (str[i] - 48);
	}
	return num;
}

//for conversion from 'MyString' to 'char*' (C-style string) operator 
MyString::operator char *()
{
	char* arr = &str[0];     
	return arr;
}

//overloading pre-increment operator 
MyString& MyString::operator++()
{
	MyString temp(*this);
	str[length - 1] += 1;    //increments last index e.g, 1 becomes 2, 10 becomes 11, abc becomes abd
	return temp;
}

//returns substring of the string from index 'start' to 'end'
MyString MyString::subString(int start, int end) const
{
	MyString s;
	s.length = (end - start) + 1;
	s.str = new char[s.length + 1];
	int j = 0;
	for (int i = start; i <= end; i++)
		s.str[j++] = str[i];
	s.str[s.length] = '\0';
	return s;
}


//returns index of first occurence of substring in the string
int MyString::find(const MyString& c) const
{
	for (int i = 0; i < length; i++)
	{
		if (c.str[0] == str[i])
		{
			bool flag = true;
			int k = i;
			for (int j = 1; j < c.length; j++)
			{
				if (str[++k] != c.str[j])
					flag = false;
			}
			if (flag == true)
				return i;
		}
	}
	cout << "Substring not found...Returning -1" << endl;
	return -1;  
}

//returns index of first occurence of char in the string
int MyString::find(const char c) const
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
			return i;
	}
	cout << "Character not found...Returning -1" << endl;
	return -1;
}

//returns index of first occurence of substring in the string after index 'start'
int MyString::find(const MyString& c, int start) const
{
	for (int i = start; i < length; i++)
	{
		if (c.str[0] == str[i])
		{
			bool flag = true;
			int k = i;
			for (int j = 1; j < c.length; j++)
			{
				if (str[++k] != c.str[j])
					flag = false;
			}
			if (flag == true)
				return i;
		}
	}
	cout << "Substring not found...Returning -1" << endl;
	return -1;
}

//returns index of last occurence of substring in the string
int MyString::rfind(const MyString& c) const
{
	for (int i = length-1; i >= 0; i--)
	{
		if (c.str[0] == str[i])
		{
			bool flag = true;
			int k = i;
			for (int j = 1; j < c.length; j++)
			{
				if (str[++k] != c.str[j])
					flag = false;
			}
			if (flag == true)
				return i;
		}
	}
	cout << "Substring not found...Returning -1" << endl;
	return -1;
}

//returns index of last occurence of char in the string 
int MyString::rfind(const char c) const
{
	for (int i = length-1; i >= 0; i--)
	{
		if (str[i] == c)
			return i;
	}
	cout << "Character not found...Returning -1" << endl;
	return -1;
}