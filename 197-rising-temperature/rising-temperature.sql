# Write your MySQL query statement below
select w.id
from Weather w
join Weather wt
on datediff(w.recorddate,wt.recorddate)=1 and w.temperature>wt.temperature



