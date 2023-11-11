#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
using namespace std;
class Date
{
public:
    int day, month, year;
    int sizedate()
    {
        int m = 6;
        if (day < 10)
            m++;
        else
            m += 2;
        if (month < 10)
            m++;
        else
            m = m + 2;
        return m;
    }
    Date(int day=0,int month=0, int year=0):day(day), month(month),year(year){}
};

class Person
{
public:
    string cccd;
    string name;
    Date date;
    string address;
    string gt;
    Person();
    Person(string cccd, string name, Date date, string address, string gt);
    void nhapthongtin();
};

Person::Person()
{
    cccd = "";
    name = "";
    date.day = 0;
    date.month = 0;
    date.year = 0;
    address = "";
    gt ="";
}
Person::Person(string cccd, string name, Date date, string address, string gt) : cccd(cccd), name(name), date(date), address(address), gt(gt){};
void Person::nhapthongtin()
{
    fflush(stdin);
	gotoXY(62, 12);
    cout  << "Ho ten: ";
    getline(cin, name);
    gotoXY(62,13);
    cout  << "So cccd: ";
    getline(cin, cccd);
     gotoXY(62,14);
    cout <<  "Ngay sinh: ";
    cin >> date.day;
     gotoXY(62,15);
    cout << "Thang sinh: ";
    cin >> date.month;
     gotoXY(62,16);
    cout  << "Nam sinh: ";
    cin >> date.year;
     gotoXY(62,17);
    cin.ignore(1);
    cout  << "Dia chi (chi nhap tinh): ";
    getline(cin, address);
     gotoXY(62,18);
    cout << "Gioi tinh (Nam/Nu): ";
    getline(cin,gt);
}
