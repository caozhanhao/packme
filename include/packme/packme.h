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
#ifndef CZH_PACKME_H
#define CZH_PACKME_H
#pragma once

#include <type_traits>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iterator>
#include <tuple>
#include <variant>
#include <array>
#include <cstring>

#define PACKME_MARCO_EXPAND(...) __VA_ARGS__

#define PACKME_ARG_COUNT_(\
	 _0,  _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, \
	_10, _11, _12, _13, _14, _15, _16, _17, _18, _19, \
	_20, _21, _22, _23, _24, _25, _26, _27, _28, _29, \
	_30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
	_40, _41, _42, _43, _44, _45, _46, _47, _48, _49, \
	_50, _51, _52, _53, _54, _55, _56, _57, _58, _59, \
	_60, _61, _62, _63, _64, N, ...) N

#define PACKME_ARG_COUNT(...) PACKME_MARCO_EXPAND(PACKME_ARG_COUNT_(0, ##__VA_ARGS__,\
	64, 63, 62, 61, 60, \
	59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
	49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
	39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
	29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
	19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
	 9,  8,  7,  6,  5,  4,  3,  2,  1,  0))
  
#define PACKME_ARG_EXPAND_1(f,t,...)  f(t)
#define PACKME_ARG_EXPAND_2(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_1(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_3(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_2(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_4(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_3(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_5(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_4(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_6(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_5(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_7(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_6(f,__VA_ARGS__)) ,f(t)
#define PACKME_ARG_EXPAND_8(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_7(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_9(f,t,...)  PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_8(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_10(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_9(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_11(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_10(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_12(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_11(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_13(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_12(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_14(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_13(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_15(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_14(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_16(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_15(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_17(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_16(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_18(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_17(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_19(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_18(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_20(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_19(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_21(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_20(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_22(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_21(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_23(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_22(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_24(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_23(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_25(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_24(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_26(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_25(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_27(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_26(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_28(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_27(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_29(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_28(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_30(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_29(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_31(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_30(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_32(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_31(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_33(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_32(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_34(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_33(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_35(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_34(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_36(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_35(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_37(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_36(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_38(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_37(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_39(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_38(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_40(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_39(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_41(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_40(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_42(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_41(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_43(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_42(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_44(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_43(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_45(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_44(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_46(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_45(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_47(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_46(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_48(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_47(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_49(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_48(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_50(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_49(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_51(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_50(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_52(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_51(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_53(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_52(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_54(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_53(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_55(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_54(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_56(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_55(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_57(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_56(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_58(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_57(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_59(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_58(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_60(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_59(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_61(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_60(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_62(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_61(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_63(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_62(f,__VA_ARGS__)),f(t)
#define PACKME_ARG_EXPAND_64(f,t,...) PACKME_MARCO_EXPAND(PACKME_ARG_EXPAND_63(f,__VA_ARGS__)),f(t)
   
#define PACKME_CONCAT_(l, r) l ## r
#define PACKME_CONCAT(l, r) PACKME_CONCAT_(l, r)

#define PACKME_EXPAND_(func,...) \
		PACKME_MARCO_EXPAND(PACKME_CONCAT(PACKME_ARG_EXPAND_, PACKME_ARG_COUNT(__VA_ARGS__))(func, __VA_ARGS__))
  
#define PACKME_EXPAND(func,...) \
    PACKME_EXPAND_(func, __VA_ARGS__)

