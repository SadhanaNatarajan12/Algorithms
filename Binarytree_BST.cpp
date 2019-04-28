#include <iostream>
#include <queue>

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

void preorder(struct Node* root)
{
    if (root == NULL)
	return;
    std::cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root)
{
    if (root == NULL)
	return;
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->data<<" ";
}

void inorder(struct Node* root)
{
    if (root == NULL)
	return;
    inorder(root->left);
    std::cout<<root->data<<" ";
    inorder(root->right);
}

void levelorder(struct Node* root)
{
    if (root == NULL)
	return;
    std::queue<struct Node*> Q;
    Q.push(root);
    while (!Q.empty()) {
	struct Node* temp = Q.front();
	std::cout<<temp->data<<" ";
	Q.pop();
	if (temp->left)
	    Q.push(temp->left);
	if (temp->right)
	    Q.push(temp->right);
    }
}

//Search in BST
bool recursiveSearchBST(struct Node* root, int value)
{
    if (root == NULL)
	return false;
    if (root->data == value)
	return true;
    if (value <= root->data)
	return recursiveSearchBST(root->left, value);
    if (value > root->data)
	return recursiveSearchBST(root->right, value);

    return false;
}

bool iterativeSearchBST(struct Node* root, int value)
{
    bool bfound = false;
    while (root != NULL) {
	if (root->data == value) {
	    bfound = true;
	    break;
	} else if (value <= root->data) {
	    root = root->left;
	} else {
	    root = root->right;
	}
    }
    return bfound;
}

Node* lca_binary_tree(struct Node* root, int n1, int n2)
{
    if (root == NULL)
	return NULL;

    if (root->data == n1 || root->data == n2)
	return root;
    
    Node* left = lca_binary_tree(root->left, n1, n2);
    Node* right = lca_binary_tree(root->right, n1, n2);
 
    if (left == NULL && right == NULL)
	return NULL;

    if (left != NULL && right != NULL)
	return root;

    return left != NULL ? left:right;
}

Node* lca_bst(struct Node* root, int n1, int n2)
{
    if (root == NULL)
	return NULL;

    if (root->data > std::max(n1, n2)) { 
	return lca_bst(root->left, n1, n2);
    } else if (root->data < std::min(n1, n2)) {
	return lca_bst(root->right, n1, n2);
    }
    return root;
}

void klargest_elements_BSTHelper(struct Node* root, int k, int &counter, std::vector<int> &vec)
{
    //Reverse inorder traversal
    if (root == NULL)
	return;

    klargest_elements_BSTHelper(root->right, k, counter, vec);

    if (counter < k) {
	counter++;
	vec.push_back(root->data);
    }

    klargest_elements_BSTHelper(root->left, k, counter, vec);
}

void klargest_elements_BST(struct Node* root, int k)
{
    std::vector<int> vec;
    int counter = 0;
    klargest_elements_BSTHelper(root, k, counter, vec);
    std::cout<<"Printing the largest "<<k<<" elements"<<std::endl;
    for (int i = 0; i <= vec.size() - 1; i++) {
	std::cout<<vec[i]<<" ";
    }
	std::cout<<std::endl;
}

void TEST_driver_klargest_elements_BST()
{
    Node *root = new Node(10);
    root->left = new Node(-10);
    root->right = new Node(30);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(25);
    root->right->right = new Node(60);
    root->right->left->left = new Node(28);
    root->right->right->right = new Node(78);

    klargest_elements_BST(root, 3);

    delete root;
}

void TEST_driver_lowest_common_ancestor_BST()
{
    Node *root = new Node(10);
    root->left = new Node(-10);
    root->right = new Node(30);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(25);
    root->right->right = new Node(60);
    root->right->left->left = new Node(28);
    root->right->right->right = new Node(78);

    std::cout<<"Finding the lowest common ancestor in a binary search tree (BST)!"<<std::endl;
    Node *resultNode = lca_bst(root, 28, 78);
    assert(resultNode->data == 30);
    resultNode = lca_bst(root, 6, 9);
    assert(resultNode->data == 8);
    resultNode = lca_bst(root, 30, 78);
    assert(resultNode->data == 30);

    delete root;
}

void TEST_driver_lowest_common_ancestor_binary_tree()
{
    Node *root = new Node(3);
    root->left = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(11);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(5);
    root->right = new Node(8);
    root->right->right = new Node(13);
    root->right->right->left = new Node(7);

    std::cout<<"Finding the lowest common ancestor in a binary tree (Binary Tree)!"<<std::endl;
    Node *resultNode = lca_binary_tree(root, 2, 5);
    assert(resultNode->data == 6);
    resultNode = lca_binary_tree(root, 8, 11);
    assert(resultNode->data == 3);
    resultNode = lca_binary_tree(root, 8, 7);
    assert(resultNode->data == 8);

    delete root;
}

void TEST_driver_search_BST()
{
    Node* root = new Node(10);
    root->left = new Node(-5);
    root->right = new Node(30);
    root->left->left = new Node(-10);
    root->left->right = new Node(0);
    root->left->right->right = new Node(5);
    root->right->right = new Node(36);

    std::cout<<"Search recursively in BST"<<std::endl;
    assert(recursiveSearchBST(root, 0) == iterativeSearchBST(root, 0));
    assert(recursiveSearchBST(root, 36) == iterativeSearchBST(root, 36));
    assert(recursiveSearchBST(root, 3) == iterativeSearchBST(root, 3));

    delete root;

    Node* root1 = new Node(10);
    root1->right = new Node(15);
    root1->right->right = new Node(16);
    root1->right->right->right = new Node(18);

    std::cout<<"Search iteratively in BST"<<std::endl;
    assert(recursiveSearchBST(root1, 18) == iterativeSearchBST(root1, 18));
    assert(recursiveSearchBST(root1, 36) == iterativeSearchBST(root1, 36));
    assert(recursiveSearchBST(root1, 15) == iterativeSearchBST(root1, 15));

    delete root1;
}

void TEST_driver_traversals()
{
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(30);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->left->left = new Node(5);
    root->right->right = new Node(2);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(8);

    std::cout<<"Preorder: "<<std::endl;
    preorder(root);
    std::cout<<std::endl;
    std::cout<<"Inorder: "<<std::endl;
    inorder(root);
    std::cout<<std::endl;
    std::cout<<"Postorder: "<<std::endl;
    postorder(root);
    std::cout<<std::endl;

    delete root;

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    std::cout<<"Level Order Traversal: "<<std::endl;
    levelorder(root1);
    std::cout<<std::endl;

    delete root1;
}

int main()
{
    TEST_driver_traversals();
    TEST_driver_search_BST();
    TEST_driver_lowest_common_ancestor_binary_tree();
    TEST_driver_lowest_common_ancestor_BST();

    TEST_driver_klargest_elements_BST();
}
