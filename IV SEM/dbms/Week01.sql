"""
Create a Scenario based ER-Models with the entities. (Hospital Details like: Wards, Patients, Doctor, Bills etc).
Convert this ER-model into table with all the entities. (Minimum five Entities).
Insert random data in each column of all the tables
Update the table by applying some conditions.(For example: using alter command)
Apply the `DELETE` and `DROP` command, and then review the results.
"""
-- Create a Scenario based ER-Models with the entities. (Hospital Details like: Wards, Patients, Doctor, Bills etc).
-- Convert this ER-model into table with all the entities. (Minimum five Entities).
CREATE TABLE Hospital (
 Hospital_ID INT PRIMARY KEY,
 Name VARCHAR(50),
 Location VARCHAR(100)
);
CREATE TABLE Ward (
 Ward_ID INT PRIMARY KEY,
 Hospital_ID INT,
 Ward_Name VARCHAR(50),
 Capacity INT,
 FOREIGN KEY (Hospital_ID) REFERENCES Hospital(Hospital_ID)
);
CREATE TABLE Patient (
 Patient_ID INT PRIMARY KEY,
 Ward_ID INT,
 Name VARCHAR(50),
 Age INT,
 Gender VARCHAR(10),
 Admission_Date DATE,
 FOREIGN KEY (Ward_ID) REFERENCES Ward(Ward_ID)
);
CREATE TABLE Doctor (
 Doctor_ID INT PRIMARY KEY,
 Name VARCHAR(50),
 Specialty VARCHAR(50),
 Phone_Number VARCHAR(15)
);
CREATE TABLE Bill (
 Bill_ID INT PRIMARY KEY,
 Patient_ID INT,
 Total_Amount DECIMAL(10, 2),
 Payment_Status VARCHAR(20),
 FOREIGN KEY (Patient_ID) REFERENCES Patient(Patient_ID)
);
CREATE TABLE Doctor_Patient (
 Doctor_ID INT,
 Patient_ID INT,
 PRIMARY KEY (Doctor_ID, Patient_ID),
 FOREIGN KEY (Doctor_ID) REFERENCES Doctor(Doctor_ID),
 FOREIGN KEY (Patient_ID) REFERENCES Patient(Patient_ID)
);

-- Insert random data in each column of all the tables
INSERT INTO Hospital (Hospital_ID, Name, Location) VALUES
(1, 'Sunrise Hospital', 'Bangalore'),(2, 'Green Valley Hospital', 'Mumbai');
INSERT INTO Ward (Ward_ID, Hospital_ID, Ward_Name, Capacity) VALUES 
(1, 1, 'General Ward', 20), (2, 1, 'ICU', 5),(3, 2, 'Pediatric Ward', 15);
INSERT INTO Patient (Patient_ID, Ward_ID, Name, Age, Gender, Admission_Date) VALUES 
(1, 1, 'Aarav', 30, 'Male', '2024-10-01'),
(2, 2, 'Diya', 25, 'Female', '2024-10-03'), (3, 3, 'Kiran', 12, 'Male', '2024-10-04');
INSERT INTO Doctor (Doctor_ID, Name, Specialty, Phone_Number)VALUES 
(1, 'Dr. Anjali', 'Cardiologist', '9876543210'),(2, 'Dr. Ramesh', 'Pediatrician', '9876543211');
INSERT INTO Bill (Bill_ID, Patient_ID, Total_Amount, Payment_Status) VALUES 
(1, 1, 5000.00, 'Paid'),(2, 2, 15000.00, 'Pending'),(3, 3, 8000.00, 'Paid');
INSERT INTO Doctor_Patient (Doctor_ID, Patient_ID) VALUES (1, 1), (2, 3);

-- Update the table by applying some conditions.(For example: using alter command)
ALTER TABLE Patient ADD Contact_Number VARCHAR(15);
UPDATE Patient SET Contact_Number = '9998887776'
WHERE Patient_ID = 1;

-- Apply the `DELETE` and `DROP` command, and then review the results.
DELETE FROM bill WHERE Patient_ID = 2;
DROP TABLE Doctor_Patient;
