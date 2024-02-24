#include <gtest/gtest.h>

#include <array>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "s21_containers.h"
#include "s21_containersplus.h"

// ARRAY

TEST(array_constructor, case1) {
  S21::array<int, 4> S21_arr_int;
  S21::array<double, 4> S21_arr_double;
  S21::array<std::string, 4> S21_arr_string;

  EXPECT_EQ(S21_arr_int.size(), 4U);
  EXPECT_EQ(S21_arr_double.size(), 4U);
  EXPECT_EQ(S21_arr_string.size(), 4U);
}

TEST(array_constructor, case2) {
  S21::array<int, 5> S21_arr_int{1, 4, 8, 9, 1};
  S21::array<double, 5> S21_arr_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::array<std::string, 5> S21_arr_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(S21_arr_int.size(), 5U);
  EXPECT_EQ(S21_arr_int[0], 1);

  EXPECT_EQ(S21_arr_double.size(), 5U);
  EXPECT_EQ(S21_arr_double[0], 1.4);

  EXPECT_EQ(S21_arr_string.size(), 5U);
  EXPECT_EQ(S21_arr_string[0], "Hello");
}

TEST(array_constructor, case3) {
  S21::array<int, 4> S21_arr_ref_int{1, 4, 8, 9};
  S21::array<int, 4> S21_arr_res_int(S21_arr_ref_int);

  S21::array<double, 4> S21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::array<double, 4> S21_arr_res_double(S21_arr_ref_double);

  S21::array<std::string, 4> S21_arr_ref_string{"Hello", ",", "world", "!"};
  S21::array<std::string, 4> S21_arr_res_string(S21_arr_ref_string);

  EXPECT_EQ(S21_arr_ref_int.size(), S21_arr_res_int.size());
  EXPECT_EQ(S21_arr_ref_int[0], S21_arr_res_int[0]);
  EXPECT_EQ(S21_arr_ref_int[1], S21_arr_res_int[1]);
  EXPECT_EQ(S21_arr_ref_int[2], S21_arr_res_int[2]);
  EXPECT_EQ(S21_arr_ref_int[3], S21_arr_res_int[3]);

  EXPECT_EQ(S21_arr_ref_double.size(), S21_arr_res_double.size());
  EXPECT_EQ(S21_arr_ref_double[0], S21_arr_res_double[0]);
  EXPECT_EQ(S21_arr_ref_double[1], S21_arr_res_double[1]);
  EXPECT_EQ(S21_arr_ref_double[2], S21_arr_res_double[2]);
  EXPECT_EQ(S21_arr_ref_double[3], S21_arr_res_double[3]);

  EXPECT_EQ(S21_arr_ref_string.size(), S21_arr_res_string.size());
  EXPECT_EQ(S21_arr_ref_string[0], S21_arr_res_string[0]);
  EXPECT_EQ(S21_arr_ref_string[1], S21_arr_res_string[1]);
  EXPECT_EQ(S21_arr_ref_string[2], S21_arr_res_string[2]);
  EXPECT_EQ(S21_arr_ref_string[3], S21_arr_res_string[3]);
}

TEST(array_constructor, case4) {
  S21::array<int, 4> S21_arr_ref_int{1, 4, 8, 9};
  S21::array<int, 4> S21_arr_res_int = std::move(S21_arr_ref_int);

  S21::array<double, 4> S21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::array<double, 4> S21_arr_res_double = std::move(S21_arr_ref_double);

  S21::array<std::string, 4> S21_arr_ref_string{"Hello", ",", "world", "!"};
  S21::array<std::string, 4> S21_arr_res_string = std::move(S21_arr_ref_string);

  EXPECT_EQ(S21_arr_res_int.size(), 4U);
  EXPECT_EQ(S21_arr_res_int[0], 1);
  EXPECT_EQ(S21_arr_res_int[1], 4);
  EXPECT_EQ(S21_arr_res_int[2], 8);
  EXPECT_EQ(S21_arr_res_int[3], 9);

  EXPECT_EQ(S21_arr_res_double.size(), 4U);
  EXPECT_EQ(S21_arr_res_double[0], 1.4);
  EXPECT_EQ(S21_arr_res_double[1], 4.8);
  EXPECT_EQ(S21_arr_res_double[2], 8.9);
  EXPECT_EQ(S21_arr_res_double[3], 9.1);

  EXPECT_EQ(S21_arr_res_string.size(), 4U);
  EXPECT_EQ(S21_arr_res_string[0], "Hello");
  EXPECT_EQ(S21_arr_res_string[1], ",");
  EXPECT_EQ(S21_arr_res_string[2], "world");
  EXPECT_EQ(S21_arr_res_string[3], "!");
}

TEST(array_constructor, case6) {
  S21::array<int, 4> S21_arr_ref_int{1, 4, 8, 9};
  S21::array<int, 4> S21_arr_res_int;
  S21_arr_res_int = std::move(S21_arr_ref_int);

  S21::array<double, 4> S21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::array<double, 4> S21_arr_res_double;
  S21_arr_res_double = std::move(S21_arr_ref_double);

  S21::array<std::string, 4> S21_arr_ref_string{"Hello", ",", "world", "!"};
  S21::array<std::string, 4> S21_arr_res_string;
  S21_arr_res_string = std::move(S21_arr_ref_string);

  EXPECT_EQ(S21_arr_res_int.size(), 4U);
  EXPECT_EQ(S21_arr_res_int[0], 1);
  EXPECT_EQ(S21_arr_res_int[1], 4);
  EXPECT_EQ(S21_arr_res_int[2], 8);
  EXPECT_EQ(S21_arr_res_int[3], 9);

  EXPECT_EQ(S21_arr_res_double.size(), 4U);
  EXPECT_EQ(S21_arr_res_double[0], 1.4);
  EXPECT_EQ(S21_arr_res_double[1], 4.8);
  EXPECT_EQ(S21_arr_res_double[2], 8.9);
  EXPECT_EQ(S21_arr_res_double[3], 9.1);

  EXPECT_EQ(S21_arr_res_string.size(), 4U);
  EXPECT_EQ(S21_arr_res_string[0], "Hello");
  EXPECT_EQ(S21_arr_res_string[1], ",");
  EXPECT_EQ(S21_arr_res_string[2], "world");
  EXPECT_EQ(S21_arr_res_string[3], "!");
}

TEST(array_at, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.at(0), 1);
  EXPECT_EQ(S21_arr_double.at(0), 1.4);
  EXPECT_EQ(S21_arr_string.at(0), "Hello");
}

TEST(array_at, case2) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_THROW(S21_arr_int.at(5), std::out_of_range);
  EXPECT_THROW(S21_arr_double.at(5), std::out_of_range);
  EXPECT_THROW(S21_arr_string.at(5), std::out_of_range);
}

TEST(array_at, case3) {
  S21::array<int, 0> S21_arr_int;
  S21::array<double, 0> S21_arr_double;
  S21::array<std::string, 0> S21_arr_string;

  EXPECT_THROW(S21_arr_int.at(5), std::out_of_range);
  EXPECT_THROW(S21_arr_double.at(5), std::out_of_range);
  EXPECT_THROW(S21_arr_string.at(5), std::out_of_range);
}

TEST(array_square_braces, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int[1], 4);
  EXPECT_EQ(S21_arr_double[1], 4.8);
  EXPECT_EQ(S21_arr_string[0], "Hello");
}

TEST(array_front, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.front(), 1);
  EXPECT_EQ(S21_arr_double.front(), 1.4);
  EXPECT_EQ(S21_arr_string.front(), "Hello");
}

TEST(array_back, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.back(), 9);
  EXPECT_EQ(S21_arr_double.back(), 9.1);
  EXPECT_EQ(S21_arr_string.back(), "!");
}

TEST(array_data, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.data(), &S21_arr_int[0]);
  EXPECT_EQ(S21_arr_double.data(), &S21_arr_double[0]);
  EXPECT_EQ(S21_arr_string.data(), &S21_arr_string[0]);
}

TEST(array_begin, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.begin(), &S21_arr_int[0]);
  EXPECT_EQ(S21_arr_double.begin(), &S21_arr_double[0]);
  EXPECT_EQ(S21_arr_string.begin(), &S21_arr_string[0]);
}

TEST(array_end, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.end(), &S21_arr_int[0] + 4);
  EXPECT_EQ(S21_arr_double.end(), &S21_arr_double[0] + 4);
  EXPECT_EQ(S21_arr_string.end(), &S21_arr_string[0] + 4);
}

TEST(array_empty, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.empty(), 0);
  EXPECT_EQ(S21_arr_double.empty(), 0);
  EXPECT_EQ(S21_arr_string.empty(), 0);
}

TEST(array_empty, case2) {
  S21::array<int, 0> S21_arr_int;
  S21::array<double, 0> S21_arr_double;
  S21::array<std::string, 0> S21_arr_string;

  EXPECT_EQ(S21_arr_int.empty(), 1);
  EXPECT_EQ(S21_arr_double.empty(), 1);
  EXPECT_EQ(S21_arr_string.empty(), 1);
}

