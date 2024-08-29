-- 1757. Recyclable and Low Fat Products

-- Products table:
-- | product_id | low_fats | recyclable |
-- | ---------- | -------- | ---------- |
-- | 0          | Y        | N          |
-- | 1          | Y        | Y          |
-- | 2          | N        | Y          |
-- | 3          | Y        | Y          |
-- | 4          | N        | N          |

CREATE TABLE Products
(
    product_id INTEGER PRIMARY KEY,
    low_fats   TEXT,
    recyclable TEXT
);

INSERT INTO Products (product_id, low_fats, recyclable)
VALUES (0, 'Y', 'N'),
       (1, 'Y', 'Y'),
       (2, 'N', 'Y'),
       (3, 'Y', 'Y'),
       (4, 'N', 'N');

