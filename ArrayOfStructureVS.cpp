#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<direct.h>// <doc.h>
#include<cctype>
#include<sstream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KeyEsc 27

using namespace std;

void menu();

struct tutor {
    int tutorID;
    string tutorName;
    string dateJoined;
    string dateTerminated;
    string tutorPhone;
    string address;
    string centreID;
    string subjectID;
    float rating;
};

struct tuitionCentre {
    string centreID;
    string centreLocation;
};

struct subject {
    string subjectID;
    string subjectName;
    float subjectRate;
};


//DEFINE ARRAY SIZE 
int tutorSize = 10;
int subjectSize = 3;
int centreSize = 3;

//CREAT ARRAY OF STRUCTURE
tutor* t = new tutor[tutorSize];
subject* s = new subject[subjectSize];
tuitionCentre* c = new tuitionCentre[centreSize];


//CLASS CENTRE FUNCTION
class CentreFunction {

public:

    //HARDCODE DEFAULT DATA
    void hardcodedData() {

        //Default Tutor Information.
        t[0].tutorID = 1;
        t[0].tutorName = "Chiah";
        t[0].dateJoined = "16/03/2020";
        t[0].dateTerminated = "";

        t[0].tutorPhone = "01116005510";
        t[0].address = "KL";
        t[0].centreID = "C1";
        t[0].subjectID = "S1";
        t[0].rating = 3.0;

        t[1].tutorID = 2;
        t[1].tutorName = "Melody";
        t[1].dateJoined = "16/04/2020";
        t[1].dateTerminated = "";

        t[1].tutorPhone = "01116005510";
        t[1].address = "PJ";
        t[1].centreID = "C2";
        t[1].subjectID = "S1";
        t[1].rating = 4.0;


        t[2].tutorID = 3;
        t[2].tutorName = "Monkey";
        t[2].dateJoined = "01/04/2020";
        t[2].dateTerminated = "";

        t[2].tutorPhone = "01116005510";
        t[2].address = "PJ";
        t[2].centreID = "C3";
        t[2].subjectID = "S1";
        t[2].rating = 5.0;

        t[3].tutorID = 4;
        t[3].tutorName = "TJ Law";
        t[3].dateJoined = "01/08/2020";
        t[3].dateTerminated = "";

        t[3].tutorPhone = "01116005510";
        t[3].address = "SK";
        t[3].centreID = "C3";
        t[3].subjectID = "S2";
        t[3].rating = 5.0;

        t[4].tutorID = 5;
        t[4].tutorName = "Caven Jay";
        t[4].dateJoined = "09/09/2020";
        t[4].dateTerminated = "";

        t[4].tutorPhone = "0125551232";
        t[4].address = "BJ";
        t[4].centreID = "C3";
        t[4].subjectID = "S2";
        t[4].rating = 3.0;

        t[5].tutorID = 6;
        t[5].tutorName = "Elijah Woo";
        t[5].dateJoined = "09/09/2020";
        t[5].dateTerminated = "";

        t[5].tutorPhone = "0125551232";
        t[5].address = "NT";
        t[5].centreID = "C3";
        t[5].subjectID = "S2";
        t[5].rating = 3.0;

        t[6].tutorID = 7;
        t[6].tutorName = "Adrean Lim";
        t[6].dateJoined = "09/09/1997";
        t[6].dateTerminated = "";

        t[6].tutorPhone = "01235466i4";
        t[6].address = "KL";
        t[6].centreID = "C3";
        t[6].subjectID = "S3";
        t[6].rating = 4.0;

        t[7].tutorID = 8;
        t[7].tutorName = "Timothy Wong";
        t[7].dateJoined = "09/09/1997";
        t[7].dateTerminated = "16/04/2019";

        t[7].tutorPhone = "01235466i4";
        t[7].address = "33, jalan Gorilla ";
        t[7].centreID = "C3";
        t[7].subjectID = "S3";
        t[7].rating = 5.0;

        t[8].tutorID = 9;
        t[8].tutorName = "Michelle Yeoh";
        t[8].dateJoined = "08/09/1997";
        t[8].dateTerminated = "";

        t[8].tutorPhone = "0112555232";
        t[8].address = "KL";
        t[8].centreID = "C3";
        t[8].subjectID = "S3";
        t[8].rating = 4.0;

        t[9].tutorID = 10;
        t[9].tutorName = "Amy Wong";
        t[9].dateJoined = "08/09/1997";
        t[9].dateTerminated = "";

        t[9].tutorPhone = "0112555232";
        t[9].address = "DM";
        t[9].centreID = "C3";
        t[9].subjectID = "S1";
        t[9].rating = 3.0;

        //Default Centre Information
        c[0].centreID = "C1";
        c[0].centreLocation = "Bukit Jalil";

        c[1].centreID = "C2";
        c[1].centreLocation = "Sungai Buluh";

        c[2].centreID = "C3";
        c[2].centreLocation = "Sri Petaling";

        //Default Subject Information
        s[0].subjectID = "S1";
        s[0].subjectName = "English";
        s[0].subjectRate = 40.0;

        s[1].subjectID = "S2";
        s[1].subjectName = "Malay";
        s[1].subjectRate = 50.0;

        s[2].subjectID = "S3";
        s[2].subjectName = "Math";
        s[2].subjectRate = 60.0;

    }
    
