#include <iostream>

using namespace std;

class Employee
{
protected:
    string name;
    string position;
    double salary;

public:
    Employee(string name, string position, double salary) : 
        name(name), position(position), salary(salary) { }

    string GetName()
    {
        return name;
    }
};

class Programmer : Employee
{
private:
    string prog_lang;
    string position_level;

public:
    Programmer(string name, string position, double salary, string prog_lang, string position_level) :
        Employee(name, position, salary), prog_lang(prog_lang), position_level(position_level) { }
    
    string GetName()
    {
        return Employee::GetName();
    }

    void Code()
    {
        cout << "I'm coding";
    }
};

int main()
{
    Programmer programmer("John", "Back-end developer", 1800, "C#", "Middle");
    programmer.Code();
}
