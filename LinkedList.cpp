// Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <ctime>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KeyEsc 27

using namespace std;



class Tutor
{
public:
    //global variable that stores linked list size
    int size = 0;

    //Tutor Struct
    struct tutor {

        int tutorID = 0;
        string name;
        string dateJoined;
        string dateTerminated;
        string phone;
        string address;
        string centreCode;
        string subjectCode;
        float rating = 0;
        tutor* previous;
        tutor* next;
    } *head, * tail;

    //centre Struct
    struct centre {
        string centreCode;
        string centreLocation;
        centre* next;
    }*centreHead, * centreTail;

    //subject struct
    struct subject {
        string subjectCode;
        string subjectName;
        double hourlyRate = 0;
        subject* next;
    }*subjectHead, * subjectTail;

    //tutor constructor
    Tutor() {
        head = NULL;
        tail = NULL;
        centreHead = NULL;
        centreTail = NULL;
        subjectHead = NULL;
        subjectTail = NULL;
    }

    //get the size of the list
    int getSize() {
        return size;
    }


    //fake data that will be inserted once the program runs
    void harcodedData() {
        //create new tutor
        tutor* newTutor;
        newTutor = new tutor();

        newTutor->tutorID = 1;
        newTutor->name = "Bryan";
        newTutor->dateJoined = "16/02/2018";
        newTutor->dateTerminated = "16/02/2019";

        newTutor->phone = "012345678";
        newTutor->address = "KL";
        newTutor->centreCode = "c2";
        newTutor->subjectCode = "s1";
        newTutor->rating = 3;
        newTutor->previous = NULL;
        newTutor->next = NULL;
        head = newTutor;
        tail = newTutor;
        size++;

        tutor* newTutor2;
        newTutor2 = new tutor();
        newTutor2->tutorID = 2;
        newTutor2->name = "Chun Wei";
        newTutor2->dateJoined = "16/05/2019";
        newTutor2->dateTerminated = "16/06/2020";

        newTutor2->phone = "01245678";
        newTutor2->address = "Penang";
        newTutor2->centreCode = "c1";
        newTutor2->subjectCode = "s2";
        newTutor2->rating = 3;
        newTutor2->previous = newTutor;
        newTutor2->next = NULL;
        tail->next = newTutor2;
        tail = tail->next;
        size++;

        tutor* newTutor3;
        newTutor3 = new tutor();
        newTutor3->tutorID = 3;
        newTutor3->name = "May";
        newTutor3->dateJoined = "16/02/2020";
        newTutor3->dateTerminated = "16/07/2020";

        newTutor3->phone = "01245678";
        newTutor3->address = "Penang";
        newTutor3->centreCode = "c1";
        newTutor3->subjectCode = "s2";
        newTutor3->rating = 3;
        newTutor3->previous = newTutor2;
        newTutor3->next = NULL;
        tail->next = newTutor3;
        tail = tail->next;
        size++;

        


        tutor* newTutor4;
        newTutor4 = new tutor();
        newTutor4->tutorID = 4;
        newTutor4->name = "Caven";
        newTutor4->dateJoined = "16/02/2020";
        newTutor4->dateTerminated = "16/07/2020";

        newTutor4->phone = "01245678";
        newTutor4->address = "Penang";
        newTutor4->centreCode = "c1";
        newTutor4->subjectCode = "s2";
        newTutor4->rating = 3;
        newTutor4->previous = newTutor3;
        newTutor4->next = NULL;
        tail->next = newTutor4;
        tail = tail->next;
        size++;


        tutor* newTutor5;
        newTutor5 = new tutor();
        newTutor5->tutorID = 5;
        newTutor5->name = "Kumar";
        newTutor5->dateJoined = "16/02/2020";
        newTutor5->dateTerminated = "16/07/2020";

        newTutor5->phone = "01245678";
        newTutor5->address = "Penang";
        newTutor5->centreCode = "c1";
        newTutor5->subjectCode = "s2";
        newTutor5->rating = 3;
        newTutor5->previous = newTutor4;
        newTutor5->next = NULL;
        tail->next = newTutor5;
        tail = tail->next;
        size++;


        tutor* newTutor6;
        newTutor6 = new tutor();
        newTutor6->tutorID = 6;
        newTutor6->name = "Jason";
        newTutor6->dateJoined = "16/02/2020";
        newTutor6->dateTerminated = "16/07/2020";

        newTutor6->phone = "01245678";
        newTutor6->address = "Penang";
        newTutor6->centreCode = "c1";
        newTutor6->subjectCode = "s2";
        newTutor6->rating = 3;
        newTutor6->previous = newTutor5;
        newTutor6->next = NULL;
        tail->next = newTutor6;
        tail = tail->next;
        size++;

        tutor* newTutor7;
        newTutor7 = new tutor();
        newTutor7->tutorID = 7;
        newTutor7->name = "Justin";
        newTutor7->dateJoined = "16/02/2020";
        newTutor7->dateTerminated = "16/07/2020";

        newTutor7->phone = "01245678";
        newTutor7->address = "Penang";
        newTutor7->centreCode = "c1";
        newTutor7->subjectCode = "s2";
        newTutor7->rating = 3;
        newTutor7->previous = newTutor6;
        newTutor7->next = NULL;
        tail->next = newTutor7;
        tail = tail->next;
        size++;

        tutor* newTutor8;
        newTutor8 = new tutor();
        newTutor8->tutorID = 8;
        newTutor8->name = "Peach";
        newTutor8->dateJoined = "16/02/2020";
        newTutor8->dateTerminated = "16/07/2020";

        newTutor8->phone = "01245678";
        newTutor8->address = "Penang";
        newTutor8->centreCode = "c1";
        newTutor8->subjectCode = "s2";
        newTutor8->rating = 3;
        newTutor8->previous = newTutor7;
        newTutor8->next = NULL;
        tail->next = newTutor8;
        tail = tail->next;
        size++;

        tutor* newTutor9;
        newTutor9 = new tutor();
        newTutor9->tutorID = 9;
        newTutor9->name = "Loges";
        newTutor9->dateJoined = "16/02/2020";
        newTutor9->dateTerminated = "16/07/2020";

        newTutor9->phone = "01245678";
        newTutor9->address = "Penang";
        newTutor9->centreCode = "c1";
        newTutor9->subjectCode = "s2";
        newTutor9->rating = 3;
        newTutor9->previous = newTutor8;
        newTutor9->next = NULL;
        tail->next = newTutor9;
        tail = tail->next;
        size++;

        tutor* newTutor10;
        newTutor10 = new tutor();
        newTutor10->tutorID = 10;
        newTutor10->name = "Xinghan";
        newTutor10->dateJoined = "16/02/2020";
        newTutor10->dateTerminated = "16/07/2020";

        newTutor10->phone = "01245678";
        newTutor10->address = "Penang";
        newTutor10->centreCode = "c1";
        newTutor10->subjectCode = "s2";
        newTutor10->rating = 3;
        newTutor10->previous = newTutor9;
        newTutor10->next = NULL;
        tail->next = newTutor10;
        tail = tail->next;
        size++;


        centre* centre1 = new centre();
        centre1->centreCode = "c1";
        centre1->centreLocation = "Bukit Jalil";
        centre1->next = NULL;

        centreHead = centre1;
        centreTail = centre1;

        centre* centre2 = new centre();
        centre2->centreCode = "c2";
        centre2->centreLocation = "Sungai Buloh";
        centre2->next = NULL;

        centreTail->next = centre2;
        centreTail = centreTail->next;

        centre* centre3 = new centre();
        centre3->centreCode = "c3";
        centre3->centreLocation = "Melaka";
        centre3->next = NULL;

        centreTail->next = centre3;
        centreTail = centreTail->next;

        subject* subject1 = new subject();
        subject1->subjectCode = "s1";
        subject1->subjectName = "English";
        subject1->hourlyRate = 50;
        subject1->next = NULL;

        subjectHead = subject1;
        subjectTail = subject1;

        subject* subject2 = new subject();
        subject2->subjectCode = "s2";
        subject2->subjectName = "Math";
        subject2->hourlyRate = 45;
        subject2->next = NULL;

        subjectTail->next = subject2;
        subjectTail = subjectTail->next;

        subject* subject3 = new subject();
        subject3->subjectCode = "s3";
        subject3->subjectName = "History";
        subject3->hourlyRate = 50;
        subject3->next = NULL;

        subjectTail->next = subject3;
        subjectTail = subjectTail->next;
    }