    //SHOW TUTOR DETAILS 
    int displayTutor(int size) { 
        system("CLS");
        cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

        //VARIABLE DECLARATION 
        int viewTutor; //cin value to search for tutor detials. 

        double hourlyRate; // variable to display subject rate by from subject structure
        string subjectName;// variable to display subject name by from subject structure
        string centreLocation;// variable to display centre name by from centre structure



    searchID:

        bool verifyID = false; //variables for validation
        cout << "\n\n\n\t\t\t\tDetails of Tutor: \n\n\n";
        cout << "\t\t\t\tID" << setw(25) << "Name " << setw(25) << "Date Joined ";
        cout << endl;

        //display tutor details
        for (int i = 0; i < size; i++) {
            cout << "\n\t\t\t\t" << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined;
        }

        cout << "\n\nPlease insert the tutor id to view details: ";

        //ESC TO ALLOWS USER TO EXIT FROM DISPLAY FUNCTION TO MENU. 
        bool escPressed = false;
        char key = _getch();
        if (key == KeyEsc) { //user press esc to escape to 
            menu();
        }

        //VALIDATION : ONLY INTEGER AS INPUT
        if (!(cin >> viewTutor)) { //user input here

            cout << "You have entered wrong input" << endl;
            system("pause");
            cin.clear();
            cin.ignore(123, '\n');
            system("CLS");
            cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

            goto searchID;

        }
        
        //VALIDATION: ID EXISTS IN TUTOR RECORD. 
        verifyID = checkID(viewTutor, tutorSize);


        system("CLS");
        cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

        if (verifyID) //ID exist in record 
        {
            for (int i = 0; i < size; i++) // DISPLAY DATA BY USING LOOP
            {
                if (t[i].tutorID == viewTutor)// display specific tutor data according to user input
                {
                    for (int subject = 0; subject < subjectSize; subject++) // DISPLAY SUBJECT NAME
                    {
                        // display specific subject data according to user input
                        if (t[i].subjectID == s[subject].subjectID) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)// DISPLAY CENTRE NAME
                    {
                        // display specific centre data according to user input
                        if (t[i].centreID == c[centre].centreID) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }
                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[i].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[i].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[i].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[i].dateTerminated << endl;
                    cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[i].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[i].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[i].centreID << endl;
                    cout << "\t\t\t\tCenter Location\t\t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[i].subjectID << endl;
                    cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[i].rating << endl << endl;
                    break;
                }
            }

        }
        else { // INVALID ID, RETURN TO USER INPUT 
            cout << "Invalid ID" << endl;
            system("pause");
            system("CLS");
            goto searchID;
        }
    keys:

        // USER INPUT AS NUMBER OF PAGE, USED TO OPERATE TUTOR SEQUENCE
        int pageNumber = viewTutor;
        cout << "Use left key on keyboard to navigate around, press esc button to back to menu" << endl;
        while (!escPressed) {
            switch (_getch()) {
            case KEY_LEFT:
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

                pageNumber--; // MOVE TO PREVIOUS TUTOR

                if (pageNumber < 1 || pageNumber == 1) {
                    pageNumber = 1;

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[pageNumber - 1].subjectID == (s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[pageNumber - 1].centreID ==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }

                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[pageNumber - 1].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[pageNumber - 1].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[pageNumber - 1].dateTerminated << endl;
                    cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[pageNumber - 1].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[pageNumber - 1].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[pageNumber - 1].centreID << endl;
                    cout << "\t\t\t\tCenter Location \t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[pageNumber - 1].subjectID << endl;
                    cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[pageNumber - 1].rating << endl;

                    cout << endl << "This is First Tutor" << endl;

                    cout << endl << endl << "Use left key on keyboard to navigate around, press esc button to back to menu" << endl;

                }
                else {

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[pageNumber - 1].subjectID ==(s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[pageNumber - 1].centreID==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }

                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[pageNumber - 1].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[pageNumber - 1].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[pageNumber - 1].dateTerminated << endl;
                    cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[pageNumber - 1].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[pageNumber - 1].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[pageNumber - 1].centreID << endl;
                    cout << "\t\t\t\tCenter Location \t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[pageNumber - 1].subjectID << endl;
                    cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[pageNumber - 1].rating << endl;

                    cout << endl << endl << "Use left key on keyboard to navigate around, press esc button to back to menu" << endl;


                }

                break;
                system("pause");
                menu();

            case KEY_RIGHT:
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

                pageNumber++;// MOVE TO NEXT TUTOR

                if (pageNumber > tutorSize) {
                    pageNumber = tutorSize;


                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[pageNumber - 1].subjectID == (s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[pageNumber - 1].centreID ==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }

                    //cout << "" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[pageNumber - 1].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[pageNumber - 1].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[pageNumber - 1].dateTerminated << endl;
                    cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[pageNumber - 1].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[pageNumber - 1].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[pageNumber - 1].centreID << endl;
                    cout << "\t\t\t\tCenter Location \t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[pageNumber - 1].subjectID << endl;
                    cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[pageNumber - 1].rating << endl;

                    cout << endl << "This is Last Tutor" << endl;


                    cout << endl << endl << "Use left key on keyboard to navigate around, press esc button to back to menu" << endl;

                }
                else {

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[pageNumber - 1].subjectID == (s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[pageNumber - 1].centreID ==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }

                    //cout << "" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[pageNumber - 1].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[pageNumber - 1].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[pageNumber - 1].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[pageNumber - 1].dateTerminated << endl;
                    cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[pageNumber - 1].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[pageNumber - 1].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[pageNumber - 1].centreID << endl;
                    cout << "\t\t\t\tCenter Location \t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[pageNumber - 1].subjectID << endl;
                    cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[pageNumber - 1].rating << endl;

                    cout << endl << endl << "Use left key on keyboard to navigate around, press esc button to back to menu" << endl;

                }

                break;

                system("pause");
                menu();

            case KeyEsc:
                system("CLS");
                cout << "esc key";
                escPressed = true;

                menu();
                break;

            }
        }

        return size;
    }

    //DISPLAY CENTRE
    void displayCentre(int Csize) {
        for (int i = 0; i < 3; i++) {
            cout << "\t\t\t\t" << c[i].centreID << "-----" << c[i].centreLocation << endl;
        }
    }

    //DISPLAY SUBJECTS
    int displaySubject(int Ssize) {
        for (int i = 0; i < Ssize; i++) {
            cout << "\t\t\t\t" << s[i].subjectID << "-----" << s[i].subjectName
                << "-----" << "Hourly Rate\t\t:\t\t" << s[i].subjectRate << endl;
        }
        return Ssize;
    }

    //DISPLAY CURRENT TIME
    string displayTime() {
        const int MAXLEN = 80;
        char s[MAXLEN];
        time_t t = time(0);
        strftime(s, MAXLEN, "%d/%m/%Y", localtime(&t));
        string ss;
        ss = (string)s;
        return ss;
    }

    //VALIDATION: CHECK IF TUTOR ID EXIST
    bool checkID(int id, int tutorSize) {

        for (int i = 0; i < tutorSize; i++)
        {
            if (t[i].tutorID == id) {
                return true;
            }
        }
        return false;
    }

    bool checkCentre(string centreCode) { // to check if centrecode exist

        for (int i = 0; i < centreSize; i++) {
            if (centreCode == c[i].centreID)
            {
                return true;
            }
        }
        return false;
    }

    bool checkSubject(string subjectCode) { // to check if centrecode exist

        for (int i = 0; i < centreSize; i++) {
            if (subjectCode == s[i].subjectID)
            {
                return true;
            }
        }
        return false;
    }

    //GENERATE NEW TUTOR ID 
    int newID() {
        int count=0;
        for (int i = 0; i < tutorSize; i++)
        {
            count++;

            //MAKE SURE ID NOT REPEATED
            if (count == t[i].tutorID)
            {
                //count variable 
                count++;
            }
        }
        return count;
    }

