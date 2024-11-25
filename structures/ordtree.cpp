#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Value = null_type for set
typedef __gnu_pbds::tree<Key, Value, less<Key>, __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update> Ordtree;
