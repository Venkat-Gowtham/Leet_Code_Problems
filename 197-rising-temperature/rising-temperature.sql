# Write your MySQL query statement below
select distinct wt.id 
from Weather wt , Weather vt
where  datediff(wt.recordDate ,vt.recordDate )=1 and wt.temperature>vt.temperature 