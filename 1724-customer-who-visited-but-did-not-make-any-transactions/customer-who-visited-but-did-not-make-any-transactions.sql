# Write your MySQL query statement below
select customer_id,COUNT(*) as count_no_trans
from visits
left join Transactions
using (visit_id)
where transaction_id is NUll
group by customer_id;