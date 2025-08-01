select customer_number 
from Orders o
group by customer_number
order by count(*) desc
limit 1;