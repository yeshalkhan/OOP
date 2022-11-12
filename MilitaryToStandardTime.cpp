

#include <iostream>
#include <string>
using namespace std;

class Time
{
protected:
	int hours, min, sec;
public:
	Time(int h = 0, int m = 0, int s = 0)
	{
		hours = h;
		min = m;
		sec = s;
	}
	~Time()
	{

	}
	void setTime(int h = 0, int m = 0, int s = 0)
	{
		hours = h;
		min = m;
		sec = s;
	}
	int getHours() const
	{
		return hours;
	}
	int getMinutes() const
	{
		return min;
	}
	int getSeconds() const
	{
		return sec;
	}
};

class MilTime :public Time
{
	int milHours;
	int milSec;
public:
	MilTime()
	{
		milHours = milSec = 0;
	}
	MilTime(int mh, int ms)
	{
		milHours = mh;
		milSec = ms;
		int m = milHours % 100;
		if ((milHours / 100) > 0 && (milHours / 100) < 9)
		{
			int firstDigit = milHours / 100;
			setTime(firstDigit, m, milSec);
		}
		else
		{
			int firstDigit = milHours / 1000;
			int seconfDigit = (milHours / 100) % 10;
			if (firstDigit == 1 && seconfDigit == 0)
				setTime(10, m, milSec);
			else if (firstDigit == 1 && seconfDigit == 1)
				setTime(11, m, milSec);
			else if (firstDigit == 1 && seconfDigit == 2)
				setTime(12, m, milSec);
			else
			{
				int h = (milHours / 100) - 12;
				setTime(h, m, milSec);
			}
		}
	}
	void setMilTime(int mh, int ms)
	{
		milHours = mh;
		milSec = ms;
		int m = milHours % 100;
		if ((milHours / 100) > 0 && (milHours / 100) < 9)
		{
			int firstDigit = milHours / 100;
			setTime(firstDigit, m, milSec);
		}
		else
		{
			int firstDigit = milHours / 1000;
			int secondDigit = (milHours / 100) % 10;
			if (firstDigit == 1 && secondDigit == 0)
				setTime(10, m, milSec);
			else if (firstDigit == 1 && secondDigit == 1)
				setTime(11, m, milSec);
			else if (firstDigit == 1 && secondDigit == 2)
				setTime(12, m, milSec);
			else
			{
				int h = (milHours / 100) - 12;
				setTime(h, m, milSec);
			}
		}
	}
	MilTime(MilTime& m)
	{
		milHours = m.milHours;
		milSec = m.milSec;
		setTime(m.hours, m.min, m.sec);
	}
	~MilTime() {}
	void display()
	{
		cout << hours << ":" << min << ":" << sec << endl;
	}
};



int main()
{
	int hours, sec;
	cout << "Enter Hours in Military format: ";
	cin >> hours;
	cout << "Enter seconds in military format: ";
	cin >> sec;
	MilTime m(hours, sec);
	cout << "Time in standard format: " << endl;
	m.display();
}

