#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* newNode(int data){
    Node* node=(Node*)malloc(sizeof(Node));
    node->left=node->right=NULL;
    node->data=data;
    return node;
}

void levelOrder(Node* root){

    int h = getHeight(root);
    int i;
    for(i=1; i<=h; i++)
        printLevel(root, i);

}

/* Print nodes at a given level */
void printLevel(Node* node, int level)
{
    if(node == NULL)
        return;
    if(level == 1)
        printf("%d ", node->data);
    else if (level > 1)
    {
        printLevel(node->left, level-1);
        printLevel(node->right, level-1);
    }
}

int getHeight(Node* node){
  //Write your code here
    if(node == NULL){
        return 0;
    }

    int rheight = getHeight(node->right);
    int lheight = getHeight(node->left);

    if(lheight>rheight){
        return lheight + 1;
    }
    else {
        return rheight + 1;
    }
}

Node* insert(Node* root,int data){
    if(root==NULL)
        return newNode(data);
    else{
        Node* cur;
        if(data<=root->data){
            cur=insert(root->left,data);
            root->left=cur;                
        }
        else{
            cur=insert(root->right,data);
            root->right=cur;
        }
        
    }
    return root;
}
int main(){
    Node* root=NULL;
    int T,data;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d",&data);
        root=insert(root,data);
    }
    levelOrder(root);
    return 0;
    
}
