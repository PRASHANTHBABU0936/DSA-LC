# Write your MySQL query statement below
select EmployeeUNI.unique_id,Employees.name from employees LEFT JOIN EmployeeUNI on Employees.id=EmployeeUNI.id