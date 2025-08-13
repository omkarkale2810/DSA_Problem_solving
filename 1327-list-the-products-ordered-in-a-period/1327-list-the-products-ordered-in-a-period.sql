# Write your MySQL query statement below
select product_name, sum(unit) as unit         
from Products p
join Orders o
on p.product_id = o.product_id
where month(order_date) = 2 AND year(order_date) = 2020
group by product_name
having unit >= 100;
