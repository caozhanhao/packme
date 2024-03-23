// MIT License
//
// Copyright (c) 2024 caozhanhao
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#ifndef PACKME_TEST_HPP
#define PACKME_TEST_HPP
#pragma once

#include "packme/packme.h"
#include <random>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <functional>
#include <chrono>
#include <type_traits>
#include <source_location>

#define _PACKME_STRINGFY(x) #x
#define PACKME_STRINGFY(x) _PACKME_STRINGFY(x)

#define PACKME_EXPECT_EQ(v1, v2)  ::packme::test::get_test().expect_eq(v1, v2); 
#define PACKME_EXPECT_TRUE(v1) ::packme::test::get_test().expect_eq(v1, true); 
#define PACKME_EXPECT_FALSE(v1) ::packme::test::get_test().expect_eq(v1, false);
#define PACKME_TEST(name) \
void packme_test_##name(); \
size_t packme_test_pos_##name = ::packme::test::get_test().add(PACKME_STRINGFY(name), packme_test_##name); \
void packme_test_##name()

namespace packme::test
{
  std::string location_to_str(const std::source_location &l)
  {
    return std::string(l.file_name()) + ":" + std::to_string(l.line()) +
           ":" + l.function_name() + "()";
  }
  class Error : public std::logic_error
  {
  private:
    std::string detail;

  public:
    Error(const std::string &detail_, const std::source_location &l =
    std::source_location::current())
        : logic_error("\033[0;32;31mError: \033[1;37m" + location_to_str(l) + ":\033[m " + detail_),
          detail(detail_) {}
  
    [[nodiscard]] std::string get_content() const
    {
      return what();
    }
  
    [[nodiscard]] std::string get_detail() const
    {
      return detail;
    }
  
    //For Unit Test
    bool operator==(const Error &e) const
    {
      return detail == e.detail;
    }
  };
    
    class UnitTestError
    {
    private:
      std::string test_location;
      std::string content;

    public:
      UnitTestError(const Error &err, const std::source_location &l =
      std::source_location::current())
          : content(err.get_content()), test_location(location_to_str(l)) {}
  
      const std::string &get_content() const { return content; }
  
      const std::string &get_location() const { return test_location; }
    };
  
  class Test;
  
  Test &get_test();
  
  class Timer
  {
  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> beg;
  public:
    void start()
    {
      beg = std::chrono::high_resolution_clock::now();
    }
    
    [[nodiscard]] auto get_microseconds() const
    {
      return std::chrono::duration_cast<std::chrono::microseconds>
          (std::chrono::high_resolution_clock::now() - beg).count();
    }
  };
  
