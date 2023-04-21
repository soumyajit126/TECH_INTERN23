#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition of a queue node
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Definition of a queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue a tree node to the queue
void enqueue(struct Queue* q, struct TreeNode* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue a tree node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return NULL;
    }
    struct QueueNode* temp = q->front;
    struct TreeNode* data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to find the maximum width of a binary search tree
int maxWidth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct Queue* q = createQueue();
    enqueue(q, root);
    int max_width = 0;
    while (!isEmpty(q)) {
        int width = 0;
        int n = q->front == NULL ? 0 : 1;
        for (int i = 0; i < n; i++) {
            struct TreeNode* curr = dequeue(q);
            width++;
            if (curr->left != NULL) {
                enqueue(q, curr->left);
            }
            if (curr->right != NULL) {
                enqueue(q, curr->right);
            }
        }
        if (width > max_width) {
            max_width = width;
        }
    }
    return max_width;
}

// Main function to test the program
int main() {
    // Create a binary search tree
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    // Find the maximum width of the tree
    int max_width = maxWidth(root);

    // Print the maximum width of the tree
    printf("The maximum width of the tree is: %d\n", max_width);
    
    return 0;
}
