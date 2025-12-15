#include <iostream>
#include <string>

using namespace std;

class Employee 
{
private:
    string name;
    int id;
    double salary;

public:
    Employee(string employeeName, int employeeId, double employeeSalary) 
    {
        name = employeeName;
        id = employeeId;
        salary = employeeSalary;
    }

    string getName() const 
    {
        return name;
    }

    int getId() const 
    {
        return id;
    }

    double getSalary() const 
    {
        return salary;
    }

    void setSalary(double newSalary) 
    {
        salary = newSalary;
    }
};