#define CATCH_CONFIG_MAIN  // This tells Catch2 to provide a main() - only do this in one cpp file

#include <catch.hpp>
#include <LRUCache.h>

constexpr uint32_t TEST_CAPACITY = 100u;
constexpr uint32_t NUM_OF_ELEMENTS_WITHIN = TEST_CAPACITY;
constexpr uint32_t NUM_OF_ELEMENTS_OUTSIDE = TEST_CAPACITY * 2;

TEST_CASE("Simple element", "[simple element]") {
  lru::LRUCache<int, int> cache(1u);
  cache.add(1, 10);

  REQUIRE(cache.exist(1));
}

TEST_CASE("Not existing element", "[not existing]") {
  lru::LRUCache<int, int> cache(1u);
  cache.add(1, 10);

  REQUIRE_FALSE(cache.exist(2));
}

TEST_CASE("Get not existing element", "[cannot get element]") {
  lru::LRUCache<int, int> cache(1u);
  cache.add(1, 10);

  REQUIRE_THROWS(cache.get(2));
}

TEST_CASE("Size of cache", "[cache size]") {
  lru::LRUCache<int, int> cache(3u);
  cache.add(7, 77);

  REQUIRE(cache.size() == 1u);
}

TEST_CASE("Capacity of cache", "[cache capacity]") {
  lru::LRUCache<int, int> cache(3u);

  REQUIRE(cache.capacity() == 3u);
}

TEST_CASE("Multiple elements within capacity", "[multiple elements within]") {
  lru::LRUCache<int, int> cache(TEST_CAPACITY);

  for (uint32_t i = 0u; i < NUM_OF_ELEMENTS_WITHIN; ++i) {
    cache.add(i, i * 10);
  }

  SECTION("Testing elements within capacity") {
    for (uint32_t i = 0u; i < NUM_OF_ELEMENTS_WITHIN; ++i) {
      CHECK(cache.exist(i));
    }
  }
}

TEST_CASE("Multiple elements outside capacity", "[multiple elements outside]") {
  lru::LRUCache<int, int> cache(TEST_CAPACITY);

  for (uint32_t i = 0u; i < NUM_OF_ELEMENTS_OUTSIDE; ++i) {
    cache.add(i, i * 10);
  }

  SECTION("Testing elements outside capacity") {
    for (uint32_t i = 0u; i < NUM_OF_ELEMENTS_WITHIN; ++i) {
      CHECK_FALSE(cache.exist(i));
    }
  }
}
