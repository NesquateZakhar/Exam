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

bool isValidEmployeeData(const string& name, int id, double salary) 
{
    if (name.empty()) 
    {
        cout << "Ошибка: Имени не может не быть" << endl;
        return false;
    }

    if (id <= 0) 
    {
        cout << "Ошибка: ID должен быть больше 0" << endl;
        return false;
    }

    if (salary < 0) 
    {
        cout << "Ошибка: Зарплата не может быть меньше 0" << endl;
        return false;
    }

    return true;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int ARRAY_SIZE = 5;
    vector<Employee> employees;
    
    cout << "Введите данные для трёх сотрудников:" << endl;
    
    int workersCount = 0;

    while (workersCount < 3)
    {
        string name;
        int id;
        double salary;

        cout << "\nСотрудник " << (workersCount + 1) << ":" << endl;

        cout << "Имя: ";
        getline(cin, name);

        cout << "ID: ";
        cin >> id;

        cout << "Зарплата: ";
        cin >> salary;

        cin.ignore();

        if (isValidEmployeeData(name, id, salary)) 
        {
            employees.push_back(Employee(name, id, salary));
            workersCount++;
        }
        else 
        {
            cout << "У вас неправильные данные, введите их заново" << endl;
        }
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