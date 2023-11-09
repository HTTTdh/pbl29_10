#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "linklist.h"
#include "Nganh.h"
using namespace std;

typedef bool (*CompareFunc)(ThiSinh &, string &);

bool CompareByName(ThiSinh &ts, string &name)
{
    return (ts.getname().find(name) != string::npos);
}

bool CompareByAddress(ThiSinh &ts, string &address)
{
    return (ts.getaddress().find(address) != string::npos);
}

bool CompareByCCCD(ThiSinh &ts, string &cccd)
{
    return (ts.getcccd().find(cccd) != string::npos);
}

bool CompareBySBD(ThiSinh &ts, string &sbd)
{
    return (ts.getsbd().find(sbd) != string::npos);
}

bool CompareByYear(ThiSinh &ts, string &yearStr)
{
    int year = stoi(yearStr);
    return (ts.getdate().year == year);
}

bool CompareByGender(ThiSinh &ts, string &gender)
{

    return (ts.getgt().find(gender) != string::npos);
}

void DisplayFilteredData(LinkedList &list, const string &message, CompareFunc compareFunc, string compareValue)
{
    fflush(stdin);
    node *p = list.getHead();
    gotoXY(80, 5);
    cout << message + ": ";
    getline(cin, compareValue);
    // compareValue = capitalizeFirstLetter(compareValue);
    gotoXY(0, 20);
    Form();
    while (p != NULL)
    {
        if (compareFunc(p->data, compareValue))
        {
            cout << "|";
            for (int i = 0; i < 153; i++)
                cout << "-";
            p->data.display();
            cout << endl;
        }
        p = p->next;
    }
    cout << "|";
    for (int i = 0; i < 153; i++)
    {
        cout << "-";
    }
    cout << "|" << endl;
    system("pause");
}

void search_info(LinkedList &list)
{
    string value;
    string c;
    int lc;
    do
    {
        system("cls");
        SetColor1(7, 2);
        gotoXY(62, 4);
        cout << "CAC THONG TIN CAN TIM";
        Form1();
        gotoXY(62, 13);
        cout << "Moi nhap lua chon :";
        cin >> lc;
        while (lc < 0 || lc > 6)
        {
            fflush(stdin);
            cout << "Lua chon cua ban khong hop le!!! \n Hay nhap lai: ";
            cin >> lc;
        }
        system("cls");
        SetColor1(7, 2);
        gotoXY(22, 4);
        cout << "CAC THONG TIN CAN SUA" << endl;
        draw(20, 2, 50, 15);
        gotoXY(22, 6);
        cout << "1. Ten";
        gotoXY(22, 7);
        cout << "2. Dia Chi";
        gotoXY(22, 8);
        cout << "3. CCCD";
        gotoXY(22, 9);
        cout << "4. SBD";
        gotoXY(22, 10);
        cout << "5. Nam Sinh";
        gotoXY(22, 11);
        cout << "6. Gioi Tinh";
        switch (lc)
        {
        case 1:
            DisplayFilteredData(list, "Nhap ten ban muon hien thi?", CompareByName, value);
            break;
        case 2:
            DisplayFilteredData(list, "Nhap dia chi ban muon hien thi?", CompareByAddress, value);
            break;
        case 3:
            DisplayFilteredData(list, "Nhap so can cuoc cong dan ban muon hien thi?", CompareByCCCD, value);
            break;
        case 4:
            DisplayFilteredData(list, "Nhap so bao danh ma ban muon hien thi?", CompareBySBD, value);
            break;
        case 5:
        {
            string yearString;
            DisplayFilteredData(list, "Nhap nam sinh ban muon hien thi?", CompareByYear, value);
            break;
        }
        case 6:
            DisplayFilteredData(list, "Ban muon hien thi gioi tinh nao? (Nam/Nu)", CompareByGender, value);
            break;
        }
        cout << "Ban co muon tim tiep hay khong? (y/n) ";
        cin >> c;
    } while (c == "y" || c == "Y");
}

