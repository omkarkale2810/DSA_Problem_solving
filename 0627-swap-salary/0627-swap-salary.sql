# Write your MySQL query statement below

update Salary s 
set sex = case when sex = 'f' then 'm'
when sex = 'm' then 'f' 
end;