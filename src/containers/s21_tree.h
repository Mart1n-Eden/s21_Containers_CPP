#ifndef S21_TREE_H
#define S21_TREE_H

#include "../s21_containers.h"

namespace S21 {

enum color { RED, BLACK };

template <typename key_type, typename value_type>
struct node {
  key_type key;
  value_type value;
  node* parent = nullptr;
  node* left = nullptr;
  node* right = nullptr;
  S21::color color = RED;
};

template <typename K, typename T>
class RBT {
 public:
  using key_type = K;
  using value_type = T;
  using size_type = size_t;
  using Node = node<key_type, value_type>;

  RBT() : root_(nullptr), size_(0U) {}
  RBT(const RBT& other) {
    root_ = Copy(other.root_);
    size_ = other.size_;
  }
  RBT(RBT&& other) : root_(other.root_) { other.root_ = nullptr; }
  ~RBT() { Delete(); }
  RBT& operator=(const RBT& other) {
    if (root_ != other.root_) {
      root_ = Copy(other.root_);
      size_ = other.size_;
    }
    return *this;
  }
  RBT& operator=(RBT&& other) {
    if (root_ != other.root_) {
      std::swap(root_, other.root_);
      std::swap(size_, other.size_);
    }
    other.Delete();
    return *this;
  }

  class iterator {
   public:
    iterator() : it_(nullptr) {}
    iterator(Node* node) : it_(node) {}
    iterator(const iterator& other) : it_(other.it_) {}
    iterator(iterator&& other) : it_(other.it_) { other.it_ = nullptr; }
    iterator& operator=(const iterator& other) {
      it_ = other.it_;
      return *this;
    }
    key_type& operator*() { return it_->key; }

    iterator& operator++() {
      if (it_) {
        if (it_->right != nullptr) {
          it_ = it_->right;
          while (it_->left != nullptr) {
            it_ = it_->left;
          }
        } else {
          Node* parent = it_->parent;
          while (parent != nullptr && parent->right == it_) {
            it_ = parent;
            parent = parent->parent;
          }
          it_ = parent;
        }
      }
      return *this;
    }

    iterator& operator--() {
      if (it_) {
        if (it_->left != nullptr) {
          it_ = it_->left;
          while (it_->right != nullptr) {
            it_ = it_->right;
          }
        } else {
          Node* parent = it_->parent;
          while (parent != nullptr && parent->left == it_) {
            it_ = parent;
            parent = parent->parent;
          }
          it_ = parent;
        }
      }
      return *this;
    }

    bool operator==(const iterator& other) const { return other.it_ == it_; }

    bool operator!=(const iterator& other) const { return other.it_ != it_; }

    value_type getter() { return it_->value; }

    Node* it_;
  };

  class const_iterator : public iterator {
   public:
    const_iterator() : iterator() {}
    const_iterator(Node* node) : iterator(node) {}

    const key_type& operator*() { return iterator::operator*(); }
  };

  size_type Size() { return size_; }
  void AddSize() { size_++; }