TEST(array_size, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.size(), 4U);
  EXPECT_EQ(S21_arr_double.size(), 4U);
  EXPECT_EQ(S21_arr_string.size(), 4U);
}

TEST(array_size, case2) {
  S21::array<int, 0> S21_arr_int;
  S21::array<double, 0> S21_arr_double;
  S21::array<std::string, 0> S21_arr_string;

  EXPECT_EQ(S21_arr_int.size(), 0U);
  EXPECT_EQ(S21_arr_double.size(), 0U);
  EXPECT_EQ(S21_arr_string.size(), 0U);
}

TEST(array_max_size, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  std::array<int, 4> std_arr_int{1, 4, 8, 9};

  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  std::array<double, 4> std_arr_double{1.4, 4.8, 8.9, 9.1};

  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};
  std::array<std::string, 4> std_arr_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_arr_int.max_size(), std_arr_int.max_size());
  EXPECT_EQ(S21_arr_double.max_size(), std_arr_double.max_size());
  EXPECT_EQ(S21_arr_string.max_size(), std_arr_string.max_size());
}

TEST(array_swap, case1) {
  S21::array<int, 4> S21_arr_ref_int{1, 4, 8, 9};
  S21::array<int, 4> S21_arr_res_int{21, 21, 21, 21};

  S21::array<double, 4> S21_arr_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::array<double, 4> S21_arr_res_double{21.0, 21.0, 21.0, 21.0};

  S21::array<std::string, 4> S21_arr_ref_string{"Hello", ",", "world", "!"};
  S21::array<std::string, 4> S21_arr_res_string{"21", "21", "21", "21"};

  S21_arr_ref_int.swap(S21_arr_res_int);
  S21_arr_ref_double.swap(S21_arr_res_double);
  S21_arr_ref_string.swap(S21_arr_res_string);

  EXPECT_EQ(S21_arr_ref_int[3], 21);
  EXPECT_EQ(S21_arr_res_int[0], 1);
  EXPECT_EQ(S21_arr_res_int[1], 4);
  EXPECT_EQ(S21_arr_res_int[2], 8);
  EXPECT_EQ(S21_arr_res_int[3], 9);

  EXPECT_EQ(S21_arr_ref_double[3], 21.0);
  EXPECT_EQ(S21_arr_res_double[0], 1.4);
  EXPECT_EQ(S21_arr_res_double[1], 4.8);
  EXPECT_EQ(S21_arr_res_double[2], 8.9);
  EXPECT_EQ(S21_arr_res_double[3], 9.1);

  EXPECT_EQ(S21_arr_ref_string[3], "21");
  EXPECT_EQ(S21_arr_res_string[0], "Hello");
  EXPECT_EQ(S21_arr_res_string[1], ",");
  EXPECT_EQ(S21_arr_res_string[2], "world");
  EXPECT_EQ(S21_arr_res_string[3], "!");
}

TEST(array_fill, case1) {
  S21::array<int, 4> S21_arr_int{1, 4, 8, 9};
  S21::array<double, 4> S21_arr_double{1.4, 4.8, 8.9, 9.1};
  S21::array<std::string, 4> S21_arr_string{"Hello", ",", "world", "!"};

  S21_arr_int.fill(21);
  S21_arr_double.fill(21.0);
  S21_arr_string.fill("21");

  EXPECT_EQ(S21_arr_int[0], 21);
  EXPECT_EQ(S21_arr_int[1], 21);
  EXPECT_EQ(S21_arr_int[2], 21);
  EXPECT_EQ(S21_arr_int[3], 21);

  EXPECT_EQ(S21_arr_double[0], 21.0);
  EXPECT_EQ(S21_arr_double[1], 21.0);
  EXPECT_EQ(S21_arr_double[2], 21.0);
  EXPECT_EQ(S21_arr_double[3], 21.0);

  EXPECT_EQ(S21_arr_string[0], "21");
  EXPECT_EQ(S21_arr_string[1], "21");
  EXPECT_EQ(S21_arr_string[2], "21");
  EXPECT_EQ(S21_arr_string[3], "21");
}

// LIST

template <typename value_type>
bool compare_lists(S21::list<value_type> my_list,
                   std::list<value_type> std_list) {
  bool result = true;
  if (my_list.size() == std_list.size()) {
    if (my_list.size() == 0) {
      result = true;
    } else {
      auto my_it = my_list.begin();
      auto std_it = std_list.begin();
      for (size_t i = 0; i < my_list.size(); ++i) {
        if (*my_it != *std_it) {
          result = false;
          break;
        }
        my_it++;
        std_it++;
      }
    }
  } else {
    result = false;
  }
  return result;
}

TEST(ListTest, CompareLists) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  EXPECT_TRUE(compare_lists(my_list, std_list));
  std_list.push_back(6);
  EXPECT_FALSE(compare_lists(my_list, std_list));
  std_list.pop_back();
  my_list.push_front(0);
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, DefaultConstructor) {
  S21::list<int> my_list;
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());
}

TEST(ListTest, SizeConstructor) {
  S21::list<int> my_list(1000000);
  std::list<int> std_list(1000000);
  EXPECT_EQ(my_list.size(), 1000000);
}

TEST(ListTest, InitializerListConstructor) {
  S21::list<int> my_list{1, 2, 3, 7, 9};
  std::list<int> std_list{1, 2, 3, 7, 9};
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, CopyConstructor) {
  S21::list<int> my_list{1, 2, 3};
  S21::list<int> my_list_copy(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, CopyConstructorEmpty) {
  S21::list<int> my_list;
  S21::list<int> my_list_copy(my_list);
  EXPECT_EQ(my_list.size(), 0);
  EXPECT_TRUE(my_list.empty());
  EXPECT_EQ(my_list_copy.size(), 0);
  EXPECT_TRUE(my_list_copy.empty());
}

TEST(ListTest, MoveConstructor) {
  S21::list<int> my_list{1, 2, 3};
  S21::list<int> my_list_copy(my_list);
  S21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveConstructorEmpty) {
  S21::list<int> my_list;
  S21::list<int> my_list_copy(my_list);
  S21::list<int> my_list_move(std::move(my_list));
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move(std::move(std_list));
  EXPECT_TRUE(compare_lists(my_list_copy, std_list_copy));
}

TEST(ListTest, MoveAssignmentOperator) {
  S21::list<int> my_list{1, 2, 3};
  S21::list<int> my_list_copy(my_list);
  S21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list{1, 2, 3};
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, MoveAssignmentOperatorEmpty) {
  S21::list<int> my_list;
  S21::list<int> my_list_copy(my_list);
  S21::list<int> my_list_move = std::move(my_list);
  std::list<int> std_list;
  std::list<int> std_list_copy(std_list);
  std::list<int> std_list_move = std::move(std_list);
  EXPECT_TRUE(compare_lists(my_list_move, std_list_move));
}

TEST(ListTest, CopyAssignmentOperator2) {
  S21::list<int> L1 = {1, 2, 3};
  S21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = L2;
  L3 = L4;
  ASSERT_EQ(compare_lists(L1, L3), true);
  ASSERT_EQ(compare_lists(L2, L4), true);
}

TEST(ListTest, MoveAssignmentOperator2) {
  S21::list<int> L1 = {1, 2, 3};
  S21::list<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = std::move(L2);
  L3 = std::move(L4);
  ASSERT_EQ(compare_lists(L1, L3), true);
  ASSERT_EQ(compare_lists(L2, L4), true);
}

TEST(ListTest, Front) {
  S21::list<int> my_list{99, 2, 3, 4, 5};
  std::list<int> std_list{99, 2, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}

TEST(ListTest, Back) {
  S21::list<int> my_list{1, 2, 3, 4, 99};
  std::list<int> std_list{1, 2, 3, 4, 99};
  EXPECT_EQ(my_list.back(), std_list.back());
}

TEST(ListTest, Empty) {
  S21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
  my_list.push_back(10);
  std_list.push_back(10);
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(ListTest, Size) {
  S21::list<int> my_list{1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> std_list{1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, SizeEmpty) {
  S21::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(ListTest, MaxSize) {
  S21::list<size_t> my_list_empty;
  std::list<size_t> std_list_empty;
  EXPECT_EQ(my_list_empty.max_size(), std_list_empty.max_size());
}

TEST(ListTest, Clear) {
  S21::list<int> my_list{1, 2, 3, 4};
  my_list.clear();
  std::list<int> std_list{1, 2, 5, 4, 3};
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, ClearEmpty) {
  S21::list<int> my_list;
  my_list.clear();
  std::list<int> std_list;
  std_list.clear();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushBack) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_back(6);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_back(6);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopBack) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_back();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_back();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PushFront) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.push_front(0);
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.push_front(0);
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, PopFront) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  my_list.pop_front();
  std::list<int> std_list{1, 2, 3, 4, 5};
  std_list.pop_front();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Swap) {
  S21::list<int> my_list1{1, 2, 3, 4, 5};
  S21::list<int> my_list2{6, 7, 8, 9, 10, 11};
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 2, 3, 4, 5};
  std::list<int> std_list2{6, 7, 8, 9, 10, 11};
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, Swap_2) {
  S21::list<int> my_list1{1, 5, 8, 100};
  S21::list<int> my_list2;
  my_list1.swap(my_list2);

  std::list<int> std_list1{1, 5, 8, 100};
  std::list<int> std_list2;
  std_list1.swap(std_list2);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
  EXPECT_TRUE(compare_lists(my_list2, std_list2));
}

TEST(ListTest, begin_1) {
  S21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_2) {
  S21::list<int> my_list1(4);

  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.begin(), *std_list2.begin());
}