    //addTutor
    int addTutor(int size, struct tutor*& t) {

        system("CLS");
    keys:
        bool escPressed = false;
        char key = _getch();


        //DECLARATION OF NEW ARRAY
        tutor* tutorArr = new tutor[size + 1];

        for (int index = 0; index < size; index++)
        {
            tutorArr[index] = t[index]; //pass data from original array to array that has bigger size.
        }

        string  newTutorName, dateJoined, dateTerminated, tutorPhone, address, centreID, subjectID;
        double hourlyRate;
        float TutorRating;


        cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

        tutorArr[size].tutorID = newID();
        cout << "\t\t\t\tTutor ID\t\t:\t\t\t" << tutorArr[size].tutorID << endl;

        tutorArr[size].dateJoined = displayTime();
        cout << "\t\t\t\tDate Joined\t\t:\t\t\t" << tutorArr[size].dateJoined << endl;

        tutorArr[size].dateTerminated = "";
        cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << tutorArr[size].dateTerminated << endl;
        cin.ignore();
        cout << "\t\t\t\tTutor Name\t\t:\t\t\t";

        getline(cin, newTutorName);
        tutorArr[size].tutorName = newTutorName;


        // validate phone number
        bool checkPhone = false;
        bool loopCheck;
        do {

            do
            {
                //USER ENTER PHONE 
                int correctPhone;
                cout << "\t\t\t\tPhone Number\t\t:\t\t\t";
                getline(cin, tutorPhone);

                //VALIDATION : ONLY INTEGER
                char check[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                int lenght = tutorPhone.size(); //takes the size of the string entered 
                int verify = 0; // determine number of verified charcters.
                loopCheck = true;
                for (int count = 0; count < lenght; count++)
                {
                    for (int numeral = 0; numeral <= 9; numeral++) { // inner for() loop start
                        if (tutorPhone[count] == check[numeral]) {
                            verify++;
                        }
                    }
                }
                if (verify != lenght)
                {
                    cout << "\t\t\t\tInput Error: non-numericacl characters have been entered!" << endl;
                    checkPhone = false;
                    loopCheck = false;
                }
                else {

                    //tutorPhone = atoi(tutorPhone.c_str());
                    loopCheck = true;

                }
            } while (loopCheck != true);
           

            //VALIDATION : PHONE LENGHT
            for (int i = 0; i < tutorPhone.length(); i++) {
                if (tutorPhone.length() >= 9 && tutorPhone.length() <= 11) {
                    checkPhone = true;
                    tutorArr[size].tutorPhone = tutorPhone;
                }
                else {
                    checkPhone = false;
                    cout << "\t\t\t\tInvalid Phone Number format!!" << endl;
                    cout << "\t\t\t\tEnter Phone Number again!!" << endl;
                    break;
                }
                }

        } while (checkPhone == false);

        cout << "\t\t\t\tAddress\t\t\t:\t\t\t";
        getline(cin, address);
        tutorArr[size].address = address;

    centre:
        cout << "\t\t\t\tEnter the tutor centre code" << endl;
        displayCentre(centreSize);
        cout << "\t\t\t\t";
        cin >> centreID;

        if (checkCentre(centreID) != true) {
            cout << "\t\t\t\tThe Centre Code is not valid or not found in the list." << endl;
            goto centre;
        }
        else {
            tutorArr[size].centreID = centreID;
            goto subject;
        }

    subject:
        cout << "\t\t\t\tWhat is your Subject ID? " << endl;
        displaySubject(subjectSize);
        cout << "\t\t\t\t";
        cin >> subjectID;
        if (checkSubject(subjectID) != true) {
            cout << "\t\t\t\tThe subject Code is not valid or not found in the list." << endl;
            goto subject;
        }
        else {
            tutorArr[size].subjectID = subjectID;
            goto rating;
        }
    rating:
        cout << "\t\t\t\t1 -- Very Bad\n";
        cout << "\t\t\t\t2 -- Slight Bad\n";
        cout << "\t\t\t\t3 -- Average\n";
        cout << "\t\t\t\t4-- Slightly Good\n";
        cout << "\t\t\t\t5 -- Very Good\n";
        cout << "\t\t\t\tEnter the overall rating" << endl;
        cout << "\t\t\t\t";


        //cin >> TutorRating;

        if (!(cin >> TutorRating)) { //user input here

            cout << "\t\t\t\tInput Error: non-numericacl characters have been entered!" << endl;
            system("pause");
            cin.clear();
            cin.ignore(123, '\n');

            goto rating;

        }


        if (TutorRating >= 0 && TutorRating <= 5)
        {
            tutorArr[size].rating = TutorRating;
            goto endInsertTutor;

        }
        else {
            cout << "\t\t\t\tInvalid range of rating (must within 0.0 to 5.0)\n";
            goto rating;
        }


    endInsertTutor:

        //PASS DATA FROM NEW ARRAY TO ORIGINAL ARRAY.
        t = tutorArr;

        //UPDATE TUTOR SIZE
        tutorSize = tutorSize + 1;

        cout << endl << "\t\t\t\tRecord entered." << endl;

        cout << endl << endl << "Press ESC button to go back to home page. " << endl;

        system("pause");
        menu();
        return size;

    }

    //SEARCH TUTOR 
    int searchTutor(int size, struct tutor*& t) {

        bool loopback = true;
        double hourlyRate;
        string subjectName;
        string centreLocation;
        boolean verifyID = false;
        while (loopback != false)
        {
            system("CLS");
            cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

            char searchOption;

            cout << "Which data you would like to search?" << endl;
            cout << "1) Tutor ID" << endl;
            cout << "2) Tutor Overall Performance" << endl;
            bool escPressed = false;
            char key = _getch();

            if (key == KeyEsc) {
                menu();
            }

            cout << "";
            cin >> searchOption;

            if (searchOption == '1') // search based on ID 
            {
                //search based on ID 
                int leftID, rightID, midID;

                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
 
                // DEFINE BOUNDARIES FOR BINARY SEARCH
                leftID = 0;
                rightID = tutorSize-1;
                midID = (leftID + rightID) / 2;

                int id;

                //receive user ID 
                bool reloadUserInputID = false;

            searchTutorID:
                do
                {
                    cout << "\n\n\n\t\t\t\tDetails of Tutor: \n\n\n";

                    cout << "\t\t\t\tID" << setw(25) << "Name " << setw(25) << "Date Joined ";
                    cout << endl;

                    //DISPLAY TUTOR INFO WITH LOOP
                    for (int i = 0; i < size; i++) {
                        cout << "\n\t\t\t\t" << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined;
                    }
                    
                    //ESCAPE KEY FOR USER TO ESCAPE
                    cout << endl << "Enter the tutor ID: ";
                    if (key == KeyEsc) {
                        menu();
                    }

                    if (!(cin >> id)) {

                        cout << "You have entered wrong input" << endl;
                        system("pause");
                        cin.clear();
                        cin.ignore(123, '\n');
                        system("CLS");
                        cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                        goto searchTutorID;

                    }
                   else {
                        
                        
                        for (int i = 0; i < size; i++) {
                            
                            if (id == t[i].tutorID)
                            {
                                cout << "valid" << endl;
                                verifyID = true;
                                break;
                            }

                        }
                        if (verifyID == false) {
                                cout << "Invalid ID! Enter ID that exist in list!" << endl;
                                system("pause");
                                cin.clear();
                                cin.ignore(123, '\n');
                                system("CLS");
                                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                                goto searchTutorID;
                        }
                    }
               
                    bool repeatBinarySearch = false;
                    //if element is smaller than mid, ,then it can only be present in left subarray
                    //loop for repeatBinarySearch
                    do
                    {


                        if (id == t[midID].tutorID ) {// complete binary search 
                            
                            reloadUserInputID = false;
                            repeatBinarySearch = false;


                            for (int subject = 0; subject < subjectSize; subject++)
                            {
                                if (t[midID].subjectID==(s[subject].subjectID)) {
                                    hourlyRate = s[subject].subjectRate;
                                    subjectName = s[subject].subjectName;
                                    break;
                                }
                            }
                            for (int centre = 0; centre < centreSize; centre++)
                            {
                                if (t[midID].centreID==(c[centre].centreID)) {
                                    centreLocation = c[centre].centreLocation;
                                    break;
                                }
                            }
                            //display tutor information 
                           
                            cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[midID ].tutorID << endl;
                            cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[midID].tutorName << endl;
                            cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[midID].dateJoined << endl;
                            cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[midID].dateTerminated << endl;
                            cout << "\t\t\t\tHourly Rate \t\t:\t\t\t" << hourlyRate << endl;
                            cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[midID].tutorPhone << endl;
                            cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[midID].address << endl;
                            cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[midID].centreID << endl;
                            cout << "\t\t\t\tCenter Name \t\t:\t\t\t" << centreLocation << endl;
                            cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[midID].subjectID << endl;
                            cout << "\t\t\t\tSubject Name \t\t:\t\t\t" << subjectName << endl;
                            cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[midID].rating << endl << endl;


                        }
                        else if (id > t[midID].tutorID&& id <= t[rightID].tutorID) { // search from second half, ignore left half

                            leftID = midID + 1;
                            midID = (leftID + rightID) / 2;

                            repeatBinarySearch = true;
                            reloadUserInputID = false;

                        }
                        else if (id < t[midID].tutorID && id >= 0) { // search from first half, ignore second half

                            rightID = midID - 1;
                            midID = (rightID + leftID) / 2;

                            repeatBinarySearch = true;
                            reloadUserInputID = false;
                        }
                        else {

                            cout << "out of array size" << endl;
                            reloadUserInputID = true;
                            repeatBinarySearch == true;
                        }
                    } while (repeatBinarySearch == true);
                } while (reloadUserInputID == true);
                loopback = false;

            }
            else if (searchOption == '2') { // search based on Rating 

               //search based on Performances 
                system("CLS");
                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

                // actual data
                double l, r, m;
                cout << "tutorSize " << tutorSize << endl;

                //DEFINE SEARCH RATING BOUNDARIES
                l = 0.0;
                r = 5.0;
                m = l + (r - 1) / 2;


                double rating;
                //receive user rating 
                bool reloadRatingInput = false;
                do
                {
                    cout << "Enter the tutor rating: ";
                    if (key == KeyEsc) {
                        menu();
                    }

                    cin >> rating;

                    bool repeatBinarySearch = false;
                    //if element is smaller than mid, ,then it can only be present in left subarray
                    //loop for repeatBinarySearch
                    do
                    {
                        if (rating == m ) {// complete binary search 
                            r = rating;
                            cout << "rating: " << rating << endl;
                            reloadRatingInput = false;
                            repeatBinarySearch = false;


                            cout << "\n" << setw(5) << "Tutor ID" << setw(25) << "Tutor Name" << setw(23) << "Date Joined" << setw(20) << "Date Terminate" << setw(15) << "Hourly Rate" << setw(15) << "Phone Number"
                                << setw(20) << "Address" << setw(20) << "Centre ID" << setw(20) << "Centre Location" << setw(15) << "Subject ID" << setw(15) << "Subject Name" << setw(15) << "Rating" << endl;
                            for (int i = 0; i < (tutorSize ); i++)
                            {

                                if (t[i].rating == rating) {
                                    for (int subject = 0; subject < subjectSize; subject++)
                                    {
                                        if (t[i].subjectID==(s[subject].subjectID)) {
                                            hourlyRate = s[subject].subjectRate;
                                            subjectName = s[subject].subjectName;
                                            break;
                                        }
                                    }
                                    for (int centre = 0; centre < centreSize; centre++)
                                    {
                                        if (t[i].centreID==(c[centre].centreID)) {
                                            centreLocation = c[centre].centreLocation;
                                            break;
                                        }
                                    }

                                    cout << setw(5) << t[i].tutorID << setw(25) << t[i].tutorName << setw(23) << t[i].dateJoined << setw(20) << t[i].dateJoined << setw(15) << hourlyRate << setw(15) << t[i].tutorPhone
                                        << setw(20) << t[i].address << setw(20) << t[i].centreID << setw(20) << centreLocation << setw(15) << t[i].subjectID << setw(15) << subjectName << setw(15) << t[i].rating << endl;

                                }
                            }

                        }
                        else if (rating > m&& rating <= 5.0) { // search from second half, ignore right half
                            l = r + 1;
                            m = (l + r) / 2;

                            repeatBinarySearch = true;
                            reloadRatingInput = false;

                        }
                        else if (rating < m && rating >= 0.0) { // search from first half, ignore left half
                            r = r - 1;
                            m = (r + l) / 2;

                            repeatBinarySearch = true;
                            reloadRatingInput = false;
                        }
                        else {
                            //similan dou bu shi
                            cout << "\t\t\t\tout of array size" << endl;
                            reloadRatingInput = true;
                            repeatBinarySearch == true;
                        }
                    } while (repeatBinarySearch == true);
                } while (reloadRatingInput == true);

                loopback = false;


            }
            else {

                loopback = true;
                cout << loopback << endl;
                cout << "\t\t\t\twrong input, reload !" << endl;
            }



        }
        system("pause");
        menu();
        return size;
    }

    //SELECT SORT DATA TYPE AND SEQUENCE
    void sortCenter(struct tutor*& t, int size) {

        system("CLS");
        cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
        //VARIALBLE DECLARATION
        int sortChoice;// USER SORT TYPE 
        int sequence; //ASC OR DSC
        bool correctChoice = false;

        do
        {
            cout << "Please insert the data type you wanted to sort" << endl;
            cout << "1) Sort by ID  " << endl;
            cout << "2) Sort by Hourly Pay  " << endl;
            cout << "3) Sort by Rating  " << endl;
            bool escPressed = false;
            char key = _getch();

            //ESCAPE KEY TO RETURN MENU
            if (key == KeyEsc) {
                return;
            }
            cin >> sortChoice;

            //SORT BY ID
            if (sortChoice == 1) { 

                system("CLS");
                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

                correctChoice = true;
                cout << "Sort by ID " << endl;

                double hourlyRate;
                string subjectName;
                string centreLocation;

                //display heap sort result 
                cout << "\n" << setw(5) << "Tutor ID" << setw(25) << "Tutor Name" << setw(23) << "Date Joined" 
                    << setw(20) << "Date Terminate" << setw(15) << "Hourly Rate" << setw(15) << "Phone Number"
                    << setw(20) << "Address" << setw(20) << "Centre ID" << setw(20) << "Centre Location" << setw(15) 
                    << "Subject ID" << setw(15) << "Subject Name" << setw(15) << "Rating";


                //DISPLAY SUBJECT AND CENTRE DATA WITH A LOOP
                for (int i = 0; i < size; ++i) {

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[i].subjectID==(s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[i].centreID==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }
                    cout << "\n" << setw(5) << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined << setw(20) << t[i].dateTerminated << setw(15) << hourlyRate << setw(15) << t[i].tutorPhone
                        << setw(20) << t[i].address << setw(15) << t[i].centreID << setw(25) << centreLocation << setw(15) << t[i].subjectID << setw(15) << subjectName << setw(15) << t[i].rating;
                    cout << "\n";

                }

                cout << "Would you like to sort by accending or descending? " << endl;
                cout << "1) Ascending" << endl;
                cout << "2) Descending" << endl;
                if (key == KeyEsc) {
                    return;
                }
                cin >> sequence;

                system("CLS");
                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

                //HEAP SORT DATA BASED ON SORTCHOICE AND SEQUENCE 
                heapSort(t, size, sequence, sortChoice);

                //DISPLAY SORTED DATA. 
                displayHeapedID(t, size, sortChoice);

            }
            // SORT BY HOURLY PAY
            else if (sortChoice == 2) { 

                system("CLS");
                correctChoice = true;
                cout << "Sort by Hourly Pay  " << endl;

                double hourlyRate;
                string subjectName;
                string centreLocation;

                //display heap sort result 
                cout << "\n" << setw(5) << "Tutor ID" << setw(25) << "Tutor Name" << setw(23) << "Date Joined" << setw(20) << "Date Terminate" << setw(15) << "Hourly Rate" << setw(15) << "Phone Number"
                    << setw(20) << "Address" << setw(20) << "Centre ID" << setw(20) << "Centre Location" << setw(15) << "Subject ID" << setw(15) << "Subject Name" << setw(15) << "Rating";
                for (int i = 0; i < size; ++i) {

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[i].subjectID==(s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[i].centreID==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }
                    cout << "\n" << setw(5) << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined << setw(20) << t[i].dateTerminated << setw(15) << hourlyRate << setw(15) << t[i].tutorPhone
                        << setw(20) << t[i].address << setw(15) << t[i].centreID << setw(25) << centreLocation << setw(15) << t[i].subjectID << setw(15) << subjectName << setw(15) << t[i].rating;
                    cout << "\n";

                }

                cout << "Would you like to sort by accending or descending? " << endl;
                cout << "1) Ascending" << endl;
                cout << "2) Descending" << endl;

                if (key == KeyEsc) {
                    return;
                }
                cin >> sequence;
                system("CLS");
                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                heapSort(t, size, sequence, sortChoice);
                displayHeapedID(t, size, sortChoice);

            }
            // SORT BY RATING
            else if (sortChoice == 3) {

                system("CLS");
                correctChoice = true;
                cout << "\t\t\t\tSort by Rating  " << endl;
                double hourlyRate;
                string subjectName;
                string centreLocation;

                //display heap sort result 
                cout << "\n" << setw(5) << "Tutor ID" << setw(25) << "Tutor Name" << setw(23) << "Date Joined" << setw(20) << "Date Terminate" << setw(15) << "Hourly Rate" << setw(15) << "Phone Number"
                    << setw(20) << "Address" << setw(20) << "Centre ID" << setw(20) << "Centre Location" << setw(15) << "Subject ID" << setw(15) << "Subject Name" << setw(15) << "Rating";
                for (int i = 0; i < size; ++i) {

                    for (int subject = 0; subject < subjectSize; subject++)
                    {
                        if (t[i].subjectID==(s[subject].subjectID)) {
                            hourlyRate = s[subject].subjectRate;
                            subjectName = s[subject].subjectName;
                            break;
                        }
                    }
                    for (int centre = 0; centre < centreSize; centre++)
                    {
                        if (t[i].centreID==(c[centre].centreID)) {
                            centreLocation = c[centre].centreLocation;
                            break;
                        }
                    }
                    cout << "\n" << setw(5) << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined << setw(20) << t[i].dateTerminated << setw(15) << hourlyRate << setw(15) << t[i].tutorPhone
                        << setw(20) << t[i].address << setw(15) << t[i].centreID << setw(25) << centreLocation << setw(15) << t[i].subjectID << setw(15) << subjectName << setw(15) << t[i].rating;
                    cout << "\n";

                }
                cout << "Would you like to sort by accending or descending? " << endl;
                cout << "1) Ascending" << endl;
                cout << "2) Descending" << endl;
                if (key == KeyEsc) {
                    return;
                }
                cin >> sequence;
                system("CLS");
                cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                heapSort(t, size, sequence, sortChoice);
                displayHeapedID(t, size, sortChoice);

            }
            else {
                cout << "Invalid choice, please insert correct data." << endl;
                system("pause");
                system("CLS");
                correctChoice = false;
            }
        } while (correctChoice == false);
        system("pause");

    }

    //DEFAULT SORT SETTING -> ID IN ASCENDING 
    void sortAscending(struct tutor*& t, int size) {
        heapSort(t, size, 1, 1);
    }

    //HEAPIFY SUB TREE
    void heapify(struct tutor*& t, int size, int root, int sequence, int sortChoice) {


        int largest = root; // Initialize largest as root
        int l = 2 * root + 1; // left = 2*root + 1
        int r = 2 * root + 2; // right = 2*root + 2
        double leftHourlyRate = 0;
        double rightHourlyRate = 0;
        double largestHourlyRate = 0;

        if (sortChoice == 1)
        {
            //sortID 
            if (sequence == 1)
            {
                //Ascending 
                // If left child is larger than root
                if (l < size && t[l].tutorID > t[largest].tutorID)
                    largest = l;
                if (r < size && t[r].tutorID > t[largest].tutorID)
                    largest = r;
            }
            else {

                //decending 
                if (l < size && t[l].tutorID < t[largest].tutorID)
                    largest = l;
                if (r < size && t[r].tutorID < t[largest].tutorID)
                    largest = r;
            }
            if (largest != root)
            {
                //swap root and largest
                swap(t[root], t[largest]);
                //recursively heapify the sub-tree
                heapify(t, size, largest, sequence, sortChoice);
            }
        }
        else if (sortChoice == 2) {

            for (int subject = 0; subject < subjectSize; subject++)
            {
                if (t[l].subjectID == s[subject].subjectID) {
                    leftHourlyRate = s[subject].subjectRate;
                }
                if (t[r].subjectID == s[subject].subjectID) {
                    rightHourlyRate = s[subject].subjectRate;
                }
                if (t[largest].subjectID == s[subject].subjectID) {
                    largestHourlyRate = s[subject].subjectRate;
                }
            }


            //sort hourly pay
            if (sequence == 1)
            {
                //Ascending 
                // If left child is larger than root
                int larger=0;
                int largerElement=0;
                if (leftHourlyRate >= rightHourlyRate)
                {
                    larger = leftHourlyRate;
                    largerElement = l;
                }
                else if (rightHourlyRate > leftHourlyRate) {
                    larger = rightHourlyRate;
                    largerElement = r;

                }
                if (largerElement < size && larger > largestHourlyRate) {
       
                    largest = largerElement;
                }


            }
            else {

                //Descending  
                // If left child is larger than root
                int larger = 0;
                int largerElement = 0;
                if (leftHourlyRate <= rightHourlyRate)
                {
                    larger = leftHourlyRate;
                    largerElement = l;
                }
                else if (rightHourlyRate < leftHourlyRate) {
                    larger = rightHourlyRate;
                    largerElement = r;

                }
                if (largerElement < size && larger < largestHourlyRate) {

                    largest = largerElement;
                }

            }
            if (largest != root)
            {
                //swap root and largest
                swap(t[root], t[largest]);

                //recursively heapify the sub-tree
                heapify(t, size, largest, sequence, sortChoice);
            }
        }
        else if (sortChoice == 3) {
            //sort rating 
            if (sequence == 1)
            {
                //Ascending 
                // If left child is larger than root
                if (l < size && t[l].rating > t[largest].rating)
                    largest = l;
                if (r < size && t[r].rating > t[largest].rating)
                    largest = r;
            }
            else {

                //decending 
                if (l < size && t[l].rating < t[largest].rating)
                    largest = l;
                if (r < size && t[r].rating < t[largest].rating)
                    largest = r;
            }
            if (largest != root)
            {
                //swap root and largest
                swap(t[root], t[largest]);
                //recursively heapify the sub-tree
                heapify(t, size, largest, sequence, sortChoice);
            }
        }


    }

    //HEAPSORT DATA
    void heapSort(struct tutor*& t, int size, int sequence, int sortChoice) {

        //Build heap (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(t, size, i, sequence, sortChoice);
        }

        // extracting elements from heap one by one
        for (int i = size - 1; i >= 0; i--)
        {

            if (sortChoice == 1)
            {
                //sortID
                // Move current root to end
                swap(t[0], t[i]);
                // again call max heapify on the reduced heap
                heapify(t, i, 0, sequence, sortChoice);
            }
            else if (sortChoice == 2) {
                //sort hourly pay

                swap(t[0], t[i]);
                // again call max heapify on the reduced heap
                heapify(t, i, 0, sequence, sortChoice);
            }
            else if (sortChoice == 3) {
                //sort rating 
                swap(t[0], t[i]);
                // again call max heapify on the reduced heap
                heapify(t, i, 0, sequence, sortChoice);
            }


        }
    }

