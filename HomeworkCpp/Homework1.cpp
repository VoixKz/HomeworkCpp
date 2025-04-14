#include <iostream>
#include <string>
#include <regex>

using namespace std;

#define DATE_REGEX "\\d{2}-\\d{2}-\\d{4}"
#define PHONE_SIZE 12

bool isValidDateFormat(const string &date) {
	regex pattern(DATE_REGEX);
	return regex_match(date, pattern);
}

class Student {
private:
	string fullName;
	string dateOfBirth;
	char phone[PHONE_SIZE + 1];
	string city;
	string country;
	string institutionName;
	string institutionCity;
	string institutionCountry;
	int groupNumber;

public:
	Student() :
		fullName(""),
		dateOfBirth("01-01-1900"),
		city(""),
		country(""),
		institutionName(""),
		institutionCity(""),
		institutionCountry(""),
		groupNumber(0)
	{
		phone[0] = '\0';
	}
	Student 
	(
		string fullName, string dateOfBirth, const char *phone, string city, string country,
		string institutionName, string institutionCity, string institutionCountry,
		int groupNumber
	) : 
		fullName(fullName), phone(),
		city(city), country(country), institutionName(institutionName),
		institutionCity(institutionCity), institutionCountry(institutionCountry),
		groupNumber(groupNumber) 
	{
		strcpy_s(this->phone, PHONE_SIZE + 1, phone);
		
		setDateOfBirth(dateOfBirth);
	}

	void setFullName(const string &fullName) { this->fullName = fullName; }
	void setDateOfBirth(const string &dateOfBirth) { 
		if (isValidDateFormat(dateOfBirth)) {
			this->dateOfBirth = dateOfBirth;
		}
		else {
			cout << "Invalid date format. Please use DD-MM-YYYY." << endl;
			this->dateOfBirth = "01-01-1900";
		}
	}
	void setPhone(const char *newPhone) { 
		int i = 0;
		while ((newPhone[i] != '\0') && (i < PHONE_SIZE)) {
			phone[i] = newPhone[i];
			i++;
		}
		phone[i] = '\0';
	}
	void setCity(const string &city) { this->city = city; }
	void setCountry(const string &country) { this->country = country; }
	void setInstitutionName(const string &institutionName) { this->institutionName = institutionName; }
	void setInstitutionCity(const string &institutionCity) { this->institutionCity = institutionCity; }
	void setInstitutionCountry(const string &institutionCountry) { this->institutionCountry = institutionCountry; }
	void setGroupNumber(int groupNumber) { this->groupNumber = groupNumber; }

	string getFullName() const { return fullName; }
	string getDateOfBirth() const { return dateOfBirth; }
	const char *getPhone() const { return phone; }
	string getCity() const { return city; }
	string getCountry() const { return country; }
	string getInstitutionName() const { return institutionName; }
	string getInstitutionCity() const { return institutionCity; }
	string getInstitutionCountry() const { return institutionCountry; }
	int getGroupNumber() const { return groupNumber; }

	void input() {
		cout << "Enter full name: ";
		getline(cin, fullName);
		cout << "Enter date of birth (DD-MM-YYYY): ";
		getline(cin, dateOfBirth);
		cout << "Enter phone number: ";
		cin >> phone;
		cin.ignore();
		cout << "Enter city: ";
		getline(cin, city);
		cout << "Enter country: ";
		getline(cin, country);
		cout << "Enter institution name: ";
		getline(cin, institutionName);
		cout << "Enter institution city: ";
		getline(cin, institutionCity);
		cout << "Enter institution country: ";
		getline(cin, institutionCountry);
		cout << "Enter group number: ";
		cin >> groupNumber;
		cin.ignore();
	}

	void output() const {
		cout << "Full Name: " << fullName << endl;
		cout << "Date of Birth: " << dateOfBirth << endl;
		cout << "Phone: " << phone << endl;
		cout << "City: " << city << endl;
		cout << "Country: " << country << endl;
		cout << "Institution Name: " << institutionName << endl;
		cout << "Institution City: " << institutionCity << endl;
		cout << "Institution Country: " << institutionCountry << endl;
		cout << "Group Number: " << groupNumber << endl;
	}
};



int main() {
	
	system("chcp 65001");
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	Student student1;

	Student s1("Bexultan", "14-04-2025", "+77001234567", "Astana", "Kazakhstan",
		"NIS", "Astana", "Kazakhstan", 12);

	Student s2("Wrong Date", "2025/04/14", "+77001234567", "City", "Country",
		"School", "City", "Country", 11);
	
	student1.input();
	student1.output();
	s1.output();
	s2.output();
	return 0;
}
