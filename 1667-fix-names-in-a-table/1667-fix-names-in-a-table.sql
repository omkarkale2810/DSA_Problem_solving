select user_id, concat(upper(substring(u.name, 1, 1)) ,lower(substring(u.name, 2, length(u.name)))) as name
from Users u
order by u.user_id;