    //DISPLAY SORTED DATA
    void displayHeapedID(struct tutor*& t, int size, int sortChoice) {
        double hourlyRate;
        string subjectName;
        string centreLocation;

        //display heap sort result 
        cout << "\n" << setw(5) << "Tutor ID" << setw(25) << "Tutor Name" << setw(23) << "Date Joined"
            << setw(20) << "Date Terminate" << setw(15) << "Hourly Rate" << setw(15) << "Phone Number"
            << setw(20) << "Address" << setw(20) << "Centre ID" << setw(20) << "Centre Location" << setw(15) 
            << "Subject ID" << setw(15) << "Subject Name" << setw(15) << "Rating";

        for (int i = 0; i < size; ++i) {

            for (int subject = 0; subject < subjectSize; subject++)
            {
                if (t[i].subjectID == (s[subject].subjectID)) {
                    hourlyRate = s[subject].subjectRate;
                    subjectName = s[subject].subjectName;
                    break;
                }
            }
            for (int centre = 0; centre < centreSize; centre++)
            {
                if (t[i].centreID == (c[centre].centreID)) {
                    centreLocation = c[centre].centreLocation;
                    break;
                }
            }

            cout << "\n" << setw(5) << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined << setw(20)
                << t[i].dateTerminated << setw(15) << hourlyRate << setw(15) << t[i].tutorPhone
                << setw(20) << t[i].address << setw(15) << t[i].centreID << setw(25) << centreLocation << setw(15) 
                << t[i].subjectID << setw(15) << subjectName << setw(15) << t[i].rating;
            cout << "\n";
        }
    }

