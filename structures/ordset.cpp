#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Value = null_type for set
typedef tree<Key, Value, Cmp, rb_tree_tag, tree_order_statistics_node_update> ordset;
