//
//  main.cpp
//  jazz
//
//  Created by vinfinit on 3/24/19.
//  Copyright © 2019 vinfinit. All rights reserved.
//

#include <iostream>

struct node_t
{
    unsigned v;
    struct node_t* next;
};

struct node_t* even_nodes(node_t** node) {
    node_t* cur = *node;
    node_t* next = cur->next;
    
    if (next == NULL) {
        return cur->v % 2 == 0 ? cur : NULL;;
    }
    
    if (cur->v % 2 != next->v % 2) {
        cur->next = next->next;
    }
    
    node_t* last_even = even_nodes(&next);
    
    return cur->v % 2 == 0 ? cur : last_even;
}

void print_nodes(node_t* node, std::string prefix = "") {
    std::cout << prefix + std::to_string(node->v) + " ";
    if (node->next != NULL) {
        print_nodes(node->next);
    }
    else {
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    int n = 10;
    node_t* head = NULL;
    node_t* tail = NULL;
    for (unsigned int i = 1; i < n; i++) {
        node_t* node = new node_t{i, NULL};
        if (tail != NULL) {
            tail->next = node;
            tail = node;
        }
        else {
            head = node;
            tail = node;
        }
    }
    print_nodes(head, "origin: ");
    print_nodes(even_nodes(&head), "even: ");
    print_nodes(head, "odd: ");
    std::cout << "Hello, World!\n";
    return 0;
}