    //MODIFY TUTOR
    void modifytutor(int size, struct tutor*& t)
    {
    modify:
        system("CLS");
        bool verifyID = false;
        cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

        cout << "\t\t\t\tID" << setw(25) << "Name ";
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << "\n\t\t\t\t" << t[i].tutorID << setw(25) << t[i].tutorName;

        }
        cout << "\n\n------------------------------------------------------------\n";

        int modifyid, answer, a;
        string   tutorNumber, tutorAddress;
        cout << "Enter Tutor ID to be modified: " << endl;
        bool escPressed = false;
        char key = _getch();

        if (key == KeyEsc) {
            menu();
        }


        if (!(cin >> modifyid)) {

            cout << "You have entered wrong input" << endl;
            system("pause");
            cin.clear();
            cin.ignore(123, '\n');
            system("CLS");
            cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
            goto modify;

        }


        verifyID = checkID(modifyid, tutorSize);
        cout << endl;
        if (verifyID == true)
        {

            tutor* ptr = t;

            cout << "Phone Number \t\t:\t\t\t" << t[modifyid - 1].tutorPhone << endl;
            cout << "Address \t\t:\t\t\t" << t[modifyid - 1].address << endl << endl;

            cout << "Which one do you want to modify?" << endl;
            cout << "1) Phone Number" << endl;
            cout << "2) Address" << endl;
            bool escPressed = false;
            char key = _getch();

            if (key == KeyEsc) {
                menu();
            }


            cin >> answer;


            if (answer >= 0 && answer <= 2)
            {
                switch (answer)
                {
                case 1:

                modifyphone:

                    bool loopCheck;
                        do
                        {
                            //USER ENTER PHONE 
                            int correctPhone;
                            cout << "Enter new Phone Number:\t\t\t";
                            cin.ignore(); 
                            getline(cin, tutorNumber);

                            //VALIDATION : ONLY INTEGER
                            char check[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
                            int lenght = tutorNumber.size(); //takes the size of the string entered 
                            int verify = 0; // determine number of verified charcters.
                            loopCheck = true;
                            for (int count = 0; count < lenght; count++)
                            {
                                for (int numeral = 0; numeral <= 9; numeral++) { // inner for() loop start
                                    if (tutorNumber[count] == check[numeral]) {
                                        verify++;
                                    }
                                }
                            }

                            if (verify != lenght)
                            {
                                cout << "Input Error: non-numericacl characters have been entered!" << endl;
                                loopCheck = false;
                            }
                            else {

                                loopCheck = true;

                            }
                        } while (loopCheck != true);


                        //CHECK LENGHT
                        for (int i = 0; i < tutorNumber.length(); i++) {
                            if (tutorNumber.length() >= 9 && tutorNumber.length() <= 11) {
                                for (int i = 0; i < 10; i++)
                                {
                                    if (t[i].tutorID == modifyid)
                                    {
                                        t[i].tutorPhone = tutorNumber;
                                        break;
                                    }
                                }
                                cout << "Update Sccessful!" << endl;
                                break; ;
                            }
                            else {

                                cout << "Invalid Phone Number format!!" << endl;
                                cout << "Phone Number not Saved!" << endl;
                                system("pause");
                                goto modifyphone;
                                break;

                            }
                        }

                    break;

                case 2:
                    cin.ignore();
                modifyad:
                    cout << "Enter new Address: " << endl;
                    getline(cin, tutorAddress);

                    for (int i = 0; i < 10; i++)
                    {
                        if (t[i].tutorID == modifyid)
                        {

                            t[i].address = tutorAddress;
                            break;
                        }
                    }
                    cout << "New Address Saved" << endl;
                    break;
                }
            }
            else
            {
                cout << "Invalid Answer" << endl;
                system("pause");
                system("CLS");

                goto modifyad;
            }

        }
        else {

            cout << "Invalid ID" << endl;
            system("pause");
            system("CLS");

            goto modify;
        }

        system("pause");
        menu();

    }

