#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include"person.h"
#include"Thisinh.h"
using namespace std;

class node
{
public:
    ThiSinh data;
    node *next;
    node(ThiSinh ts)
    {
        data = ts;
        next = NULL;
    }
};

void Form()
{
    cout << "+";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(15) << "Tên" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(15) << "Ngày Sinh" << setw(5) << "|";
    cout << setw(17) << "Địa Chỉ" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(8) << "Toán" << setw(3) << "|";
    cout << setw(6) << "Lý" << setw(3) << "|";
    cout << setw(7) << "Hóa" << setw(3) << "|";
    cout << setw(9) << "Tổng" << setw(3) << "|" << endl;
}
void Form1(){
           
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << setw(107) << "|   1. Tên                     |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(111) << "|   2. Địa chỉ                 |" << endl;
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   3. CCCD                    |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(107) << "|   4. SBD                     |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(108) << "|   5. Năm sinh                |\n";
            cout << setw(75) << "|" << setw(31) << "|" << endl;
            cout << setw(109) << "|   6. Giới tính               |" << endl;
            
}
class LinkedList
{
   
public:
    node *head;
    node* getHead(){
        return head;
    }
    LinkedList()
    {
        head = NULL;
    }
     void insert(ThiSinh sv)
    {
        node *newNode = new node(sv);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
     bool Delete(string sbd, string name)
    {
        node *p = search(sbd, name);
        if (p != NULL)
        {
            node *pre;
            node *temp = head;
            while (temp != NULL && p->data.sbd != temp->data.sbd)
            {
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete (temp);
            return true;
        }
        else
            return false;
    }
     void xuat()
    {
        node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
        cout << "|";
        for (int i = 0; i < 153; i++)
            cout << "-";
        cout << "|" << endl;
    }
    node *search(string sbd, string name)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data.sbd.find(sbd) != string::npos && temp->data.sbd.find(name) != string ::npos)
                return temp;
            else
                temp = temp->next;
        }
        return NULL;
    }
    void sapxepdiem(){
    if (head == NULL)
    {
        cout << "Danh sách rỗng.";
        return;
    }

    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    bool swapped;
    node *ptr1;
    node *lptr = NULL;

    // Lặp lại quá trình sắp xếp cho đến khi không có cặp phần tử nào được tráo đổi
    for (int i = 0; i < count - 1; i++)
    {
        swapped = false;
        ptr1 = head;

        // Lặp qua tất cả các phần tử và so sánh điểm của chúng
        for (int j = 0; j < count - i - 1; j++)
        {
            if (ptr1->data.sum < ptr1->next->data.sum)
            {
                // Hoán đổi nội dung giữa hai phần tử
                ThiSinh temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }

        // Nếu không có phần tử nào được tráo đổi, thì danh sách đã được sắp xếp
        if (swapped == false)
            break;
        
}
xuat();

    }
     bool testempty()
    {
        return (head==nullptr);
    }
    bool ktra(string cccd)
    {
        node *p = head;
        while (p != nullptr)
        {
            if (p->data.cccd.find(cccd) != string::npos)
                return true;
            p = p->next;
        }
        return false;
    }
    void docfile();
    void ghifile();
};

void LinkedList::docfile()
{
    ThiSinh ts;
    ifstream infile("dsthisinh.txt");
  if (infile.is_open())
{
  string line;
  while (getline(infile, line))
  {
    stringstream ss(line);
    string field;
    vector<string> fields;

    while (getline(ss, field, ',')) {
        fields.push_back(field);
    }

    if (fields.size() >= 9) {
        string name = fields[0];
        string cccd = fields[1];
        string gt = fields[2];

        string dob = fields[3];
        stringstream ss_dob(dob);
        string day_str, month_str, year_str;
        getline(ss_dob, day_str, '/');
        getline(ss_dob, month_str, '/');
        getline(ss_dob, year_str, '/');
        int day = stoi(day_str);
        int month = stoi(month_str);
        int year = stoi(year_str);

        string address = fields[4];
        string sbd = fields[5];
        float to = stof(fields[6]);
        float li = stof(fields[7]);
        float ho = stof(fields[8]);

        vector<string> wishes;
        if (fields.size() > 9) {
            stringstream ss_major(fields[9]);
            string major;
            while (ss_major >> major) {
                wishes.push_back(major);
            }
        }

        ThiSinh candidate(cccd, name, Date(day, month, year), address, gt, sbd, to, li, ho, wishes);
        insert(candidate);
    }
}

        infile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}

void LinkedList::ghifile(){
    ofstream outputFile;
    outputFile.open("dsthisinh.txt", ios::out);
    if (outputFile.is_open())
    {
        node* current = head; 
        while (current != NULL)
        {
            outputFile << current->data.name << ", " << current->data.cccd << ", " << current->data.gt << ", "
                       << current->data.date.day << "/" << current->data.date.month << "/" << current->data.date.year
                       << ", " << current->data.address<< ", " << current->data.sbd << ", " << current->data.to
                       << ", " << current->data.li << ", " << current->data.ho;
             for (string wish : current->data.wishes) {
                outputFile  << ", " << wish;
            }
            outputFile << endl;
            current = current->next; 
        }
        outputFile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}
