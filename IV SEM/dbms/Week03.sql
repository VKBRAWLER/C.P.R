"""
Create an Employee table with the following attributes and constraints:
Employee Table - (Employee Id. (Primary key), Name, Department, Age (check >18), Salary, City).
Display the total number of employees.
Retrieve all information of employees whose age is 22.
Fetch the employee id, name, and department, whose salary >= 50000.
Print the name of the employees and label the column as 'Full Name' for those employees whose department name is 'Finance' and age is 22.
Print the department names from the employee table without having the duplicates.
"""
-- Create Employee table
CREATE TABLE IF NOT EXISTS Employee (
  EmployeeId INT PRIMARY KEY,
  Name VARCHAR(100),
  Department VARCHAR(100),
  Age INT CHECK (Age > 18),
  Salary DECIMAL(10, 2),
  City VARCHAR(100)
);
-- Insert demo data into Employee table
INSERT INTO Employee (EmployeeId, Name, Department, Age, Salary, City) VALUES
(1, 'John Doe', 'Finance', 25, 60000, 'New York'),
(2, 'Jane Smith', 'HR', 30, 55000, 'Los Angeles'),
(3, 'Alice Johnson', 'IT', 28, 70000, 'Chicago'),
(4, 'Chris Lee', 'Finance', 22, 50000, 'Houston'),
(5, 'Emma Davis', 'Marketing', 35, 45000, 'Phoenix'),
(6, 'Michael Brown', 'Finance', 22, 52000, 'Philadelphia');

-- Display the total number of employees
SELECT COUNT(*) AS TotalEmployees FROM Employee;

-- Retrieve all information of employees whose age is 22
SELECT * FROM Employee WHERE Age = 22;

-- Fetch the employee id, name, and department, whose salary >= 50000
SELECT EmployeeId, Name, Department FROM Employee WHERE Salary >= 50000;

-- Print the name of the employees and label the column as 'Full Name' for those employees whose department name is 'Finance' and age is 22
SELECT Name AS 'Full Name' FROM Employee WHERE Department = 'Finance' AND Age = 22;

-- Print the department names from the employee table without having the duplicates
SELECT DISTINCT Department FROM Employee;