class Employee {
    String name;
    int id;
    double salary;

    Employee(String name, int id, double salary) {
        this.name = name;
        this.id = id;
        this.salary = salary;
    }

    void displayEmployeeInfo() {
        System.out.println("Employee Name: " + name);
        System.out.println("Employee ID: " + id);
        System.out.println("Salary: " + salary);
    }
}

class Manager extends Employee {
    String department;

    Manager(String name, int id, double salary, String department) {
        super(name, id, salary); 
        this.department = department;
    }

    void displayManagerInfo() {
        displayEmployeeInfo(); 
        System.out.println("Department: " + department);
    }
}

class ProjectManager extends Manager {
    String projectName;

    ProjectManager(String name, int id, double salary, String department, String projectName) {
        super(name, id, salary, department); 
        this.projectName = projectName;
    }

    void displayProjectManagerInfo() {
        displayManagerInfo(); 
        System.out.println("Project Name: " + projectName);
    }
}

public class MultiLevelInheritanceEmployee {
    public static void main(String[] args) {
        ProjectManager projectManager = new ProjectManager("Sandy", 101, 95000.00, "IT", "AI Development");

        projectManager.displayProjectManagerInfo();
    }
}
