<h2 align="center">
packme
</h2> 

<p align="center">
<strong> A single header C++ library for serialization</strong>
</p>

<p align="center">
  <a href="https://github.com/caozhanhao/packme/actions/workflows/tests.yml" >
    <img src="https://img.shields.io/github/actions/workflow/status/caozhanhao/packme/tests.yml?style=flat-square" alt="build" />  
  </a>
  <a href="LICENSE" >
    <img src="https://img.shields.io/github/license/caozhanhao/packme?label=License&style=flat-square&color=yellow" alt="License" />  
  </a>
  <a href="https://github.com/caozhanhao/packme/releases" >
    <img src="https://img.shields.io/github/v/release/caozhanhao/packme?label=Release&style=flat-square&color=orange" alt="Release" />  
  </a>
</p>

- single header
- easy to use

### Setup

`#include "packme/packme.h"`

### Usage
#### non-invasive
- aggregate struct 
- container with `begin()`, `end()`, `insert(iter, val)`
- tuple-like
- trivially copyable type
- ...
```c++
struct A{ int a; double b;};
struct B
{
  int a;
  std::string b;
  std::vector<int> c;
  std::map<std::string, int> d;
  A e;
};

B b{ 1, "2", std::vector<int>{ 3 }, 
     std::map<std::string, int>{{ "4", 5 }},
     A{ 6, 7.0 }};
std::string str = pack(b);
B new_b = unpack<B>(str);
```
#### invasive
- types with `PACKME_FIELDS(typename, field1, field2, ...)`

```c++
class C
{
private:
  int a;   
  double* b; 
public:
  C(std::string b_): a(128), b(new double(3.14)) { }   
  ~C()
  {
    delete b;
    b = nullptr;
  }
  PACKME_FIELDS(C, a, b);
}; 
C c("packme");
std::string str = pack(c);
C new_c = unpack<C>(str);
```
`PACKME_FIELDS` will generate two functions in place.
```c++
class C
{
  public:
  using packme_tuple_type = std::tuple<int, double*>;
  inline auto packme_make_tuple() const
  { return std::make_tuple(a, b); }
  explicit C(const CustomTypeHelper<C> &t)
    : a(t.get<0>()), b(t.get<1>()) {}
  // CustomTypeHelper is a helper class defined in packme.h
};
```

### Note

- Requires C++ 20