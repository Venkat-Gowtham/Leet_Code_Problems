# Write your MySQL query statement below
select e.employee_id , e.name ,count(*) as reports_count, round(avg(f.age)) as average_age
from employees e 
join 
employees f 
where e.employee_id = f.reports_to
group by e.employee_id
order by employee_id