    //print partially or all details of the list
    void printlist(tutor** pointer, string type) {
        string centreLocation;
        string subjectName;
        double hourlyPay;
        tutor* tmp;
        tmp = *pointer;
        centre* c;
        c = centreHead;
        subject* s;
        s = subjectHead;
        if (type == "id") {
            cout << endl;
            cout <<"\t\t\t\t"<< setw(10) << "Tutor ID" << setw(22) << "Name" << endl;
        }
        else {
            cout <<setw(10) << "Tutor ID" << setw(22) << "Name" << setw(30) << "Contact Number" << setw(45) << "Address" << setw(30) << "Hourly Rate" << setw(22) 
                << "Subject Taught" << setw(22) << "Centre Location" << setw(27) << "Rating" << endl;
            
        }
        while (tmp != NULL) {
            while (c != NULL) {
                if (c->centreCode == tmp->centreCode) {
                    centreLocation = c->centreLocation;
                    c = centreHead;
                    break;
                }
                c = c->next;
            }
            while (s != NULL) {
                if (s->subjectCode == tmp->subjectCode) {
                    subjectName = s->subjectName;
                    hourlyPay = s->hourlyRate;
                    s = subjectHead;
                    break;
                }
                s = s->next;
            }
            if (type == "id") {
                cout <<"\t\t\t\t"<< setw(7) << tmp->tutorID << setw(25) << tmp->name << endl;
            }
            else {
                cout << setw(7) << tmp->tutorID << setw(25) << tmp->name << setw(25) << tmp->phone << setw(50) << tmp->address << setw(25) 
                    << hourlyPay << setw(25) << subjectName << setw(25) << centreLocation << setw(25) << tmp->rating << endl;
            }
            tmp = tmp->next;
        }
        cout << endl;

    }

    //display existing centre code and its location
    void displayCentre() {
        centre* tmp = centreHead;
        while (tmp != NULL) {
            cout << tmp->centreCode << " ----- " << tmp->centreLocation << endl;
            tmp = tmp->next;
        }
    }

    //display existing subject code and its name
    void displaySubject() {
        subject* tmp = subjectHead;
        while (tmp != NULL) {
            cout << tmp->subjectCode << " ----- " << tmp->subjectName << endl;
            tmp = tmp->next;
        }
    }

    //generate new tutor ID(auto increment)
    int newID() {
        tutor* tmp = head;
        int i = 1;
        for (i; tmp->next != NULL; i++) {
            tmp = tmp->next;
        }
        int tutorID = int(tmp->tutorID) + 1;
        return tutorID;
    }


