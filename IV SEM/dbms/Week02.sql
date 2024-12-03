"""
Create a user and provide the GRANT privileges to the user on the database then REVOKE the given privileges.
Insert any five records in the previous schema and apply the rollback. Also check the results.
Add default, check, unique and not null constraints to the schema.
Insert NULL values and check the results.
Add duplicate value and try to make a column as primary key, check what happen to the table.
"""

-- Create a user and provide the GRANT privileges to the user on the database then REVOKE the given privileges.
CREATE USER 'dbms_user'@'localhost'
IDENTIFIED BY 'dbms_password';
GRANT ALL PRIVILEGES ON dbms.* TO 'dbms_user'@'localhost';
REVOKE ALL PRIVILEGES ON dbms.* FROM 'dbms_user'@'localhost';

-- Insert any five records in the previous schema and apply the rollback. Also check the results.
START TRANSACTION;
INSERT INTO Patient (Patient_ID, Ward_ID, Name, Age, Gender,
Admission_Date, Contact_Number) VALUES
(4, 1, 'Vikas', 45, 'Male', '2024-10-06', '9876543212'),
(5, 3, 'Meera', 28, 'Female', '2024-10-06', '9876543213'),
(6, 2, 'Raj', 32, 'Male', '2024-10-06', '9876543214'),
(7, 1, 'Pooja', 23, 'Female', '2024-10-06', '9876543215'),
(8, 3, 'Kabir', 36, 'Male', '2024-10-06', '9876543216');
ROLLBACK;
SELECT * FROM Patient WHERE Patient_ID >= 3;

-- Add default, check, unique and not null constraints to the schema.
ALTER TABLE Patient 
MODIFY Age INT NOT NULL,
ADD CONSTRAINT chk_age CHECK (Age > 0),
ADD CONSTRAINT unique_contact UNIQUE (Contact_Number),
MODIFY Gender VARCHAR(10) DEFAULT 'Unknown';

-- Insert NULL values and check the results.
INSERT INTO Patient (Patient_ID, Ward_ID, Name, Age, Gender, Admission_Date, Contact_Number)
VALUES (9, 1, 'Priya', NULL, NULL, '2024-10-06', NULL);

-- Add duplicate value and try to make a column as primary key, check what happens to the table.
INSERT INTO Patient (Patient_ID, Ward_ID, Name, Age, Gender,
Admission_Date, Contact_Number) VALUES (10, 2, 'Sohail', 29, 'Male', '2024-10-06', '9876543215');
ALTER TABLE Patient ADD PRIMARY KEY (Contact_Number);
