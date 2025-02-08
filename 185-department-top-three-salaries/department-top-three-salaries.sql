# Write your MySQL query statement below
with sub as (
        select * from 
    (
        select *, dense_rank() over (partition by departmentId order by salary desc ) as rnk
        from employee
    ) ranked
    where ranked.rnk <=3
)

select d.name as Department , sub.name as Employee, sub.salary as Salary from department d
inner join sub 
on d.id = sub.departmentId
-- on department.id = sub.departmentId

-- on employee.departmentId = department.id
-- order by departmentId
-- group by departmentId