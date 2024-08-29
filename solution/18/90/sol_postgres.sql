-- 1890. The Latest Login in 2020
SELECT user_id, MAX(time_stamp) AS last_stamp
FROM Logins
WHERE time_stamp::date BETWEEN '2020-01-01' AND '2020-12-31'
GROUP BY user_id;