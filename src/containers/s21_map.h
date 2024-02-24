#ifndef S21_MAP_H
#define S21_MAP_H

#include "../s21_containers.h"
#include "s21_tree.h"

namespace S21 {
template <typename K, typename T>
class map {
 public:
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using Node = typename RBT<key_type, mapped_type>::Node;
  using iterator = typename RBT<key_type, mapped_type>::iterator;
  using const_iterator = typename RBT<key_type, mapped_type>::const_iterator;
  using size_type = size_t;

  map() : tree_() {}
  map(std::initializer_list<value_type> const &items) {
    if (items.size()) {
      for (value_type it : items) {
        tree_.Insert(it.first, it.second);
      }
    }
  }
  map(const map &m) : tree_(m.tree_) {}
  map(map &&m) : tree_(m.tree_) { m.clear(); }
  ~map() { tree_.Delete(); }

  map &operator=(map &&m) {
    tree_ = std::move(m.tree_);
    return *this;
  }

  map &operator=(map &m) {
    tree_.Delete();
    tree_ = m.tree_;
    return *this;
  }

  T &at(const K &key) {
    Node *node = tree_.Search(key);
    if (node) {
      return node->value;
    } else {
      throw std::out_of_range("Out of range");
    }
  }

  T &operator[](const K &key) {
    iterator res = iterator(tree_.Search(key));
    if (res.it_) {
      return res.it_->value;
    } else {
      res = insert(key, mapped_type()).first;
      return res.it_->value;
    }
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
    return tree_.Insert(value.first, value.second);
  }
  std::pair<iterator, bool> insert(const K &key, const T &obj) {
    return tree_.Insert(key, obj);
  }
  std::pair<iterator, bool> insert_or_assign(const K &key, const T &obj) {
    std::pair<iterator, bool> res = tree_.Insert(key, obj);
    if (!res.second) {
      tree_.Remove(res.first.it_);
      tree_.Insert(key, obj);
    }
    return res;
  }
  void erase(iterator pos) { tree_.Remove(pos.it_); }
  void swap(map &other) { tree_.Swap(other.tree_); }
  void merge(map &other) {
    if (!other.empty()) {
      for (auto pos = other.begin(); pos != other.end();) {
        if ((insert(pos.it_->key, pos.it_->value)).second) {
          Node *node = other.tree_.Search(pos.it_->key);
          ++pos;
          other.erase(iterator(node));
        } else {
          ++pos;
        }
      }
    }
  }

  bool contains(const key_type &key) {
    return tree_.Search(key) ? true : false;
  }

  template <class... Args>
  void insert_many(Args &&...args) {
    insert_many_aux(args...);
  }

 private:
  RBT<key_type, mapped_type> tree_;

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
