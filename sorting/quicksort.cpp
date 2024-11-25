void quicksort(vi &nums, int lb, int rb) {
  if (rb - lb <= 1) return;
  int pivot = lb + rng() % (rb - lb);
  int pivot_val = nums[pivot];
  swap(nums[lb], nums[pivot]);
  int eq = lb, gr = lb + 1;
  for (int i = lb + 1; i < rb; ++i) {
    int ii = i;
    if (nums[ii] <= pivot_val) {
      swap(nums[ii], nums[gr]); ii = gr++;
    }
    if (nums[ii] < pivot_val) wap(nums[ii], nums[eq++]);
  }
  quicksort(nums, lb, eq);
  quicksort(nums, gr, rb);
}
