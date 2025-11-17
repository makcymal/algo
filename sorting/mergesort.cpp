void mergesort(vi &nums, vi &buff, int lb, int rb) {
  if (rb - lb <= 1) return;
  int md = lb + (rb - lb) / 2;
  mergesort(nums, buff, lb, md);
  mergesort(nums, buff, md, rb);
  copy(nums.begin() + lb, nums.begin() + md, buff.begin() + lb);
  auto lhs = buff.begin() + lb, lhs_end = buff.begin() + md;
  auto rhs = nums.begin() + md, rhs_end = nums.begin() + rb;
  auto target = nums.begin() + lb;
  while (lhs != lhs_end or rhs != rhs_end) {
    if (lhs == lhs_end) *target = *(rhs++);
    else if (rhs == rhs_end) *target = *(lhs++);
    else if (*lhs <= *rhs) *target = *(lhs++);
    else *target = *(rhs++);
    target++;
  }
}
