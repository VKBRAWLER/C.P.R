"""
Fetch the information of employee who belong to the city 'Delhi' or 'Pune.'
Print the name and department of employee whose ID is in the range from 2001 to 2005.
Show the names of employee who belong to the same city (use the IN operator).
Check whether the all employee is belongs to the same city or not. (use ALL operator)
Check whether the all employee is belongs to the same city or not. (use ANY operator)
Check whether the all employee is belongs to the same city or not. (use Exists operator)
"""
-- Insert Demo data to demonstrate the given queries.
Truncate table employee;
Insert into employee (EmployeeId, name, city, department) VALUES 
(2001, 'Rahul', 'Delhi', 'IT'), (2002, 'Rohit', 'Pune', 'HR'),
(2003, 'Raj', 'Delhi', 'IT'), (2004, 'Ravi', 'Pune', 'HR'),
(2005, 'Rahul', 'Delhi', 'IT'), (2006, 'Rohit', 'Pune', 'HR'),
(2007, 'Raj', 'Delhi', 'IT'), (2008, 'Ravi', 'Pune', 'HR');       


-- Fetch the information of employee who belong to the city 'Delhi' or 'Pune.'
SELECT * FROM employee WHERE city IN ('Delhi', 'Pune');

-- Print the name and department of employee whose ID is in the range from 2001 to 2005.
SELECT name, department FROM employee WHERE EmployeeId BETWEEN 2001 AND 2005;

-- Show the names of employee who belong to the same city (use the IN operator).
SELECT name FROM employee WHERE city IN (SELECT city FROM employee);

-- Check whether all employees belong to the same city or not. (use ALL operator)
  SELECT city FROM employee WHERE city = ALL (SELECT city FROM employee);

-- Check whether any employee belongs to the same city or not. (use ANY operator)
SELECT city FROM employee WHERE city = ANY (SELECT city FROM employee);

-- Check whether any employee belongs to the same city or not. (use EXISTS operator)
SELECT city FROM employee WHERE EXISTS (SELECT city FROM employee WHERE employee.city = city);