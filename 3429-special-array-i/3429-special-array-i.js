/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isArraySpecial = function(nums) {
    
    var odd = nums[0]%2!=0;
   for (let i = 1; i < nums.length; i++) {
    if ((odd && nums[i] % 2 !== 0) || (!odd && nums[i] % 2 === 0)) {
            return false;
        }
        odd = !odd;
    }

    return true;
};