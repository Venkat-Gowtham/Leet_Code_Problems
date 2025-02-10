# Write your MySQL query statement below
select e.name as name , bonus
from employee e 
left JOIN bonus b 
on e.empId = b.empId
where bonus is null or bonus<1000

-- union
-- SELECT e.name, b.bonus
-- FROM employee e 
-- RIGHT JOIN bonus b ON e.empId = b.empId
-- WHERE b.bonus <= 1000;

-- 