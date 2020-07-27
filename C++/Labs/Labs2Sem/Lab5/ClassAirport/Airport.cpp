/*
	Герасимчик Анна. 1 курс. 7 группа.
	Индивидуальное задание - класс Аэропорт.
*/
#include "Airport.h"

Airport::Airport()
{
	int id = 0;
	string name = "";
	double latitude = 0;
	double longitude = 0;
	string Country = "";
	string municipality = "";
}

Airport::Airport(int x, string nm, double alt, double lon, string isc, string mnc)
{
	id = x;
	name = nm;
	latitude = alt;
	longitude = lon;
	country = isc;
	municipality = mnc;
}

void Airport::setId(int i)
{
	id = i;
}

void Airport::setName(string nm)
{
	name = nm;
}

void Airport::setLatitude(double alt)
{
	latitude = alt;
}

void Airport::setLongitude(double lon)
{
	longitude = lon;
}

void Airport::setCountry(string isc)
{
	country = isc;
}

void Airport::setMunicipality(string mnc)
{
	municipality = mnc;
}

int Airport::getId()
{
	return id;
}

string Airport::getName()
{
	return name;
}

double Airport::getLatitude()
{
	return latitude;
}

double Airport::getLongitude()
{
	return longitude;
}

string Airport::getCountry()
{
	return country;
}

string Airport::getMunicipality()
{
	return municipality;
}

istream& operator >>(istream &in, Airport &air)
{
	string str;
	in >> air.id;
	getline(in, str);
	getline(in, air.name, '\n');
	in >> air.latitude;
	in >> air.longitude;
	getline(in, str);
	getline(in, air.municipality);
	getline(in, air.country);
	return in;
}

ostream& operator <<(ostream &out, const Airport &air)
{
	out << right << setw(8) << air.id << " ";
	out << left << setw(45) << air.name << " ";
	out << right << setw(10) << air.latitude << " ";
	out << right << setw(10) << air.longitude << " ";
	out << left << setw(10) << air.country << " ";
	out << left << air.municipality << "\n";
	return out;
}

double Airport::distanceTo(Airport theOther)
{
	double dlon = (longitude - theOther.getLongitude()) * (M_PI / 180);
	double dlat = (latitude - theOther.getLatitude()) * (M_PI / 180);

	double a = pow(sin(dlat / 2), 2) + cos(theOther.latitude) * cos(latitude) * pow(sin(dlon / 2), 2);

	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double d = 6373.0 * c;
	return d;
}