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

### Example

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

### Note

- Requires C++ 20