    //DELETE TUTOR
    tutor* deletetutor(int size, struct tutor* t)
    {
        system("CLS");

    deleteid:
        double hourlyRate;
        string subjectName;
        string centreLocation;
        bool verifyID = false;
        cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";


        cout << "\t\t\t\tID" << setw(25) << "Name " << setw(25) << "Date Joined ";
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << "\n\t\t\t\t" << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateJoined;

        }
        cout << "\n\n------------------------------------------------------------\n";

        int deleteid, answer, i;
        cout << "Enter Tutor ID to be deleted: " << endl;
        bool escPressed = false;
        char key = _getch();

        if (key == KeyEsc) {
            menu();
        }

        if (!(cin >> deleteid)) {

            cout << "You have entered wrong input" << endl;
            cin.clear();
            cin.ignore(123, '\n');
            system("CLS");
            cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
            goto deleteid;

        }
        verifyID = checkID(deleteid, tutorSize);
        cout << endl;
        if (verifyID == true)
        {
            system("CLS");
            cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

            tutor* ptr = t;
            tutor* tutorArr = new tutor[size - 1];
            for (int i = 0; i < size; i++)
            {
                if (t[i].tutorID == deleteid)
                {

                    cout << "\t\t\t\tTutor ID \t\t:\t\t\t" << t[i].tutorID << endl;
                    cout << "\t\t\t\tTutor Name \t\t:\t\t\t" << t[i].tutorName << endl;
                    cout << "\t\t\t\tDate Joined \t\t:\t\t\t" << t[i].dateJoined << endl;
                    cout << "\t\t\t\tDate Terminated\t\t:\t\t\t" << t[i].dateTerminated << endl;
                    cout << "\t\t\t\tPhone Number \t\t:\t\t\t" << t[i].tutorPhone << endl;
                    cout << "\t\t\t\tAddress \t\t:\t\t\t" << t[i].address << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << t[i].centreID << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << centreLocation << endl;
                    cout << "\t\t\t\tSubject ID \t\t:\t\t\t" << t[i].subjectID << endl;
                    cout << "\t\t\t\tCenter ID \t\t:\t\t\t" << subjectName << endl;
                    cout << "\t\t\t\tRating \t\t\t:\t\t\t" << t[i].rating << endl;
                    break;
                }

            }
            cout << endl;
            cout << "Are you sure you want to delete this tutor? " << endl;
            cout << "1) YES " << endl;
            cout << "2) NO " << endl << endl;
            bool escPressed = false;
            char key = _getch();

            if (key == KeyEsc) {
                menu();
            }

            cin >> answer;
            if (answer >= 0 && answer <= 2)
            {
                switch (answer)
                {
                case 1:
                    for (int i = 0; i < size; i++)
                    {
                        if (t[i].tutorID == deleteid)
                        {
                            for (int d = i; d < (size - 1); d++)
                            {
                                tutorArr[d] = t[d + 1];

                            }
                            size--;
                            tutorSize = size;
                            break;

                        }
                        tutorArr[i] = t[i];

                    }
                    cout << "Tutor deleted successfully..!!\n";



                    return tutorArr;
                    break;
                case 2:
                    cout << "Tutor not deleted!" << endl;
                    break;
                }

            }
            else {
                cout << "Invalid Answer" << endl;
                system("pause");
                system("CLS");

                goto deleteid;
            }


        }
        else {

            cout << "Invalid ID" << endl;
            system("pause");
            system("CLS");

            goto deleteid;
        }





    }

    //UPDATE TERMINATED DATE
    void modifydate(int size, struct tutor*& t)
    {
    modify:
        system("CLS");
        cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";

        bool verifyID = false;

        cout << "\t\t\t\tID" << setw(25) << "Name " << setw(25) << "Date Terminate ";
        cout << endl;

        for (int i = 0; i < size; i++) {
            cout << "\n\t\t\t\t" << t[i].tutorID << setw(25) << t[i].tutorName << setw(25) << t[i].dateTerminated;

        }
        cout << "\n\n------------------------------------------------------------\n";

        int modifyid, answer, a;
        string  date;
        cout << "Enter Tutor ID to be modified: " << endl;
        bool escPressed = false;
        char key = _getch();

        if (key == KeyEsc) {
            menu();
        }

        if (!(cin >> modifyid)) {

            cout << "You have entered wrong input" << endl;
            system("pause");
            cin.clear();
            cin.ignore(123, '\n');
            system("CLS");
            cout << "\n\n\n\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
            goto modify;

        }
        verifyID = checkID(modifyid, tutorSize);
        cout << endl;
        if (verifyID == true)
        {
            tutor* ptr = t;

            cout << "Are you sure you want to update date termination for this tutor? " << endl;
            cout << "1) YES " << endl;
            cout << "2) NO " << endl << endl;
            bool escPressed = false;
            char key = _getch();

            if (key == KeyEsc) {
                menu();
            }

            cin >> answer;
            if (answer >= 0 && answer <= 2)
            {
                switch (answer)
                {
                case 1:

                    for (int i = 0; i < 10; i++)
                    {
                        if (t[i].tutorID == modifyid)
                        {
                            t[i].dateTerminated = displayTime();
                            break;
                        }
                    }
                    cout << "Update Sccessful!" << endl;
                    break;
                case 2:

                    cout << "Update Unsuccessful!" << endl;
                    break;
                }
            }


            system("pause");
            menu();

        }
        else
        {
            cout << "Invalid ID" << endl;
            system("pause");
            system("CLS");

            goto modify;
        }
    }

    //REMOVE TERMINATED RECORD
    void deleteOutdated(int size, tutor* t) {
        bool terminated = false;
        for (int i = 0; i < size; i++) {

            string currentDay, terminationDate, terminationDay, terminationMonth, terminationYear;
            int currentMonth = 0, currentYear = 0, numberofMonth = 0;
            time_t currentTime = time(0);
            tm* currentDate = localtime(&currentTime);

            currentDay = to_string(currentDate->tm_mday);
            currentMonth = currentDate->tm_mon + 1;
            currentYear = currentDate->tm_year + 1900;



            terminationDate = t[i].dateTerminated;
            if (terminationDate != "") {

                terminationDay = terminationDate.substr(0, 2);
                terminationMonth = terminationDate.substr(3, 2);
                terminationYear = terminationDate.substr(6, 4);


                numberofMonth = (currentYear - stoi(terminationYear)) * 12;
                numberofMonth += (currentMonth - stoi(terminationMonth));
                if (currentDay < terminationDay) {
                    numberofMonth--;
                }

                if (numberofMonth >= 6) {

                    cout << "Tutor " << t[i].tutorID << " has been terminated! " << endl;

                    tutor* tutorArr = new tutor[size - 1];

                    for (int d = i; d < (size - 1); d++)
                    {
                        t[d] = t[d + 1];


                    }
                    i--;
                    size--;
                    tutorSize = size;
                    terminated = true;
                }
                else {
                    cout << numberofMonth << endl;
                }
                numberofMonth = 0;
            }

        }


        if (!terminated) {
            cout << "No record has been terminated!" << endl;
        }
        system("pause");
    }
};

