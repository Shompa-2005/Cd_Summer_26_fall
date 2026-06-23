#include <iostream>
using namespace std;


void numeric()
{
    string a;
    int count = 0;

    cout << "Enter Input: ";
    cin >> a;

    for(int i=0; i<a.length(); i++)
    {
        if(a[i] >= 48 && a[i] <= 57)
            count++;
    }

    if(count == a.length())
        cout << "Numeric Constant";
    else
        cout << "Not Numeric";
}


void op()
{
    string a;

    cout << "Enter Expression: ";
    cin >> a;

    for(int i=0; i<a.length(); i++)
    {
        if(a[i]==43 || a[i]==45 || a[i]==42 ||
           a[i]==47 || a[i]==37 || a[i]==61)
        {
            cout << a[i] << " is Operator" << endl;
        }
    }
}


void comment()
{
    string a;

    cout << "Enter Comment: ";
    cin >> a;

    if(a[0]==47 && a[1]==47)
        cout << "Single Line Comment";
    else if(a[0]==47 && a[1]==42)
        cout << "Multi Line Comment";
    else
        cout << "Not Comment";
}


void identifier()
{
    string a;

    cout << "Enter Identifier: ";
    cin >> a;

    if((a[0]>=65 && a[0]<=90) ||
       (a[0]>=97 && a[0]<=122) ||
       a[0]==95)
    {
        cout << "Valid Identifier";
    }
    else
    {
        cout << "Invalid Identifier";
    }
}


void average()
{
    int a[5], sum=0;

    cout << "Enter 5 Numbers: ";

    for(int i=0; i<5; i++)
    {
        cin >> a[i];
        sum = sum + a[i];
    }

    cout << "Average = " << sum/5.0;
}


void maxmin()
{
    int a[5];

    cout << "Enter 5 Numbers: ";

    for(int i=0; i<5; i++)
        cin >> a[i];

    int max = a[0];
    int min = a[0];

    for(int i=1; i<5; i++)
    {
        if(a[i] > max)
            max = a[i];

        if(a[i] < min)
            min = a[i];
    }

    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min;
}


void fullname()
{
    string first, last;

    cout << "Enter First Name: ";
    cin >> first;

    cout << "Enter Last Name: ";
    cin >> last;

    cout << "Full Name = " << first << " " << last;
}

int main()
{
    int choice;

    cout << "MENU" << endl;
    cout << "1. Numeric Constant" << endl;
    cout << "2. Operator Detection" << endl;
    cout << "3. Comment Detection" << endl;
    cout << "4. Identifier Detection" << endl;
    cout << "5. Average of Array" << endl;
    cout << "6. Maximum and Minimum" << endl;
    cout << "7. Full Name Concatenation" << endl;

    cout << "Enter Your Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            numeric();
            break;

        case 2:
            op();
            break;

        case 3:
            comment();
            break;

        case 4:
            identifier();
            break;

        case 5:
            average();
            break;

        case 6:
            maxmin();
            break;

        case 7:
            fullname();
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}