TEST(ListTest, begin_3_throw) {
  S21::list<int> my_list1;
  EXPECT_EQ(*my_list1.begin(), 0);
}

TEST(ListTest, end_1) {
  S21::list<int> my_list1{500, 15000, 30000};

  std::list<int> std_list2{500, 15000, 30000};
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, end_2) {
  S21::list<int> my_list1(4);
  std::list<int> std_list2(4);
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, end_3) {
  S21::list<int> my_list1;
  std::list<int> std_list2;
  EXPECT_EQ(*my_list1.end(), *std_list2.end());
}

TEST(ListTest, Merge_1) {
  S21::list<int> my_list1{1, 9999, 20000};
  S21::list<int> my_list2{500, 15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_2) {
  S21::list<int> my_list1{1, 9999, 20000};
  S21::list<int> my_list2{15000, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{15000, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_3) {
  S21::list<int> my_list1{1, 20000, 666};
  S21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_4) {
  S21::list<int> my_list1;
  S21::list<int> my_list2{15000, 154, 124, 30000};
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{15000, 154, 124, 30000};
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_5) {
  S21::list<int> my_list1{1, 20000, 666};
  S21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1{1, 20000, 666};
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Merge_6) {
  S21::list<int> my_list1;
  S21::list<int> my_list2;
  my_list1.merge(my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.merge(std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Reverse_1) {
  S21::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_2) {
  S21::list<int> my_list(4);
  std::list<int> std_list(4);
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Reverse_3) {
  S21::list<int> my_list;
  std::list<int> std_list;
  my_list.reverse();
  std_list.reverse();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_1) {
  S21::list<int> my_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  std::list<int> std_list{90, 10, 3, 40, 30, 20, 10, 10, 90, 90, 90};
  my_list.unique();
  std_list.unique();
  //  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_2) {
  S21::list<int> my_list(3);
  std::list<int> std_list(3);
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Unique_3) {
  S21::list<int> my_list;
  std::list<int> std_list;
  my_list.unique();
  std_list.unique();
  EXPECT_TRUE(compare_lists(my_list, std_list));
}

TEST(ListTest, Splice_1) {
  S21::list<int> my_list1{1, 9999, 20000};
  S21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_2) {
  S21::list<int> my_list1;
  S21::list<int> my_list2{500, 15000, 30000};
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2{500, 15000, 30000};
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_3) {
  S21::list<int> my_list1{1, 9999, 20000};
  S21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1{1, 9999, 20000};
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Splice_4) {
  S21::list<int> my_list1;
  S21::list<int> my_list2;
  my_list1.splice(my_list1.begin(), my_list2);

  std::list<int> std_list1;
  std::list<int> std_list2;
  std_list1.splice(std_list1.begin(), std_list2);
  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_1) {
  S21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_2) {
  S21::list<int> my_list1{1, 9999, 20000};
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_3) {
  S21::list<int> my_list1;
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_4) {
  S21::list<int> my_list1;
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1;
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_5) {
  S21::list<int> my_list1(4);
  my_list1.insert(my_list1.begin(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.begin(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Insert_6) {
  S21::list<int> my_list1(4);
  my_list1.insert(my_list1.end(), 5);

  std::list<int> std_list1(4);
  std_list1.insert(std_list1.end(), 5);

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_1) {
  S21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(my_list1.begin());

  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.begin());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_2_throw) {
  S21::list<int> my_list1{1, 9999, 20000};

  EXPECT_THROW(my_list1.erase(my_list1.end()), std::invalid_argument);
}

TEST(ListTest, Erase_3) {
  S21::list<int> my_list1{1, 9999, 20000};
  my_list1.erase(--my_list1.end());
  my_list1.end()--;
  std::list<int> std_list1{1, 9999, 20000};
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Erase_4_throw) {
  S21::list<int> my_list1;

  EXPECT_THROW(my_list1.erase(my_list1.end()--), std::invalid_argument);
}

TEST(ListTest, Erase_5) {
  S21::list<int> my_list1(5);
  my_list1.erase(--my_list1.end());

  std::list<int> std_list1(5);
  std_list1.erase(std_list1.end().operator--());

  EXPECT_TRUE(compare_lists(my_list1, std_list1));
}

TEST(ListTest, Sort) {
  S21::list<int> my_list{123, 123, 123, 3, -3, 3, 321, 123, 123, 321, 3, 3};
  std::list<int> std_list{123, 123, 123, 3, -3, 3, 321, 123, 123, 321, 3, 3};
  my_list.sort();
  std_list.sort();
  auto it = my_list.begin();
  auto stdit = std_list.begin();
  for (std::size_t i = 0; i < my_list.size(); ++i, ++it, ++stdit) {
    ASSERT_EQ(*it, *stdit);
  }
}

TEST(ListTest, Insert_many) {
  S21::list<int> my_list{123, 123, 123, 3, -3, 3, 321, 123, 123, 321, 3, 3};
  my_list.insert_many_back(-7, 0, 22);
  my_list.insert_many_front(1, 13, 37);
  auto it = my_list.begin();
  for (int i = 0; i < 4; ++i, ++it) {
  }
  my_list.insert_many(it, 21, 42);
  it = my_list.begin();
  for (std::size_t i = 0; i < my_list.size(); ++i, ++it) {
    if (i == 0) {
      ASSERT_EQ(*it, 22);
    }
    if (i == 1) {
      ASSERT_EQ(*it, 0);
    }
    if (i == 2) {
      ASSERT_EQ(*it, -7);
    }
    if (i == my_list.size() - 3) {
      ASSERT_EQ(*it, 1);
    }
    if (i == my_list.size() - 2) {
      ASSERT_EQ(*it, 13);
    }
    if (i == my_list.size() - 1) {
      ASSERT_EQ(*it, 37);
    }
    if (i == 4) {
      ASSERT_EQ(*it, 21);
    }
    if (i == 5) {
      ASSERT_EQ(*it, 42);
    }
  }
}

// SET

TEST(SetTest, DefaultConstructor) {
  S21::set<int> a;
  std::set<int> b;
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(SetTest, InitializerListConstructor) {
  S21::set<int> a{1, 2, 3, 4, 5};
  std::set<int> b{1, 2, 3, 4, 5};
  EXPECT_EQ(a.size(), b.size());
}

TEST(SetTest, CopyConstructor) {
  S21::set<int> a{1, 2, 3, 4, 5};
  S21::set<int> b(a);
  EXPECT_EQ(b.size(), a.size());
}

TEST(SetTest, MoveConstructor) {
  S21::set<int> a{1, 2, 3, 4, 5};
  S21::set<int> b(std::move(a));
  std::set<int> c{1, 2, 3, 4, 5};
  std::set<int> d(std::move(c));

  EXPECT_EQ(b.size(), d.size());
}

TEST(SetTest, copy_asignment) {
  S21::set<int> a{1, 2, 3, 4, 5};
  S21::set<int> b;
  std::set<int> c{1, 2, 3, 4, 5};
  std::set<int> d;
  b = a;
  d = c;
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(SetTest, move_asignment) {
  S21::set<int> a{1, 2};
  S21::set<int> b{3, 4, 5};
  a = std::move(b);
  std::set<int> c{1, 2};
  std::set<int> d{3, 4, 5};
  c = std::move(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(SetTest, begin) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21::set<int>::iterator it = a.begin();
  std::set<int>::iterator set_it = b.begin();
  EXPECT_EQ(*set_it, *(it));
}

TEST(SetTest, iterators) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21::set<int>::iterator it = a.begin();
  std::set<int>::iterator set_it = b.begin();
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), ((*(it))));

  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), ((*(it))));
}

TEST(SetTest, erase) {
  S21::set<int> a{1,  2,   3,   4,    5,    60,   70,  80,
                  90, 100, 110, 1200, 1300, 1400, 1500};
  std::set<int> b{1,  2,   3,   4,    5,    60,   70,  80,
                  90, 100, 110, 1200, 1300, 1400, 1500};
  a.erase(a.begin());
  b.erase(b.begin());
  EXPECT_EQ(a.size(), b.size());
}

TEST(SetTest, erase2) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  std::set<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  S21::set<int>::iterator it1 = a.begin();
  std::set<int>::iterator it2 = b.begin();
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  a.erase(it1);
  b.erase(it2);
  a.erase(a.begin());
  b.erase(b.begin());
  EXPECT_EQ(a.size(), b.size());
}

TEST(SetTest, swap) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7};
  S21::set<int> b;
  std::set<int> c{1, 2, 3, 4, 5, 6, 7};
  std::set<int> d;
  a.swap(b);
  c.swap(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(SetTest, insert) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7};
  std::set<int> b{1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ((a.insert(0)).second, (b.insert(0)).second);
  EXPECT_EQ((a.insert(1)).second, (b.insert(1)).second);
  EXPECT_EQ((a.insert(3)).second, (b.insert(3)).second);
  EXPECT_EQ((a.insert(4)).second, (b.insert(4)).second);
  EXPECT_EQ((a.insert(5)).second, (b.insert(5)).second);
  EXPECT_EQ((a.insert(6)).second, (b.insert(6)).second);
  EXPECT_EQ((a.insert(7)).second, (b.insert(7)).second);
  EXPECT_EQ((a.insert(8)).second, (b.insert(8)).second);
  EXPECT_EQ((a.insert(9)).second, (b.insert(9)).second);
  EXPECT_EQ((a.insert(-1)).second, (b.insert(-1)).second);
  EXPECT_EQ((a.insert(-2)).second, (b.insert(-2)).second);
  EXPECT_EQ((a.insert(-3)).second, (b.insert(-3)).second);
  EXPECT_EQ((a.insert(-4)).second, (b.insert(-4)).second);
  EXPECT_EQ(a.size(), b.size());
}

TEST(SetTest, merge) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7};
  S21::set<int> b{1, 2, 3, 4, 5, 6, 7};
  a.merge(b);
  std::set<int> c{1, 2, 3, 4, 5, 6, 7};
  std::set<int> d{1, 2, 3, 4, 5, 6, 7};
  c.merge(d);
  EXPECT_EQ(a.size(), c.size());
}

TEST(SetTest, find) {
  S21::set<int> a{1, 2, 3, 4, 5, 6, 7};
  std::set<int> b{1, 2, 3, 4, 5, 6, 7};

  EXPECT_EQ((*(a.find(5))), *(b.find(5)));
}

TEST(SetTest, insert_many) {
  S21::set<int> a{1, 2};
  a.insert_many(3, 4, 5);
  std::set<int> b{1, 2, 3, 4, 5};
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.contains(3), 1);
  EXPECT_EQ(a.contains(4), 1);
  EXPECT_EQ(a.contains(5), 1);
}

