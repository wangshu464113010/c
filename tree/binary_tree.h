//
// Created by wangshu on 2020/4/7.
//

#ifndef PROJECT_BINARY_TREE_H
#define PROJECT_BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct binary_tree_node{
    struct binary_tree_node* left;
    struct binary_tree_node* right;
    void *data;
}b_tree_node;
typedef b_tree_node* B_TREE_NODE;
typedef struct b_tree{
    struct binary_tree_node* root;
    int height;
    int size;
}b_tree;
typedef b_tree* B_TREE;


#endif //PROJECT_BINARY_TREE_H
