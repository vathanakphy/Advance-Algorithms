#include <iostream>
using namespace std;


// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/**
 * Validate a given date
 * @param year, month, day : the date
 * @return true if the date is valid, false otherwise
 */
bool isValidDate(int year, int month, int day) {
    // TODO
    int numberOfDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(!isLeapYear){
        numberOfDay[1]=29;
    }
    // The year shall be a positive number
    if(year<0) return  false;
    // The month shall be a number between 1 and 12
    if(month<0 || month >12) return false;
    // The day shall be a number between 1 and the max days
    if(day<1 || day>numberOfDay[month-1]) return false;
    return true;
}

/**
 * Compare 2 dates (date1 and date2)
 * @param year1, month1, day1 : date 1
 * @param year2, month2, day2 : date 2
 * @return
 *      -1 if date1 < date2
 *      0 if they are the same
 *      1 if date1 > date2
 */
int compare(int year1, int month1, int day1, int year2, int month2, int day2) {
    // TODO
    if(year1<year2) return -1;
    if(year1>year2) return 1;
    if(month1<month2) return -1;
    if(month1>month2) return 1;
    if(day1<day2) return -1;
    if(day1>day2) return 1;
    return 0;
}

int main() {
    // 1- Input the dates
    int year1, month1, day1;
    cout << "Enter the first person's date of birth (year/month/day): ";
    cin >> year1 >> month1 >> day1;

    int year2, month2, day2;
    cout << "Enter the second person's date of birth (year/month/day): ";
    cin >> year2 >> month2 >> day2;

    // 2- Validate the dates (BONUS)
    // TODO
    if(isValidDate(year1,month1,day1)==false || isValidDate(year2,month2,day2)==false){
        cout<<"invalid dates"<<endl;
        exit(2);
    }
    // 3- Compare the dates
    // TODO
    int compareDate = compare(year1,month1,day1,year2,month2,day2);
    switch(compareDate){
        case 1:
            cout<<"The first person is the youngest";
            break;
        case -1:
            cout<<"The second person is the youngest";
            break;
        case 0:
            cout<<"Both persons have the same age";
            break;
    }
    return 0;
}
