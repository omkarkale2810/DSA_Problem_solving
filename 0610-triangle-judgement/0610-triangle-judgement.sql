select x, y, z, if(x+y>z and y+z>x and z+x>y, "Yes", "No") as triangle from Triangle

-- select *, case when x + y > z and y + z > x and x + z > y then 'Yes'
-- else 'No' end as triangle
-- from triangle;