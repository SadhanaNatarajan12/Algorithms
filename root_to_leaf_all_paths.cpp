#include <iostream>
#include <vector>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data) {
	this->data = data;
	left = NULL;
	right = NULL;
    }
    ~Node() {
	delete left;
	delete right;
    }
};

void printVector(const std::vector<int>& vec)
{
    for (int i = 0; i <= vec.size() - 1; i++) {
	std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void printAllPathsRootToLeafHelper(struct Node* root, std::vector<int> &vec)
{
    if (root == NULL)
	return;

    vec.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
	printVector(vec);
    }

    printAllPathsRootToLeafHelper(root->left, vec);
    printAllPathsRootToLeafHelper(root->right, vec);

    vec.pop_back();
}

void printAllPathsRootToLeaf(struct Node* root)
{
    std::vector<int> vec;
    printAllPathsRootToLeafHelper(root, vec);
}

int main()
{
     /*
     *       10
     *      /  \
     *     16   5
     *      \   /\
     *      -3 6  11
     */

    Node* root = new Node(10);
    root->left = new Node(16);
    root->left->right = new Node(-3);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(11);

    printAllPathsRootToLeaf(root);

    delete root;
}
