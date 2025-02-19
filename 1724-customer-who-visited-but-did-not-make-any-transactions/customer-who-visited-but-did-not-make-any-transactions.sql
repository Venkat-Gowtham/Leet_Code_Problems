# Write your MySQL query statement below
select customer_id , count(*) as count_no_trans
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.visit_id is null
group by customer_id



-- select branch , count(branch)
-- from college
-- join college2

-- students
-- student_id , name
-- 1 divya
-- 2 nandini
-- 3 gowtham

-- parents
-- student_id,parent_name
-- 1 tulasi
-- 2 gowtam
-- 3 tualsi
-- 6 sindhu  grgiej



-- student_id,name,student_id,parent_name
-- 1          divya      1        tulasi
-- 2          nandini    2        gowtham
-- 3          gowtham    3        tulasi
-- 4           hars      null     null 
-- null        null      5         pr4mny 






