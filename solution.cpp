#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol213;
using namespace std;

/*takeaways
  - DP
  - time complexity: O(n)
  - this is the same as question 198 only that you
    are considering two separate lists
    - nums[0..n-2]
      - you consider the house 0 but not the
        house n-1. Or you can assume there is
        no hosue n-1 at all.
    - nums[1..n-1]
      - you consider the house n-1 but not the
        house 0. Or you can assume there is
        no hosue 0 at all.
    - the answer is whoever has a larger amount
*/
int Solution::rob(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
    return 0;

  return max(_rob(nums, 0, n - 2), _rob(nums, 1, n - 1));
}

int Solution::_rob(vector<int> &nums, int start, int end)
{

  /* dp[i] max amount you can rob after considering house i
   - you might or might not rob the house i
     - if you don't rob it carries over dp[i-1]
     - if you rob it than it's dp[i-2] + nums[i]
     - you need to find which way will create a larger
       amount
  */

  int n = end - start + 1;
  auto dp = vector<int>(n);

  for (auto i = start; i <= end; i++)
    dp[i] = max(
        (i > start + 1 ? dp[i - 2] : 0) + nums[i],
        i > start ? dp[i - 1] : 0);

  auto result = dp[n - 1];

  return result;
}