#define PACKME_COPY_1(f1) f1(t.get<0>())
#define PACKME_COPY_2(f1, f2) f1(t.get<0>()), f2(t.get<1>())
#define PACKME_COPY_3(f1, f2, f3) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>())
#define PACKME_COPY_4(f1, f2, f3, f4) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>())
#define PACKME_COPY_5(f1, f2, f3, f4, f5) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>())
#define PACKME_COPY_6(f1, f2, f3, f4, f5, f6) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>())
#define PACKME_COPY_7(f1, f2, f3, f4, f5, f6, f7) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>())
#define PACKME_COPY_8(f1, f2, f3, f4, f5, f6, f7, f8) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>())
#define PACKME_COPY_9(f1, f2, f3, f4, f5, f6, f7, f8, f9) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>())
#define PACKME_COPY_10(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>())
#define PACKME_COPY_11(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>())
#define PACKME_COPY_12(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>())
#define PACKME_COPY_13(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>())
#define PACKME_COPY_14(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>())
#define PACKME_COPY_15(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>())
#define PACKME_COPY_16(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>())
#define PACKME_COPY_17(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>())
#define PACKME_COPY_18(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>())
#define PACKME_COPY_19(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>())
#define PACKME_COPY_20(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>())
#define PACKME_COPY_21(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>())
#define PACKME_COPY_22(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>())
#define PACKME_COPY_23(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>())
#define PACKME_COPY_24(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>())
#define PACKME_COPY_25(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>())
#define PACKME_COPY_26(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>())
#define PACKME_COPY_27(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>())
#define PACKME_COPY_28(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>())
#define PACKME_COPY_29(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>())
#define PACKME_COPY_30(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>())
#define PACKME_COPY_31(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>())
#define PACKME_COPY_32(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>())
#define PACKME_COPY_33(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>())
#define PACKME_COPY_34(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>())
#define PACKME_COPY_35(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>())
#define PACKME_COPY_36(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>())
#define PACKME_COPY_37(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>())
#define PACKME_COPY_38(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>())
#define PACKME_COPY_39(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>())
#define PACKME_COPY_40(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>())
#define PACKME_COPY_41(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>())
#define PACKME_COPY_42(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>())
#define PACKME_COPY_43(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>())
#define PACKME_COPY_44(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>())
#define PACKME_COPY_45(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>())
#define PACKME_COPY_46(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>())
#define PACKME_COPY_47(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>())
#define PACKME_COPY_48(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>())
#define PACKME_COPY_49(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>())
#define PACKME_COPY_50(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>())
#define PACKME_COPY_51(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>())
#define PACKME_COPY_52(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>())
#define PACKME_COPY_53(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>())
#define PACKME_COPY_54(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>())
#define PACKME_COPY_55(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>())
#define PACKME_COPY_56(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>())
#define PACKME_COPY_57(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>())
#define PACKME_COPY_58(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>())
#define PACKME_COPY_59(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>())
#define PACKME_COPY_60(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>()), f60(t.get<59>())
#define PACKME_COPY_61(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>()), f60(t.get<59>()), f61(t.get<60>())
#define PACKME_COPY_62(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>()), f60(t.get<59>()), f61(t.get<60>()), f62(t.get<61>())
#define PACKME_COPY_63(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>()), f60(t.get<59>()), f61(t.get<60>()), f62(t.get<61>()), f63(t.get<62>())
#define PACKME_COPY_64(f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f20, f21, f22, f23, f24, f25, f26, f27, f28, f29, f30, f31, f32, f33, f34, f35, f36, f37, f38, f39, f40, f41, f42, f43, f44, f45, f46, f47, f48, f49, f50, f51, f52, f53, f54, f55, f56, f57, f58, f59, f60, f61, f62, f63, f64) f1(t.get<0>()), f2(t.get<1>()), f3(t.get<2>()), f4(t.get<3>()), f5(t.get<4>()), f6(t.get<5>()), f7(t.get<6>()), f8(t.get<7>()), f9(t.get<8>()), f10(t.get<9>()), f11(t.get<10>()), f12(t.get<11>()), f13(t.get<12>()), f14(t.get<13>()), f15(t.get<14>()), f16(t.get<15>()), f17(t.get<16>()), f18(t.get<17>()), f19(t.get<18>()), f20(t.get<19>()), f21(t.get<20>()), f22(t.get<21>()), f23(t.get<22>()), f24(t.get<23>()), f25(t.get<24>()), f26(t.get<25>()), f27(t.get<26>()), f28(t.get<27>()), f29(t.get<28>()), f30(t.get<29>()), f31(t.get<30>()), f32(t.get<31>()), f33(t.get<32>()), f34(t.get<33>()), f35(t.get<34>()), f36(t.get<35>()), f37(t.get<36>()), f38(t.get<37>()), f39(t.get<38>()), f40(t.get<39>()), f41(t.get<40>()), f42(t.get<41>()), f43(t.get<42>()), f44(t.get<43>()), f45(t.get<44>()), f46(t.get<45>()), f47(t.get<46>()), f48(t.get<47>()), f49(t.get<48>()), f50(t.get<49>()), f51(t.get<50>()), f52(t.get<51>()), f53(t.get<52>()), f54(t.get<53>()), f55(t.get<54>()), f56(t.get<55>()), f57(t.get<56>()), f58(t.get<57>()), f59(t.get<58>()), f60(t.get<59>()), f61(t.get<60>()), f62(t.get<61>()), f63(t.get<62>()), f64(t.get<63>())

