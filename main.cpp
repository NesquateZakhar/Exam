#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

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

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int ARRAY_SIZE = 5;
    vector<Employee> employees;
    
    cout << "Введите данные для трёх сотрудников:" << endl;
    
    for (int i = 0; i < 3; i++) 
    {
        string name;
        int id;
        double salary;
        
        cout << "\nСотрудник " << (i + 1) << ":" << endl;
        
        cout << "Имя: ";
        getline(cin, name);
        
        cout << "ID: ";
        cin >> id;
        
        cout << "Зарплата: ";
        cin >> salary;
        
        cin.ignore();
        
        employees.push_back(Employee(name, id, salary));
    }
    
    cout << "\nСписок всех сотрудников:" << endl;
    
    for (int i = 0; i < employees.size(); i++) 
    {
        cout << "ID: " << employees[i].getId() 
             << ", Name: " << employees[i].getName() 
             << ", Salary: " << employees[i].getSalary() << endl;
    }
    
    return 0;
}