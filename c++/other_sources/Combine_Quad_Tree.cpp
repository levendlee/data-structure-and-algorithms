#include <string>
#include <iostream>

struct QuadTreeNode {
  bool value;
  bool has_children;
  QuadTreeNode* children[4];

  QuadTreeNode(bool value, bool has_children) : value(value), has_children(has_children) {
    for (int i = 0; i < 4; ++i) {
      children[i] = nullptr;
    }
  }
};

void Dump(QuadTreeNode* node, const std::string& prefix = "") {
  if (node->has_children) {
    for (int i = 0; i < 4; ++i) {
      std::cout << prefix << "child " << i << ":\n";
      Dump(node->children[i], prefix + "##");
    }
  } else {
    std::cout << prefix << node->value << "\n";
  }
}

QuadTreeNode* MergeQuadTree(bool value_a, bool value_b) {
  return new QuadTreeNode(value_a | value_b, false);
}


QuadTreeNode* MergeQuadTree(QuadTreeNode* root_a, bool value_b) {
  if (value_b) {
    return new QuadTreeNode(true, false);
  } else {
    return root_a;
  }
}

QuadTreeNode* SimplyfyNode(QuadTreeNode* node) {
  int children_total = 0;
  if (!node->has_children) {
    return node;
  }
  for (int i = 0; i < 4; ++i) {
    if (node->children[i]->has_children) {
      return node;
    }
   children_total += node->children[i]->value;
  }
  if (children_total == 4) {
    return new QuadTreeNode(true, false);
  } else if (children_total == 0) {
    return new QuadTreeNode(false, false);
  }
  return node;
}

QuadTreeNode* MergeQuadTree(QuadTreeNode* root_a, QuadTreeNode* root_b) {
  if (root_a->has_children && root_b->has_children) {
    QuadTreeNode* node = new QuadTreeNode(false, true);
    for (int i = 0; i < 4; ++i) {
      node->children[i] = MergeQuadTree(root_a->children[i], root_b->children[i]);
    }
    return SimplyfyNode(node);
  } else if (root_a->has_children) {
    return MergeQuadTree(root_a, root_b->value);
  } else if (root_b->has_children) {
    return MergeQuadTree(root_a->value, root_b);
  } else {
    return MergeQuadTree(root_a->value, root_b->value);
  }
}


void MergeAndDump(QuadTreeNode* root_a, QuadTreeNode* root_b) {
  std::cout << "A:\n";
  Dump(root_a);
  std::cout << "B:\n";
  Dump(root_b);
  std::cout << "Merged:\n";
  Dump(MergeQuadTree(root_a, root_b));
}

int main() {
  QuadTreeNode node_0(true, false);
  QuadTreeNode node_1(false, false);

  const std::string s(20, '#');

  std::cout << s << "\n";
  MergeAndDump(&node_0, &node_1);

  QuadTreeNode node_2(true, false);
  QuadTreeNode node_3(false, false);
  node_0.has_children = true;
  node_0.children[0] = &node_2;
  node_0.children[1] = &node_3;
  node_0.children[2] = &node_2;
  node_0.children[3] = &node_3;

  std::cout << s << "\n";
  MergeAndDump(&node_0, &node_1);

  node_1.has_children = true;
  node_1.children[0] = &node_3;
  node_1.children[1] = &node_2;
  node_1.children[2] = &node_3;
  node_1.children[3] = &node_2;

  std::cout << s << "\n";
  MergeAndDump(&node_0, &node_1);

  node_1.has_children = true;
  node_1.children[0] = &node_3;
  node_1.children[1] = &node_3;
  node_1.children[2] = &node_2;
  node_1.children[3] = &node_2;

  std::cout << s << "\n";
  MergeAndDump(&node_0, &node_1);


  return 0;
}
