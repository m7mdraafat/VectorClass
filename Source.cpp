#include<iostream>
#include"Vector.h"
#include<algorithm>
using namespace std;

struct PhoneEntry {
    string name;
    string phone_number;

    void print() const {
        cout << "Name        : " << name << " \n";
        cout << "Phone Number: " << phone_number << "\n";
    }

    PhoneEntry() {} // Default constructor. 
    PhoneEntry(string name, string phone) {
        this->name = name;
        this->phone_number = phone;
    }

    // Less than operator
    bool operator<(const PhoneEntry& other) const {
        return name < other.name;
    }

    // Equal to operator
    bool operator==(const PhoneEntry& other) const {
        return name == other.name;
    }
};

int main() {
    Vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.print();

    Vector<string> v1(6);
    v1.push_back("Mohamed");
    v1.push_back("Sawsan");
    v1.push_back("Memo");
    v1.print();

    v1.pop_back();
    v1.print();

    Vector<PhoneEntry> Contacts;  
    Contacts.push_back(PhoneEntry("Mohamed", "01503755070"));
    Contacts.push_back(PhoneEntry("Sawsan", "01104845364"));
    Contacts.push_back(PhoneEntry("Ahmed", "012072010134"));

    for (auto& p : Contacts)
        p.print();

    // print sorted.
    cout << "***************************\n";
    sort(Contacts.begin(), Contacts.end());
    for (auto& p : Contacts)
        p.print();

    return 0;
}
