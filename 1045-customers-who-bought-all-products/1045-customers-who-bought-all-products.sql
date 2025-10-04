with temp as (select 
    customer_id,
    count(distinct product_key) as ct
from Customer
group by customer_id)

select customer_id 
from temp 
where ct = (select count(distinct product_key) from Product); 

