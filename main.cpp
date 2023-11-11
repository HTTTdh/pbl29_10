#include <iostream>
#include <windows.h>
#include <string>
#include "mylib.h"
#include "main.h"

using namespace std
int x = 40;
int y = 5;
void box(int x, int y, int w, int h, int t_color, int b_color, string tieude)
{
    textcolor(b_color);
    for (int iy = y + 1; iy <= y + h - 1; iy++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << tieude;
    textcolor(1);
    SetColor(t_color);
    if (h <= 1 || w <= 1)
        return;
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoXY(ix, y);
        cout << char(196);
        gotoXY(ix, y + h);
        cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoXY(x, iy);

        cout << char(179);
        gotoXY(x + w, iy);
        cout << char(179);
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x, y + h);
    cout << char(192);
    gotoXY(x + w, y + h);
    cout << char(217);
}
void n_box(int x, int y, int w, int h, int t_color, int b_color, string nd[], int n)
{
    for (int i = 0; i < n; i++)
    {
        box(x, y + i * 2, w, h, t_color, b_color, nd[i]);
        if (i != 0)
        {
            gotoXY(x, y + i * 2);
            cout << char(195);
            gotoXY(x + 40, y + (i * 2));
            cout << char(180);
        }
    }
}
void thanh_sang(int x, int y, int w, int h, int b_color, string tieude)
{
    textcolor(b_color);
    for (int iy = y + 1; iy <= y + h - 1; iy++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    cout << tieude;
}
void inMenu(int x, int y, int w, int h, int t_color, int b_color, int b_color_sang, string nd[], int n)
{
    n_box(x, y, w, h, t_color, b_color, nd, n);
    thanh_sang(x, y, w, h, b_color_sang, nd[0]);
}
void menu()
{
    LinkedList danhsach;
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    danhsach.docfile();
    ShowCur(0);
    int w = 40;
    int h = 2;
    string nd[10] = {"XUAT DANH SACH CAC THI SINH", "THEM MOT THI SINH", "XOA MOT THI SINH", "SUA THONG TIN THI SINH", "TIM KIEM THONG TIN THI SINH", "SAP XEP DANH SACH THEO DIEM", "DANH DACH DAU DAI HOC", "DANH SACH DAU THEO NGANH", "THOAT"};
    int n = 9;
    bool kt = false;
    int b_color = 1;
    int pointer = 0;
    int t_color = 11;
    int b_color_sang = 75;
    inMenu(x, y, w, h, t_color, b_color, b_color_sang, nd, n);
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    int i = 0;
    int d = 0;
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, nd[i]);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, nd[d]);
            kt = false;
            i = d;
        }

        if (_kbhit())
        {
            char cs;
            char c = _getch();
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72)
                {
                    if (yp != y)
                    {
                        yp -= 2;
                        d = i - 1;
                    }
                    else
                    {
                        yp = y + h * (n - 1);
                        d = (i - 1 + (n)) % n;
                    }
                }
                else if (c == 80)
                {
                    if (yp != y + h * (n - 1))
                    {
                        yp += 2;
                        d = i + 1;
                    }
                    else
                    {
                        yp = y;
                        d = (i + 1) % n;
                    }
                }
            }
            else if (c == 13)
            {
                system("cls");
                system("COLOR F0");
                switch (d)
                {
                case 0:
                {
                    danhsach.xuat();
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 1:
                {
                    output();
                    ts.input();
                    danhsach.insert(ts);
                    danhsach.ghifile();
                    gotoXY(62,31);
                    cout << "Da them thanh cong";
                    gotoXY(70,3);
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 2:
                {
                    draw(60,2,90,10);
                    SetColor1(7, 2);
                    gotoXY(62,4);
                    cout << "Nhap thong tin ban muon xoa:" << endl;
                        fflush(stdin);
                        SetColor1(7, 4);
                        gotoXY(62,6);
                         cout << "Ten: ";
                        getline(cin, name);
                        gotoXY(62,7);
                        cout << "sbd: ";
                        getline(cin, sbd);
                    if (danhsach.search(sbd, name) != NULL)
                    {
                        if (danhsach.Delete(sbd, name) == true)
                         {  gotoXY(62,9); 
                            cout << "Da xoa thanh cong\n";}
                        else
                        {
                            gotoXY(62,9);
                            cout << "Khong xoa duoc thong tin nay" << endl;
                        }
                    }
                    else
                       {gotoXY(62,9); 
                        cout << "Khong tim thay thong tin" << endl;}
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 3:
                {
                     draw(60,2,90,10);
                    SetColor1(7, 4);
                    gotoXY(62,4);
                    cout << "Nhap thong tin ban muon sua:" << endl;
                        fflush(stdin);
                        SetColor1(7, 4);
                        gotoXY(62,6);
                         cout << "Ten: ";
                        getline(cin, name);
                        gotoXY(62,7);
                        cout << "sbd: ";
                        getline(cin, sbd);
                    if (danhsach.search(sbd, name) != NULL)
                    {
                        edit_infor(danhsach, sbd, name);
                        danhsach.ghifile();
                        gotoXY(0,20);
                        danhsach.xuat();
                    }
                    else
                        {gotoXY(62,9); cout << "khong tim thay thong tin" << endl;}
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 4:
                {
                    for (int i = 0; i < 50; i++)
                        cout << "-";
                    cout << endl;
                    cout << "Ban muon tim kiem thong qua thong tin nao?" << endl;
                    search_info(danhsach);
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 5:
                {
                    danhsach.sapxepdiem();
                    danhsach.xuat();
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 6:
                {
                    LinkedList ds;
                    ds = check_dau(danhsach);
                     cout << "+";
    for (int i = 0; i < 170; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(14) << "Ten" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(14) << "Ngay Sinh" << setw(5) << "|";
    cout << setw(12) << "Dia Chi" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(7) << "Toan" << setw(3) << "|";
    cout << setw(5) << "Ly" << setw(3) << "|";
    cout << setw(6) << "Hoa" << setw(3) << "|";
    cout << setw(7) << "Tong" << setw(3) << "|";
    cout << "Ten Nganh" << setw(13) << "|" << endl;
    node *temp = ds.head;
while (temp != NULL)
{
    temp->data.display();
    cout << temp->data.wishes[0];
    cout << endl;
    temp = temp->next;
}
        cout << "|";
        for (int i = 0; i < 153; i++)
            cout << "-";
        cout << "|" << endl;
                    // ds.xuat();
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 7:
                {
                    cout << "Nguoi dung chon: " << nd[i] << endl;
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 8:
                {
                    exit(0);
                    break;
                }
                }
                 n_box(x, y, w, h, t_color, b_color, nd, n);
            }
        }
    }
}
int main()
{
    SetConsoleOutputCP(437);
    menu();
    return 0;
}
