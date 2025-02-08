# Write your MySQL query statement below
with sub as (
       select 
       d.name as Department ,
       e.name as Employee,
       e.salary as salary,
       Dense_rank() over (Partition by e.departmentId order by salary desc) as rnk
       from Employee e 
       join department d on e.departmentId  = d.id
)


select Department , Employee,Salary 
from sub 
where rnk<=3


-- WITH cte AS (
--       SELECT 
--         d.name AS Department,
--         e.name AS Employee,
--         e.salary AS Salary,
--         DENSE_RANK() OVER (PARTITION BY e.departmentId  ORDER BY Salary DESC) AS rnk
--     FROM Employee e
--     JOIN Department d ON e.departmentId = d.id )

-- SELECT Department, Employee, Salary
-- FROM cte
-- WHERE rnk <=3