// MAP

TEST(MapTest, DefaultConstructor) {
  S21::map<int, int> a;
  std::map<int, int> b;
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(MapTest, InitializerListConstructor) {
  S21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.at(2), b.at(2));
  EXPECT_EQ(a[1], b[1]);
}

TEST(MapTest, CopyConstructor) {
  S21::map<int, int> a{{1, 1}, {2, 2}};
  S21::map<int, int> b(a);
  EXPECT_EQ(b.size(), a.size());
}

TEST(MapTest, MoveConstructor) {
  S21::map<int, int> a{{1, 1}, {2, 2}};
  S21::map<int, int> b(std::move(a));
  EXPECT_EQ(b.size(), 2);
  EXPECT_EQ(a.size(), 0);
}

TEST(MapTest, copy_asignment) {
  S21::map<int, int> a{{1, 1}, {2, 2}};
  S21::map<int, int> b{{3, 3}, {4, 4}, {5, 5}};
  a = b;
  EXPECT_EQ(a.size(), b.size());
}

TEST(MapTest, move_asignment) {
  S21::map<int, int> a{{1, 1}, {2, 2}};
  S21::map<int, int> b{{3, 3}, {4, 4}, {5, 5}};
  a = std::move(b);
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(b.size(), 0);
}

TEST(MapTest, at) {
  S21::map<int, int> a{{1, 68}, {2, 78}};
  std::map<int, int> b{{1, 68}, {2, 78}};
  EXPECT_EQ(a.at(1), b.at(1));
  EXPECT_ANY_THROW(a.at(3));
}

TEST(MapTest, operator_brackets) {
  S21::map<int, int> a{{1, 68}, {2, 78}};
  std::map<int, int> b{{1, 68}, {2, 78}};
  EXPECT_EQ(a[1], b[1]);
  EXPECT_EQ(a.contains(2), 1);
  EXPECT_EQ(a[3], b[3]);
  EXPECT_EQ(a.size(), b.size());
}

TEST(MapTest, begin) {
  S21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  S21::map<int, int>::iterator it = a.begin();
  std::map<int, int>::iterator map_it = b.begin();
  EXPECT_EQ(*(it), map_it->first);
}

TEST(MapTest, iterators) {
  S21::map<int, int> a{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  std::map<int, int> b{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5},
                       {6, 6}, {7, 7}, {8, 8}, {9, 9}};
  S21::map<int, int>::iterator it = a.begin();
  std::map<int, int>::iterator map_it = b.begin();
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);
  ++it;
  ++map_it;
  EXPECT_EQ(*(it), map_it->first);

  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
  --it;
  --map_it;
  EXPECT_EQ(*(it), map_it->first);
}

TEST(MapTest, erase) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> b{{1, 5}, {2, 6}, {3, 7}};
  a.erase(a.begin());
  b.erase(b.begin());
  EXPECT_EQ(a.size(), b.size());
  EXPECT_ANY_THROW(a.at(1));
  EXPECT_EQ(a.at(2), b.at(2));
  EXPECT_EQ(a.at(3), b.at(3));
}

TEST(MapTest, swap) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  S21::map<int, int> b;
  std::map<int, int> c{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> d;
  a.swap(b);
  c.swap(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
  EXPECT_EQ(b.at(1), d.at(1));
}

TEST(MapTest, insert1) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> b{{1, 5}, {2, 6}, {3, 7}};
  EXPECT_EQ((a.insert({4, 8})).second, (b.insert({4, 8})).second);
  EXPECT_EQ((a.insert({3, 2})).second, (b.insert({3, 2})).second);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.at(4), b.at(4));
}

TEST(MapTest, insert2) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> b{{1, 5}, {2, 6}, {3, 7}};
  EXPECT_EQ((a.insert(4, 8)).second, (b.insert({4, 8})).second);
  EXPECT_EQ((a.insert(3, 2)).second, (b.insert({3, 2})).second);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.at(4), b.at(4));
}

TEST(MapTest, insert3) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> b{{1, 5}, {2, 6}, {3, 7}};
  EXPECT_EQ((a.insert_or_assign(4, 8)).second,
            (b.insert_or_assign(4, 8)).second);
  EXPECT_EQ((a.insert_or_assign(3, 2)).second,
            (b.insert_or_assign(3, 2)).second);
  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.at(4), b.at(4));
}

