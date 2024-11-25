void radixsort(vi &nums) {
  if (nums.size() <= 1) return;
  int max_rank = 1;
  for (int num : nums) max_rank = max(max_rank, (int)ceil(log10(abs(num) + 1)));
  vi sorted(nums.size());
  for (int rank = 0, power = 1; rank < max_rank; ++rank, power *= 10) {
    vi digit_count(10, 0);
    for (int num : nums) {
      int digit = (num / power) % 10; digit_count[digit] += 1;
    }
    for (int i = 0, digit_count_accum = 0; i < 10; ++i) {
      int tmp = digit_count[i];
      digit_count[i] = digit_count_accum;
      digit_count_accum += tmp;
    }
    for (int num : nums) {
      int digit = (num / power) % 10;
      sorted[digit_count[digit]] = num;
      digit_count[digit]++;
    }
    nums = sorted;
  }
}
