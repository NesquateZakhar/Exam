#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>

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

    virtual double getSalary() const 
    {
        return salary;
    }

    void setSalary(double newSalary) 
    {
        salary = newSalary;
    }
};

class Manager : public Employee 
{
private:
    string department;

public:
    Manager(string employeeName, int employeeId, double employeeSalary, string managerDepartment) : Employee(employeeName, employeeId, employeeSalary) 
    {
        department = managerDepartment;
    }

    double getSalary() const override 
    {
        return Employee::getSalary() * 1.1;
    }

    string getDepartment() const 
    {
        return department;
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

void saveToFile(const Employee employees[], int size, const string& filename) 
{
    ofstream outFile(filename);
    
    if (!outFile.is_open()) 
    {
        cout << "Не удалось открыть файл" << endl;
        return;
    }
    
    for (int i = 0; i < size; i++) 
    {
        outFile << employees[i].getId() << " " 
                << employees[i].getName() << " " 
                << employees[i].getSalary() << endl;
    }
    
    outFile.close();
    cout << "Данные сохранены в файл " << filename << endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int ARRAY_SIZE = 5;
    vector<Employee*> employees;
    
    cout << "Введите данные для трёх сотрудников:" << endl;
    
    int workersCount = 0;

    while (workersCount < 3)
    {
        string name;
        int id;
        double salary;
        string classworkers;

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
            cout << "Введите должность работника(1 - рабочий, 2 - менеджер): ";
            getline(cin, classworkers);
            
            if (classworkers == "2") 
            {
                string department;
                cout << "Отдел: ";
                getline(cin, department);
                employees.push_back(new Manager(name, id, salary, department));
            } 
            else 
            {
                employees.push_back(new Employee(name, id, salary));
            }
            
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
        cout << "ID: " << employees[i]->getId() 
             << ", Name: " << employees[i]->getName() 
             << ", Salary: " << employees[i]->getSalary();

        Manager* manager = dynamic_cast<Manager*>(employees[i]);
        if (manager != nullptr) 
        {
            cout << ", Department: " << manager->getDepartment();
        }
        cout << endl;
    }

    Employee** employeesArray = employees.data();
    saveToFile(*employeesArray, employees.size(), "employees.txt");
    
    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }
    
    return 0;
}