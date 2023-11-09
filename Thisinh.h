#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "person.h"
#include "mylib.h"
using namespace std;
class ThiSinh : public Person
{
    string sbd;
    float to, li, ho;
    float sum = to + li + ho;
    public:
    vector<string> wishes;
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w);
    void setsbd(string sbd);
    string getsbd();
    void setto(float to);
    float getto();
    void setli(float li);
    float getli();
    void setho(float ho);
    float getho();
    float getsum();
    void input();
    void display();
    ~ThiSinh()
    {
    }
};
void ThiSinh::setsbd(string sbd){
    this->sbd=sbd;
}
string ThiSinh::getsbd(){
    return sbd;
}
    void ThiSinh::setto(float to){
        this->to=to;
    }
    float ThiSinh::getto(){
        return to;
    }
    void ThiSinh::setli(float li){
        this->li=li;
    }
    float ThiSinh:: getli(){
        return li;
    }
    void ThiSinh::setho(float ho){
        this->ho=ho;
    }
    float ThiSinh::getho(){
        return ho;
    }
    float ThiSinh:: getsum(){
        return sum;
    }
ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
}
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w) : Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho)
{
    wishes = w;
};
void ThiSinh::input()
{
    gotoXY(35,1);
    cout << "DIEN THONG TIN THI SINH";
    draw(20, 2, 62, 30);
    SetColor1(7, 4);
    nhapthongtin();
    fflush(stdin);
    gotoXY(22, 11);
    cout << "So bao danh: ";
    getline(cin, sbd);
    gotoXY(22, 12);
    cout << "Diem toan: ";
    cin >> to;
    gotoXY(22, 13);
    cout << "Diem ly: ";
    cin >> li;
    gotoXY(22, 14);
    cout << "Diem hoa: ";
    cin >> ho;
    gotoXY(22, 15);
    int so_nv;
    cout << "So nguyen vong dang ki : ";
    cin >> so_nv;
    fflush(stdin);
    for (int i = 0; i < so_nv; i++)
    {
        string nv;
        gotoXY(22, 16 + i);
        cin.ignore(0);
        cout << "Nguyen vong thu " << i + 1 << " : ";
        getline(cin, nv);
        wishes.push_back(nv);
    }
}
void ThiSinh::display()
{
    cout << "|" << endl;
    cout << "|" << getname() << setw(34 - getname().length()) << "|";
    cout << getcccd() << setw(20 - getcccd().length()) << "|";
    cout << setw(4) << getgt() << setw(4) << "|";
    cout << getdate().day << "/" << getdate().month << "/" << getdate().year << setw(19 - getdate().sizedate()) << "|";
    cout << getaddress() << setw(20 - getaddress().length()) << "|";
    cout << sbd << setw(16 - sbd.length()) << "|";
    cout << setw(7) << to << setw(3) << "|";
    cout << setw(5) << li << setw(3) << "|";
    cout << setw(6) << ho << setw(3) << "|";
    cout << setw(5) << to + li + ho << setw(5) << "|";
}
