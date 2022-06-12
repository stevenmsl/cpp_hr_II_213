#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol213;

/* Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
*/
tuple<vector<int>, int>
testFixture1()
{
  auto input = vector<int>{2, 3, 2};
  return make_tuple(input, 3);
}

/* Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

*/
tuple<vector<int>, int>
testFixture2()
{
  auto input = vector<int>{1, 2, 3, 1};
  return make_tuple(input, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.rob(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.rob(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}