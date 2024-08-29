-- 584. Find Customer Referee

-- Customer table:
-- +----+------+------------+
-- | id | name | referee_id |
-- +----+------+------------+
-- | 1  | Will | null       |
-- | 2  | Jane | null       |
-- | 3  | Alex | 2          |
-- | 4  | Bill | null       |
-- | 5  | Zack | 1          |
-- | 6  | Mark | 2          |
-- +----+------+------------+

CREATE TABLE Customer
(
    id         INTEGER PRIMARY KEY,
    name       TEXT,
    referee_id INTEGER
);

INSERT INTO Customer (id, name, referee_id)
VALUES (1, 'Will', NULL),
       (2, 'Jane', NULL),
       (3, 'Alex', 2),
       (4, 'Bill', NULL),
       (5, 'Zack', 1),
       (6, 'Mark', 2);
