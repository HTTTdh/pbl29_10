#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include"person.h"
using namespace std;
class ThiSinh : public Person
{
public:
    string sbd;
    float to, li, ho;
    float sum =to +li +ho;
    vector<string> wishes;
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w);
    void input();
    void display();
    ~ThiSinh(){
        
    }
};

ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
}
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, vector<std::string> w) : Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho){
    wishes = w;
};
void ThiSinh::input()
{
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    nhapthongtin();
    fflush(stdin);
    cout << "Nhập số báo danh: ";
    getline(cin, sbd);
    cout << "Nhập điểm toán: ";
    cin >> to;
    cout << "Nhập điểm lý: ";
    cin >> li;
    cout << "Nhập điểm hóa: ";
    cin >> ho;
    int so_nv;
    cout << "Số nguyện vọng bạn đăng kí : " ;
    cin >> so_nv;
    fflush(stdin);
    for (int i = 0; i < so_nv; i++){
        string nv;
        cout << "Nguyện vọng " << i << " : " ;
        cin.ignore();
        getline(cin,nv);
        wishes.push_back(nv);
    }
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
}
void ThiSinh::display()
{
    // cout << "|";
    // for (int i = 0; i < 153; i++)
    //     cout << "-";
    // cout << "|" << endl;
    // cout << "|" << name << setw(34 - name.length()) << "|";
    // cout << cccd << setw(20 - cccd.length()) << "|";
    // cout << setw(4) << gt << setw(4) << "|";
    // cout << date.day << "/" << date.month << "/" << date.year << setw(19 - date.sizedate()) << "|";
    // cout << address<< setw(20 - address.length()) << "|";
    // cout << sbd << setw(16 - sbd.length()) << "|";
    // cout << setw(7) << to << setw(3) << "|";
    // cout << setw(5) << li << setw(3) << "|";
    // cout << setw(6) << ho << setw(3) << "|";
    // cout << setw(5) << to + li + ho << setw(5) << "|" ;
   
    cout << name << " " << cccd << " " << gt << " " << date.day << "/" << date.month << "/" << date.year << " " << address << " " << sbd << " " 
    << to << " " << li << " " << ho << " " << to+li+ho << " ";
    for (string wish : wishes) {
                cout << wish << " ";
            }
    cout << endl;
}


 