TEST(MapTest, merge) {
  S21::map<int, int> a{{1, 5}, {2, 6}, {3, 7}};
  S21::map<int, int> b{{4, 8}, {5, 5}, {1, 3}};
  a.merge(b);
  std::map<int, int> c{{1, 5}, {2, 6}, {3, 7}};
  std::map<int, int> d{{1, 3}, {4, 8}, {5, 5}};
  c.merge(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(a.at(1), c.at(1));
}

TEST(MapTest, insert_many) {
  std::pair<int, int> pair1(1, 5);
  std::pair<int, int> pair2(2, 4);
  std::pair<int, int> pair3(3, 3);
  std::pair<int, int> pair4(4, 2);
  std::pair<int, int> pair5(5, 1);
  S21::map<int, int> a{pair1, pair2};
  a.insert_many(pair3, pair4, pair5);
  S21::map<int, int>::iterator iter(a.begin());
  EXPECT_EQ((*iter), 1);
  ++iter;
  EXPECT_EQ((*iter), 2);
  ++iter;
  EXPECT_EQ((*iter), 3);
  ++iter;
  EXPECT_EQ((*iter), 4);
  ++iter;
  EXPECT_EQ((*iter), 5);
}

// MULTISET

TEST(MultisetTest, DefaultConstructor) {
  S21::multiset<int> a;
  std::multiset<int> b;
  EXPECT_EQ(a.empty(), b.empty());
}

TEST(MultisetTest, InitializerListConstructor) {
  S21::multiset<int> a{1, 2, 3, 4, 5};
  std::multiset<int> b{1, 2, 3, 4, 5};
  EXPECT_EQ(a.size(), b.size());
}

TEST(MultisetTest, Insert) {
  S21::multiset<int> a{1, 2, 3, 4, 5};
  a.insert(1);
  EXPECT_EQ(a.size(), 6);
}

TEST(MultisetTest, CopyConstructor) {
  S21::multiset<int> a{1, 2, 3, 4, 5};
  S21::multiset<int> b(a);
  EXPECT_EQ(b.size(), 5);
}

TEST(MultisetTest, MoveConstructor) {
  S21::multiset<int> a{1, 1, 2, 3, 4, 5};
  S21::multiset<int> b(std::move(a));
  std::multiset<int> c{1, 1, 2, 3, 4, 5};
  std::multiset<int> d(std::move(c));

  EXPECT_EQ(b.size(), d.size());
}

TEST(MultisetTest, copy_asignment) {
  S21::multiset<int> a{1, 2, 3, 4, 5};
  S21::multiset<int> b;
  std::multiset<int> c{1, 2, 3, 4, 5};
  std::multiset<int> d;
  b = a;
  d = c;
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(MultisetTest, move_asignment) {
  S21::multiset<int> a{1, 2};
  S21::multiset<int> b{3, 4, 5};
  a = std::move(b);
  std::multiset<int> c{1, 2};
  std::multiset<int> d{3, 4, 5};
  c = std::move(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(MultisetTest, begin) {
  S21::multiset<int> a{1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9};
  std::multiset<int> b{1, 1, 2, 3, 4, 4, 5, 6, 7, 8, 9};
  S21::multiset<int>::iterator it = a.begin();
  std::multiset<int>::iterator set_it = b.begin();
  EXPECT_EQ(*(set_it), (*(it)));
}

TEST(MultisetTest, iterators) {
  S21::multiset<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::multiset<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};
  S21::multiset<int>::iterator it = a.begin();
  std::multiset<int>::iterator set_it = b.begin();
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  ++it;
  ++set_it;
  EXPECT_EQ(*(set_it), (*(it)));

  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
  --it;
  --set_it;
  EXPECT_EQ(*(set_it), (*(it)));
}
TEST(MultisetTest, swap) {
  S21::multiset<int> a{1, 2, 3, 4, 5, 6, 7};
  S21::multiset<int> b;
  std::multiset<int> c{1, 2, 3, 4, 5, 6, 7};
  std::multiset<int> d;
  a.swap(b);
  c.swap(d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(b.size(), d.size());
}

TEST(MultisetTest, merge) {
  S21::multiset<int> a{1, 2, 3, 4, 5, 6, 7};
  S21::multiset<int> b{1, 2, 3, 4, 5, 6, 7};
  a.merge(b);
  std::multiset<int> c{1, 2, 3, 4, 5, 6, 7};
  std::multiset<int> d{1, 2, 3, 4, 5, 6, 7};
  c.merge(d);
  S21::multiset<int>::iterator it = a.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 1);
  EXPECT_EQ(a.size(), c.size());
}

TEST(MultisetTest, find) {
  S21::multiset<int> a{1, 2, 3, 4, 5, 6, 7};
  std::multiset<int> b{1, 2, 3, 4, 5, 6, 7};

  EXPECT_EQ((*(a.find(5))), *(b.find(5)));
}

TEST(MultisetTest, lower_bound) {
  S21::multiset<int> a{1, 2, 3, 3, 5, 6, 7, 7};
  std::multiset<int> b{1, 2, 3, 3, 5, 6, 7, 7};
  EXPECT_EQ(*(b.lower_bound(-1045)), *(a.lower_bound(-1045)));
  EXPECT_EQ(*(a.lower_bound(3)), *(b.lower_bound(3)));
  EXPECT_EQ(*(a.lower_bound(5)), *(b.lower_bound(5)));
  EXPECT_EQ(*(a.lower_bound(7)), *(b.lower_bound(7)));
}

TEST(MultisetTest, upper_bound) {
  S21::multiset<int> a{1, 2, 3, 3, 5, 6, 7, 7};
  std::multiset<int> b{1, 2, 3, 3, 5, 6, 7, 7};
  EXPECT_EQ(*(b.upper_bound(-1045)), *(a.upper_bound(-1045)));

  EXPECT_EQ(*(a.upper_bound(3)), *(b.upper_bound(3)));
  EXPECT_EQ(*(a.upper_bound(5)), *(b.upper_bound(5)));
}

TEST(MultisetTest, equal_range) {
  S21::multiset<int> a{1, 1, 1, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7};
  std::multiset<int> b{1, 1, 1, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7};

  EXPECT_EQ(*(a.equal_range(5).first), *(b.equal_range(5).first));
  EXPECT_EQ(*(a.equal_range(6).first), *(b.equal_range(6).first));
  EXPECT_EQ(*(a.equal_range(1).first), *(b.equal_range(1).first));
}

TEST(MultisetTest, erase) {
  S21::multiset<int> a{1, 1, 2, 3};
  S21::multiset<int>::iterator iter(a.begin());
  a.erase(iter);
  std::multiset<int> b{1, 1, 2, 3};
  std::multiset<int>::iterator mul_iter = b.begin();
  b.erase(mul_iter);
  EXPECT_EQ(a.size(), b.size());
}

TEST(MultisetTest, insert_many) {
  S21::multiset<int> a{1, 2, 3};
  a.insert_many(1, 4, 5);
  S21::multiset<int>::iterator iter(a.begin());
  EXPECT_EQ(a.size(), 6);
  EXPECT_EQ(iter.getter(), 2);
  ++iter;
  ++iter;
  EXPECT_EQ(iter.getter(), 1);
}

// STACK

TEST(StackTest, Constructor_default) {
  S21::stack<int> my_stack;
  std::stack<int> std_stack;
  EXPECT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_initializer_list_1) {
  S21::stack<int> my_stack{1, 2, 4};
  EXPECT_EQ(my_stack.size(), 3);
  EXPECT_EQ(my_stack.top(), 4);
}

TEST(StackTest, Constructor_initializer_list_2) {
  std::initializer_list<int> b;
  S21::stack<int> my_stack{b};
  std::stack<int> std_stack{b};
  EXPECT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, Constructor_copy_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_copy{my_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_copy{std_stack};
  EXPECT_EQ(my_stack_copy.size(), std_stack_copy.size());
  EXPECT_EQ(my_stack_copy.top(), std_stack_copy.top());
}

TEST(StackTest, Constructor_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_move{my_stack};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{std_stack};
  EXPECT_EQ(my_stack_move.size(), std_stack_move.size());
  EXPECT_EQ(my_stack_move.top(), std_stack_move.top());
}

TEST(StackTest, Opertator_move_1) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_move{il2};
  my_stack = std::move(my_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_move{il2};
  my_stack = std::move(my_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Opertator_move_3) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_move{il2};
  my_stack = std::move(my_stack_move);

  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_move{il2};
  std_stack = std::move(std_stack_move);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Top_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};

  std::stack<int> std_stack{il1};

  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Top_2_throw) {
  std::initializer_list<int> il1;

  S21::stack<int> my_stack{il1};

  EXPECT_THROW(my_stack.top(), std::out_of_range);
}

TEST(StackTest, Empty_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(my_stack.empty(), std_stack.empty());
}

TEST(StackTest, Empty_2) {
  std::initializer_list<int> il1;

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(my_stack.empty(), std_stack.empty());
}

TEST(StackTest, Size_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, Size_2) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};

  EXPECT_EQ(my_stack.size(), std_stack.size());
}

TEST(StackTest, Push_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};
  my_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Push_2) {
  std::initializer_list<int> il1;

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};
  my_stack.push(1);
  std_stack.push(1);
  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};
  my_stack.pop();
  std_stack.pop();
  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());
}

TEST(StackTest, Pop_2) {
  std::initializer_list<int> il1;

  S21::stack<int> my_stack{il1};
  std::stack<int> std_stack{il1};
  my_stack.pop();
  std_stack.pop();
  EXPECT_EQ(my_stack.size(), 0);
}

TEST(StackTest, Swap_1) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {1, 2, 3};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(my_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_2) {
  std::initializer_list<int> il1 = {1, 2, 3};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(my_stack_swap.top(), std_stack_swap.top());
}

TEST(StackTest, Swap_3) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2;

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_4) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_5) {
  std::initializer_list<int> il1;
  std::initializer_list<int> il2;

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
}

TEST(StackTest, Swap_6) {
  std::initializer_list<int> il1 = {4, 5, 6, 7};
  std::initializer_list<int> il2 = {4, 5, 6, 7};

  S21::stack<int> my_stack{il1};
  S21::stack<int> my_stack_swap{il2};
  std::stack<int> std_stack{il1};
  std::stack<int> std_stack_swap{il2};
  my_stack.swap(my_stack_swap);
  std_stack.swap(std_stack_swap);

  EXPECT_EQ(my_stack.size(), std_stack.size());
  EXPECT_EQ(my_stack.top(), std_stack.top());

  EXPECT_EQ(my_stack_swap.size(), std_stack_swap.size());
  EXPECT_EQ(my_stack_swap.top(), std_stack_swap.top());
}

// QUEUE

