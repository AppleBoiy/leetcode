"""
1890. The Latest Login in 2020

Input:
    Logins table:
    +---------+---------------------+
    | user_id | time_stamp          |
    +---------+---------------------+
    | 6       | 2020-06-30 15:06:07 |
    | 6       | 2021-04-21 14:06:06 |
    | 6       | 2019-03-07 00:18:15 |
    | 8       | 2020-02-01 05:10:53 |
    | 8       | 2020-12-30 00:46:50 |
    | 2       | 2020-01-16 02:49:50 |
    | 2       | 2019-08-25 07:59:08 |
    | 14      | 2019-07-14 09:00:00 |
    | 14      | 2021-01-06 11:59:59 |
    +---------+---------------------+
Output:
    +---------+---------------------+
    | user_id | last_stamp          |
    +---------+---------------------+
    | 2       | 2020-01-16 02:49:50 |
    | 6       | 2020-06-30 15:06:07 |
    | 8       | 2020-12-30 00:46:50 |
    +---------+---------------------+
Explanation:
    User 6 logged into their account 3 times but only once in 2020, so we include this login in the result table.
    User 8 logged into their account 2 times in 2020, once in February and once in December.
    We include only the latest one (December) in the result table.
    User 2 logged into their account 2 times but only once in 2020, so we include this login in the result table.
    User 14 did not login in 2020, so we do not include them in the result table.
"""

import pandas as pd


def latest_login(logins: pd.DataFrame) -> pd.DataFrame:
    df_2020 = logins[logins['time_stamp'].dt.year == 2020]
    return (
        df_2020
        .groupby('user_id', as_index=False)['time_stamp']
        .max()
        .rename(columns={'time_stamp': 'last_stamp'})
    )


if __name__ == '__main__':
    data = {
        'user_id': [6, 6, 6, 8, 8, 2, 2, 14, 14],
        'time_stamp': map(pd.Timestamp, [
            '2020-06-30 15:06:07', '2021-04-21 14:06:06', '2019-03-07 00:18:15',
            '2020-02-01 05:10:53', '2020-12-30 00:46:50', '2020-01-16 02:49:50',
            '2019-08-25 07:59:08', '2019-07-14 09:00:00', '2021-01-06 11:59:59'
        ])
    }

    _logins = pd.DataFrame(data)
    print(latest_login(_logins))
