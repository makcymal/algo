int find_lis(vi &nums) {
  if (nums.size() <= 1) return nums.size();
  vi lis(1, nums.front());
  for (int i = 1; i < nums.size(); ++i) {
    auto ins = lower_bound(lis.begin(), lis.end(), nums[i]);
    if (ins == lis.end()) lis.push_back(nums[i]);
    else *ins = nums[i];
  }
  return lis.size();
}
