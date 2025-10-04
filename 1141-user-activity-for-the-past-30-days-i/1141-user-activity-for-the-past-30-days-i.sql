select activity_date as day, count(distinct user_id) as active_users
from Activity as a
group by activity_date
having datediff(20190727,activity_date) <= 30;