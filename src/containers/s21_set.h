#ifndef S21_SET_H
#define S21_SET_H

#include "../s21_containers.h"

namespace S21 {
template <typename T>
class set {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RBT<key_type, value_type>::iterator;
  using const_iterator = typename RBT<key_type, value_type>::const_iterator;
  using size_type = size_t;

  set() : tree_() {}
  set(std::initializer_list<value_type> const &items) {
    if (items.size()) {
      for (auto it = items.begin(); it != items.end(); it++) {
        tree_.Insert(*it, 1);
      }
    }
  }
  set(const set &s) : tree_(s.tree_) {}
  set(set &&s) : tree_(s.tree_) { s.clear(); }
  ~set() { tree_.Delete(); }

  set &operator=(set &&s) {
    tree_ = std::move(s.tree_);
    return *this;
  }

  set &operator=(const set &s) {
    tree_.Delete();
    tree_ = s.tree_;
    return *this;
  }

  iterator begin() { return iterator(tree_.begin()); }
  iterator end() { return iterator(tree_.end()); }

  bool empty() { return !tree_.Size(); }
  size_type size() { return tree_.Size(); }
  size_type max_size() {
    int sys = sizeof(void *) == 4 ? 31 : 63;
    return static_cast<size_type>(pow(2, sys)) / sizeof(value_type) - 1;
  }

  void clear() { tree_.Delete(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.Insert(value, 1);
  }
  void erase(iterator pos) { tree_.Remove(pos.it_); }
  void swap(set &other) { tree_.Swap(other.tree_); }
  void merge(set &other) {
    if (!other.empty()) {
      for (auto pos = other.begin(); pos != other.end(); ++pos) {
        if ((insert(*pos)).second) {
          other.erase(pos);
        }
      }
    }
  }

  iterator find(const key_type &key) { return iterator(tree_.Search(key)); }
  bool contains(const key_type &key) {
    return tree_.Search(key) ? true : false;
  }

  template <class... Args>
  void insert_many(Args &&...args) {
    insert_many_aux(args...);
  }

 private:
  RBT<key_type, int> tree_;

  template <class U>
  void insert_many_aux(U &&arg) {
    insert(arg);
  }

  template <class U, class... Args>
  void insert_many_aux(U &&arg, Args &&...args) {
    insert(arg);
    insert_many_aux(args...);
  }
};
}  // namespace S21

#endif
