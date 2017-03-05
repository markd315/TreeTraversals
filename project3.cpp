#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Node{
    int left;
    int right;
    int data;
    Node(){
        left=-1;
        right=-1; //Defaults to null pointers.
    }
};
struct Tree{
    int size;
    std::vector<Node> arr;
    int currentIndex;
    bool insert(int val, int rightIndex, int leftIndex){
        int hashedIndex = val%size;
        Node* newNode = new Node();
            newNode->right = rightIndex;
            newNode->left = leftIndex;
            newNode->data = val;
        arr[currentIndex] = *newNode;
        currentIndex++;
        return true;
    }
    Tree(){
        currentIndex=0;
    }
};

void preOrder(std::vector<Node> *vec, int index){
    Node* root = &vec->at(index);
    cout<<root->data<<" ";
    if(root->left != -1)
    preOrder(vec, root->left);
    if(root->right != -1)
    preOrder(vec, root->right);
}
void inOrder(std::vector<Node> *vec, int index){
    Node* root = &vec->at(index);
    if(root->left != -1)
    inOrder(vec, root->left);
    cout<<root->data<<" ";
    if(root->right != -1)
    inOrder(vec, root->right);
}
void postOrder(std::vector<Node> *vec, int index){
    Node* root = &vec->at(index);
    if(root->left != -1)
    postOrder(vec, root->left);
    if(root->right != -1)
    postOrder(vec, root->right);
    cout<<root->data<<" ";
}
int height(Tree* tree, int rootIndex)
{
    if (rootIndex>=tree->size)
        return 0;
    if (rootIndex==-1)
        return 0;
    Node* node = &tree->arr.at(rootIndex);
    {
        int lh = height(tree, node->left);
        int rh = height(tree, node->right);
        return max(rh+1,lh+1);
    }
}
 
void printGivenLevel(Tree* tree, int rootIndex, int level)
{
    if (rootIndex == -1)
        return;
    Node* root = &tree->arr.at(rootIndex);
    if (level == 1)
        std::cout<<root->data<<" ";
    else if (level > 1)
    {
        printGivenLevel(tree, root->left, level-1);
        printGivenLevel(tree, root->right, level-1);
    }
}
void levelOrder(Tree* tree, int rootIndex)
{
    int h = height(tree, rootIndex);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(tree, rootIndex, i);
}

int main(){
ios::sync_with_stdio(false); //faster is better.
int nodeCount;
std::cin>>nodeCount; //Elements of tree
Tree* tree = new Tree();
    tree->size = nodeCount;
    std::vector<Node>* arrz = new vector<Node>(nodeCount); 
    tree->arr = *arrz;
//ONLY positive integers is specified in parameters.
int insertData, rightIndex, leftIndex;
for(int i=0; i<nodeCount; i++){ //Populate the tree.
    std::cin>>insertData;
    std::cin>>rightIndex;
    std::cin>>leftIndex;
    Node* tempNode = new Node();
        tempNode->data = insertData;
        tempNode->right = rightIndex;
        tempNode->left = leftIndex;
    tree->insert(insertData, leftIndex, rightIndex);
}


levelOrder(tree, 0);
preOrder(&tree->arr, 0);
std::cout<<endl;
inOrder(&tree->arr, 0);
std::cout<<endl;
postOrder(&tree->arr, 0);
}
