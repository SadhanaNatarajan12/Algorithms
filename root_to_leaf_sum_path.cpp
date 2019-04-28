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

void printVector(const std::vector<int> &vec)
{
    for (int i = 0; i <= vec.size() - 1; i++) {
	std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;
}

void root_to_leaf_sumHelper(Node *root, int K, std::vector<int> &vec, int sum)
{
    if (root == NULL)
	return;

    sum = sum + root->data;
    vec.push_back(root->data);

    if (root->left == NULL && root->right == NULL && sum == K) {
	printVector(vec);
	return;
    }
    root_to_leaf_sumHelper(root->left, K, vec, sum);
    root_to_leaf_sumHelper(root->right, K, vec, sum);

    vec.pop_back();
}

void root_to_leaf_sum(Node *root, int K)
{
    std::vector<int> vec;
    int sum = 0;
    root_to_leaf_sumHelper(root, K, vec, sum);
}

int main()
{

    /*
     *       10
     *      /  \
     *     16   5
     *      \   /\
     *      -3 6  11
     *
     *      Given Sum = 26!
     */

    Node* root = new Node(10);
    root->left = new Node(16);
    root->left->right = new Node(-3);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(11);

    root_to_leaf_sum(root, 26);

    root_to_leaf_sum(root, 23);

    root_to_leaf_sum(root, 50);

    delete root;
}
