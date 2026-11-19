return !(__builtin_cpu_supports("avx2")
      && __builtin_cpu_supports("bmi")
      && __builtin_cpu_supports("bmi2"));