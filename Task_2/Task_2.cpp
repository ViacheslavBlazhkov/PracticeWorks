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
    Employee() {}

    void Show()
    {
        printf("Name: %s, Position: %s, Salary: %.2f", name.c_str(), position.c_str(), salary);
    }
};

class Programmer : Employee
{
protected:
    string prog_lang;
    string position_level;

public:
    Programmer(string name, string position, double salary, string prog_lang, string position_level) :
        Employee(name, position, salary), prog_lang(prog_lang), position_level(position_level) { }

    void Show()
    {
        Employee::Show();
        printf("Programming language: %s, Position level: %s", prog_lang.c_str(), position_level.c_str());
    }
};
class Manager : private Employee
{
protected:
    int project_count;
    string position_level;

public:
    Manager(string name, string position, double salary, int project_count, string position_level) :
        Employee(name, position, salary), project_count(project_count), position_level(position_level) { }
    Manager(int project_count) : Employee(), project_count(project_count) { }

    void Show()
    {
        Employee::Show();
        printf("Project count: %d, Position level: %s", project_count, position_level.c_str());
    }
};
class BussinessAnalyst : private Employee
{
protected:
    string some_field;

public:
    BussinessAnalyst(string name, string position, double salary, string some_field) :
        Employee(name, position, salary), some_field(some_field) { }
    BussinessAnalyst(string some_field) : Employee(), some_field(some_field) { }

    void Show()
    {
        Employee::Show();
        printf("Some field: %s", some_field.c_str());
    }
};

class ProjectManager : public Programmer, public Manager, private BussinessAnalyst
{
public:
    ProjectManager(string name, string position, double salary, string some_field, string prog_lang, string position_level, int project_count) :
        Programmer(name, position, salary, prog_lang, position_level), Manager(project_count), BussinessAnalyst(some_field) { }

    void Show()
    {
        Programmer::Show();
        printf("Some field: %s", some_field.c_str());
    }
};
class BackendDeveloper : public Programmer
{
public:
    BackendDeveloper(string name, string position, double salary, string prog_lang, string position_level) :
        Programmer(name, position, salary, prog_lang, position_level){ }

    void Show()
    {
        Programmer::Show();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}