template <typename value_type>
bool compare_queue(S21::queue<value_type> my_queue,
                   std::queue<value_type> std_queue) {
  bool result = true;
  if (my_queue.size() == std_queue.size()) {
    while (!my_queue.empty() && !std_queue.empty()) {
      if (my_queue.front() != std_queue.front()) {
        result = false;
        break;
      }
      my_queue.pop();
      std_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(QueueTest, CompareQueues) {
  S21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, CompareQueues_2) {
  S21::queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(100);
  EXPECT_FALSE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, DefaultConstructor) {
  S21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.size(), 0);
  EXPECT_TRUE(my_queue.empty());
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor) {
  S21::queue<int> my_queue{1, 2, 3, 7, 9};
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  S21::queue<int> my_queue{b};
  std::queue<int> std_queue{b};
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, CopyConstructor) {
  S21::queue<int> my_queue{1, 2, 3, 7, 9};
  S21::queue<int> my_queue_copy(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 9};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queue(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, CopyConstructorEmpty) {
  S21::queue<int> my_queue;
  S21::queue<int> my_queue_copy(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  EXPECT_TRUE(compare_queue(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructor) {
  S21::queue<int> my_queue{1, 2, 3, 7, 20};
  S21::queue<int> my_queue_copy(my_queue);
  S21::queue<int> my_queue_move(std::move(my_queue));
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queue(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveConstructorEmpty) {
  S21::queue<int> my_queue;
  S21::queue<int> my_queue_copy(my_queue);
  S21::queue<int> my_queue_move(std::move(my_queue));
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move(std::move(std_queue));
  EXPECT_TRUE(compare_queue(my_queue_copy, std_queue_copy));
}

TEST(QueueTest, MoveAssignmentOperator) {
  S21::queue<int> my_queue{1, 2, 3, 7, 20};
  S21::queue<int> my_queue_copy(my_queue);
  S21::queue<int> my_queue_move = std::move(my_queue);
  std::initializer_list<int> il = {1, 2, 3, 7, 20};
  std::queue<int> std_queue{il};
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queue(my_queue_move, std_queue_move));
}

TEST(QueueTest, MoveAssignmentOperatorEmpty) {
  S21::queue<int> my_queue;
  S21::queue<int> my_queue_copy(my_queue);
  S21::queue<int> my_queue_move = std::move(my_queue);
  std::queue<int> std_queue;
  std::queue<int> std_queue_copy(std_queue);
  std::queue<int> std_queue_move = std::move(std_queue);
  EXPECT_TRUE(compare_queue(my_queue_move, std_queue_move));
}

TEST(QueueTest, Front) {
  S21::queue<int> my_queue{99, 2, 3, 4, 5};
  std::initializer_list<int> il = {99, 1, 3, 7, 20};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.front(), std_queue.front());
}

TEST(QueueTest, Back) {
  S21::queue<int> my_queue{1, 2, 3, 3, 4, 99};
  std::initializer_list<int> il = {99, 1, 3, 5, 4, 7, 99};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.back(), std_queue.back());
}

TEST(QueueTest, Empty) {
  S21::queue<int> my_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_EQ(my_queue.empty(), std_queue.empty());
}

TEST(QueueTest, Size) {
  S21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  EXPECT_EQ(my_queue.size(), std_queue.size());
}

TEST(QueueTest, Push) {
  S21::queue<int> my_queue;
  std::queue<int> std_queue;
  my_queue.push(627);
  std_queue.push(627);
  my_queue.push(2354);
  std_queue.push(2354);
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
}

TEST(QueueTest, Pop) {
  S21::queue<int> my_queue{1, 2, 3, 4, 5, 6, 7, 8};
  std::initializer_list<int> il = {1, 2, 3, 4, 5, 6, 7, 8};
  std::queue<int> std_queue{il};
  my_queue.pop();
  my_queue.pop();
  std_queue.pop();
  std_queue.pop();
  EXPECT_TRUE(compare_queue(my_queue, std_queue));
  EXPECT_EQ(my_queue.front(), 3);
}

TEST(QueueTest, Swap) {
  S21::queue<int> my_queue1{1, 2, 3, 4, 5};
  S21::queue<int> my_queue2{6, 7, 8, 9, 10, 11};
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il1 = {1, 2, 3, 4, 5};
  std::initializer_list<int> il2 = {6, 7, 8, 9, 10, 11};
  std::queue<int> std_queue1{il1};
  std::queue<int> std_queue2{il2};
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queue(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queue(my_queue2, std_queue2));
}

TEST(QueueTest, Swap_2) {
  S21::queue<int> my_queue1{1, 2, 99, 4, 242};
  S21::queue<int> my_queue2;
  my_queue1.swap(my_queue2);

  std::initializer_list<int> il = {1, 2, 99, 4, 242};
  std::queue<int> std_queue1{il};
  std::queue<int> std_queue2;
  std_queue1.swap(std_queue2);

  EXPECT_TRUE(compare_queue(my_queue1, std_queue1));
  EXPECT_TRUE(compare_queue(my_queue2, std_queue2));
}

// VECTOR

TEST(vector_constructor, case1) {
  S21::vector<int> S21_vec_int;
  S21::vector<double> S21_vec_double;
  S21::vector<std::string> S21_vec_string;

  EXPECT_EQ(S21_vec_int.size(), 0U);
  EXPECT_EQ(S21_vec_int.capacity(), 0U);
  EXPECT_EQ(&S21_vec_int[0], nullptr);

  EXPECT_EQ(S21_vec_double.size(), 0U);
  EXPECT_EQ(S21_vec_double.capacity(), 0U);
  EXPECT_EQ(&S21_vec_double[0], nullptr);

  EXPECT_EQ(S21_vec_string.size(), 0U);
  EXPECT_EQ(S21_vec_string.capacity(), 0U);
  EXPECT_EQ(&S21_vec_string[0], nullptr);
}

TEST(vector_constructor, case2) {
  S21::vector<int> S21_vec_int(5);
  S21::vector<double> S21_vec_double(5);
  S21::vector<std::string> S21_vec_string(5);

  EXPECT_EQ(S21_vec_int.size(), 5U);
  EXPECT_EQ(S21_vec_int.capacity(), 5U);
  EXPECT_NE(&S21_vec_int[0], nullptr);

  EXPECT_EQ(S21_vec_double.size(), 5U);
  EXPECT_EQ(S21_vec_double.capacity(), 5U);
  EXPECT_NE(&S21_vec_double[0], nullptr);

  EXPECT_EQ(S21_vec_string.size(), 5U);
  EXPECT_EQ(S21_vec_string.capacity(), 5U);
  EXPECT_NE(&S21_vec_string[0], nullptr);
}

TEST(vector_constructor, case3) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.size(), 4U);
  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_int[0], 1);
  EXPECT_EQ(S21_vec_int[1], 4);
  EXPECT_EQ(S21_vec_int[2], 8);
  EXPECT_EQ(S21_vec_int[3], 9);

  EXPECT_EQ(S21_vec_double.size(), 4U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_double[0], 1.4);
  EXPECT_EQ(S21_vec_double[1], 4.8);
  EXPECT_EQ(S21_vec_double[2], 8.9);
  EXPECT_EQ(S21_vec_double[3], 9.1);

  EXPECT_EQ(S21_vec_string.size(), 4U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
  EXPECT_EQ(S21_vec_string[0], "Hello");
  EXPECT_EQ(S21_vec_string[1], ",");
  EXPECT_EQ(S21_vec_string[2], "world");
  EXPECT_EQ(S21_vec_string[3], "!");
}

TEST(vector_constructor, case4) {
  S21::vector<int> S21_vec_ref_int{1, 4, 8, 9};
  S21::vector<int> S21_vec_res_int(S21_vec_ref_int);

  S21::vector<double> S21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<double> S21_vec_res_double(S21_vec_ref_double);

  S21::vector<std::string> S21_vec_ref_string{"Hello", ",", "world", "!"};
  S21::vector<std::string> S21_vec_res_string(S21_vec_ref_string);

  EXPECT_EQ(S21_vec_ref_int.size(), S21_vec_res_int.size());
  EXPECT_EQ(S21_vec_ref_int.capacity(), S21_vec_res_int.capacity());
  EXPECT_EQ(S21_vec_ref_int[0], S21_vec_res_int[0]);
  EXPECT_EQ(S21_vec_ref_int[1], S21_vec_res_int[1]);
  EXPECT_EQ(S21_vec_ref_int[2], S21_vec_res_int[2]);
  EXPECT_EQ(S21_vec_ref_int[3], S21_vec_res_int[3]);

  EXPECT_EQ(S21_vec_ref_double.size(), S21_vec_res_double.size());
  EXPECT_EQ(S21_vec_ref_double.capacity(), S21_vec_res_double.capacity());
  EXPECT_EQ(S21_vec_ref_double[0], S21_vec_res_double[0]);
  EXPECT_EQ(S21_vec_ref_double[1], S21_vec_res_double[1]);
  EXPECT_EQ(S21_vec_ref_double[2], S21_vec_res_double[2]);
  EXPECT_EQ(S21_vec_ref_double[3], S21_vec_res_double[3]);

  EXPECT_EQ(S21_vec_ref_string.size(), S21_vec_res_string.size());
  EXPECT_EQ(S21_vec_ref_string.capacity(), S21_vec_res_string.capacity());
  EXPECT_EQ(S21_vec_ref_string[0], S21_vec_res_string[0]);
  EXPECT_EQ(S21_vec_ref_string[1], S21_vec_res_string[1]);
  EXPECT_EQ(S21_vec_ref_string[2], S21_vec_res_string[2]);
  EXPECT_EQ(S21_vec_ref_string[3], S21_vec_res_string[3]);
}

TEST(vector_constructor, case5) {
  S21::vector<int> S21_vec_ref_int{1, 4, 8, 9};
  S21::vector<int> S21_vec_res_int = std::move(S21_vec_ref_int);
  S21::vector<double> S21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<double> S21_vec_res_double = std::move(S21_vec_ref_double);
  S21::vector<std::string> S21_vec_ref_string{"Hello", ",", "world", "!"};
  S21::vector<std::string> S21_vec_res_string = std::move(S21_vec_ref_string);

  EXPECT_EQ(S21_vec_ref_int.size(), 0U);
  EXPECT_EQ(S21_vec_ref_int.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_int.size(), 4U);
  EXPECT_EQ(S21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_int[0], 1);
  EXPECT_EQ(S21_vec_res_int[1], 4);
  EXPECT_EQ(S21_vec_res_int[2], 8);
  EXPECT_EQ(S21_vec_res_int[3], 9);

  EXPECT_EQ(S21_vec_ref_double.size(), 0U);
  EXPECT_EQ(S21_vec_ref_double.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_double.size(), 4U);
  EXPECT_EQ(S21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_double[0], 1.4);
  EXPECT_EQ(S21_vec_res_double[1], 4.8);
  EXPECT_EQ(S21_vec_res_double[2], 8.9);
  EXPECT_EQ(S21_vec_res_double[3], 9.1);

  EXPECT_EQ(S21_vec_ref_string.size(), 0U);
  EXPECT_EQ(S21_vec_ref_string.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_string.size(), 4U);
  EXPECT_EQ(S21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_string[0], "Hello");
  EXPECT_EQ(S21_vec_res_string[1], ",");
  EXPECT_EQ(S21_vec_res_string[2], "world");
  EXPECT_EQ(S21_vec_res_string[3], "!");
}

TEST(vector_constructor, case6) {
  S21::vector<int> S21_vec_ref_int{1, 4, 8, 9};
  S21::vector<int> S21_vec_res_int;
  S21_vec_res_int = std::move(S21_vec_ref_int);

  S21::vector<double> S21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<double> S21_vec_res_double;
  S21_vec_res_double = std::move(S21_vec_ref_double);

  S21::vector<std::string> S21_vec_ref_string{"Hello", ",", "world", "!"};
  S21::vector<std::string> S21_vec_res_string;
  S21_vec_res_string = std::move(S21_vec_ref_string);

  EXPECT_EQ(S21_vec_ref_int.size(), 0U);
  EXPECT_EQ(S21_vec_ref_int.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_int.size(), 4U);
  EXPECT_EQ(S21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_int[0], 1);
  EXPECT_EQ(S21_vec_res_int[1], 4);
  EXPECT_EQ(S21_vec_res_int[2], 8);
  EXPECT_EQ(S21_vec_res_int[3], 9);

  EXPECT_EQ(S21_vec_ref_double.size(), 0U);
  EXPECT_EQ(S21_vec_ref_double.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_double.size(), 4U);
  EXPECT_EQ(S21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_double[0], 1.4);
  EXPECT_EQ(S21_vec_res_double[1], 4.8);
  EXPECT_EQ(S21_vec_res_double[2], 8.9);
  EXPECT_EQ(S21_vec_res_double[3], 9.1);

  EXPECT_EQ(S21_vec_ref_string.size(), 0U);
  EXPECT_EQ(S21_vec_ref_string.capacity(), 0U);
  EXPECT_EQ(S21_vec_res_string.size(), 4U);
  EXPECT_EQ(S21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_string[0], "Hello");
  EXPECT_EQ(S21_vec_res_string[1], ",");
  EXPECT_EQ(S21_vec_res_string[2], "world");
  EXPECT_EQ(S21_vec_res_string[3], "!");
}

TEST(vector_at, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.at(0), 1);
  EXPECT_EQ(S21_vec_double.at(0), 1.4);
  EXPECT_EQ(S21_vec_string.at(0), "Hello");
}

TEST(vector_at, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_THROW(S21_vec_int.at(5), std::out_of_range);
  EXPECT_THROW(S21_vec_double.at(5), std::out_of_range);
  EXPECT_THROW(S21_vec_string.at(5), std::out_of_range);
}

TEST(vector_at, case3) {
  S21::vector<int> S21_vec_int;
  S21::vector<double> S21_vec_double;
  S21::vector<std::string> S21_vec_string;

  EXPECT_THROW(S21_vec_int.at(5), std::out_of_range);
  EXPECT_THROW(S21_vec_double.at(5), std::out_of_range);
  EXPECT_THROW(S21_vec_string.at(5), std::out_of_range);
}

TEST(vector_square_braces, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int[3], 9);
  EXPECT_EQ(S21_vec_double[0], 1.4);
  EXPECT_EQ(S21_vec_string[0], "Hello");
}

