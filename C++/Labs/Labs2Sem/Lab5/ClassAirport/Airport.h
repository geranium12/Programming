#pragma once

#define _USE_MATH_DEFINES

#include<cmath>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Airport 
{
private:
	int id;
	string name;
	double latitude;
	double longitude;
	string country;
	string municipality;
public:
	Airport();
	Airport(int x, string nm, double alt, double lon, string isc, string mnc);
	~Airport() {}
	void setId(int i);
	void setName(string nm);
	void setLatitude(double alt);
	void setLongitude(double lon);
	void setCountry(string isc);
	void setMunicipality(string mnc);

	int getId();
	string getName();
	double getLatitude();
	double getLongitude();
	string getCountry();
	string getMunicipality();

	friend istream& operator >>(istream &in, Airport &air);
	friend ostream& operator <<(ostream &out, const Airport &air);
	double distanceTo(Airport theOther);
};