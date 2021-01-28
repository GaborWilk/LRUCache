#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <iostream>
#include <list>
#include <stdexcept>
#include <unordered_map>


namespace lru {

/*
 LRUCache (Least Recently Used) implementation using C++17.
 It consists a linked list (to store the actual items) and a hashtable of pointers to the linked list nodes.
 As a result, this gives O(1) operations (assuming a decent hash function). The multithreaded version can be done easily,
 just lock the whole structure (granular locking is not needed).

 How does it work:
 On an access of a value, you move the corresponding node in the linked list to the head.
 When you need to remove a value from the cache, you remove from the tail end.
 When you add a value to cache, you just place it at the head of the linked list.
*/

template <typename Key, typename Value>
class LRUCache {
public:
  using KeyValuePair = typename std::pair<Key, Value>;
  using Iterator = typename std::list<KeyValuePair>::iterator;

  explicit LRUCache(uint32_t capacity = 10u) : capacity_(capacity) {}

  /* adds the given element to the front of the cache,
     or updates an existing one and places it to the front */
  void add(const Key& key, const Value& value) {
    cache_.push_front(KeyValuePair(key, value));
    auto it = dict_.find(key);
    if (it != dict_.end()) {
      cache_.erase(it->second);
      dict_.erase(it);
    }
    dict_[key] = cache_.begin();

    /* drop old element */
    if (dict_.size() > capacity_) {
      auto last = cache_.end();
      --last;
      dict_.erase(last->first);
      cache_.pop_back();
    }
  }

  /* returns the given element if found, otherwise throws exception */
  const Value& get(const Key& key) {
    auto it = dict_.find(key);
    /* element found */
    if (it != dict_.end()) {
      cache_.splice(cache_.begin(), cache_, it->second);
      return it->second->second;
    } else {
      /* element not found */
      throw std::range_error("Key not found in the cache.");
    }
  }

  /* checks whether the given element is in the cache */
  bool exist(const Key& key) const {
    return dict_.find(key) != dict_.end();
  }

  /* returns the number of elements of the cache */
  uint32_t size() const {
    return dict_.size();
  }

  /* returns the maximum number of elements that can be stored in the cache */
  uint32_t capacity() const {
    return capacity_;
  }

  /* clears the cache */
  void clear() {
    cache_.clear();
    dict_.clear();
  }

  /* prints the elements of the cache */
  void print() const {
    for (const auto& it : cache_) {
      std::cout << "[" << it.first << " - " << it.second << "]" << std::endl;
    }
  }

private:
  std::list<KeyValuePair> cache_;
  std::unordered_map<Key, Iterator> dict_;
  uint32_t capacity_;
};

} // namespace lru

#endif // end of LRU_dict_H
