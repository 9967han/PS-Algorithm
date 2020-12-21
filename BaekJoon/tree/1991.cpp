#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;
int N;
char ch[3];
struct Node{
    char ch;
    Node* left;
    Node* right;
};
void pre_order(Node* curNode);
void in_order(Node* curNode);
void post_order(Node* curNode);
void make_tree(Node* curNode, char ch, char left, char right);

int main(){
    cin >> N;
    Node tree = {'A', NULL, NULL};
    Node* root = &tree;
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            cin >> ch[j];
        }
        make_tree(root, ch[0], ch[1], ch[2]);
    }
    pre_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    post_order(root);
    cout << endl;
}

void pre_order(Node* curNode){
    if(curNode == NULL) return;
    cout << curNode->ch;
    pre_order(curNode->left);
    pre_order(curNode->right);
}

void in_order(Node* curNode){
    if(curNode == NULL) return;
    in_order(curNode->left);
    cout << curNode->ch;
    in_order(curNode->right);
}

void post_order(Node* curNode){
    if(curNode == NULL) return;
    post_order(curNode->left);
    post_order(curNode->right);
    cout << curNode->ch;
}

void make_tree(Node* curNode, char ch, char left, char right){
    if(curNode->ch == ch){
        if(left != '.') {
            Node* leftNode = (Node*)malloc(sizeof(struct Node));
            leftNode->ch = left, leftNode->left = NULL, leftNode->right = NULL;
            curNode->left = leftNode;
        } 
        if(right != '.') {
            Node* rightNode = (Node*)malloc(sizeof(struct Node));
            rightNode->ch = right, rightNode->left = NULL, rightNode->right = NULL;
            curNode->right = rightNode;
        }
        return;
    }
    if(curNode->left != NULL) make_tree(curNode->left, ch, left, right);
    if(curNode->right != NULL) make_tree(curNode->right, ch, left, right);
    return;
}


