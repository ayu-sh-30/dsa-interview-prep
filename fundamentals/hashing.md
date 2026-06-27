# HashMap & HashSet in C++ — Quick Revision

---

## HashMap → `unordered_map`
`#include <unordered_map>`

### Declaration
```cpp
unordered_map<KeyType, ValueType> mp;
unordered_map<string, int> mp;
```

### Core Operations
```cpp
mp[key] = val;           // insert / update (creates key if missing!)
mp.at(key);              // access (throws if key missing)
mp.insert({key, val});   // insert pair

mp.erase(key);           // delete by key
mp.clear();              // remove all

mp.count(key);           // 1 if exists, 0 if not  ← preferred existence check
mp.find(key) != mp.end() // alternative existence check

mp.size();
mp.empty();
```

### Iteration
```cpp
// 1. Range-based for (most common)
for (auto& [key, val] : mp)
    cout << key << " → " << val << "\n";

// 2. Using 'pair' (older style)
for (auto& p : mp)
    cout << p.first << " → " << p.second << "\n";

// 3. Iterator
for (auto it = mp.begin(); it != mp.end(); it++)
    cout << it->first << " → " << it->second << "\n";

// 4. Keys only
for (auto& [key, val] : mp)
    cout << key << "\n";

// 5. Values only
for (auto& [key, val] : mp)
    cout << val << "\n";
```

### Common Patterns
```cpp
// Frequency count
for (int x : nums) freq[x]++;

//check duplicacy
for(int x : nums){
    seen[x] return true;
    seen[x] = true;
}

// Two Sum
mp[nums[i]] = i;
if (mp.count(target - nums[i])) ...
```

---

## HashSet → `unordered_set`
`#include <unordered_set>`

Stores **unique keys only** — no values.

### Declaration
```cpp
unordered_set<int> st;
unordered_set<string> st;
```

### Core Operations
```cpp
st.insert(val);           // add element
st.erase(val);            // remove element
st.clear();               // remove all

st.count(val);            // 1 if exists, 0 if not
st.find(val) != st.end(); // alternative existence check

st.size();
st.empty();
```

### Iteration
```cpp
for (auto& x : st)
    cout << x;
```

### Common Patterns
```cpp
// Remove duplicates from vector
unordered_set<int> st(v.begin(), v.end());

// Check duplicates
if (!st.insert(x).second) cout << "duplicate!";

// Check if element seen before
if (st.count(x)) ...
st.insert(x);
```

---

## unordered vs ordered — Quick Comparison

| Feature        | `unordered_map/set`  | `map/set`         |
|----------------|----------------------|-------------------|
| Ordering       | ❌ No order          | ✅ Sorted by key  |
| Lookup         | O(1) avg             | O(log n)          |
| Worst case     | O(n) (collision)     | O(log n)          |
| Use when       | Speed matters        | Sorted order needed |

---

## Key Reminders
- `mp[key]` **creates** the key with default value if not present — use `count()` to check first
- `unordered_*` has no guaranteed order — use `map/set` if order matters
- Both have **O(1) avg** insert, delete, lookup
- `unordered_set` = HashMap with only keys, no values