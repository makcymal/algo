from heapq import heapify, heappush, heappop
def heap_example():
  heap = [(5, "b"), (2, "a")]
  heapify(heap)   # min-heap
  heappush(heap, (1, "c"))
  priority, value = heappop(heap)
  return priority, value  # (1, "c")