#include <iostream>

using namespace std;

class EmployeeComponent {
public:
    virtual void displayInfo() = 0;
    virtual double calculateSalary() = 0;
    virtual ~EmployeeComponent() {}
};

class Employee : public EmployeeComponent {
private:
    string name;
    double salary;

public:
    Employee(string empName, double empSalary) : name(empName), salary(empSalary) {}

    void displayInfo() override {
        cout << "Employee: " << name << " Salary: Rs." << salary << endl;
    }

    double calculateSalary() override {
        return salary;
    }
};

class Department : public EmployeeComponent {
private:
    string name;
    vector<EmployeeComponent*> members;

public:
    Department(string deptName) : name(deptName) {}

    void addMember(EmployeeComponent* member) {
        members.push_back(member);
    }

    void displayInfo() override {
        cout << "Department: " << name << endl;
        for (auto member : members) {
            member->displayInfo();
        }
    }

    double calculateSalary() override {
        double totalSalary = 0.0;
        for (auto member : members) {
            totalSalary += member->calculateSalary();
        }
        return totalSalary;
    }
};

class Team : public EmployeeComponent {
private:
    string name;
    vector<EmployeeComponent*> members;

public:
    Team(string teamName) : name(teamName) {}

    void addMember(EmployeeComponent* member) {
        members.push_back(member);
    }

    void displayInfo() override {
        cout << "Team: " << name << endl;
        for (auto& member : members) {
            member->displayInfo();
        }
    }

    double calculateSalary() override {
        double totalSalary = 0.0;
        for (auto member : members) {
            totalSalary += member->calculateSalary();
        }
        return totalSalary;
    }
};


int main() {
    EmployeeComponent* keerti = new Employee("Keerti", 100.0);
    EmployeeComponent* amit = new Employee("Amit", 200.0);

    Team* sales = new Team("Sales");
    sales->addMember(keerti);
    sales->addMember(amit);

    EmployeeComponent* bob = new Employee("Bob", 50.0);

    Team* marketing = new Team("Marketing");
    marketing->addMember(bob);

    Department* headOffice = new Department("Head Office");
    headOffice->addMember(sales);
    headOffice->addMember(marketing);

    // Display and calculate total salary for the organization hierarchy
    headOffice->displayInfo();
    double totalSalary = headOffice->calculateSalary();
    cout << "Total Salary for the Organization: Rs." << totalSalary << endl;

    // Clean up memory (consider using smart pointers in a real application)
    delete keerti;
    delete amit;
    delete sales;
    delete bob;
    delete marketing;
    delete headOffice;

    return 0;
}

