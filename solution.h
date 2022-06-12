#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;
namespace sol213
{

  class Solution
  {
  private:
    int _rob(vector<int> &nums, int start, int end);

  public:
    int rob(vector<int> &nums);
  };
}
#endif