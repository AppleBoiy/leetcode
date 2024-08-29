/**
 * @param {number[]} ratings
 * @return {number}
 */
const candy = (ratings) => {
    let n = ratings.length;
    let left = new Array(n).fill(1);
    let right = new Array(n).fill(1);
    let candies = 0;
    for (let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
    }
    for (let i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }
    for (let i = 0; i < n; i++) {
        candies += Math.max(left[i], right[i]);
    }
    return candies;
};