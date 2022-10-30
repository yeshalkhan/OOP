

#include <iostream>
#include <string>
using namespace std;

class ParkingTicket;
class PoliceOfficer;
class ParkedCar
{
	string model;
	string license;
	int min;
public:
	friend PoliceOfficer;
	ParkedCar()
	{
		model = license = " ";
		min = 0;
	}
	ParkedCar(string a, string b, int c)
	{
		model = a;
		license = b;
		min = c;
	}
	~ParkedCar()
	{

	}
	void setCar(string a, string b, int c)
	{
		model = a;
		license = b;
		min = c;
	}
	string getModel() const
	{
		return model;
	}
	string getLicense() const
	{
		return license;
	}
	int getMin() const
	{
		return min;
	}
};

class ParkingMeter
{
	int parkMin;
public:
	friend PoliceOfficer;
	ParkingMeter()
	{
		parkMin = 0;
	}
	ParkingMeter(int a)
	{
		parkMin = a;
	}
	void setParkMin(int a)
	{
		parkMin = a;
	}
	~ParkingMeter()
	{

	}
	int getParkMin() const
	{
		return parkMin;
	}
};

class ParkingTicket
{
	int fine;
	ParkedCar* car;
	PoliceOfficer* officer;
public:
	ParkingTicket()
	{
		fine = 0;
	}
	ParkingTicket(int a, ParkedCar& p, PoliceOfficer& o)
	{
		fine = a;
		car = &p;
		officer = &o;
	}
	~ParkingTicket()
	{

	}
	void setTicket(int a, ParkedCar& p, PoliceOfficer& o)
	{
		fine = a;
		car = &p;
		officer = &o;
	}
	int calculateFine(int carMin, int parkMin)
	{
		int min = carMin - parkMin;
		fine = 0;
		if (min <= 60)
			fine += 25;
		else if (min > 60)
		{
			fine += 25;
			for (int i = min; i >= 60;)
			{
				i -= 60;
				fine += 10;
			}
		}
		return fine;
	}
	int getFine() const
	{
		return fine;
	}
	void displayCar()
	{
		cout << "Model: " << car->getModel() << "   License Number: " << car->getLicense() << endl;
	}
	PoliceOfficer& getOfficer()
	{
		return *officer;
	}
};


class PoliceOfficer
{
	string name;
	int badge;
public:
	PoliceOfficer()
	{
		name = " ";
		badge = 0;
	}
	PoliceOfficer(string n, int b)
	{
		name = n;
		badge = b;
	}
	~PoliceOfficer()
	{

	}
	bool determineExpiry(ParkedCar &p,ParkingMeter &m)
	{
		if (p.min > m.parkMin)
			return true;
		else
			return false;
	}
	ParkingTicket& issueTicket(ParkedCar &p,ParkingMeter &m)
	{
		ParkingTicket t;
		int f = t.calculateFine(p.min, m.parkMin);
		t.setTicket(f, p, *this);
		return t;
	}
	string getName() const
	{
		return name;
	}
	int getBadge() const
	{
		return badge;
	}
};


int main()
{
	ParkedCar car("Porsche", "BB2022", 120);
	ParkingMeter meter(50);
	PoliceOfficer officer("Robert", 619);
	if (officer.determineExpiry(car, meter))
	{
		ParkingTicket ticket = officer.issueTicket(car, meter);
		cout << "Car's info: " << endl;
	    ticket.displayCar();
		cout << "Officer's info: " << endl;
		cout << "Name: " << ticket.getOfficer().getName() << "   Badge Number: " << ticket.getOfficer().getBadge() << endl;
		cout << "Fine: ";
		cout << ticket.getFine() << endl;
	}
	else
	{
		cout << "No parking ticket issued..." << endl;
	}
}

