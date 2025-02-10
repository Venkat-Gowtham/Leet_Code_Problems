# Write your MySQL query statement below
-- select * from employee e
-- join employee f
-- on e.employee_id = f.employee_id and e.department_id = f.department_id

-- SELECT * FROM EMPLOYEE GROUP BY employee_id;
select employee_id , department_id from employee e
where primary_flag = 'Y' or employee_id in  (select employee_id from employee group by employee_id having count(employee_id)=1  )