    //Checking the Centre Code is existed or not
    bool checkCentre(string centreCode) {
        centre* temp = centreHead;
        while (temp != NULL) {
            transform(centreCode.begin(), centreCode.end(), centreCode.begin(), ::tolower);
            transform(temp->centreCode.begin(), temp->centreCode.end(), temp->centreCode.begin(), ::tolower);
            cout << temp->centreCode << "=" << centreCode<<endl;
            if (temp->centreCode.compare(centreCode) == 0) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    //Checking the Subject Code is existed or not
    bool checkSubject(string subjectCode) {
        subject* temp = subjectHead;
        while (temp != NULL) {
            transform(subjectCode.begin(), subjectCode.end(), subjectCode.begin(), ::tolower);
            transform(temp->subjectCode.begin(), temp->subjectCode.end(), temp->subjectCode.begin(), ::tolower);
            cout << temp->subjectCode << "=" << subjectCode << endl;
            if (temp->subjectCode.compare(subjectCode) == 0) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }



    // insert new node
    void add(tutor** head_ref) {

        //create new tutor
        tutor* newTutor;
        tutor* temp = head;
        newTutor = new tutor;

        cin.ignore();
        //name
        newTutor->tutorID = newID();
        //date joined
        cout << "Enter the tutor name" << endl;
        getline(cin, newTutor->name);
        newTutor->dateJoined = displayTime();
        //date Terminated
        newTutor->dateTerminated = "Not Yet Terminated";
        //hourly rate

        //validate phone number
        bool checkPhone = false;
        do {
            //contact Number
            cout << "Enter the tutor contact number" << endl;
            getline(cin, newTutor->phone);

            for (int i = 0; i < newTutor->phone.length(); i++) {
                if (newTutor->phone[i] - 48 >= 0 && newTutor->phone[i] - 48 <= 9) {
                    checkPhone = true;
                }
                else {
                    checkPhone = false;
                    cout << "Invalid Phone Number format!!" << endl;
                    break;
                }
            }

            if (newTutor->phone.length() != 10 && newTutor->phone.length() != 11) {
                checkPhone = false;
                cout << "Invalid Phone Number format!!" << endl;

            }
        } while (checkPhone == false);

        //address
        cout << "Enter the tutor address" << endl;
        getline(cin, newTutor->address);
        //centre code
    centre:
        cout << "Enter the tutor centre code" << endl;
        displayCentre();
        cin >> newTutor->centreCode;
        if (!checkCentre(newTutor->centreCode)) {
            cout << "The Centre Code is not valid or not found in the list." << endl;
            goto centre;
        }
        //subject Code
    subject:
        cout << "Enter the subject Code" << endl;
        displaySubject();
        cin >> newTutor->subjectCode;
        if (!checkSubject(newTutor->subjectCode)) {
            cout << "The Subject Code is not valid or not found in the list." << endl;
            goto subject;
        }
    rating:
        cout << "1 -- Very Bad\n";
        cout << "2 -- Slight Bad\n";
        cout << "3 -- Average\n";
        cout << "4-- Slightly Good\n";
        cout << "5 -- Very Good\n";
        cout << "Enter the overall rating" << endl;
        if (cin >> newTutor->rating) {
            if (newTutor->rating >= 0 && newTutor->rating <= 5) {
                newTutor->rating = (int)(newTutor->rating * 10 + .5);
                newTutor->rating = (float)newTutor->rating / 10;
            }
            else {
                cout << "Invalid range of rating (must within 0.0 to 5.0)\n";
                goto rating;
            }
        }

        newTutor->next = NULL;
        newTutor->previous = NULL;
        //the linked list is empty
        if (head == NULL) {
            head = tail = newTutor;
        }

        else {
            newTutor->previous = tail;
            tail->next = newTutor;
            tail = newTutor;
        }

    
}

    string displayTime() {
        const int MAXLEN = 80;
        char s[MAXLEN];
        time_t t = time(0);
        strftime(s, MAXLEN, "%d/%m/%Y", localtime(&t));
        string ss;
        ss = (string)s;
        return ss;
    }

    //show Details by ID 
    void searchID() {
        tutor* tmp;
        string centreLocation;
        string subjectName;
        double hourlyPay;
        
        centre* c;
        c = centreHead;
        subject* s;
        s = subjectHead;
        int id;
        cout << "Enter the tutor ID: ";
        bool escPressed = false;

        char key = _getch();

        if (key == KeyEsc) {
            return;
        }
        cin >> id;
        if (id <= (getSize() / 2)) { //if the id is in the first half, search from front
            cout << "Search from front\n";
            tmp = head;
            cout << "Search Result: " << endl; cout << setw(10) << "Tutor ID" << setw(22) << "Name" << setw(30) << "Contact Number" << setw(45) 
                << "Address" << setw(30) << "Hourly Rate" << setw(22) << "Subject Taught" << setw(22) << "Centre Location" << setw(27) << "Rating" << endl; 
            while (tmp != NULL) {
               
                if (tmp->tutorID == id) {
                    while (c != NULL) {
                        if (c->centreCode == tmp->centreCode) {
                            centreLocation = c->centreLocation;
                            c = centreHead;
                            break; 
                        }
                        c = c->next;
                    }
                    while (s != NULL) {
                        if (s->subjectCode == tmp->subjectCode) {
                            subjectName = s->subjectName;
                            hourlyPay = s->hourlyRate;
                            s = subjectHead;
                            break;
                        }
                        s = s->next;
                    }
                    cout << setw(7) << tmp->tutorID << setw(25) << tmp->name << setw(25) << tmp->phone << setw(50) 
                        << tmp->address << setw(25) << hourlyPay << setw(25) << subjectName << setw(25) << centreLocation << setw(25) << tmp->rating << endl;
                    break;
                }
                tmp = tmp->next;
            }
        }
        else {
            cout << "Search from back\n";
            tmp = tail;
            cout << "Search Result: " << endl;
            cout << setw(10) << "Tutor ID" << setw(22) << "Name" << setw(30) << "Contact Number" << setw(45) << "Address" 
                << setw(30) << "Hourly Rate" << setw(22) << "Subject Taught" << setw(22) << "Centre Location" << setw(27) << "Rating" << endl;
            while (tail != NULL) {
                if (tmp->tutorID == id) {
                    while (c != NULL) {
                        if (c->centreCode == tmp->centreCode) {
                            centreLocation = c->centreLocation;
                            c = centreHead;
                            break;
                        }
                        c = c->next;
                    }
                    while (s != NULL) {
                        if (s->subjectCode == tmp->subjectCode) {
                            subjectName = s->subjectName;
                            hourlyPay = s->hourlyRate;
                            s = subjectHead;
                            break;
                        }
                        s = s->next;
                    }
                    cout << setw(7) << tmp->tutorID << setw(25) << tmp->name << setw(25) << tmp->phone << setw(50) 
                        << tmp->address << setw(25) << hourlyPay << setw(25) << subjectName << setw(25) << centreLocation << setw(25) << tmp->rating << endl;
                    break;
                }
                tmp = tmp->previous;
            }
        }

        if (tmp == NULL) {
            cout << "No Result Found!" << endl;
        }
        
    }


    //// search by Rating
    void searchRating() {
        tutor* tmp;
        string centreLocation;
        string subjectName;
        double hourlyPay;
        centre* c;
        c = centreHead;
        subject* s;
        s = subjectHead;
        float rating;
        bool foundResult=false;
        cout << "Enter the tutor ID: ";
        bool escPressed = false;

        char key = _getch();

        if (key == KeyEsc) {
            return;
        }
        cin >> rating;
       
            tmp = head;
            cout << "Search Result: " << endl; 
            cout << setw(10) << "Tutor ID" << setw(22) << "Name" << setw(30) << "Contact Number" << setw(45) << "Address" << setw(30) << "Hourly Rate" << setw(22) << "Subject Taught" << setw(22) << "Centre Location" << setw(27) << "Rating" << endl; 
            while (tmp != NULL) {

                if (tmp->rating == rating) {
                    //Found Result
                    if (foundResult == false) {
                        foundResult = true;
                    }

                    //matching centreCode and SUbject Code
                    while (c != NULL) {
                        if (c->centreCode == tmp->centreCode) {
                            centreLocation = c->centreLocation;
                            c = centreHead;
                            break;
                        }
                        c = c->next;
                    }
                    while (s != NULL) {
                        if (s->subjectCode == tmp->subjectCode) {
                            subjectName = s->subjectName;
                            hourlyPay = s->hourlyRate;
                            s = subjectHead;
                            break;
                        }
                        s = s->next;
                    }
                    //display Data
                    cout << setw(7) << tmp->tutorID << setw(25) << tmp->name << setw(25) << tmp->phone << setw(50) << tmp->address << setw(25) << hourlyPay << setw(25) << subjectName << setw(25) << centreLocation << setw(25) << tmp->rating << endl;
                    
                }
                tmp = tmp->next;
            }
        
            
        // display if not found result
        if (foundResult == false) {
            cout << "No Result Found!" << endl;
        }

    }

    tutor* Merge(tutor* h1, tutor* h2,string item)
    {
        tutor* t = head;
        tutor* temp = NULL;

        // Return if the first list is empty.
        if (h1 == NULL)
            return h2;

        // Return if the Second list is empty.
        if (h2 == NULL)
            return h1;
        //sort for ID
        if (item == "id") {
           
            if (h1->tutorID <= h2->tutorID) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2,"id");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next,"id");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }
        //sort for HourlyRate
        if (item == "hourlyPay") {
            subject* s=subjectHead;
            double h1hourlyPay;
            double h2hourlyPay;
           
                while (s != NULL) {
                    if (s->subjectCode == h1->subjectCode) {
                        h1hourlyPay = s->hourlyRate;
                        s = subjectHead;
                        break;
                    }
                    s = s->next;
                }

                while (s != NULL) {
                    if (s->subjectCode == h2->subjectCode) {
                        h2hourlyPay = s->hourlyRate;
                        s = subjectHead;
                        break;
                    }
                    s = s->next;
                }
            
            
            
            if (h1hourlyPay <= h2hourlyPay) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2, "hourlyPay");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next, "hourlyPay");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }
        //Sort for Rating
        if (item == "rating") {
           
           
            if (h1->rating <= h2->rating) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2,"rating");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next,"rating");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }

       
        return temp;

        
    }


    // A function implementing Merge Sort on linked list using reference.
    void MergeSort(tutor** header,string item)
    {
        tutor* first ;
        tutor* second ;
        tutor* temp = *header;
       
        

        // Return if list have less than two nodes.
        if (temp == NULL || (temp->next == NULL))
        {
            return;
        }
        
        //breakdown into single element
        FrontBackSplit(temp, &first, &second);
        //merge the first half
        MergeSort(&first,item);
        //merge the another half
        MergeSort(&second,item);

        // Merge the two part of the list into a sorted one.      
        *header = Merge(first, second,item);
        
    }

    tutor* MergeDes(tutor* h1, tutor* h2, string item)
    {
        tutor* t = head;
        tutor* temp = NULL;

        // Return if the first list is empty.
        if (h1 == NULL)
            return h2;

        // Return if the Second list is empty.
        if (h2 == NULL)
            return h1;
        //sort for ID
        if (item == "id") {

            if (h1->tutorID >= h2->tutorID) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2, "id");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next, "id");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }
        //sort for HourlyRate
        if (item == "hourlyPay") {
            subject* s = subjectHead;
            double h1hourlyPay;
            double h2hourlyPay;

            while (s != NULL) {
                if (s->subjectCode == h1->subjectCode) {
                    h1hourlyPay = s->hourlyRate;
                    s = subjectHead;
                    break;
                }
                s = s->next;
            }

            while (s != NULL) {
                if (s->subjectCode == h2->subjectCode) {
                    h2hourlyPay = s->hourlyRate;
                    s = subjectHead;
                    break;
                }
                s = s->next;
            }



            if (h1hourlyPay >= h2hourlyPay) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2, "hourlyPay");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next, "hourlyPay");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }
        //Sort for Rating
        if (item == "rating") {


            if (h1->rating >= h2->rating) {
                temp = h1;
                //continue merge and sort
                temp->next = Merge(h1->next, h2, "rating");
                h1->next->previous = h1;
                h1->previous = NULL;
            }
            else {
                temp = h2;
                //continue merge and sort
                temp->next = Merge(h1, h2->next, "rating");
                h2->next->previous = h2;
                h2->previous = NULL;
            }
        }


        return temp;


    }


    // A function implementing Merge Sort on linked list using reference.
    void MergeSortDes(tutor** header, string item)
    {
        tutor* first;
        tutor* second;
        tutor* temp = *header;



        // Return if list have less than two nodes.
        if (temp == NULL || (temp->next == NULL))
        {
            return;
        }

        //breakdown into single element
        FrontBackSplit(temp, &first, &second);
        //merge the first half
        MergeSortDes(&first, item);
        //merge the another half
        MergeSortDes(&second, item);

        // Merge the two part of the list into a sorted one.      
        *header = MergeDes(first, second, item);

    }

    void FrontBackSplit(tutor* source, tutor** frontRef, tutor** backRef)
    {
        tutor* fast;
        tutor* slow;
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
        at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
        /*printlist(frontRef); check division
        printlist(backRef);*/

    }

    //Modify data
    void modify(int id,int option) {
        string newData;
        tutor* tmp = head; 
        while (tmp != NULL) {
            if (tmp->tutorID == id) {
                // modify phone number
                if (option == 1) {
                    cout << "Previous Phone Number: " << tmp->phone << endl;
                    //validate phone number
                    bool checkPhone = false;
                    do {
                        //contact Number
                        cout << "Enter the new tutor contact number" << endl;
                        cin.ignore();
                        getline(cin, tmp->phone);

                        for (int i = 0; i < tmp->phone.length(); i++) {
                            if (tmp->phone[i] - 48 >= 0 && tmp->phone[i] - 48 <= 9) {
                                checkPhone = true;
                            }
                            else {
                                checkPhone = false;
                                cout << "Invalid Phone Number format!!" << endl;
                                
                                break;
                            }
                        }

                        
                    } while (checkPhone == false);

                    break;
                }
                else if (option == 2) {
                    //modify address
                    cout << "Previous Phone Number: " << tmp->address << endl;
                    cout << "Enter the new tutor address " << endl;;
                    cin >> tmp->address;
                    
                    break;
                }
            }
            tmp = tmp->next;
        }
        cout << "modified done." << endl;
    }

    void deleteTutor(int id) {
        tutor* current = head;
        tutor* previous = NULL; 

        // if the first one to delete
        if (current->tutorID == id && current != NULL) {
            head = current->next;
            free(current);
            return;
        }
        //searching for the matched id
        while (current != NULL&&current->tutorID!=id) {
            previous = current;
            current = current->next;
        }
        //if found the matched id,delete it
        if (current != NULL&& current->tutorID == id) {
            previous->next = current->next;
            free(current);
        }
        //cannot found it
        else {
            cout << "Cannot found the tutor with this id." << endl;
        }
    }

    

    void showDetails() {
        
            int id;
            tutor* temp = head;
            string centreLocation;
            string subjectName;
            double hourlyPay;
            centre* c;
            c = centreHead;
            subject* s;
            s = subjectHead;

            //insert the tutor id
            cout << "Please insert the tutor id to view details: ";
            bool escPressed = false;

            char key = _getch();
           
                if (key == KeyEsc) {
                    return;
                }

            if (!(cin >> id)) {


                cout << "You have entered wrong input" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                MergeSort(&head, "id");
                cout << "Number of List: " << getSize() << endl;
                printlist(&head, "id");
                showDetails();
            }

            //print the insert value
            if (verifyID(id)) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                if (id <= (getSize() / 2)) { //if the id is in the first half, search from front
                    temp = head;
                    while (temp != NULL) {

                        if (temp->tutorID == id) {
                            while (c != NULL) {
                                if (c->centreCode == temp->centreCode) {
                                    centreLocation = c->centreLocation;
                                    c = centreHead;
                                    break;
                                }
                                c = c->next;
                            }
                            while (s != NULL) {
                                if (s->subjectCode == temp->subjectCode) {
                                    subjectName = s->subjectName;
                                    hourlyPay = s->hourlyRate;
                                    s = subjectHead;
                                    break;
                                }
                                s = s->next;
                            }
                            //display data
                            cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" 
                                << "\t\t\t\t\t\tName: " << temp->name 
                                << "\n" << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" 
                                << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n" 
                                << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" 
                                << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" 
                                << "\t\t\t\t\t\tAddress: " << temp->address << "\n" 
                                << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n" 
                                << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" 
                                << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;

                            if (temp == head) {
                                cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                            }
                            else if (temp != head && temp != tail) {
                                cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                            }
                            else if (temp == tail) {
                                cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                            }
                            cout << "--------Press ESC to return to menu-------" << endl;
                            break;
                        }
                        else
                            temp = temp->next;
                    }
                }

                else {
                    //search from back using tail pointer
                    temp = tail;
                    while (tail != NULL) {

                        if (temp->tutorID == id) {
                            while (c != NULL) {
                                if (c->centreCode == temp->centreCode) {
                                    centreLocation = c->centreLocation;
                                    c = centreHead;
                                    break;
                                }
                                c = c->next;
                            }
                            while (s != NULL) {
                                if (s->subjectCode == temp->subjectCode) {
                                    subjectName = s->subjectName;
                                    hourlyPay = s->hourlyRate;
                                    s = subjectHead;
                                    break;
                                }
                                s = s->next;
                            }
                            cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" 
                                << "\t\t\t\t\t\tName: " << temp->name << "\n" 
                                << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" 
                                << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n" 
                                << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" 
                                << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" 
                                << "\t\t\t\t\t\tAddress: " << temp->address << "\n" 
                                << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n" 
                                << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" 
                                << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;

                            if (temp == head) {
                                cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                            }
                            else if (temp != head && temp != tail) {
                                cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                            }
                            else if (temp == tail) {
                                cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                            }
                            cout << "--------Press ESC to return to menu-------" << endl;
                            break;
                        }
                        else
                            temp = temp->previous;
                    }
                }
            }
            else {
                cout << "Wrong id\n";
                system("pause");
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                MergeSort(&head, "id");
                cout << "Number of List: " << getSize() << endl;
                printlist(&head, "id");
                showDetails();
            }

        

        //tracking Arrow input key
       
        

        
        while (!escPressed) {
            
            switch (_getch()) {
            case KEY_LEFT:
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                if (temp->previous != NULL) {
                    temp = temp->previous;
                    while (c != NULL) {
                        if (c->centreCode == temp->centreCode) {
                            centreLocation = c->centreLocation;
                            c = centreHead;
                            break;
                        }
                        c = c->next;
                    }
                    while (s != NULL) {
                        if (s->subjectCode == temp->subjectCode) {
                            subjectName = s->subjectName;
                            hourlyPay = s->hourlyRate;
                            s = subjectHead;
                            break;
                        }
                        s = s->next;
                    }
                            
                    cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" 
                        << "\t\t\t\t\t\tName: " << temp->name << "\n" 
                        << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" 
                        << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n"
                        << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" 
                        << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" 
                        << "\t\t\t\t\t\tAddress: " << temp->address << "\n" 
                        << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n"
                        << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" 
                        << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;

                    if (temp == head) {
                        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp != head && temp != tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp == tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                    }
                    cout << "--------Press ESC to return to menu-------" << endl;
                
                }
                else {
                    cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" << "\t\t\t\t\t\tName: " << temp->name << "\n" << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n" << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" << "\t\t\t\t\t\tAddress: " << temp->address << "\n" << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n" << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;
                    if (temp == head) {
                        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp != head && temp != tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp == tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                    }
                    cout << "--------Press ESC to return to menu-------" <<endl;
                }
                /*


                
            */

                break;

            case KEY_RIGHT:
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";

                if (temp->next != NULL) {
                    temp = temp->next;
                    while (c != NULL) {
                        if (c->centreCode == temp->centreCode) {
                            centreLocation = c->centreLocation;
                            c = centreHead;
                            break;
                        }
                        c = c->next;
                    }
                    while (s != NULL) {
                        if (s->subjectCode == temp->subjectCode) {
                            subjectName = s->subjectName;
                            hourlyPay = s->hourlyRate;
                            s = subjectHead;
                            break;
                        }
                        s = s->next;
                    }
                    cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" << "\t\t\t\t\t\tName: " << temp->name << "\n" << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n" << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" << "\t\t\t\t\t\tAddress: " << temp->address << "\n" << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n" << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;
                    if (temp == head) {
                        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp != head && temp != tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp == tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                    }
                    cout << "--------Press ESC to return to menu-------" << endl;
                }
                else {
                    cout << "\t\t\t\t\t\tTutor ID: " << temp->tutorID << "\n" << "\t\t\t\t\t\tName: " << temp->name << "\n" << "\t\t\t\t\t\tDate Joined: " << temp->dateJoined << "\n" << "\t\t\t\t\t\tDate Terminated: " << temp->dateTerminated << "\n" << "\t\t\t\t\t\tHourly Pay Rate: " << hourlyPay << "\n" << "\t\t\t\t\t\tContact Number: " << temp->phone << "\n" << "\t\t\t\t\t\tAddress: " << temp->address << "\n" << "\t\t\t\t\t\tCentre Location: " << centreLocation << "\n" << "\t\t\t\t\t\tSubject Taught: " << subjectName << "\n" << "\t\t\t\t\t\tOverall Performance: " << fixed << setprecision(1) << temp->rating << endl;
                    if (temp == head) {
                        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp != head && temp != tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t-->\n";
                    }
                    else if (temp == tail) {
                        cout << "<--\t\t\t\t\t\t\t\t\t\t\t\t\t\n";
                    }
                    cout << "--------Press ESC to return to menu-------" << endl;
                }
                break;
                  
            //return to menu
            case KeyEsc:
                escPressed = true;
                break;
            }
        }

    }

    //Checking the id is existed or not
    bool verifyID(int id) {
        tutor* temp = head;

        while (temp != NULL) {
            if (temp->tutorID == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteOutdated() {

       
        string currentDay, terminationDate, terminationDay, terminationMonth, terminationYear;
        int currentMonth = 0, currentYear = 0, numberofMonth = 0;
        tutor* temp = head;
        tutor* previous = NULL;
        time_t currentTime = time(0);
        tm* currentDate = localtime(&currentTime);

        currentDay = to_string(currentDate->tm_mday);
        currentMonth = currentDate->tm_mon + 1;
        currentYear = currentDate->tm_year + 1900;
        

        bool terminated = false;
        
        while (temp != NULL) {
            string terminationDay = temp->dateTerminated.substr(0, 2);
            
            string terminationMonth = temp->dateTerminated.substr(3, 2);
            string terminationYear = temp->dateTerminated.substr(6, 4);
            
            
            numberofMonth = (currentYear - stoi(terminationYear)) * 12;
            numberofMonth += (currentMonth - stoi(terminationMonth));
            if (currentDay < terminationDay) {
                numberofMonth--;
            }

            if (numberofMonth >= 6) {
                cout << "Tutor id " << temp->tutorID << " record has been terminated" <<endl;
                if (temp == head) {
                    tutor* deleteNode = temp;
                    temp = temp->next;
                    head = temp;
                    free(deleteNode);
                    size--;
                    numberofMonth = 0;
                }
                else if (temp == tail) {
                    tutor* deleteNode = temp;
                    temp = temp->previous;
                    tail = temp;
                    tail->next = NULL;
                    free(deleteNode);
                    size--;
                    numberofMonth = 0;
                }
                else {
                    tutor* deleteNode = temp;
                    temp = temp->next;
                    deleteNode->previous->next = temp;
                    temp->previous = deleteNode->previous;
                    free(deleteNode);
                    size--;
                    numberofMonth = 0;
                }
                terminated = true;
            }
            else {
                temp = temp->next;
            }
           
            
        }
        if (!terminated) {
            cout << "No record has been terminated!" << endl;
        }
        system("pause");
    }

    void updateDateTermination(int id) {
        tutor* temp = head;
        int choice;
        time_t now = time(0);
        // convert now to string form
        tm* ltm = localtime(&now);
        string date;

        while (temp != NULL) {
            if (temp->tutorID == id) {
                cout << "Are you sure that you want to update the status?" << endl;
                cout << "1) Yes" << endl;
                cout << "2) No" << endl;
                cin >> choice;
                switch(choice) {
                    case 1:
                        date = displayTime();
                        temp->dateTerminated = date;
                        cout << "Updated tutor status. Tutor has been terminated." << endl;
                        break;
                    
                    case 2:
                    
                        break;
                }
            }
            temp = temp->next;
        }
        cout << " done";
    }

};


Tutor t;
int main();
void menu();

class LoginManager {
public:
    LoginManager() {
        accessRight = 0;
        
    }


     void Login() {
         string username;
         string password;
        system("CLS");
        cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
        cout << "\t\t\t\t\t\tUsername: ";
        cin >> username;
        
        if (username == adminUsername) {
            cout << "\t\t\t\t\t\tPassword: ";
            cin >> password;
            if (password == adminPass) {
                cout << "\n\t\t\t********************************************************************\n";
                cout << "\t\t\t\tWelcome admin! Press any key to login to the system.\n";
                cout << "\n\t\t\t********************************************************************\n";
                setAccessRight(1); // accessRight 1 refers to admin login. 
                t.deleteOutdated();
                menu();
                system("pause");
            }
            else {
                cout << "\n\t\t\t********************************************************************\n";
                cout << "\t\t\t\tInvalid Password. Please try to login again!\n";
                cout << "\n\t\t\t********************************************************************\n";
                system("pause");
                Login();
            }
        }
        
        

        else if (username == hrUsername) {
            cout << "\t\t\t\t\t\tPassword: ";
            cin >> password;
            if (password == hrPass) {
                cout << "\n\t\t\t********************************************************************\n";
                cout << "\t\t\t\tWelcome HR Manager! Press any key to login to the system.\n";
                cout << "\n\t\t\t********************************************************************\n";
                setAccessRight(2); // accessRight 1 refers to admin login. 
                t.deleteOutdated();
                menu();
                system("pause");
            }
            else {
                cout << "\n\t\t\t********************************************************************\n";
                cout << "\t\t\t\tInvalid Password. Please try to login again!\n";
                cout << "\n\t\t\t********************************************************************\n";
                system("pause");
                Login();
            }
        }
        else {
            cout << "\n\t\t\t********************************************************************\n";
            cout << "\t\t\t\tInvalid Username. Please try to login again!\n";
            cout << "\n\t\t\t********************************************************************\n";
            system("pause");
            Login();
        }
        

    }
     void setAccessRight(int access) {
         accessRight = access;
     }

     int getAccessRight() {
         return accessRight;
     }

     

private:
    string adminUsername="admin";
    string adminPass="admin123";
    string hrUsername="hrmanager";
    string hrPass= "hrmanager123";
    int accessRight;

};

LoginManager login;

 void menu(){
    
    int choice;
    int id = 0;
    int data = 0;
    string newData;
    char key=NULL;
    int accessRight = login.getAccessRight();
    system("CLS");
    cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
    t.MergeSort(&t.head, "id");
    if (accessRight == 1) { // admin menu
        cout << "\n\nPlease select these options from the menu below:" << endl;
        cout << "1) Display all tutors information" << endl;
        cout << "2) Add new tutor" << endl;
        cout << "3) Search" << endl;
        cout << "4) Sort" << endl;
        cout << "5) Logout" << endl;
        cout << "6) Exit Program" << endl;
        
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            cout << "Number of List: " << t.getSize() << endl;
            t.printlist(&t.head, "id");
            t.showDetails();
            menu();
            break;
        case 2:
            t.add(&t.head);
            system("pause");
            menu();
            break;

        case 3:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            cout << "Which data you would like to search?" << endl;
            cout << "1) Tutor ID" << endl;
            cout << "2) Tutor Overall Performance" << endl;
            

            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.searchID();
            }
            else if (choice == 2) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.searchRating();
            }
            system("pause");
            menu();
            break;

        case 4:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            cout << "Which data you would like to sort?" << endl;
            cout << "1) Tutor ID" << endl;
            cout << "2) Tutor Hourly Pay" << endl;
            cout << "3) Tutor Overall Performance" << endl;
            

            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.MergeSort(&t.head, "id");
                t.printlist(&t.head, "all");
                system("pause");
                menu();

            }
            else if (choice == 2) {
                choice = 1;
                do {
                    system("CLS");
                    cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                    if (choice == 1) {
                        t.MergeSort(&t.head, "hourlyPay");
                        t.printlist(&t.head, "all");
                    }
                    else if (choice == 2) {
                        t.MergeSortDes(&t.head, "hourlyPay");
                        t.printlist(&t.head, "all");
                    }
                    
                    cout << "1) Accending Order\n";
                    cout << "2) Descending Order\n";
                    

                     key = _getch();

                    if (key == KeyEsc) {
                        menu();
                    }
                    
                } while (true);
                system("pause");
              

                menu();
            }
            else if (choice == 3) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.MergeSort(&t.head, "rating");
                t.printlist(&t.head, "all");
                system("pause");
                menu();
            }
            else {
                cout << "No such options for the system. Please try again." << endl;
                system("pause");
                menu();
            }
            break;
        case 5:
            login.Login();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "No such options for the system. Please try again." << endl;
            system("pause");
            menu();

        }
    }

    else if (accessRight == 2) { // hr manager menu
        cout << "\n\nPlease select these options from the menu below:" << endl;
        cout << "1) Display all tutors information" << endl;
        cout << "2) Add new tutor" << endl;
        cout << "3) Search" << endl;
        cout << "4) Sort" << endl;
        cout << "5) Modify a Tutor Record" << endl;
        cout << "6) Delete a Tutor Record" << endl;
        cout << "7) Terminate Tutor" << endl;
        cout << "8) Logout" << endl;
        cout << "9) Exit Program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            t.MergeSort(&t.head, "id");
            t.printlist(&t.head, "id");
            t.showDetails();
            menu();

        case 2:
            t.add(&t.head);
            system("pause");
            menu();
            break;

        case 3:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            cout << "Which data you would like to search?" << endl;
            cout << "1) Tutor ID" << endl;
            cout << "2) Tutor Overall Performance" << endl;
            

            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.searchID();
            }
            else if (choice == 2) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.searchRating();
            }
            else{
                cout << "No such options for the system. Please try again." << endl;
                system("pause");
                menu();
            }
            system("pause");
            menu();
            break;

        case 4:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            cout << "Which data you would like to sort?" << endl;
            cout << "1) Tutor ID" << endl;
            cout << "2) Tutor Hourly Pay" << endl;
            cout << "3) Tutor Overall Performance" << endl;
            

            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            cin >> choice;
            if (choice == 1) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.MergeSort(&t.head, "id");
                t.printlist(&t.head, "all");
                system("pause");
                
                menu();

            }
            else if (choice == 2) {
                choice = 1;
                do {
                    system("CLS");
                    cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                    if (choice == 1) {
                        t.MergeSort(&t.head, "hourlyPay");
                        t.printlist(&t.head, "all");
                    }
                    else if (choice == 2) {
                        t.MergeSortDes(&t.head, "hourlyPay");
                        t.printlist(&t.head, "all");
                    }

                    cout << "1) Accending Order\n";
                    cout << "2) Descending Order\n";
                    

                    key = _getch();

                    if (key == KeyEsc) {
                        menu();
                    }
                } while (true);
                system("pause");


                menu();
            }
            else if (choice == 3) {
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.MergeSort(&t.head, "rating");
                t.printlist(&t.head, "all");
                system("pause");
                
                menu();
            }
            else {
                cout << "No such options for the system. Please try again." << endl;
                system("pause");
                menu();
            }
            break;
        
        case 5:
            modify:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            t.MergeSort(&t.head, "id");
            t.printlist(&t.head,"id");
            cout << "Please insert the tutor id that you would like to modify: ";
            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            
            if (!(cin >> id)) {
                cout << "You have entered wrong input" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                
                goto modify;
            }
            if (t.verifyID(id)) {
                cout << "You have selected tutor ID (" << id << "), which data you want to edit?" << endl;
                cout << "1) Phone Number" << endl;
                cout << "2) Address" << endl;
                cin >> data;
                
                if (data == 1) {
                    t.modify(id, 1);
                }
                else if (data == 2) {
                    t.modify(id, 2);
                }
                else {
                    cout << "No such options for the system. Please try again." << endl;
                    system("pause");
                    menu();
                }
                
                system("pause");
            }
            else {
                cout << "Tutor ID not found in the list! Please try again!";
                system("pause");
                goto modify;
            }
            
            menu();
            break;

        case 6:
            deleteTutor:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
                t.MergeSort(&t.head, "id");
                t.printlist(&t.head,"id");
                /*t.printlist();*/
                cout << "Please insert the tutor id that you would like to delete: ";
                

                key = _getch();

                if (key == KeyEsc) {
                    menu();
                }
                if (!(cin >> id)) {
                    cout << "You have entered wrong input" << endl;
                    system("pause");
                    cin.clear();
                    cin.ignore(123, '\n');
                    system("CLS");
                    cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";

                    goto deleteTutor;
                }
                if (t.verifyID(id)) {
                    cout << "You have selected tutor ID (" << id << "), are you sure to delete the record?" << endl;
                    cout << "1) Yes" << endl;
                    cout << "2) No" << endl;
                    cin >> data;
                    if (data == 1) {
                        t.deleteTutor(id);
                    }
                }
                else {
                    cout << "The tutor ID is not valid or not found."<<endl;
                    system("pause");
                    goto deleteTutor;
                }
                menu();
              break;
        case 7:
            //termination function
            terminate:
            system("CLS");
            cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";
            t.MergeSort(&t.head, "id");
            t.printlist(&t.head, "id");
            cout << "Please insert the tutor id that you would like to modify: ";
            

            key = _getch();

            if (key == KeyEsc) {
                menu();
            }
            if (!(cin >> id)) {
                cout << "You have entered wrong input" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t*********Welcome to Excel Tuition Centre Management System**********\n\n\n\n\n";

                goto terminate;
            }
            
            if (t.verifyID(id)) {
                t.updateDateTermination(id);
            }
            else {
                cout << "Tutor ID not found in the list! Please try again!";
                system("pause");
                goto terminate;
            }

            menu();
            
            break;
        case 8:
            login.Login();
            break;
        case 9:
            exit(0);
            break;

        default:
            cout << "No such options for the system. Please try again." << endl;
            system("pause");
            menu();
        }
        
    }
}



    



int main()
{   
    t.harcodedData();
    login.Login();
    return 0;
    
    
    

}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