TEST(vector_front, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.front(), 1);
  EXPECT_EQ(S21_vec_double.front(), 1.4);
  EXPECT_EQ(S21_vec_string.front(), "Hello");
}

TEST(vector_back, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.back(), 9);
  EXPECT_EQ(S21_vec_double.back(), 9.1);
  EXPECT_EQ(S21_vec_string.back(), "!");
}

TEST(vector_data, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.data(), &S21_vec_int[0]);
  EXPECT_EQ(S21_vec_double.data(), &S21_vec_double[0]);
  EXPECT_EQ(S21_vec_string.data(), &S21_vec_string[0]);
}

TEST(vector_begin, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.begin(), &S21_vec_int[0]);
  EXPECT_EQ(S21_vec_double.begin(), &S21_vec_double[0]);
  EXPECT_EQ(S21_vec_string.begin(), &S21_vec_string[0]);
}

TEST(vector_end, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.end(), &S21_vec_int[0] + 4);
  EXPECT_EQ(S21_vec_double.end(), &S21_vec_double[0] + 4);
  EXPECT_EQ(S21_vec_string.end(), &S21_vec_string[0] + 4);
}

TEST(vector_empty, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.empty(), 0);
  EXPECT_EQ(S21_vec_double.empty(), 0);
  EXPECT_EQ(S21_vec_string.empty(), 0);
}

TEST(vector_empty, case2) {
  S21::vector<int> S21_vec_int{};
  S21::vector<double> S21_vec_double{};
  S21::vector<std::string> S21_vec_string{};

  EXPECT_EQ(S21_vec_int.empty(), 1);
  EXPECT_EQ(S21_vec_double.empty(), 1);
  EXPECT_EQ(S21_vec_string.empty(), 1);
}

TEST(vector_size, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.size(), 4U);
  EXPECT_EQ(S21_vec_double.size(), 4U);
  EXPECT_EQ(S21_vec_string.size(), 4U);
}

TEST(vector_size, case2) {
  S21::vector<int> S21_vec_int{};
  S21::vector<double> S21_vec_double{};
  S21::vector<std::string> S21_vec_string{};

  EXPECT_EQ(S21_vec_int.size(), 0U);
  EXPECT_EQ(S21_vec_double.size(), 0U);
  EXPECT_EQ(S21_vec_string.size(), 0U);
}

TEST(vector_max_size, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  std::vector<int> std_vec_int{1, 4, 8, 9};

  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  std::vector<double> std_vec_double{1.4, 4.8, 8.9, 9.1};

  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};
  std::vector<std::string> std_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.max_size(), std_vec_int.max_size());
  EXPECT_EQ(S21_vec_double.max_size(), std_vec_double.max_size());
  EXPECT_EQ(S21_vec_string.max_size(), std_vec_string.max_size());
}

TEST(vector_reserve, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.reserve(20);
  S21_vec_double.reserve(20);
  S21_vec_string.reserve(20);

  EXPECT_EQ(S21_vec_int.capacity(), 20U);
  EXPECT_EQ(S21_vec_double.capacity(), 20U);
  EXPECT_EQ(S21_vec_string.capacity(), 20U);
}

TEST(vector_reserve, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.reserve(2);
  S21_vec_double.reserve(2);
  S21_vec_string.reserve(2);

  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
}

TEST(vector_capacity, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
}

TEST(vector_capacity, case2) {
  S21::vector<int> S21_vec_int{};
  S21::vector<double> S21_vec_double{};
  S21::vector<std::string> S21_vec_string{};

  EXPECT_EQ(S21_vec_int.capacity(), 0U);
  EXPECT_EQ(S21_vec_double.capacity(), 0U);
  EXPECT_EQ(S21_vec_string.capacity(), 0U);
}

TEST(vector_shrink_to_fit, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.reserve(20);
  S21_vec_double.reserve(20);
  S21_vec_string.reserve(20);

  S21_vec_int.shrink_to_fit();
  S21_vec_double.shrink_to_fit();
  S21_vec_string.shrink_to_fit();

  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
}

TEST(vector_shrink_to_fit, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.shrink_to_fit();
  S21_vec_double.shrink_to_fit();
  S21_vec_string.shrink_to_fit();

  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
}

TEST(vector_clear, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.clear();
  S21_vec_double.clear();
  S21_vec_string.clear();

  EXPECT_EQ(&S21_vec_int[0], nullptr);
  EXPECT_EQ(&S21_vec_double[0], nullptr);
  EXPECT_EQ(&S21_vec_string[0], nullptr);
}

TEST(vector_clear, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.clear();
  S21_vec_double.clear();
  S21_vec_string.clear();

  EXPECT_EQ(&S21_vec_int[0], nullptr);
  EXPECT_EQ(&S21_vec_double[0], nullptr);
  EXPECT_EQ(&S21_vec_string[0], nullptr);
}