void edit_infor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    string New;
    int d;
    string c;
    Date date;
    int luachon;
    do
    {
        system("cls");
        SetColor1(7, 2);
        gotoXY(62, 4);
        cout << "CAC THONG TIN CAN SUA" << endl;
        Form1();
        gotoXY(62, 12);
        cout << "7. Diem";
        gotoXY(62, 14);
        cout << "Moi nhap lua chon :";
        cin >> luachon;
        while (luachon < 0 || luachon > 8)
        {
            fflush(stdin);
            gotoXY(62, 16);
            cout << "Lua chon cua ban khong hop le!!!";
            cout << "Hay nhap lai: ";
            cin >> luachon;
        }
        system("cls");
        SetColor1(7, 2);
        gotoXY(22, 4);
        cout << "CAC THONG TIN CAN SUA" << endl;
        draw(20, 2, 50, 15);
        gotoXY(22, 6);
        cout << "1. Ten";
        gotoXY(22, 7);
        cout << "2. Dia Chi";
        gotoXY(22, 8);
        cout << "3. CCCD";
        gotoXY(22, 9);
        cout << "4. SBD";
        gotoXY(22, 10);
        cout << "5. Nam Sinh";
        gotoXY(22, 11);
        cout << "6. Gioi Tinh";
        gotoXY(22, 12);
        cout << "7. Diem";
        switch (luachon)
        {
        case 1:
        {
            gotoXY(70, 4);
            cout << "Nhap lai ten: ";
            cin.ignore();
            getline(cin, New);
            p->data.setname(New);
            break;
        }
        case 2:
        {
            gotoXY(70, 4);
            string newAddress;
            cout << "Nhap lai dia chi: ";
            cin.ignore();
            getline(cin, newAddress);
            p->data.getaddress() = newAddress;
            break;
        }
        case 3:
        {
            gotoXY(70, 4);
            string newCCCD;
            cout << "Nhap so CCCD moi: ";
            cin.ignore();
            getline(cin, newCCCD);
            p->data.getcccd() = newCCCD;
            break;
        }
        case 4:
        {
            gotoXY(70, 4);
            string sbdnew;
            cout << "Nhap so bao danh moi: ";
            cin.ignore();
            getline(cin, sbdnew);
            p->data.getsbd() = sbdnew;
            break;
        }
        case 5:
        {
            int day, month, year;
            gotoXY(70, 4);
            cout << "Nhap lai ngay/thang/nam sinh: " << endl;
            gotoXY(70, 5);
            cout << "Nhap ngay: ";
            cin >> day;
            gotoXY(70, 6);
            cout << "Nhap thang: ";
            cin >> month;
            gotoXY(70, 7);
            cout << "Nhap nam: ";
            cin >> year;
            // p->data.getdate().day = day;
            // p->data.getdate().month = month;
            // p->data.getdate().year = year;
            p->data.setdate(day, month, year);
            break;
        }
        case 6:
        {
            string newgt;
            gotoXY(70, 4);
            cout << "Nhap gioi tinh: (Nam/Nu) ";
            cin >> newgt;
            p->data.getgt() = newgt;
            break;
        }
        case 7:
        {
            float newMath, newPhysics, newChemistry;
            gotoXY(70, 4);
            cout << "Nhap lai diem";
            gotoXY(70, 6);
            cout << "Nhap diem toan: ";
            cin >> newMath;
            gotoXY(70, 7);
            cout << "Nhap diem ly: ";
            cin >> newPhysics;
            gotoXY(70, 8);
            cout << "Nhap diem hoa: ";
            cin >> newChemistry;
            // p->data.getto() = newMath;
            // p->data.getli() = newPhysics;
            // p->data.getho() = newChemistry;
            p->data.setto(newMath);
            p->data.setli(newPhysics);
            p->data.setho(newChemistry);
            break;
        }
            gotoXY(70, 10);
            cout << "Da cap nhap thong tin\n";
            gotoXY(70, 12);
            cout << "Ban co muon sua thong tin nao nua khong? (y/n) ";
            cin >> c;
        }
    }
        while (c == "y" || c == "Y");

}
    string tim_nganh(float *dc, string s)
    {
        string str = "";
        int result;
        mofile();
        Nganhdaotao *p = pHead;
        while (p != NULL)
        {
            result = strcmp(p->TenNganh.c_str(), s.c_str());
            if (result == 0)
            {
                *dc = p->DiemChuan;
                return s;
            }
            p = p->next;
        }
        // cout << "Khong co ten nganh nay !" << endl;
        return str;
    }
    LinkedList check_dau(LinkedList & ds)
    {
        LinkedList dsdau;
        node *p = ds.head;
        float dc;
        string s;
        while (p != NULL)
        {
            int i = 0;
            do
            {
                s = tim_nganh(&dc, p->data.wishes[i]);
                if (s != "")
                {
                    if (p->data.getsum() >= dc)
                    {
                        p->data.wishes.clear();
                        p->data.wishes.push_back(s);
                        dsdau.insert(p->data);
                        break;
                    }
                }
                else
                {
                    // {cout<<"Khong co ten nganh da nhap";
                    break;
                }
                i++;
            } while (i < p->data.wishes.size());
            p = p->next;
        }
        return dsdau;
    }
