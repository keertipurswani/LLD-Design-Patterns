import java.util.*;

abstract class EmployeeComponent {
    public abstract void displayInfo();
    public abstract double calculateSalary();
}

class Employee extends EmployeeComponent {
    private String name;
    private double salary;

    public Employee(String empName, double empSalary) {
        name = empName;
        salary = empSalary;
    }

    @Override
    public void displayInfo() {
        System.out.println("Employee: " + name + " Salary: Rs." + salary);
    }

    @Override
    public double calculateSalary() {
        return salary;
    }
}

class Department extends EmployeeComponent {
    private String name;
    private List<EmployeeComponent> members;

    public Department(String deptName) {
        name = deptName;
        members = new ArrayList<>();
    }

    public void addMember(EmployeeComponent member) {
        members.add(member);
    }

    @Override
    public void displayInfo() {
        System.out.println("Department: " + name);
        for (EmployeeComponent member : members) {
            member.displayInfo();
        }
    }

    @Override
    public double calculateSalary() {
        double totalSalary = 0.0;
        for (EmployeeComponent member : members) {
            totalSalary += member.calculateSalary();
        }
        return totalSalary;
    }
}

class Team extends EmployeeComponent {
    private String name;
    private List<EmployeeComponent> members;

    public Team(String teamName) {
        name = teamName;
        members = new ArrayList<>();
    }

    public void addMember(EmployeeComponent member) {
        members.add(member);
    }

    @Override
    public void displayInfo() {
        System.out.println("Team: " + name);
        for (EmployeeComponent member : members) {
            member.displayInfo();
        }
    }

    @Override
    public double calculateSalary() {
        double totalSalary = 0.0;
        for (EmployeeComponent member : members) {
            totalSalary += member.calculateSalary();
        }
        return totalSalary;
    }
}

public class EmployeesDemo {
    public static void main(String[] args) {
        EmployeeComponent keerti = new Employee("Keerti", 100.0);
        EmployeeComponent amit = new Employee("Amit", 200.0);

        Team sales = new Team("Sales");
        sales.addMember(keerti);
        sales.addMember(amit);

        EmployeeComponent bob = new Employee("Bob", 50.0);

        Team marketing = new Team("Marketing");
        marketing.addMember(bob);

        Department headOffice = new Department("Head Office");
        headOffice.addMember(sales);
        headOffice.addMember(marketing);

        // Display and calculate total salary for the organization hierarchy
        headOffice.displayInfo();
        double totalSalary = headOffice.calculateSalary();
        System.out.println("Total Salary for the Organization: Rs." + totalSalary);
    }
}
