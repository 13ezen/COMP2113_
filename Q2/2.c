#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*node structure contains int key which is the key of the treenode
structure treeNode *left is the pointer to the left subtree
structure treeNode *right is the pointer to the right subtree
*/
struct treeNode {
    int key;
    struct treeNode *left;
    struct treeNode *right;
};

//shortcut
typedef struct treeNode treeNode;

//uses recursive to insert tree node after comparing with the nodes
//if the node key is larger than the root, it is inserted to the right 
//if node key is smaller than root key, it is inserted into the left
treeNode * Insert(treeNode * currentNode, int key) {
    // Case 1: If the tree rooted at currentNode is empty
    if (currentNode == NULL) {
        currentNode= (treeNode*)malloc(sizeof(struct treeNode));
        currentNode->key = key;
        currentNode -> left = NULL;
        currentNode -> right = NULL;

    }
    // Case 2: If the tree rooted at currentNode is not empty and if the given key is greater than currentNode -> key
    if (key > (currentNode -> key)) {
        currentNode -> right = Insert(currentNode -> right, key);
    }
    // Case 3: If the tree rooted at currentNode is not empty and if the given key is smaller than currentNode -> key
    else if (key < (currentNode -> key)) {
        currentNode -> left = Insert(currentNode -> left, key);    
    }
    return currentNode;
}
//prints all elements in the tree in ascending order
void Print(treeNode *currentNode){
    if(currentNode ==NULL){
        return;
    }
    Print(currentNode->left);
    printf("%d ", currentNode->key);
    Print(currentNode->right);
}

//Looks for minimum element in the tree
treeNode * FindMin(treeNode *currentNode) {
    if(currentNode -> left == NULL){
        return currentNode;
    }
    FindMin(currentNode -> left);
}

//Looks for maximum element in the tree
treeNode * FindMax(treeNode *currentNode) {
    if(currentNode -> right == NULL){
        return currentNode;
    }
    FindMax(currentNode -> right);
}

//Looks for element key in the tree
treeNode * Find(treeNode * currentNode, int key) {
    if((*currentNode).key == key){
        return currentNode;
    }
    else{
        if((currentNode -> left != NULL)){
            treeNode *left = Find(currentNode ->left, key);
            if(left !=NULL){
                return left;
            }
        }
        if((currentNode -> right != NULL)){
            return Find(currentNode ->right, key);
        }
    }
    return NULL;
}



int main() {
    treeNode *root = NULL;

    char command[30];
    int value;
    scanf("%s", command);
    while (strcmp(command, "END") != 0) {
        if (strcmp(command, "INSERT") == 0) {
            scanf("%d", &value);
            root = Insert(root, value);
        }
        else if (strcmp(command, "FIND") == 0) {
            scanf("%d", &value);
            treeNode * temp;
            temp = Find(root, value);
            if (temp == NULL)
                printf("Element %d not found\n", value);
            else
                printf("Element %d found\n", value);
        }
        else if (strcmp(command, "PRINT") == 0) {
            Print(root);
            putchar('\n');
        }
        else if (strcmp(command, "FINDMIN") == 0) {
            treeNode * temp;
            temp = FindMin(root);
            printf("Minimum element is %d\n", temp -> key);
        }
        else if (strcmp(command, "FINDMAX") == 0) {
            treeNode * temp;
            temp = FindMax(root);
            printf("Maximum element is %d\n", temp -> key);
        }
        scanf("%s", command);
    }
}
