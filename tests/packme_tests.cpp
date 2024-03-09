#include "test.h"
#include "packme/packme.h"

#include <numeric>

namespace packme::test
{
  PACKME_TEST(czh)
  {
    // Number
    auto s1 = pack(63);
    PACKME_EXPECT_EQ(63, unpack<int>(s1))
    PACKME_EXPECT_EQ(s1.size(), 1)
    auto s2 = pack(-128);
    PACKME_EXPECT_EQ(-128, unpack<int>(s2))
    PACKME_EXPECT_EQ(s2.size(), 2)
    auto s3 = pack((std::numeric_limits<unsigned long long>::max)());
    PACKME_EXPECT_EQ((std::numeric_limits<unsigned long long>::max)(), unpack<unsigned long long>(s3))
    auto s4 = pack((std::numeric_limits<long long>::min)());
    PACKME_EXPECT_EQ((std::numeric_limits<long long>::min)(), unpack<long long>(s4))
    
    // Array and String
    auto s5 = pack<const char[20]>("PACK ME TEST STRING");
    PACKME_EXPECT_EQ(s5.size(), 20)
    auto chararray = unpack<const char[20]>(s5);
    PACKME_EXPECT_TRUE(strcmp("PACK ME TEST STRING", chararray) == 0)
    free(const_cast<char*>(chararray));
    
    s5 = pack(std::string{"PACK ME TEST STRING"});
    PACKME_EXPECT_EQ(s5.size(), 19)
    PACKME_EXPECT_EQ("PACK ME TEST STRING", unpack<std::string>(s5))
  
    // Trivially Copyable
    struct A {int a; double b;
      bool operator==(const A& a1) const
      {
        return a == a1.a && b == a1.b;
      }
    };
    static_assert(std::is_trivially_copyable_v<A>);
    A a{1, 2.0};
    auto s6 = pack(a);
    PACKME_EXPECT_EQ(a, unpack<A>(s6));

    // Aggregate Struct
    struct B {int a; std::string b; std::vector<int> c; std::map<std::string, int> d; A e;
      bool operator==(const B& b1) const
      {
        return a == b1.a && b == b1.b && c == b1.c && d == b1.d && e == b1.e;
      }};
    static_assert(std::is_aggregate_v<B>);
    B b{1, "2", std::vector<int>{3}, std::map<std::string, int>{{"4", 5}}, A{6, 7.0}};
    auto s7 = pack(b);
    PACKME_EXPECT_EQ(b, unpack<B>(s7))

    // Tuple Like
    auto tuple_like1 = std::make_tuple(b, a, 1, 2, 3.0, 4e31);
    auto tuple_like2 = std::make_pair(a, b);
    auto s8 = pack(tuple_like1);
    auto s9 = pack(tuple_like2);
    PACKME_EXPECT_EQ(tuple_like1, unpack<decltype(tuple_like1)>(s8))
    PACKME_EXPECT_EQ(tuple_like2, unpack<decltype(tuple_like2)>(s9))

    // Container
    std::vector<std::string> container1{"A", "B", "C"};
    class Container
    {
    public:
      using value_type = int;
    public:
      Container() = default;

      std::vector<int> c;

      auto begin() const { return c.begin(); }

      auto end() const  { return c.end(); }

      auto insert(typename std::vector<int>::const_iterator it, int i) { return c.insert(it, i); }
      bool operator==(const Container& b) const
      {
        return c == b.c;
      }
    };
    Container container2;
    container2.insert(container2.end(), 1);

    auto s10 = pack(container1);
    auto s11 = pack(container2);
    PACKME_EXPECT_EQ(container1, unpack<decltype(container1)>(s10))
    PACKME_EXPECT_EQ(container2, unpack<decltype(container2)>(s11))
  }
}

int main()
{
  auto &test = packme::test::get_test();
  int ret = test.run_tests();
  test.print_results();
  return ret;
}