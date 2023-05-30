#include <iostream>
#include <string>

using namespace std;

struct Trio {
    unsigned int field1;
    unsigned int field2;
    unsigned int field3;

    void init(unsigned int value1, unsigned int value2, unsigned int value3) {
        field1 = value1;
        field2 = value2;
        field3 = value3;
    }

    void read() {
        cout << "Enter three values: ";
        cin >> field1 >> field2 >> field3;
    }

    void display() {
        cout << field1 << " " << field2 << " " << field3 << endl;
    }
};

class Date {
    Trio date;

public:
    unsigned int getYear() const {
        return date.field1;
    }

    unsigned int getMonth() const {
        return date.field2;
    }

    unsigned int getDay() const {
        return date.field3;
    }

    void setYear(unsigned int year) {
        date.field1 = year;
    }

    void setMonth(unsigned int month) {
        date.field2 = month;
    }

    void setDay(unsigned int day) {
        date.field3 = day;
    }

    void init(const string& dateString) {
        size_t dot1 = dateString.find('.');
        size_t dot2 = dateString.find('.', dot1 + 1);
        string yearString = dateString.substr(0, dot1);
        string monthString = dateString.substr(dot1 + 1, dot2 - dot1 - 1);
        string dayString = dateString.substr(dot2 + 1);

        unsigned int year = stoi(yearString);
        unsigned int month = stoi(monthString);
        unsigned int day = stoi(dayString);

        date.init(year, month, day);
    }

    void display() {
        cout << date.field1 << "." << date.field2 << "." << date.field3 << endl;
    }

    void addDays(unsigned int days) {
        unsigned int year = date.field1;
        unsigned int month = date.field2;
        unsigned int day = date.field3;

        while (days > 0) {
            unsigned int daysInMonth;

            if (month == 2) {
                if ((year % 4 == 0 && year % 100 != 0)  (year % 400 == 0))
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
            }
            else if (month == 4  month == 6  month == 9  month == 11) {
                daysInMonth = 30;
            }
            else {
                daysInMonth = 31;
            }

            unsigned int daysToAdd = min(days, daysInMonth - day + 1);

            if (day + daysToAdd > daysInMonth) {
                day = 1;

                if (month == 12) {
                    month = 1;
                    year++;
                }
                else {
                    month++;
                }
            }
            else {
                day += daysToAdd;
            }

            days -= daysToAdd;
        }

        date.init(year, month, day);
    }
};

int main() {
    Trio trio;
    trio.init(10, 20, 30);
    trio.display();

    trio.read();
    trio.display();

    Date date;
    date.init("2023.05.29");
    date.display();

    date.addDays(10);
    date.display();

    return 0;
}