CentreFunction f;
class loginManager {
private:
    string adminUsername = "admin";
    string adminPass = "admin";
    string hrUsername = "hr";
    string hrPass = "hr";
    int accessRight;

public:

    //reset the access right for validation purposes
    loginManager() {
        accessRight = 0;
    }

    // LOGIN
    void Login() {
        string username;
        string password;
        system("CLS");

        cout << "\n\n\n\t\t\t*Welcome to Excel Tuition Centre Management System\n\n\n\n\n";
        cout << "\t\t\t\t\t\tUsername: ";
        cin >> username;



        if (username == adminUsername) {

            cout << "\t\t\t\t\t\tPassword: ";
            cin >> password;
            if (password == adminPass) {
                cout << "\n\t\t\t****************************************************\n";
                cout << "\t\t\tWelcome admin! Press any key to login to the system.\n";
                cout << "\n\t\t\t****************************************************\n";
                setAccessRight(1); // accessRight 1 refers to admin login.
                menu();
                system("pause");

            }
            else {
                cout << "\n\t\t\t*********************************************************\n";
                cout << "\t\t\t\tInvalid Password. Please try to login again!\n";
                cout << "\n\t\t\t*********************************************************\n";

                system("pause");
                Login();
            }
        }
        else if (username == hrUsername) {
            cout << "\t\t\t\t\t\tPassword: ";
            cin >> password;
            if (password == hrPass) {
                cout << "\n\t\t\t*********************************************************\n";
                cout << "\t\t\tWelcome HR manager! Press any key to login to the system.\n";
                cout << "\n\t\t\t*********************************************************\n";
                setAccessRight(2);
                f.deleteOutdated(tutorSize, t);
                // accessRight 1 refers to admin login.
                menu();
                system("pause");

            }
            else {
                cout << "\n\t\t\t*********************************************************\n";
                cout << "\t\t\t\tInvalid Password. Please try to login again!\n";
                cout << "\n\t\t\t*********************************************************\n";
                system("pause");
                Login();
            }
        }
        else {
            cout << "\n\t\t\t*********************************************************\n";
            cout << "\t\t\t\tInvalid Username. Please try to login again!\n";
            cout << "\n\t\t\t*********************************************************\n";

            system("pause");
            Login();
        }

    }