  template<typename T>
  T random_digit(T a, T b)//[a,b]
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dis{a, b};
    return dis(gen);
  }
  
  char randichar(int a, int b)//[a,b]
  {
    return static_cast<char>(static_cast<char>(random_digit(a, b)) + '0');
  }
  
  std::string rand_digit_str(size_t n)
  {
    if (n == 0)return "";
    std::string num;
    num += randichar(1, 9);
    for (size_t i = 1; i < n; ++i)
    {
      num += randichar(0, 9);
    }
    return num;
  }
  
  template<typename T>
  std::string to_str(T &&a)
  {
    if constexpr(std::is_same_v<std::string, std::remove_cvref_t<T>>
    || (std::is_array_v<T>
            && std::is_same_v<char, std::remove_cvref_t<std::remove_all_extents_t<T>>>))
    {
      return a;
    }
    else if constexpr(std::is_same_v<char, std::remove_cvref_t<T>>)
    {
      return std::string(1, a);
    }
    else if constexpr(details::is_container_v<std::remove_cvref_t<T>>)
    {
      std::string ret = "{";
      for(auto& r : a)
      {
        ret += to_str(r);
        ret += ", ";
      }
      if(ret != "{")
      {
        ret.pop_back();
        ret.pop_back();
      }
      ret += "}";
      return ret;
    }
    else if constexpr(details::is_serializable_tuple_like_v<std::remove_cvref_t<T>>)
    {
      std::string ret = "{";
      details::field_for_each(a, [&ret](auto&& item){
        ret += to_str(item);
        ret += ", ";
      });
      if(ret != "{")
      {
        ret.pop_back();
        ret.pop_back();
      }
      ret += "}";
      return ret;
    }
    else if constexpr(std::is_integral_v<std::remove_cvref_t<T>> || std::is_floating_point_v<std::remove_cvref_t<T>>)
    {
      return std::to_string(std::forward<T>(a));
    }
    return "CZH_PACKME_TO_STRING_FAILED";
  }
  
  class Test
  {
  private:
    std::vector<std::pair<std::string, std::function<void()>>> all_tests;
    std::vector<size_t> exceptions;
    std::vector<size_t> failure;
    double time;
    std::string results;
    size_t curr_test;
  public:
    Test() : time(0), curr_test(0) {}
    
    template<typename T1, typename T2>
    void expect_eq(const T1 &t1, const T2 &t2,
                   const std::source_location &l =
                   std::source_location::current())
    {
      if (t1 != t2)
      {
        results += ("[\033[0;32;31mFAILED\033[m] Test '" + all_tests[curr_test].first + "' in \033[1;37m"
                    + location_to_str(l) + ":\033[m " + to_str(t1) +
                    "\033[0;32;31m != \033[m" + to_str(t2) +
                    "\n");
        failure.emplace_back(curr_test);
      }
    }
    
    template<typename T>
    size_t add(const std::string &name, const T &func)
    {
      all_tests.emplace_back(std::make_pair(name, func));
      return all_tests.size() - 1;
    }
    
    template<typename T1, typename T2>
    int add_expect_exception(const std::string &name, const T1 &func, const T2 &exception,
                             const std::source_location &l =
                             std::source_location::current())
    {
      all_tests.template emplace_back(
          [this, func, exception, location = location_to_str(l)]()
          {
            bool caught = false;
            try
            {
              func();
            }
            catch (T2 &err)
            {
              if (err != exception)
              {
                throw err;
              }
              else
                caught = true;
            }
            if (!caught)
            {
              results += ("[\033[0;32;31mFAILED\033[m] Test '" + all_tests[curr_test].first + "' in \033[1;37m"
                          + location + ":\033[m Exception not captured.");
              failure.template emplace_back(curr_test);
            }
          });
      return all_tests.size() - 1;
    }
    
    int run_tests()
    {
      Timer timer;
      timer.start();
      std::string curr_msg;
      size_t curr_pos = 0;
      bool print_mark = false;
      auto s = timer.get_microseconds();
      auto e = s;
      size_t last_failure = 0;
      size_t last_exception = 0;
      for (curr_test = 0; curr_test < all_tests.size(); ++curr_test)
      {
        try
        {
          all_tests[curr_test].second();
          e = timer.get_microseconds();
        }
        catch (UnitTestError &e)
        {
          results += ("[\033[0;32;31mEXCEPTION\033[m] Test "
                      + std::to_string(curr_test) + " at " + e.get_location()
                      + ":\n" + e.get_content() + "\n");
          exceptions.emplace_back(curr_test);
        }
        if (failure.size() != last_failure || exceptions.size() != last_exception)
        {
          last_exception = exceptions.size();
          last_failure = failure.size();
        }
        else
        {
          results += "[\033[0;32;32mPASSED\033[m] " + all_tests[curr_test].first
                     + " | " + "(" + to_str((e - s) * 0.001) + " ms)\n";
        }
        time += e - s;
        s = timer.get_microseconds();
      }
      
      if (!failure.empty() || !exceptions.empty()) return -1;
      return 0;
    }
    
    void print_results()
    {
      std::cout << results;
      if (failure.empty() && exceptions.empty())
      {
        std::cout << ("\033[0;32;32mUNITTEST PASSED\033[m");
      }
      else
      {
        std::cout << ("\033[0;32;31mUNITTEST FAILED\033[m");
      }
      std::cout << ("(" + to_str(time * 0.000001) + " s)\n");
      if (!exceptions.empty())
      {
        std::cout << "[\033[0;32;33mDETAIL\033[m] "
                  << (std::to_string(exceptions.size()) + " unexpected exception(s) at[");
        std::string str;
        for (auto &r: exceptions)
        {
          str += std::to_string(r) + ',';
        }
        str.pop_back();
        std::cout << str << "]." << std::endl;
      }
      if (!failure.empty())
      {
        std::cout << "[\033[0;32;33mDETAIL\033[m] " << (std::to_string(failure.size()) + " failure at[");
        std::string str;
        for (auto &r: failure)
        {
          str += std::to_string(r) + ',';
        }
        str.pop_back();
        std::cout << str << "]." << std::endl;
      }
    }
  };
  
  Test &get_test()
  {
    static Test test;
    return test;
  }
}
#endif
