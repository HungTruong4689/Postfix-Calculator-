#include "stack.h"
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;


char get_command();
bool do_command(char command, Stack& numbers);
void introduction();
void instructions();
bool isNumber(const string&db) {
    
    char *ptr=nullptr;
    double val=strtod(db.c_str(),&ptr);
    return ptr != db.c_str() && (*ptr)=='\0' && val!=HUGE_VAL;
    
}
bool isCommand(const string&db) {
    if (db.find('?') || db.find( '=') || db.find( '+') ||
                    db.find('-') || db.find('*') || db.find('/') ||
                    db.find('q') || db.find('x') || db.find('s') ||
                    db.find('%') || db.find('^') || db.find('v') ||
                    db.find('a')){
                    return true;
                }

    return false;
    
}
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/
int main(int argc,char *argv[])
{
    Stack stored_numbers;
    double a;
    string s(argv[1]);
    if (s == "-p") {
            introduction();
            instructions();
            while (do_command(get_command(), stored_numbers));
        }
    else {
        for (int i = 1; i < argc; i++) {
        
            string str()
        
            
            if (isNumber(argv[i])) {
                stored_numbers.push(stod(argv[i]));
            }
            if(isCommand(argv[i])){

                    do_command(*argv[i], stored_numbers);

            }

        }
    }
    stored_numbers.top(a);
    cout<<a<<endl;
    //return 0;
}

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting)
    {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == '%' || command == '^' || command == 'v' ||
            command == 'a')
            waiting = false;

        else
        {
            instructions();
        }
    }
    return command;
}

/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/
bool do_command(char command, Stack& numbers)
{
    double p, q;
    switch (command)
    {
    case '?':
        cout << "Enter a real number: " << flush;
        cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;

    case '+':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(q + p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Add options for further user commands.
    case '-':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(q - p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Substraction options for further user commands.

    case '/':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(q / p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Division options for further user commands.

    case '*':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Multiplication options for further user commands.
    case '%':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(remainder(q,p)) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Multiplication options for further user commands.
    case '^':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                if (numbers.push(pow(q, p)) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        } break;
        // Multiplication options for further user commands.
    case 'v':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.push(sqrt( p)) == overflow)
                cout << "Warning: Stack full, lost result" << endl;
               
        } break;
        // Multiplication options for further user commands.

    case 'x':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            Stack temp,temp2;
            temp.push(p);
            numbers.pop();
            
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                temp.push(q);
                numbers.pop();
                /*if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;*/
                
                while (!temp.empty()) {
                    temp.top(q);
                    temp2.push(q);
                    temp.pop();
                }
                while (!temp2.empty()) {
                    temp2.top(q);
                    numbers.push(q);
                    temp2.pop();
                }
                
            }
        } break;
        
        // Exchange options for further user commands.
    case 's':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            double a, result;
            double size;
            //size = numbers.size();
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                double a;
                Stack temp3;
                temp3.push(q+p);
                while (!numbers.empty()) {
                    numbers.top(q);
                    numbers.pop();
                    temp3.top(a);
                    temp3.pop();
                    temp3.push(q + a);
                }
                
                while (!temp3.empty()) {
                    temp3.top(a);
                    numbers.push(a);
                    temp3.pop();
                }
            }
        } break;
    case 'a':
        if (numbers.top(p) == underflow) cout << "Stack empty" << endl;
        else {
            double a, result;
            double size;
            size = numbers.size();
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.pop();
                
                Stack temp3;
                temp3.push(q + p);
                while (!numbers.empty()) {
                    numbers.top(q);
                    numbers.pop();
                    temp3.top(a);
                    temp3.pop();
                    temp3.push(q + a);
                }

                while (!temp3.empty()) {
                    temp3.top(a);
                    result = a / size;
                    numbers.push(result);
                    temp3.pop();
                }
            }
        } break;
    case 'q':
        cout << "Calculation finished.\n";
        return false;
    }
    return true;
}

void introduction()
{
    cout << "Welcome to Postfix calculator.\n";
}

void instructions()
{
    cout << "Please enter a valid command:\n"
        << "[?]push to stack   [=]print top\n"
        << "[x] exchanges the last two stack entries\n"
        << "[s] sums all stack entries\n"
        << "[a] calculates average of all stack entries\n"
        << "[+] [-] [*] [/]   are arithmetic operations\n"
        << "[%]   find remainder of two numbers\n"
        << "[^]   find power increase between two numbers\n"
        << "[v]   find squared root of number\n"
        << "[Q]uit.\n";
}

