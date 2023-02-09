#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_LINE_LEN 1000

typedef struct node
{
    char word[MAX_WORD_LEN];
    int line;
    struct node *left, *right;
} Node;

Node *root = NULL;

Node *newNode(char *word, int line)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->word, word);
    node->line = line;
    node->left = node->right = NULL;
    return node;
}

void insert(Node *node, char *word, int line)
{
    int cmp = strcmp(word, node->word);
    if (cmp == 0)
    {
        node->line = line;
    }
    else if (cmp < 0)
    {
        if (node->left == NULL)
        {
            node->left = newNode(word, line);
        }
        else
        {
            insert(node->left, word, line);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            node->right = newNode(word, line);
        }
        else
        {
            insert(node->right, word, line);
        }
    }
}

void inorder(Node *node)
{
    if (node->left != NULL)
    {
        inorder(node->left);
    }
    printf("%s %d\n", node->word, node->line);
    if (node->right != NULL)
    {
        inorder(node->right);
    }
}

void freeTree(Node *node)
{
    if (node->left != NULL)
    {
        freeTree(node->left);
    }
    if (node->right != NULL)
    {
        freeTree(node->right);
    }
    free(node);
}

void freeAll()
{
    if (root != NULL)
    {
        freeTree(root);
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 2;
    }

    char line[MAX_LINE_LEN];
    int lineNumber = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {
        lineNumber++;
        char *word = strtok(line, " \n\t,.;!?");
        while (word != NULL)
        {
            int len = strlen(word);
            if (len >= 3)
            {
                for (int i = 0; i < len; i++)
                {
                    word[i] = tolower(word[i]);
                }
                if (root == NULL)
                {
                    root = newNode(word, lineNumber);
                }
                else
                {
                    insert(root, word, lineNumber);
                }
            }
            word = strtok(NULL, " \n\t,.;!?");
        }
    }

    inorder(root);
    fclose(fp);
    freeAll();
    return 0;
}