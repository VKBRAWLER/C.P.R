"""
Show the record of employees who are working in the 'CSE' department.
Fetch the names of employees whose names start with the letters 'ay'.
Fetch the information of employees, including their names and departments, whose names end with the letters 'sh'.
Display the employee names and their departments of employees, whose city name starts with 'D' or ends with 'h'.
Print all records of employees whose salary is greater than 15,000 and whose name starts with 'h'.
Print the names of employees whose names consist of exactly three letters.
Print the names of employees along with their city for those whose names have at least five letters.
"""
-- Show the record of employees who are working in the 'CSE' department.
Truncate table employee;
Insert into employee (EmployeeId, name, city, department) VALUES 
(2001, 'Ayush', 'Delhi', 'CSE'), (2002, 'Ayan', 'Pune', 'ECE'),
(2003, 'Harsh', 'Mumbai', 'CSE'), (2004, 'Ravi', 'Delhi', 'ME'),
(2005, 'Kish', 'Pune', 'CSE'), (2006, 'John', 'Delhi', 'CSE'),
(2007, 'Hitesh', 'Delhi', 'CSE'), (2008, 'Rohit', 'Pune', 'ECE'),
(2009, 'Ayesha', 'Mumbai', 'CSE'), (2010, 'Dinesh', 'Delhi', 'ME');
SELECT * FROM employee WHERE department = 'CSE';

-- Fetch the names of employees whose names start with the letters 'ay'.
SELECT name FROM employee WHERE name LIKE 'ay%';

-- Fetch the information of employee, including their names and departments, whose names end with the letters 'sh'.
SELECT name, department FROM employee WHERE name LIKE '%sh';

-- Display the employee names and their departments of employee, whose city name starts with 'D' or ends with 'h'.
SELECT name, department FROM employee WHERE city LIKE 'D%' OR city LIKE '%h';

-- Print all records of employee whose salary is greater than 15,000 and whose name starts with 'h'.
SELECT * FROM employee WHERE salary > 15000 AND name LIKE 'h%';

-- Print the names of employee whose names consist of exactly three letters.
SELECT name FROM employee WHERE LENGTH(name) = 3;

-- Print the names of employee along with their city for those whose names have at least five letters.
SELECT name, city FROM employee WHERE LENGTH(name) >= 5;