#define PACKME_FIELDS(T, ...) \
inline auto packme_make_tuple() const                \
{                                                    \
  return std::make_tuple(__VA_ARGS__);               \
}                                                    \
using packme_tuple_type = decltype(::packme::details::as_tuple(::packme::details::reverse_t<::packme::details::TypeList<PACKME_EXPAND(decltype, __VA_ARGS__)>>{}));                                 \
explicit T(const ::packme::details::CustomTypeHelper<T>& t):                                                                               \
  PACKME_MARCO_EXPAND(PACKME_CONCAT(PACKME_COPY_, PACKME_ARG_COUNT(__VA_ARGS__)) (__VA_ARGS__)) {}                         \

namespace packme
{
  template<typename T>
  std::decay_t<T> unpack(const std::string &str);
  
  template<typename T>
  std::string pack(const T &item);
  
  namespace details
  {
    template<typename... List>
    struct TypeList {};
    struct TypeListError {};
    template<typename... List>
    std::tuple<List...> as_tuple(TypeList<List...>);
  
    template<typename List, typename NewElement>
    struct push_back;
    template<typename... elems, typename new_elem>
    struct push_back<TypeList<elems...>, new_elem>
    {
      using type = TypeList<elems..., new_elem>;
    };
    template<typename List, typename new_elem>
    using push_back_t = typename push_back<List, new_elem>::type;
  
    template<typename List>
    struct is_empty
    {
      static constexpr bool value = false;
    };
    template<>
    struct is_empty<TypeList<>>
    {
      static constexpr bool value = true;
    };
    template<typename List>
    constexpr bool is_empty_v = is_empty<List>::value;
  
    template<typename List>
    struct front;
    template<typename First, typename ...Rest>
    struct front<TypeList<First, Rest...>>
    {
      using type = First;
    };
    template<typename List>
    using front_t = typename front<List>::type;
  
    template<typename List>
    struct pop_front;
    template<typename First, typename ...Rest>
    struct pop_front<TypeList<First, Rest...>>
    {
      using type = TypeList<Rest...>;
    };
    template<typename List>
    using pop_front_t = typename pop_front<List>::type;
  
    template<typename List, bool Empty = is_empty_v<List>>
    struct reverse;
    template<typename List>
    struct reverse<List, false> : public push_back<typename reverse<pop_front_t<List>>::type, front_t<List>> { };
    template<typename List>
    struct reverse<List, true>
    {
      using type = List;
    };
    template<typename List>
    using reverse_t = typename reverse<List>::type;
  
    template<typename T>
    struct CustomTypeHelper{
      using tuple_type = typename T::packme_tuple_type;
      tuple_type tuple;
      template<size_t index>
      auto get() const
      {
        return std::get<index>(tuple);
      }
    };
    
    struct Any
    {
      template<typename T>
      operator T();
    };
    
    template<typename T, template<typename...> typename Primary>
    struct is_specialization_of : public std::false_type {};
    template<template<typename...> typename Primary, typename... Args>
    struct is_specialization_of<Primary<Args...>, Primary> : public std::true_type {};
    template<typename T, template<typename...> typename Primary>
    constexpr bool is_specialization_of_v = is_specialization_of<T, Primary>::value;
    
    template<typename T>
    constexpr bool is_map_v = is_specialization_of_v<T, std::map>;
    
    template<typename T>
    constexpr bool is_serializable_tuple_like_v =
        (is_specialization_of_v<T, std::pair>
        || is_specialization_of_v<T, std::tuple>)
           && std::is_default_constructible_v<T>;
    
    template<typename T>
    requires std::is_aggregate_v<std::remove_cvref_t<T>> || is_serializable_tuple_like_v<std::remove_cvref_t<T>>
    consteval auto field_num(auto &&... args)
    {
      if constexpr(is_serializable_tuple_like_v<T>)
      {
        return std::tuple_size<T>();
      }
      else
      {
        if constexpr (!requires{ T{args...}; })
        {
          return sizeof ...(args) - 1;
        }
        else
        {
          return field_num<T>(args..., Any{});
        }
      }
    }
    
