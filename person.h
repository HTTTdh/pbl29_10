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
    cout << "Nhập họ tên: ";
    getline(cin, name);
    cout << "Nhập số cccd: ";
    getline(cin, cccd);
    cout << "Nhập ngày sinh: ";
    cin >> date.day;
    cout << "Nhập tháng sinh: ";
    cin >> date.month;
    cout << "Nhập năm sinh: ";
    cin >> date.year;
    cin.ignore(1);
    cout << "Nhập địa chỉ (chỉ nhập tỉnh): ";
    getline(cin, address);
    cout << "Nhập giới tính (Nam/Nu): ";
    getline(cin,gt);
}
