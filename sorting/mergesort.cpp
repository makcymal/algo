void mergesort(vi &nums, vi &buff, int lb, int rb) {
  if (rb - lb <= 1) return;
  int md = lb + (rb - lb) / 2;
  mergesort(nums, buff, lb, md);
  mergesort(nums, buff, md, rb);
  copy(nums.BEG + lb, nums.BEG + md, buff.BEG + lb);
  auto lhs = buff.BEG + lb, lhs_end = buff.BEG + md;
  auto rhs = nums.BEG + md, rhs_end = nums.BEG + rb;
  auto target = nums.BEG + lb;
  while (lhs != lhs_end or rhs != rhs_end) {
    if (lhs == lhs_end) *target = *(rhs++);
    else if (rhs == rhs_end) *target = *(lhs++);
    else if (*lhs <= *rhs) *target = *(lhs++);
    else *target = *(rhs++);
    target++;
  }
}
