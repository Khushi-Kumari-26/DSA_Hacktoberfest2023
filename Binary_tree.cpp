#include <iostream>
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int target) {
    if (root == nullptr || root->key == target) {
        return root;
    }

    if (target < root->key) {
        return searchBST(root->left, target);
    }
    return searchBST(root->right, target);
}
TreeNode* insertBST(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->key) {
        root->left = insertBST(root->left, value);
    } else if (value > root->key) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        root = insertBST(root, key);
    }

    std::cout << "In-Order Traversal of the BST: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    int target = 40;
    TreeNode* result = searchBST(root, target);

    if (result != nullptr) {
        std::cout << "Element " << target << " found in the BST." << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the BST." << std::endl;
    }

    return 0;
}
