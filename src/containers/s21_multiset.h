#ifndef S21_MULTISET_H
#define S21_MULTISET_H

#include "../s21_containersplus.h"

namespace S21 {

template <typename T>
class multiset {
 public:
  using key_type = T;
  using value_type = T;
  using reference = value_type&;
  using const_reference = const value_type&;
  using Node = typename RBT<key_type, int>::Node;
  using size_type = size_t;

  class iterator {
   public:
    iterator() : it_(nullptr), count_(0U) {}
    iterator(Node* node) : it_(node), count_(node->value) {}
    iterator(const iterator& other) : it_(other.it_), count_(other.count_) {}
    iterator(iterator&& other) : it_(other.it_), count_(other.count_) {
      other.it_ = nullptr;
      count_ = 0U;
    }
    iterator& operator=(const iterator& other) {
      it_ = other.it_;
      count_ = other.count_;
      return *this;
    }
    key_type& operator*() { return it_->key; }

    iterator& operator++() {
      if (it_) {
        if (it_->value > count_) {
          count_++;
        } else if (it_->right != nullptr) {
          it_ = it_->right;
          while (it_->left != nullptr) {
            it_ = it_->left;
          }
          count_ = it_->value;
        } else {
          Node* parent = it_->parent;
          while (parent != nullptr && parent->right == it_) {
            it_ = parent;
            parent = parent->parent;
          }
          it_ = parent;
          count_ = it_->value;
        }
      }
      return *this;
    }

    iterator& operator--() {
      if (it_) {
        if (count_ > 1) {
          count_--;
        } else if (it_->left != nullptr) {
          it_ = it_->left;
          while (it_->right != nullptr) {
            it_ = it_->right;
          }
          count_ = it_->value;
        } else {
          Node* parent = it_->parent;
          while (parent != nullptr && parent->left == it_) {
            it_ = parent;
            parent = parent->parent;
          }
          it_ = parent;
          count_ = it_->value;
        }
      }
      return *this;
    }

    bool operator==(const iterator& other) const {
      return other.it_ == it_ && other.count_ == count_;
    }

    bool operator!=(const iterator& other) const {
      return other.it_ != it_ && other.count_ == count_;
    }

    value_type getter() { return it_->value; }
    void setter(value_type value) { it_->value = value; }

    Node* it_;
    int count_;
  };

  class const_iterator : public iterator {
   public:
    const_iterator() : iterator() {}
    const_iterator(Node* node) : iterator(node) {}

    const key_type& operator*() { return iterator::operator*(); }
  };

  multiset() : tree_() {}
  multiset(std::initializer_list<value_type> const& items) {
    if (items.size()) {
      for (auto it = items.begin(); it != items.end(); it++) {
        if (!(tree_.Insert(*it, 1).second)) {
          tree_.AddSize();
        }
      }
    }
  }
  multiset(const multiset& s) : tree_(s.tree_) {}
  multiset(multiset&& s) : tree_(s.tree_) { s.clear(); }
  ~multiset() { tree_.Delete(); }

  multiset& operator=(multiset&& s) {
    tree_ = std::move(s.tree_);
    return *this;
  }

  multiset& operator=(const multiset& s) {
    tree_.Delete();
    tree_ = s.tree_;
    return *this;
  }

  iterator begin() {
    iterator res = iterator(tree_.begin());
    res.count_ = 1;
    return res;
  }
  iterator end() {
    Node* node = tree_.Max();
    return iterator(node);
  }

  bool empty() { return !tree_.Size(); }
  size_type size() { return tree_.Size(); }
  size_type max_size() {
    int sys = sizeof(void*) == 4 ? 31 : 63;
    return static_cast<size_type>(pow(2, sys)) / sizeof(value_type) - 1;
  }

  void clear() { tree_.Delete(); }
  iterator insert(const value_type& value) {
    iterator pos;
    Node* node = tree_.Search(value);
    if (node) {
      pos = iterator(node);
      pos.setter(pos.getter() + 1);
      tree_.AddSize();
    } else {
      tree_.Insert(value, 1);
    }
    return iterator(tree_.Search(value));
  }
  void erase(iterator pos) {
    int count = pos.getter();
    if (count > 1) {
      pos.setter(--count);
    } else {
      tree_.Remove(pos.it_);
    }
  }
  void swap(multiset& other) { tree_.Swap(other.tree_); }
  void merge(multiset& other) {
    if (!other.empty()) {
      for (auto pos = other.begin(); pos != other.end(); ++pos) {
        insert(*pos);
      }
      insert(*(other.end()));
      other.clear();
    }
  }

  size_type count(const T& key) {
    Node* node = tree_.Search(key);
    if (node) {
      return node->value;
    }
    return 0U;
  }
  iterator find(const T& key) { return iterator(tree_.Search(key)); }
  bool contains(const T& key) { return tree_.Search(key) ? true : false; }
  std::pair<iterator, iterator> equal_range(const T& key) {
    return {iterator(lower_bound(key)), --iterator(upper_bound(key))};
  }
  iterator lower_bound(const T& key) {
    Node* node = tree_.Search(key);
    iterator res;
    if (node) {
      res = iterator(node);
      res.count_ = 1;
    } else {
      res = insert(key);
      iterator tmp = res;
      ++res;
      erase(tmp);
    }
    return res;
  }
  iterator upper_bound(const T& key) {
    Node* node = tree_.Search(key);
    iterator res;
    if (node) {
      res = iterator(node);
      ++res;
    } else {
      res = insert(key);
      iterator tmp = res;
      ++res;
      erase(tmp);
    }
    return res;
  }

  template <class... Args>
  void insert_many(Args&&... args) {
    insert_many_aux(args...);
  }

 private:
  RBT<key_type, int> tree_;

  template <class U>
  void insert_many_aux(U&& arg) {
    insert(arg);
  }

  template <class U, class... Args>
  void insert_many_aux(U&& arg, Args&&... args) {
    insert(arg);
    insert_many_aux(args...);
  }
};
}  // namespace S21

#endif
