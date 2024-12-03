"""
Create two tables named as employee and department with the given constraints and attributes:
Employee table - (Employee Id.(Primary key), Department ID,
Name, Age (check >18), Salary, City)
Department table - (Department Id, and Department name)
Display the details of employees along with their corresponding department names.
Print the names of employees who are not assigned to any department.
Print the employee names and department names for employees whose salary is greater than 25,000. (Using left join).
Display the names of employees along with their department names for those who are not assigned to any department.
Print the employee names and their corresponding department names for employees with a salary greater than 25,000. (Using right join).
Display the names of departments along with the names of employees who are older than 30 years.
"""
-- Create two tables named as employee and department with the given constraints and attributes:
-- Employee table - (Employee Id.(Primary key), Department ID,
-- Name, Age (check >18), Salary, City)
-- Department table - (Department Id, and Department name)
CREATE TABLE Employee (
  EmployeeID INT PRIMARY KEY,
  DepartmentID INT,
  Name VARCHAR(100),
  Age INT CHECK (Age > 18),
  Salary DECIMAL(10, 2),
  City VARCHAR(100)
);

CREATE TABLE Department (
  DepartmentID INT PRIMARY KEY,
  DepartmentName VARCHAR(100)
);

INSERT INTO Department (DepartmentID, DepartmentName) VALUES
(1, 'HR'), (2, 'Finance'), (3, 'Engineering');

INSERT INTO Employee (EmployeeID, DepartmentID, Name, Age, Salary, City) VALUES
(1, 1, 'Alice', 25, 30000, 'New York'), (2, 2, 'Bob', 35, 40000, 'Los Angeles'),
(3, 3, 'Charlie', 28, 20000, 'Chicago'), (4, NULL, 'David', 22, 15000, 'Houston'),
(5, 1, 'Eve', 32, 27000, 'Phoenix'), (6, NULL, 'Frank', 40, 50000, 'Philadelphia');

-- Display the details of employees along with their corresponding department names
SELECT e.*, d.DepartmentName FROM Employee e 
LEFT JOIN Department d ON e.DepartmentID = d.DepartmentID;

-- Print the names of employees who are not assigned to any department
SELECT Name FROM Employee WHERE DepartmentID IS NULL;

-- Print the employee names and department names for employees whose salary is greater than 25,000 (Using left join)
SELECT e.Name, d.DepartmentName FROM Employee e LEFT JOIN Department d 
ON e.DepartmentID = d.DepartmentID WHERE e.Salary > 25000;

-- Display the names of employees along with their department names for those who are not assigned to any department
SELECT e.Name, d.DepartmentName FROM Employee e LEFT JOIN Department d 
ON e.DepartmentID = d.DepartmentID WHERE e.DepartmentID IS NULL;

-- Print the employee names and their corresponding department names for employees with a salary greater than 25,000 (Using right join)
SELECT e.Name, d.DepartmentName FROM Employee e RIGHT JOIN Department d 
ON e.DepartmentID = d.DepartmentID WHERE e.Salary > 25000;

-- Display the names of departments along with the names of employees who are older than 30 years
SELECT d.DepartmentName, e.Name FROM Department d JOIN Employee e 
ON d.DepartmentID = e.DepartmentID WHERE e.Age > 30;