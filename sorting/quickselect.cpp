int quickselect(vi &nums, int k, int lb, int rb) {
  if (rb - lb == 1) return nums[lb];
  int pivot_idx = lb + rng() % (rb - lb);
  int pivot = nums[pivot_idx];
  swap(nums[lb], nums[pivot_idx]);
  int eq = lb, gr = lb + 1;
  for (int i = lb + 1; i < rb; ++i) {
    int ii = i;
    if (nums[ii] <= pivot) {
      swap(nums[gr], nums[ii]); ii = gr++;
    }
    if (nums[ii] < pivot) swap(nums[eq++], nums[ii]);
  }
  if (k < eq - lb) return quickselect(nums, k, lb, eq);
  if (k < gr - lb) return pivot;
  return quickselect(nums, k - (gr - lb), gr, rb);
}
