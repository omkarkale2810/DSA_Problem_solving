# Write your MySQL query statement below

-- select max(num) from (select num
-- from MyNumbers
-- group by num
-- having count(*) = 1) ;


with temp as (select num
from MyNumbers
group by num
having count(*) = 1)

select max(num) as num from temp;