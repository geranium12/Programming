#include <sstream>
#include "Airport.h"

void printMenu();
void readAirports(string fileName, vector<Airport> & airports);

int main()
{
	int selection;
	vector<Airport> airports;
	readAirports("Airports.txt", airports);

	//printMenu();
	selection = 0;
	while (selection != 5)
	{
		printMenu();
		cin >> selection;
		switch (selection)
		{
		case 1:
		{
			string str;
			getline(cin, str);
			cout << "Enter the name of the airport : ";
			getline(cin, str);
			bool f = false;
			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getName() == str)
				{
					cout << "Longitude is " << airports[i].getLongitude() << endl << "Latitude is " << airports[i].getLatitude() << endl;
					f = true;
				}
			}
			if (!f) cout << "The list doesn't contain this airport." << endl;
		}
		break;
		case 2:
		{
			string str;
			getline(cin, str);
			cout << "Enter the name of the country : ";
			getline(cin, str);
			bool f = false;
			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getCountry() == str)
				{
					cout << airports[i];
					f = true;
				}
			}
			if (!f) cout << "There are no airports in this country." << endl;
		}
		break;
		case 3:
		{
			string first, second;
			getline(cin, first);
			cout << "Enter the name of the first airport : ";
			getline(cin, first);
			cout << "Enter the name of the second airport : ";
			getline(cin, second);
			int i1 = -1;
			int i2 = -1;
			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getName() == first)
					i1 = i;
				if (airports[i].getName() == second)
						i2 = i;
			}
			if ((i1 != -1) && (i2 != -1))
			{
				cout << airports[i1].distanceTo(airports[i2]) << endl;
			}
			else
			{
				cout << "Can't find one of the airports" << endl;
			}
		}
		break;
		case 4:
		{
			string str;
			getline(cin, str);
			cout << "Enters the name of the municipality : ";
			getline(cin, str);
			bool f = false;
			for (int i = 0; i < airports.size(); i++)
			{
				if (airports[i].getMunicipality() == str)
				{
					cout << airports[i];
					f = true;
				}
			}
			if (!f) cout << "There are no airports in this municipality." << endl;
		}
		break;
		default:
		{
			cout << "Exiting." << endl;
			return 0;
		}
		}
	}
	return 0;
}

void printMenu()
{
	cout << "1. Display the latitude and longitude of a given airport by name.\n"
			"2. Display all airports in a given country.\n"
			"3. Display the distance between two given airports by name.\n"
			"4. Display all the airports in a given municipality.\n"
			"5. Exit the application.\n";
}

void readAirports(string fileName, vector<Airport> &airports) {
	ifstream in;
	in.open(fileName.c_str(), ios::in);
	if (in.is_open()) {
		while (!in.eof())
		{
			Airport air;
			in >> air;
			airports.push_back(air);
		}
	}
}