    //SET ACCESS RIGHT VALUE
    void setAccessRight(int access) {
        accessRight = access;
    }


    //GET ACCESS RIGHT 
    int getAccessRight() {
        return accessRight;
    }
};

loginManager login;

//SYSTEM MAIN MENU
void menu() {
    while (true) {
        int choice;
        int id = 0;

        int accessRight = login.getAccessRight();
        f.sortAscending(t, tutorSize);
        system("CLS");
        cout << "\n\n\n\t\t\t*Welcome to Excel Tuition Centre Management System\n\n\n\n\n";

        // DISPLAY MENY FOR ADMIN
        if (accessRight == 1)
        {

        menuChoice: 

            cout << "\n\nPlease select these options from the menu below:" << endl;
            cout << "1) Display all tutors information" << endl;
            cout << "2) Add new tutor" << endl;
            cout << "3) Search" << endl;
            cout << "4) Sort" << endl;
            cout << "5) Logout" << endl;
            cout << "6) Exit Program" << endl;

            //VALIDATION : ONLY INTEGER AS INPUT
            if (!(cin >> choice)) { //user input here

                cout << "Error: User input out of bound!" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                goto menuChoice;

            }

            if (choice < 7 && choice > 0)
            {
                switch (choice) {
                case 1:
                    f.displayTutor(tutorSize);
                    break;

                case 2:
                    f.addTutor(tutorSize, t);
                    break;

                case 3:
                    f.searchTutor(tutorSize, t);
                    break;

                case 4:
                    f.sortCenter(t, tutorSize);
                    break;

                case 5:
                    login.Login();
                    break;

                case 6:
                    exit(0);
                    break;
                }
            }
            else {
                cout << "Error: User input out of bound!" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                goto menuChoice;
            }



        }
        // DISPLAY MENU FOR HR MANAGER
        if (accessRight == 2) 
        {
        HRmenuChoice:

            cout << "\n\nPlease select these options from the menu below:" << endl;
            cout << "1) Display all tutors information" << endl;
            cout << "2) Add new tutor" << endl;
            cout << "3) Search" << endl;
            cout << "4) Sort" << endl;
            cout << "5) Modify Tutor" << endl;
            cout << "6) Delete Tutor" << endl;
            cout << "7) Update Date Termination" << endl;
            cout << "8) Logout" << endl;
            cout << "9) Exit Program" << endl;

            //VALIDATION : ONLY INTEGER AS INPUT
            if (!(cin >> choice)) { //user input here

                cout << "Error: User input out of bound!" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                goto HRmenuChoice;

            }

            if (choice < 10 && choice > 0)
            {
                switch (choice) {
                case 1:
                    f.displayTutor(tutorSize);
                    break;

                case 2:
                    f.addTutor(tutorSize, t);
                    break;

                case 3:
                    f.searchTutor(tutorSize, t);
                    break;

                case 4:
                    f.sortCenter(t, tutorSize);
                    break;

                case 5:
                    f.modifytutor(tutorSize, t);
                    break;

                case 6:
                    t = f.deletetutor(tutorSize, t);
                    system("pause");
                    break;

                case 7:
                    f.modifydate(tutorSize, t);
                    break;

                case 8:
                    login.Login();
                    break;

                case 9:
                    exit(0);
                    break;

                }
            }
            else {
                cout << "Error: User input out of bound!" << endl;
                system("pause");
                cin.clear();
                cin.ignore(123, '\n');
                system("CLS");
                cout << "\n\n\n\t\t\t\t*********Excel Tuition Centre Management System**********\n\n\n\n\n";
                goto HRmenuChoice;
            }
        }
    }
}

//MAIN FUNCTION
int main() {

    f.hardcodedData();
    login.Login();
    return 0;

}