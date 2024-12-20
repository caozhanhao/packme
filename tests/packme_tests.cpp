#include "test.h"
#include "packme/packme.h"

#include <numeric>

namespace packme::test
{
  PACKME_TEST(czh)
  {
    // Number
    std::string str;
    str = pack<uint32_t>(64);
    PACKME_EXPECT_EQ(64, unpack<uint32_t>(str))
    PACKME_EXPECT_EQ(str.size(), 1)
    str = pack(-128);
    PACKME_EXPECT_EQ(-128, unpack<int>(str))
    PACKME_EXPECT_EQ(str.size(), 2)
    str = pack((std::numeric_limits<unsigned long long>::max)());
    PACKME_EXPECT_EQ((std::numeric_limits<unsigned long long>::max)(), unpack<unsigned long long>(str))
    str = pack((std::numeric_limits<long long>::min)());
    PACKME_EXPECT_EQ((std::numeric_limits<long long>::min)(), unpack<long long>(str))

    auto num_test = []<typename T>()
        {
          std::random_device rd;
          std::mt19937 gen(rd());
          for(int i = 0; i < 1024; ++i)
          {
            std::uniform_int_distribution<T> u((std::numeric_limits<T>::min)(),(std::numeric_limits<T>::max)());
            auto num = u(gen);
            auto s = pack(num);
            PACKME_EXPECT_EQ(unpack<T>(s), num);
          }
        };
    num_test.operator()<int16_t>();
    num_test.operator()<uint16_t>();
    num_test.operator()<int32_t>();
    num_test.operator()<uint32_t>();
    num_test.operator()<int64_t>();
    num_test.operator()<uint64_t>();
  
    // Enum
    
    enum class E
    {
      A, B, C, D
    };
    
    str = pack<E>(E::A);
    PACKME_EXPECT_EQ(unpack<E>(str), E::A);
    str = pack<E>(E::C);
    PACKME_EXPECT_EQ(unpack<E>(str), E::C)
    
    // Array and String
    str = pack<char[20]>("PACK ME TEST STRING");
    PACKME_EXPECT_EQ(str.size(), 20)
    auto chararray = unpack<char[20]>(str);
    PACKME_EXPECT_TRUE(strcmp("PACK ME TEST STRING", chararray) == 0)
    delete[] chararray;
  
    str = pack(std::string{"PACK ME TEST STRING"});
    PACKME_EXPECT_EQ(str.size(), 19)
    PACKME_EXPECT_EQ("PACK ME TEST STRING", unpack<std::string>(str))
    
    // Trivially Copyable
    struct A {
      int a; double b;
      bool operator==(const A& a1) const
      {
        return a == a1.a && b == a1.b;
      }
    };
    static_assert(std::is_trivially_copyable_v<A>);
    A a{1, 2.0};
    str = pack(a);
    PACKME_EXPECT_EQ(a, unpack<A>(str));

    // Aggregate Struct
    struct B {
      int a; std::string b; std::vector<int> c; std::map<std::string, int> d; A e;
      bool operator==(const B& b1) const
      {
        return a == b1.a && b == b1.b && c == b1.c && d == b1.d && e == b1.e;
      }};
    static_assert(std::is_aggregate_v<B>);
    B b{1, "2", std::vector<int>{3}, std::map<std::string, int>{{"4", 5}}, A{6, 7.0}};
    str = pack(b);
    PACKME_EXPECT_EQ(b, unpack<B>(str))
  
    // Custom Type
    class C
    {
    private:
      int a;
      std::string b;
      double* c;
    public:
      explicit C(std::string b_): a(128), b(std::move(b_)), c(new double(3.14)) { }
      ~C()
      {
        delete c;
        c= nullptr;
      }
      bool operator==(const C& c1) const
      {
        return a == c1.a && b == c1.b && *c == *c1.c;
      }
      PACKME_FIELDS(C, a, b, c)
    };
    static_assert(!std::is_aggregate_v<C>);
    C c("packme");
    str = pack(c);
    PACKME_EXPECT_EQ(c, unpack<C>(str))

    // Tuple Like
    auto tuple_like1 = std::make_tuple(a, b, 1, 2, 3.0, 4e31);
    auto tuple_like2 = std::make_pair(a, b);
    str = pack(tuple_like1);
    PACKME_EXPECT_EQ(tuple_like1, unpack<decltype(tuple_like1)>(str))
    str = pack(tuple_like2);
    PACKME_EXPECT_EQ(tuple_like2, unpack<decltype(tuple_like2)>(str))

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
  
    str = pack(container1);
    PACKME_EXPECT_EQ(container1, unpack<std::vector<std::string>>(str))
    str = pack(container2);
    PACKME_EXPECT_EQ(container2, unpack<Container>(str))
  }
}

int main()
{
  auto &test = packme::test::get_test();
  int ret = test.run_tests();
  test.print_results();
  return ret;
}