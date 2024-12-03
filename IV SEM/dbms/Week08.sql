"""
Create the table to keep track of customer records and their order.
Customer table - (Name as Not null, Customer_id as primary key, Age, Address)
Order table - (Customer_id, order_id, date).
Apply the full join and the full outer join to the schema and review the results.
Display the name of the city as 'destination' for customers who have placed orders.
Apply the cross join and check the results.
Display the customer names and order IDs for customers who have placed orders from the same city.
"""

-- Create the table to keep track of customer records and their order.
-- Customer table - (Name as Not null, Customer_id as primary key, Age, Address)
-- Order table - (Customer_id, order_id, date).
CREATE TABLE Customers (
  Name VARCHAR(100) NOT NULL,
  CustomerID INT PRIMARY KEY,
  Age INT,
  Address VARCHAR(100)
);

CREATE TABLE Orders (
  CustomerID INT,
  OrderID INT,
  Date DATE
);

  INSERT INTO Customers (Name, CustomerID, Age, Address) VALUES
  ('Alice', 1, 25, 'New York'), ('Bob', 2, 35, 'Los Angeles'),
  ('Charlie', 3, 28, 'Chicago'), ('David', 4, 22, 'New York'), ('Eve', 5, 32, 'Los Angeles');

  INSERT INTO Orders (CustomerID, OrderID, Date) VALUES
  (1, 101, '2023-01-01'), (2, 102, '2023-01-02'), (3, 103, '2023-01-03'), 
  (3, 103, '2023-01-03'), (4, 104, '2023-01-04'), (5, 105, '2023-01-05');

-- Apply the full join and the full outer join to the schema and review the results.
SELECT * FROM Customers c FULL JOIN Orders o ON c.CustomerID = o.CustomerID;

-- Display the name of the city as 'destination' for customers who have placed orders.
SELECT c.Name, c.Address AS Destination, o.OrderID FROM Customers c JOIN Orders o ON c.CustomerID = o.CustomerID;

-- Apply the cross join and check the results.
SELECT * FROM Customers CROSS JOIN Orders;

-- Display the customer names and order IDs for customers who have placed orders from the same city.
SELECT c.Name, o.OrderID FROM Customers c JOIN Orders o ON c.CustomerID = o.CustomerID
WHERE c.Address IN (SELECT Address FROM Customers GROUP BY Address HAVING COUNT(*) > 1);
