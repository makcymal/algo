int lower_bound(vi &nums, int target) {
  int lb = 0, rb = nums.size();
  while (lb < rb) {
    int md = lb + (rb - lb) / 2;
    if (nums[md] < target) lb = md + 1;  // <= for upper_bound
    else rb = md;
  }
  return lb;
}
