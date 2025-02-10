# Write your MySQL query statement below
with first as (select * from activity 
where activity_type = "start"
order by machine_id , process_id,timestamp),
second as (select * from activity 
where activity_type = "end"
order by machine_id , process_id,timestamp)


select first.machine_id ,round(avg(second.timestamp-first.timestamp),3) as processing_time
from first
join second
on first.machine_id = second.machine_id and first.process_id = second.process_id
group by first.machine_id
