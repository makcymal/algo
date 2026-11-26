from itertools import permutations, combinations, product, accumulate, groupby
permutations([1, 2, 3])
# [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]
permutations([1, 2, 3], 2)
# [(1, 2), (1, 3), (2, 1), (2, 3), (3, 1), (3, 2)]
combinations([1, 2, 3], 2)
# [(1, 2), (1, 3), (2, 3)]
product([1, 2, 3], repeat=2)
# [(1, 1), (1, 2), (1, 3), (2, 1), (2, 2), (2, 3), (3, 1), (3, 2), (3, 3)]
accumulate([1, 2, 3])
# [1, 3, 6]
accumulate([1, 2, 3], initial=10)
# [10, 11, 13, 16]
accumulate([1, -2, 3], max)
# [1, 1, 3]
groupby([1, 1, 2, 2])
# [[1, [1, 1]], [2, [2, 2]]]