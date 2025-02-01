#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUP();
    void forgot();
} obj;

int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;

    switch (choice) {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.signUP();
        break;
    case '3':
        cin.ignore();
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid Selection...!";
    }
}

void temp::signUP() {
    cout << "\nEnter Your User Name :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
    cout << "\nAccount Created Successfully!";
}

void temp::login() {
    cout << "----------LOGIN---------" << endl;
    cout << "Enter Your User Name :: ";
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
        if (userName == searchName) {
            if (password == searchPass) {
                cout << "\nAccount Login Successful...!";
                cout << "\nUsername :: " << userName << endl;
                cout << "Email :: " << Email << endl;
                found = true;
                break;
            } else {
                cout << "Password is Incorrect...!" << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "\nAccount Not Found...!" << endl;
    }

    file.close();
}

void temp::forgot() {
    cout << "\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
        if (userName == searchName) {
            if (Email == searchEmail) {
                cout << "\nAccount Found...!" << endl;
                cout << "Your Password :: " << password << endl;
                found = true;
                break;
            } else {
                cout << "Email does not match...!" << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "\nAccount Not Found...!" << endl;
    }

    file.close();
}