TEST(vector_insert, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "", "!"};

  auto pos_int = S21_vec_int.begin() + 2;
  auto pos_double = S21_vec_double.begin() + 2;
  auto pos_string = S21_vec_string.begin() + 2;

  S21_vec_int.insert(pos_int, 2);
  S21_vec_double.insert(pos_double, 2.0);
  S21_vec_string.insert(pos_string, "world");

  EXPECT_EQ(S21_vec_int[2], 2);
  EXPECT_EQ(S21_vec_double[2], 2.0);
  EXPECT_EQ(S21_vec_string[2], "world");
}

TEST(vector_insert, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "", "!"};

  auto pos_int = S21_vec_int.begin();
  auto pos_double = S21_vec_double.begin();
  auto pos_string = S21_vec_string.begin();

  S21_vec_int.insert(pos_int, 2);
  S21_vec_double.insert(pos_double, 2.0);
  S21_vec_string.insert(pos_string, "world");

  EXPECT_EQ(S21_vec_int[0], 2);
  EXPECT_EQ(S21_vec_double[0], 2.0);
  EXPECT_EQ(S21_vec_string[0], "world");
}

TEST(vector_insert, case3) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "", "!"};

  auto pos_int = S21_vec_int.end();
  auto pos_double = S21_vec_double.end();
  auto pos_string = S21_vec_string.end();

  S21_vec_int.insert(pos_int, 2);
  S21_vec_double.insert(pos_double, 2.0);
  S21_vec_string.insert(pos_string, "world");

  EXPECT_EQ(S21_vec_int[4], 2);
  EXPECT_EQ(S21_vec_double[4], 2.0);
  EXPECT_EQ(S21_vec_string[4], "world");
}

TEST(vector_erase, case1) {
  S21::vector<int> S21_vec_int{1, 4, 1, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 1.0, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "", "world", "!"};

  auto pos_int = S21_vec_int.begin() + 2;
  auto pos_double = S21_vec_double.begin() + 2;
  auto pos_string = S21_vec_string.begin() + 2;

  S21_vec_int.erase(pos_int);
  S21_vec_double.erase(pos_double);
  S21_vec_string.erase(pos_string);

  EXPECT_EQ(S21_vec_int[2], 8);
  EXPECT_EQ(S21_vec_double[2], 8.9);
  EXPECT_EQ(S21_vec_string[2], "world");
}

TEST(vector_erase, case2) {
  S21::vector<int> S21_vec_int{1, 1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.0, 1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"", "Hello", ",", "world", "!"};

  auto pos_int = S21_vec_int.begin();
  auto pos_double = S21_vec_double.begin();
  auto pos_string = S21_vec_string.begin();

  S21_vec_int.erase(pos_int);
  S21_vec_double.erase(pos_double);
  S21_vec_string.erase(pos_string);

  EXPECT_EQ(S21_vec_int[0], 1);
  EXPECT_EQ(S21_vec_double[0], 1.4);
  EXPECT_EQ(S21_vec_string[0], "Hello");
}

TEST(vector_push_back, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.push_back(10);
  S21_vec_double.push_back(10.0);
  S21_vec_string.push_back("!!");

  EXPECT_EQ(*(S21_vec_int.end() - 1), 10);
  EXPECT_EQ(*(S21_vec_double.end() - 1), 10.0);
  EXPECT_EQ(*(S21_vec_string.end() - 1), "!!");
}

TEST(vector_push_back, case2) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.reserve(20);
  S21_vec_double.reserve(20);
  S21_vec_string.reserve(20);

  S21_vec_int.push_back(10);
  S21_vec_double.push_back(10.0);
  S21_vec_string.push_back("!!");

  EXPECT_EQ(*(S21_vec_int.end() - 1), 10);
  EXPECT_EQ(*(S21_vec_double.end() - 1), 10.0);
  EXPECT_EQ(*(S21_vec_string.end() - 1), "!!");
}

TEST(vector_pop_back, case1) {
  S21::vector<int> S21_vec_int{1, 4, 8, 9};
  S21::vector<double> S21_vec_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<std::string> S21_vec_string{"Hello", ",", "world", "!"};

  S21_vec_int.pop_back();
  S21_vec_double.pop_back();
  S21_vec_string.pop_back();

  EXPECT_EQ(S21_vec_int.size(), 3U);
  EXPECT_EQ(S21_vec_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_double.size(), 3U);
  EXPECT_EQ(S21_vec_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_string.size(), 3U);
  EXPECT_EQ(S21_vec_string.capacity(), 4U);
}

TEST(vector_swap, case1) {
  S21::vector<int> S21_vec_ref_int{1, 4, 8, 9};
  S21::vector<int> S21_vec_res_int{0, 0, 0};

  S21::vector<double> S21_vec_ref_double{1.4, 4.8, 8.9, 9.1};
  S21::vector<double> S21_vec_res_double{0.0, 0.0, 0.0};

  S21::vector<std::string> S21_vec_ref_string{"Hello", ",", "world", "!"};
  S21::vector<std::string> S21_vec_res_string{"", "", ""};

  S21_vec_ref_int.swap_(S21_vec_res_int);
  S21_vec_ref_double.swap_(S21_vec_res_double);
  S21_vec_ref_string.swap_(S21_vec_res_string);

  EXPECT_EQ(S21_vec_res_int.size(), 4U);
  EXPECT_EQ(S21_vec_res_int.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_int[2], 8);

  EXPECT_EQ(S21_vec_res_double.size(), 4U);
  EXPECT_EQ(S21_vec_res_double.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_double[2], 8.9);

  EXPECT_EQ(S21_vec_res_string.size(), 4U);
  EXPECT_EQ(S21_vec_res_string.capacity(), 4U);
  EXPECT_EQ(S21_vec_res_string[2], "world");
}

TEST(vector_emplace, case1) {
  S21::vector<int> S21_vec_int{1, 4};
  S21::vector<double> S21_vec_double{1.4, 4.8};
  S21::vector<std::string> S21_vec_string{"Hello", ","};

  auto pos_int = S21_vec_int.begin() + 1;
  auto pos_double = S21_vec_double.begin() + 1;
  auto pos_string = S21_vec_string.begin() + 1;

  S21_vec_int.insert_many(pos_int, 2, 3);
  S21_vec_double.insert_many(pos_double, 2.0, 3.56);
  S21_vec_string.insert_many(pos_string, "world", "!");

  EXPECT_EQ(S21_vec_int[1], 2);
  EXPECT_EQ(S21_vec_int[2], 3);

  EXPECT_EQ(S21_vec_double[1], 2.0);
  EXPECT_EQ(S21_vec_double[2], 3.56);

  EXPECT_EQ(S21_vec_string[1], "world");
  EXPECT_EQ(S21_vec_string[2], "!");
}

TEST(vector_emplace, case2) {
  S21::vector<int> S21_vec_int{1, 4};
  S21::vector<double> S21_vec_double{1.4, 4.8};
  S21::vector<std::string> S21_vec_string{"Hello", ","};

  auto pos_int = S21_vec_int.begin();
  auto pos_double = S21_vec_double.begin();
  auto pos_string = S21_vec_string.begin();

  S21_vec_int.insert_many(pos_int, 2, 3);
  S21_vec_double.insert_many(pos_double, 2.0, 3.56);
  S21_vec_string.insert_many(pos_string, "world", "!");

  EXPECT_EQ(S21_vec_int[0], 2);
  EXPECT_EQ(S21_vec_int[1], 3);

  EXPECT_EQ(S21_vec_double[0], 2.0);
  EXPECT_EQ(S21_vec_double[1], 3.56);

  EXPECT_EQ(S21_vec_string[0], "world");
  EXPECT_EQ(S21_vec_string[1], "!");
}

TEST(vector_emplace, case3) {
  S21::vector<int> S21_vec_int;
  S21::vector<double> S21_vec_double;
  S21::vector<std::string> S21_vec_string;

  auto pos_int = S21_vec_int.begin();
  auto pos_double = S21_vec_double.begin();
  auto pos_string = S21_vec_string.begin();

  S21_vec_int.insert_many(pos_int, 2, 3);
  S21_vec_double.insert_many(pos_double, 2.0, 3.56);
  S21_vec_string.insert_many(pos_string, "world", "!");

  EXPECT_EQ(S21_vec_int[0], 2);
  EXPECT_EQ(S21_vec_int[1], 3);

  EXPECT_EQ(S21_vec_double[0], 2.0);
  EXPECT_EQ(S21_vec_double[1], 3.56);

  EXPECT_EQ(S21_vec_string[0], "world");
  EXPECT_EQ(S21_vec_string[1], "!");
}

TEST(vector_emplace_back, case1) {
  S21::vector<int> S21_vec_int{1, 4};
  S21::vector<double> S21_vec_double{1.4, 4.8};
  S21::vector<std::string> S21_vec_string{"Hello", ","};

  S21_vec_int.insert_many_back(2, 3);
  S21_vec_double.insert_many_back(2.0, 3.56);
  S21_vec_string.insert_many_back("world", "!");

  EXPECT_EQ(S21_vec_int[2], 2);
  EXPECT_EQ(S21_vec_int[3], 3);

  EXPECT_EQ(S21_vec_double[2], 2.0);
  EXPECT_EQ(S21_vec_double[3], 3.56);

  EXPECT_EQ(S21_vec_string[2], "world");
  EXPECT_EQ(S21_vec_string[3], "!");
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}