
#include <iostream>
#include "MyString.h"
#define MAX_LENGTH 65536
using namespace std;

//overloading stream insertion operator as friend function
ostream& operator<<(ostream& outObj, const MyString& c)
{
	outObj << c.str << endl;
	return outObj;
}

//overloading stream extraction operator as friend function
istream& operator>>(istream& inObj, MyString& c)
{
	c.length = 10;   //set initial length
	c.str = new char[c.length + 1];
	int i;
	char ch;
	for (i = 0; i < MAX_LENGTH; i++)  //maximum length i've allowed for my string is 65535
	{
		if (i >= c.length)   //to create virtually unlimited memory
			c.resize();
		inObj.get(ch);
		if (ch == '\n')   //stop at enter key
			break;
		else
			c.str[i] = ch;
	}
	c.length = i;
	c.str[i] = '\0';
	return inObj;
}


//This driver function shows working of all the member functions of MyString
int main()
{
	int choice;
	char* arr = new char[MAX_LENGTH + 1];

	cout << "\n\tENTER -1 TO STOP" << endl;
	cout << "\n\tENTER A NUMBER\n" << endl;
	cout << "1. Show working of DEFAULT CONSTRUCTOR" << endl;
	cout << "2. Show working of PARAMETERZIED CONSTRUCTOR" << endl;
	cout << "3. Show working of >> OPERATOR" << endl;
	cout << "4. Show working of << OPERATOR" << endl;
	cout << "5. Show working of DISPLAY FUNCTION" << endl;
	cout << "6. Show working of ASSIGNMENT OPERATOR" << endl;
	cout << "7. Show working of + OPERATOR" << endl;
	cout << "8. Show working of == OPERATOR" << endl;
	cout << "9. Show working of < OPERATOR" << endl;
	cout << "10. Show working of <= OPERATOR" << endl;
	cout << "11. Show working of += OPERATOR" << endl;
	cout << "12. Show working of SETSTR FUNCTION" << endl;
	cout << "13. Show working of OPERATOR INT" << endl;
	cout << "14. Show working of OPERATOR CHAR*" << endl;
	cout << "15. Show working of PRE INCREMENT OPERATOR" << endl;
	cout << "16. Show working of SUBSTRING FUNCTION (from start to end)" << endl;
	cout << "17. Show working of FIND FUNCTION (1st occurence of substring)" << endl;
	cout << "18. Show working of FIND FUNCTION (1st occurence of character)" << endl;
	cout << "19. Show working of FIND FUNCTION (1st occurence of substring after index 'start')" << endl;
	cout << "20. Show working of RFIND FUNCTION (last occurence of substring)" << endl;
	cout << "21. Show working of RFIND FUNCTION (last occurence of character)" << endl;
	cout << "22. Show working of COPY CONSTRUCTOR" << endl;
	cout << "23. Show working of GETLENGTH FUNCTION" << endl;

	do
	{
		cout << "\nENTER CHOICE: ";
		cin >> choice;
		if (choice == 1)
		{
			MyString a;
			cout << "OUTPUT OF DEFAULT STRING: " << a << endl;
		}
		else if (choice == 2)
		{
			MyString b("Demo value");
			cout << "OUTPUT OF PARAMETERIZED STRING: " << b << endl;
		}
		else if (choice == 3)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			cout << "OUTPUT OF ENTERED STRING: " << c << endl;
		}
		else if (choice == 4)
		{
			MyString d;
			cout << "Enter string to display: ";
			cin.ignore();
			cin >> d;
			cout << "OUTPUT: " << d << endl;
		}
		else if (choice == 5)
		{
			MyString d;
			cout << "Enter string to display: ";
			cin.ignore();
			cin >> d;
			cout << "OUTPUT: ";
			d.display();
			cout << endl;
		}
		else if (choice == 6)
		{
			MyString s1;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			MyString s2;
			cout << "Assigning s1's value to s2: " << endl;
			s2 = s1;
			cout << "S2 AFTER ASSIGNMENT: " << s2 << endl;
		}
		else if (choice == 7)
		{
			MyString s1, s2, s3;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			cout << "Enter string in s2: ";
			cin >> s2;
			cout << "Adding s1 & s2: " << endl;
			s3 = s1 + s2;
			cout << "OUTPUT OF CONCATENATION: " << s3 << endl;
		}
		else if (choice == 8)
		{
			MyString s1, s2;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			cout << "Enter string in s2: ";
			cin >> s2;
			if (s1 == s2) cout << "S1 & S2 ARE EQUAL" << endl;
			else cout << "S1 & S2 ARE NOT EQUAL" << endl;
		}
		else if (choice == 9)
		{
			MyString s1, s2;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			cout << "Enter string in s2: ";
			cin >> s2;
			if (s1 < s2) cout << "S1 IS LESS THAN S2" << endl;
			else cout << "S1 IS NOT LESS THAN S2" << endl;
		}
		else if (choice == 10)
		{
			MyString s1, s2;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			cout << "Enter string in s2: ";
			cin >> s2;
			if (s1 <= s2) cout << "S1 IS LESS THAN OR EQUAL TO S2" << endl;
			else cout << "S1 IS NOT LESS THAN OR EQUAL TO S2" << endl;
		}
		else if (choice == 11)
		{
			MyString s1, s2;
			cout << "Enter string in s1: ";
			cin.ignore();
			cin >> s1;
			cout << "Enter string in s2: ";
			cin >> s2;
			cout << "Adding s1 & s2: " << endl;
			s1 += s2;
			cout << "S1 AFTER +=: " << s1 << endl;
		}
		else if (choice == 12)
		{
			MyString a;
			cout << "Enter character array: ";
			cin.ignore();
			cin.get(arr, MAX_LENGTH);
			a.setStr(arr);
			cout << "OUTPUT AFTER SETSTR: " << a << endl;
		}
		else if (choice == 13)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			int val = c.operator int();
			cout << "AFTER CONVERSION: " << val << endl;
		}
		else if (choice == 14)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			char* val = c.operator char* ();
			cout << "AFTER CONVERSION: " << val << endl;
		}
		else if (choice == 15)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			++c;
			cout << "AFTER INCREMENT: " << c << endl;
		}
		else if (choice == 16)
		{
			MyString c, sub;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			int start, end;
			cout << "Enter starting index: ";
			cin >> start;
			cout << "Enter ending index: ";
			cin >> end;
			sub = c.subString(start, end);
			cout << "SUBSTRING FROM INDEX " << start << " TO " << end << " IS: " << sub << endl;
		}
		else if (choice == 17)
		{
			MyString c, sub;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			cout << "Enter substring to find: ";
			cin >> sub;
			int index = c.find(sub);
			cout << "1ST OCCURENCE OF SUBSTRING IS AT INDEX: " << index << endl;
		}
		else if (choice == 18)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			char ch;
			cout << "Enter character to find: ";
			cin >> ch;
			int index = c.find(ch);
			cout << "1ST OCCURENCE OF CHARACTER IS AT INDEX: " << index << endl;
		}
		else if (choice == 19)
		{
			MyString c, sub;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			cout << "Enter substring to find: ";
			cin >> sub;
			int start;
			cout << "Enter starting index: ";
			cin >> start;
			int index = c.find(sub, start);
			cout << "1ST OCCURENCE OF SUBSTRING AFTER START IS AT INDEX: " << index << endl;
		}
		else if (choice == 20)
		{
			MyString c, sub;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			cout << "Enter substring to find: ";
			cin >> sub;
			int index = c.rfind(sub);
			cout << "LAST OCCURENCE OF SUBSTRING IS AT INDEX: " << index << endl;
		}
		else if (choice == 21)
		{
			MyString c;
			cout << "Enter string: ";
			cin.ignore();
			cin >> c;
			char ch;
			cout << "Enter character to find: ";
			cin >> ch;
			int index = c.rfind(ch);
			cout << "LAST OCCURENCE OF CHARACTER IS AT INDEX: " << index << endl;
		}
		else if (choice == 22)
		{
		    MyString s1;
		    cout << "Enter string in S1: ";
		    cin.ignore();
		    cin >> s1;
			cout << "Copying S1 into S2: " << endl;
			MyString s2(s1);
			cout << "OUTPUT OF S2: " << s2 << endl;
		}
		else if (choice == 23)
		{
		    MyString s1;
		    cout << "Enter string: ";
		    cin.ignore();
		    cin >> s1;
			cout << "LENGTH OF ENTERED STRING: " << s1.getLength() << endl;
		}
		else
		{
			cout << "INVALID CHOICE...PROGRAM ENDED" << endl;
			break;
		}
	}
	while (choice != -1);

}

