/*
 * Program  : Huffman Coding
 * Subject  : Design and Analysis of Algorithms Lab
 * Category : Greedy
 * Complexity: O(n log n)
 *
 * Aim: Assign variable-length prefix-free binary codes to characters
 *      based on their frequencies to achieve data compression.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 256

/* A node in the Huffman tree */
typedef struct HuffmanNode {
    char               character;
    int                frequency;
    struct HuffmanNode *left_child;
    struct HuffmanNode *right_child;
} HuffmanNode;

/* Min-heap to always extract the two lowest-frequency nodes */
HuffmanNode *min_heap[MAX_NODES];
int          heap_size = 0;

HuffmanNode *createNode(char character, int frequency,
                        HuffmanNode *left, HuffmanNode *right) {
    HuffmanNode *node   = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->character     = character;
    node->frequency     = frequency;
    node->left_child    = left;
    node->right_child   = right;
    return node;
}

/* Bubble the node at index up to restore min-heap property */
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && min_heap[parent]->frequency > min_heap[index]->frequency) {
        HuffmanNode *temp   = min_heap[index];
        min_heap[index]     = min_heap[parent];
        min_heap[parent]    = temp;
        index  = parent;
        parent = (index - 1) / 2;
    }
}

/* Push the node at index down to restore min-heap property */
void heapifyDown(int index) {
    int smallest   = index;
    int left_child  = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child  < heap_size && min_heap[left_child]->frequency  < min_heap[smallest]->frequency)
        smallest = left_child;
    if (right_child < heap_size && min_heap[right_child]->frequency < min_heap[smallest]->frequency)
        smallest = right_child;

    if (smallest != index) {
        HuffmanNode *temp    = min_heap[index];
        min_heap[index]      = min_heap[smallest];
        min_heap[smallest]   = temp;
        heapifyDown(smallest);
    }
}

void insertHeap(HuffmanNode *node) {
    min_heap[heap_size++] = node;
    heapifyUp(heap_size - 1);
}

HuffmanNode *extractMin(void) {
    HuffmanNode *top = min_heap[0];
    min_heap[0]      = min_heap[--heap_size];
    heapifyDown(0);
    return top;
}

/* Traverse the Huffman tree and print each character's binary code */
void generateCodes(HuffmanNode *node, char *code_buffer, int depth) {
    if (!node->left_child && !node->right_child) {
        /* Leaf node: this is an actual character */
        code_buffer[depth] = '\0';
        printf("  '%c'  freq=%-4d  code=%s\n",
               node->character, node->frequency, code_buffer);
        return;
    }
    code_buffer[depth] = '0';
    generateCodes(node->left_child,  code_buffer, depth + 1);
    code_buffer[depth] = '1';
    generateCodes(node->right_child, code_buffer, depth + 1);
}

int main(void) {
    int num_characters;
    printf("Enter number of distinct characters: ");
    scanf("%d", &num_characters);

    printf("Enter each character and its frequency:\n");
    for (int i = 0; i < num_characters; i++) {
        char character; int frequency;
        scanf(" %c %d", &character, &frequency);
        insertHeap(createNode(character, frequency, NULL, NULL));
    }

    /* Build Huffman tree: repeatedly merge two lowest-frequency nodes */
    while (heap_size > 1) {
        HuffmanNode *left  = extractMin();
        HuffmanNode *right = extractMin();
        insertHeap(createNode('\0', left->frequency + right->frequency, left, right));
    }

    char code_buffer[MAX_NODES];
    printf("\nHuffman Codes:\n");
    generateCodes(extractMin(), code_buffer, 0);

    return 0;
}
