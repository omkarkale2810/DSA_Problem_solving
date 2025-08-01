# Write your MySQL query statement below

with temp as (select class, count(*) as no 
from Courses c 
group by class)

select class from temp where no >= 5;