"""
Find out the maximum and minimum salary from the employee table.
Show the total salary and average salary of all the employees.
Show all the details of the employees who have the same salary.
Display the employees name from lowest salary to the highest salary.
Display the employee name and salary (department-wise) for employees, whose salary is greater than or equal to 10,000 and age is greater than 25.
"""
-- Find out the maximum and minimum salary from the employee table.
SELECT MAX(salary) AS max_salary, MIN(salary) AS min_salary FROM employee;

-- Show the total salary and average salary of all the employees.
SELECT SUM(salary) AS total_salary, AVG(salary) AS average_salary FROM employee;

-- Show all the details of the employees who have the same salary.
Insert into employee (EmployeeId, name, department, salary, age, city) 
values (7, 'John Foe', 'HR', 60000, 30, "New York");
SELECT salary, COUNT(salary) AS salary_count FROM employee GROUP BY salary HAVING COUNT(salary) > 1;

-- Display the employees name from lowest salary to the highest salary.
SELECT name FROM employee ORDER BY salary ASC;

-- Display the employee name and salary (department-wise) for employees, whose salary is greater than or equal to 10,000 and age is greater than 25.
SELECT department, name, salary FROM employee
WHERE salary >= 10000 AND age > 25 ORDER BY department, salary;