    template<typename T, typename Fn>
    requires std::is_aggregate_v<std::remove_cvref_t<T>> || is_serializable_tuple_like_v<std::remove_cvref_t<T>>
    constexpr auto field_for_each(T &&t, Fn &&fn)
    {
      constexpr auto num = field_num<std::remove_cvref_t<T>>();
      if constexpr (num == 1) {auto&& [_1] = std::forward<T>(t);fn(_1);}
      else if constexpr (num == 2) {auto&& [_1, _2] = std::forward<T>(t);fn(_1);fn(_2);}
      else if constexpr (num == 3) {auto&& [_1, _2, _3] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);}
      else if constexpr (num == 4) {auto&& [_1, _2, _3, _4] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);}
      else if constexpr (num == 5) {auto&& [_1, _2, _3, _4, _5] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);}
      else if constexpr (num == 6) {auto&& [_1, _2, _3, _4, _5, _6] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);}
      else if constexpr (num == 7) {auto&& [_1, _2, _3, _4, _5, _6, _7] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);}
      else if constexpr (num == 8) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);}
      else if constexpr (num == 9) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);}
      else if constexpr (num == 10) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);}
      else if constexpr (num == 11) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);}
      else if constexpr (num == 12) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);}
      else if constexpr (num == 13) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);}
      else if constexpr (num == 14) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);}
      else if constexpr (num == 15) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);}
      else if constexpr (num == 16) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);}
      else if constexpr (num == 17) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);}
      else if constexpr (num == 18) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);}
      else if constexpr (num == 19) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);}
      else if constexpr (num == 20) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);}
      else if constexpr (num == 21) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);}
      else if constexpr (num == 22) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);}
      else if constexpr (num == 23) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);}
      else if constexpr (num == 24) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);}
      else if constexpr (num == 25) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);}
      else if constexpr (num == 26) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);}
      else if constexpr (num == 27) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);}
      else if constexpr (num == 28) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);}
      else if constexpr (num == 29) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);}
      else if constexpr (num == 30) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);}
      else if constexpr (num == 31) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);}
      else if constexpr (num == 32) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);}
      else if constexpr (num == 33) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);}
      else if constexpr (num == 34) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);}
      else if constexpr (num == 35) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);}
      else if constexpr (num == 36) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);}
      else if constexpr (num == 37) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);}
      else if constexpr (num == 38) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);}
      else if constexpr (num == 39) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);}
      else if constexpr (num == 40) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);}
      else if constexpr (num == 41) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);}
      else if constexpr (num == 42) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);}
      else if constexpr (num == 43) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);}
      else if constexpr (num == 44) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);}
      else if constexpr (num == 45) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);}
      else if constexpr (num == 46) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);}
      else if constexpr (num == 47) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);}
      else if constexpr (num == 48) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);}
      else if constexpr (num == 49) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);}
      else if constexpr (num == 50) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);}
      else if constexpr (num == 51) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);}
      else if constexpr (num == 52) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);}
      else if constexpr (num == 53) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);}
      else if constexpr (num == 54) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);}
      else if constexpr (num == 55) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);}
      else if constexpr (num == 56) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);}
      else if constexpr (num == 57) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);}
      else if constexpr (num == 58) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);}
      else if constexpr (num == 59) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);}
      else if constexpr (num == 60) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);fn(_60);}
      else if constexpr (num == 61) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);fn(_60);fn(_61);}
      else if constexpr (num == 62) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);fn(_60);fn(_61);fn(_62);}
      else if constexpr (num == 63) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);fn(_60);fn(_61);fn(_62);fn(_63);}
      else if constexpr (num == 64) {auto&& [_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64] = std::forward<T>(t);fn(_1);fn(_2);fn(_3);fn(_4);fn(_5);fn(_6);fn(_7);fn(_8);fn(_9);fn(_10);fn(_11);fn(_12);fn(_13);fn(_14);fn(_15);fn(_16);fn(_17);fn(_18);fn(_19);fn(_20);fn(_21);fn(_22);fn(_23);fn(_24);fn(_25);fn(_26);fn(_27);fn(_28);fn(_29);fn(_30);fn(_31);fn(_32);fn(_33);fn(_34);fn(_35);fn(_36);fn(_37);fn(_38);fn(_39);fn(_40);fn(_41);fn(_42);fn(_43);fn(_44);fn(_45);fn(_46);fn(_47);fn(_48);fn(_49);fn(_50);fn(_51);fn(_52);fn(_53);fn(_54);fn(_55);fn(_56);fn(_57);fn(_58);fn(_59);fn(_60);fn(_61);fn(_62);fn(_63);fn(_64);}
      else
      {
        static_assert(num <= 64, "too many fields");
      }
    }
    
    struct not_implemented_tag {};
    struct trivially_copy_tag {};
    struct pointer_tag {};
    struct int_tag {};
    struct enum_tag {};
    struct container_tag {};
    struct string_tag {};
    struct map_tag {};
    struct array_tag {};
    struct struct_tag {};
    struct custom_tag {};
  
    template<typename T>
    concept CustomType =
    requires(T value)
    {
      { value.packme_make_tuple() };
    };
    
    template<typename BeginIt, typename EndIt>
    concept ItRange =
    requires(BeginIt begin_it, EndIt end_it)
    {
      { ++begin_it };
      { *begin_it };
      requires !std::is_void_v<decltype(*begin_it)>;
      { begin_it != end_it };
    };
    
    template<typename T>
    concept Container =
    requires(T value)
    {
      { std::begin(value) };
      { std::end(value) };
      requires ItRange<decltype(std::begin(value)), decltype(std::end(
          value))>;
    };
    
    template<typename T>
    concept SerializableContainer =
    Container<T> &&
    requires(T value)
    {
      { value.insert(std::end(value), std::declval<decltype(*std::begin(value))>()) };
      requires std::is_default_constructible_v<T>;
    };
  
    template<typename T, typename U = void>
    struct is_custom_type : public std::false_type {};
    template<typename T> requires CustomType<T>
    struct is_custom_type<T> : public std::true_type {};
    template<typename T>
    constexpr bool is_custom_type_v = is_custom_type<T>::value;
    
    template<typename T, typename U = void>
    struct is_container : public std::false_type {};
    template<typename T> requires Container<T>
    struct is_container<T> : public std::true_type {};
    template<typename T>
    constexpr bool is_container_v = is_container<T>::value;
    
    template<typename T, typename U = void>
    struct is_serializable_container : public std::false_type {};
    template<typename T> requires SerializableContainer<T>
    struct is_serializable_container<T> : public std::true_type {};
    template<typename T>
    constexpr bool is_serializable_container_v = is_serializable_container<T>::value;
    
    template<typename T>
    constexpr bool is_serializable_struct_v = !is_container_v<T> && std::is_aggregate_v<T> && std::is_default_constructible_v<T>;
    
    template<typename T>
    auto dispatch_tag()
    {
      using R = std::remove_cvref_t<T>;
      if constexpr(is_custom_type_v<R>) return custom_tag{};
      else if constexpr(std::is_array_v<R>) return array_tag{};
      else if constexpr(std::is_pointer_v<R>) return pointer_tag{};
      else if constexpr(std::is_integral_v<R>) return int_tag{};
      else if constexpr(std::is_enum_v<R>) return enum_tag{};
      else if constexpr(std::is_same_v<R, std::string>) return string_tag{};
      else if constexpr(is_map_v<R>) return map_tag{};
      else if constexpr(is_serializable_container_v<R>) return container_tag{};
      else if constexpr(is_serializable_struct_v<R> || is_serializable_tuple_like_v<R>) return struct_tag{};
      else if constexpr(std::is_default_constructible_v<R> && std::is_trivially_copyable_v<R>) return trivially_copy_tag{};
      else return not_implemented_tag{};
    }
    
    template<typename T, typename Tag>
    constexpr bool tag_is = std::is_same_v<decltype(dispatch_tag<T>()), Tag>;
    
    template<typename T>
    std::string internal_pack(not_implemented_tag, const T &item);
  
    template<typename T>
    T internal_unpack(not_implemented_tag, const std::string &str);
    
    template<typename T>
    std::string internal_pack(int_tag, const T &item)
    {
      if constexpr(sizeof(T) > 1)
      {
        if constexpr(std::is_signed_v<T>)
        {
          return internal_pack<std::make_unsigned_t<T>>(int_tag{},
                                                        static_cast<std::make_unsigned_t<T>>((item << 1) ^ (item
                                                            >> (sizeof(T) * 8 - 1))));
        }
        else
        {
          std::string data(((sizeof(T) * 8) / 7) * 8 + 1, '\0');
          size_t pos = 0;
          auto num = item;
          while (num >= 128)
          {
            data[pos++] = 0x80 | static_cast<char>(num & 0x7f);
            num >>= 7;
          }
          data[pos++] = static_cast<char>(num);
          return data.substr(0, pos);
        }
      }
      else
      {
        return internal_pack(trivially_copy_tag{}, item);
      }
    }
    
    template<typename T>
    T internal_unpack(int_tag, const std::string &str)
    {
      if constexpr(sizeof(T) > 1)
      {
        if constexpr(std::is_signed_v<T>)
        {
          auto v = internal_unpack<std::make_unsigned_t<T>>(int_tag{}, str);
          return static_cast<T>((v >> 1) ^ -(v & 1));
        }
        else
        {
          T result = 0;
          size_t shift = 0;
          for (auto &c : str)
          {
            result |= static_cast<T>(c & 0x7f) << shift;
            shift += 7;
          }
          return result;
        }
      }
      else
      {
        return internal_unpack<T>(trivially_copy_tag{}, str);
      }
    }
    
    template<typename T>
    std::string internal_pack(enum_tag, const T &item)
    {
      return internal_pack(int_tag{}, static_cast<std::underlying_type_t<std::remove_cvref_t<T>>>(item));
    }
    
    template<typename T>
    T internal_unpack(enum_tag, const std::string &str)
    {
      return static_cast<T>(internal_unpack<std::underlying_type_t<std::remove_cvref_t<T>>>(int_tag{}, str));
    }
    
    template<typename T>
    std::string internal_pack(trivially_copy_tag, const T &item)
    {
      std::string data(sizeof(T), '\0');
      std::memcpy(data.data(), &item, sizeof(T));
      return data;
    }
    
    template<typename T>
    T internal_unpack(trivially_copy_tag, const std::string &str)
    {
      T item;
      std::memcpy(&item, str.data(), sizeof(T));
      return item;
    }
    
    template<typename T>
    std::string internal_pack(string_tag, const T &item)
    {
      return item;
    }
  
    template<typename T>
    T internal_unpack(string_tag, const std::string &str)
    {
      return str;
    }
    
    template<typename T>
    std::string internal_pack(map_tag, const T &item)
    {
      std::vector<std::pair<std::remove_cvref_t<typename T::key_type>,
          std::remove_cvref_t<typename T::mapped_type>>> v;
      for (auto &r: item)
        v.emplace_back(r);
      return pack(v);
    }
  
    template<typename T>
    T internal_unpack(map_tag, const std::string &str)
    {
      auto v = unpack<std::vector<std::pair<std::remove_cvref_t<typename T::key_type>,
          std::remove_cvref_t<typename T::mapped_type>>>>(str);
      T ret;
      for (auto &r: v)
        ret.emplace_hint(ret.end(), std::move(r));
      return ret;
    }
    
    template<typename T>
    void item_pack_helper(std::string &buf, size_t &pos, const T &item)
    {
      if constexpr(tag_is<T, trivially_copy_tag> || tag_is<T, int_tag> || tag_is<T, enum_tag>)
      {
        // These types don't need a size indicator.
        auto data = pack<T>(static_cast<T>(const_cast<std::remove_const_t<decltype(item)>>(item)));
        if (buf.size() - pos < data.size())
          buf.resize(buf.size() + data.size() + 64);
        for (size_t i = 0; i < data.size(); ++i, ++pos)
          buf[pos] = data[i];
      }
      else
      {
        auto data = pack<T>(static_cast<T>(const_cast<std::remove_const_t<decltype(item)>>(item)));
        
        auto data_size = internal_pack(int_tag{}, data.size());
        if (buf.size() - pos < data.size() + data_size.size())
          buf.resize(buf.size() + data.size() + data_size.size() + 64);
        
        for (size_t i = 0; i < data_size.size(); ++i, ++pos)
          buf[pos] = data_size[i];
        for (size_t i = 0; i < data.size(); ++i, ++pos)
          buf[pos] = data[i];
      }
    }
    
    template<typename T>
    auto item_unpack_helper(const std::string &str, size_t &pos)
    {
      // These types don't need a size indicator.
      if constexpr(tag_is<T, trivially_copy_tag> || (tag_is<T, int_tag> && sizeof(T) == 1))
      {
        std::string buf = str.substr(pos, sizeof(T));
        pos += sizeof(T);
        return unpack<std::remove_cvref_t<T>>(buf);
      }
      else
      {
        // if tag is not trivially_copy_tag, it must be int, string or custom-type,
        // and they all have an integer at the beginning indicating its size(trivially_copy) or value(int).
        size_t int_size = 1;
        for (size_t i = pos; i < str.size(); ++i, ++int_size)
        {
          if ((str[i] & 0x80) == 0) break;
        }
        std::string buf = str.substr(pos, int_size);
        pos += int_size;
        
        if constexpr(tag_is<T, int_tag> || tag_is<T, enum_tag>)
        {
          return unpack<std::remove_cvref_t<T>>(buf);
        }
        else
        {
          auto data_size = unpack<size_t>(buf);
          std::string data_buf = str.substr(pos, data_size);
          pos += data_size;
          return unpack<std::remove_cvref_t<T>>(data_buf);
        }
      }
    }
    
    template<typename T>
    std::string internal_pack(container_tag, const T &item)
    {
      std::string buf(64, '\0');
      size_t pos = 0;
      for (const auto& r : item)
        item_pack_helper(buf, pos, r);
      return buf.substr(0, pos);
    }
    
    template<typename T>
    T internal_unpack(container_tag, const std::string &str)
    {
      if (str.empty()) return T{};
      T ret;
      using value_type = std::remove_cvref_t<decltype(*std::begin(ret))>;
      for (size_t i = 0; i < str.size();)
      {
        ret.insert(std::end(ret), std::move(item_unpack_helper<value_type>(str, i)));
      }
      return ret;
    }
    
    template<typename T>
    std::string internal_pack(struct_tag, const T &item)
    {
      std::string buf(64, '\0');
      size_t pos = 0;
      field_for_each(item, [&buf, &pos](auto &&r) { item_pack_helper(buf, pos, r); });
      return buf.substr(0, pos);
    }
    
    template<typename T>
    T internal_unpack(struct_tag, const std::string &str)
    {
      if (str.empty()) return T{};
      T ret;
      size_t pos = 0;
      field_for_each(ret, [&str, &pos](auto &&r) { r = std::move(item_unpack_helper<decltype(r)>(str, pos)); });
      return ret;
    }
  
    template<typename T>
    std::string internal_pack(pointer_tag, const T &item)
    {
      return pack(*item);
    }
  
    template<typename T>
    T internal_unpack(pointer_tag, const std::string &str)
    {
      using value_type = std::remove_pointer_t<T>;
      T item = new value_type();
      *item = unpack<value_type>(str);
      return item;
    }
  
    template<typename T>
    std::string internal_pack(array_tag, const T &item)
    {
      using value_type = std::remove_extent_t<T>;
      std::string buf(64, '\0');
      size_t pos = 0;
      for (size_t i = 0; i < sizeof(T) / sizeof(value_type); ++i)
        item_pack_helper(buf, pos, item[i]);
      return buf.substr(0, pos);
    }
  
    template<typename T>
    std::decay_t<T> internal_unpack(array_tag, const std::string &str)
    {
      using value_type = std::remove_extent_t<T>;
      if (str.empty()) return nullptr;
      auto ret = new value_type[sizeof(T) / sizeof(value_type)];
      for (size_t i = 0, pos = 0; i < str.size() && pos < sizeof(T) / sizeof(value_type); ++pos)
      {
        ret[pos] = std::move(item_unpack_helper<value_type>(str, i));
      }
      return ret;
    }
  
    template<typename T>
    std::string internal_pack(custom_tag, const T &item)
    {
      return internal_pack(struct_tag{}, item.packme_make_tuple());
    }
  
    template<typename T>
    T internal_unpack(custom_tag, const std::string &str)
    {
      T ret(CustomTypeHelper<T>{internal_unpack<typename T::packme_tuple_type>(struct_tag{}, str)});
      return ret;
    }
  }
  
  template<typename T>
  std::string pack(const T &item)
  {
    static_assert(!details::tag_is<T, details::not_implemented_tag>,
                  "Please add PACKME_FIELDS(typename, field1, field2, ...)");
    return details::internal_pack<T>(details::dispatch_tag<T>(), item);
  }
  
  
  template<typename T>
  std::decay_t<T> unpack(const std::string &str)
  {
    static_assert(!details::tag_is<T, details::not_implemented_tag>,
                  "Please add PACKME_FIELDS(typename, field1, field2, ...)");
    return details::internal_unpack<T>(details::dispatch_tag<T>(), str);
  }
}
#endif