  void Swap(RBT<key_type, value_type>& other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  void Delete() { Delete(root_); }

  void Delete(Node* node) {
    if (node != nullptr) {
      Delete(node->left);
      Delete(node->right);
      delete node;
    }
    root_ = nullptr;
    size_ = 0U;
  }

  Node* begin() { return Min(); }

  Node* end() {
    Node* node = Max();
    return node->right;
  }

  std::pair<iterator, bool> Insert(key_type k, value_type v) {
    std::pair<iterator, bool> res;
    res.second = true;
    res.first = nullptr;
    Node* children = new Node;
    children->key = k;
    children->value = v;

    Node* parent = nullptr;

    if (root_ == nullptr) {
      ++size_;
      root_ = children;
      root_->color = BLACK;
    } else {
      Node* current = root_;
      while (current != nullptr) {
        parent = current;
        if (k < current->key) {
          current = current->left;
        } else if (k > current->key) {
          current = current->right;
        } else {
          res.second = false;
          break;
        }
      }
      if (res.second) {
        ++size_;
        children->parent = parent;
        if (k < parent->key) {
          parent->left = children;
        } else {
          parent->right = children;
        }
        Balance(children);
      } else {
        delete children;
      }
    }
    res.first = iterator(Search(k));
    return res;
  }

  Node* Min() {
    Node* node = root_;
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }

  Node* Max() {
    Node* node = root_;
    while (node->right != nullptr) {
      node = node->right;
    }
    return node;
  }

  Node* Search(key_type k) {
    Node* node = root_;
    while (node != nullptr && node->key != k) {
      if (node->key > k) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return node;
  }

  void Remove(Node* node) {
    Node* successor = nullptr;
    if (node->left == nullptr || node->right == nullptr) {
      successor = node;
    } else {
      successor = Successor(node);
    }
    Node* child = nullptr;
    if (successor->left != nullptr) {
      child = successor->left;
    } else {
      child = successor->right;
    }
    if (child != nullptr) {
      child->parent = successor->parent;
    }
    if (successor->parent == nullptr) {
      root_ = child;
    } else if (successor == successor->parent->left) {
      successor->parent->left = child;
    } else {
      successor->parent->right = child;
    }
    if (successor != node) {
      node->key = successor->key;
      node->value = successor->value;
    }
    if (successor->color == BLACK) {
      RemoveBalance(child, successor->parent);
    }
    delete successor;
    --size_;
  }

  void print() { inorderTraversal(root_); }

 protected:
  Node* root_;
  size_type size_;

  void Balance(Node* children) {
    while (children->parent != nullptr && children->parent->color == RED) {
      if (children->parent == children->parent->parent->left) {
        Node* uncle = children->parent->parent->right;
        if (uncle != nullptr && uncle->color == RED) {
          children->parent->color = BLACK;
          uncle->color = BLACK;
          children->parent->parent->color = RED;
          children = children->parent->parent;
        } else {
          if (children == children->parent->right) {
            children = children->parent;
            LeftRotate(children);
          }
          children->parent->color = BLACK;
          children->parent->parent->color = RED;
          RightRotate(children->parent->parent);
        }
      } else {
        Node* uncle = children->parent->parent->left;
        if (uncle != nullptr && uncle->color == RED) {
          children->parent->color = BLACK;
          uncle->color = BLACK;
          children->parent->parent->color = RED;
          children = children->parent->parent;
        } else {
          if (children == children->parent->left) {
            children = children->parent;
            RightRotate(children);
          }
          children->parent->color = BLACK;
          children->parent->parent->color = RED;
          LeftRotate(children->parent->parent);
        }
      }
    }
    root_->color = BLACK;
  }

  void LeftRotate(Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != nullptr) {
      rightChild->left->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == nullptr) {
      root_ = rightChild;
    } else if (node == node->parent->left) {
      node->parent->left = rightChild;
    } else {
      node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
  }

  void RightRotate(Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != nullptr) {
      leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;
    if (node->parent == nullptr) {
      root_ = leftChild;
    } else if (node == node->parent->right) {
      node->parent->right = leftChild;
    } else {
      node->parent->left = leftChild;
    }
    leftChild->right = node;
    node->parent = leftChild;
  }

  void RemoveBalance(Node* node, Node* grand) {
    while (node != root_ && (node == nullptr || node->color == BLACK)) {
      if (node == grand->left) {
        Node* parent = grand->right;
        if (parent->color == RED) {
          parent->color = BLACK;
          grand->color = RED;
          LeftRotate(grand);
          parent = grand->right;
        }
        if ((parent->left == nullptr || parent->left->color == BLACK) &&
            (parent->right == nullptr || parent->right->color == BLACK)) {
          parent->color = RED;
          node = grand;
          grand = node->parent;
        } else {
          if (parent->right == nullptr || parent->right->color == BLACK) {
            parent->left->color = BLACK;
            parent->color = RED;
            RightRotate(parent);
            parent = grand->right;
          }
          parent->color = grand->color;
          grand->color = BLACK;
          parent->right->color = BLACK;
          LeftRotate(grand);
          node = root_;
        }
      } else {
        Node* parent = grand->left;
        if (parent->color == RED) {
          parent->color = BLACK;
          grand->color = RED;
          RightRotate(grand);
          parent = grand->left;
        }
        if ((parent->right == nullptr || parent->right->color == BLACK) &&
            (parent->left == nullptr || parent->left->color == BLACK)) {
          parent->color = RED;
          node = grand;
          grand = node->parent;
        } else {
          if (parent->left == nullptr || parent->left->color == BLACK) {
            parent->right->color = BLACK;
            parent->color = RED;
            LeftRotate(parent);
            parent = grand->left;
          }
          parent->color = grand->color;
          grand->color = BLACK;
          parent->left->color = BLACK;
          RightRotate(grand);
          node = root_;
        }
      }
    }
    if (node != nullptr) {
      node->color = BLACK;
    }
  }

  Node* Successor(Node* node) {
    Node* current = nullptr;
    if (node->right != nullptr) {
      current = node->right;
      while (current->left != nullptr) {
        current = current->left;
      }
    }
    return current;
  }

  void inorderTraversal(Node* node) {
    if (node != nullptr) {
      inorderTraversal(node->left);
      std::cout << "(" << node->key << ": " << node->value << ") ";
      inorderTraversal(node->right);
    }
  }

  Node* Copy(Node* node) {
    Node* res = new Node;
    if (node) {
      res->key = node->key;
      res->value = node->value;
      res->left = Copy(node->left);
      res->right = Copy(node->right);
      res->parent = node->parent;
    }
    return res;
  }
};
}  // namespace S21

#endif  //
