#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char infixExpr[256], postfixExpr[256];

typedef struct nod Node;
typedef struct arbore Tree;
typedef struct nodArbore treeNode;

struct nod
{
    char info;
    Node *urm;
};

typedef struct
{
    char info;
    Node *urm;
}queueNode;

struct arbore
{
    char info[10];
    Tree *st, *dr;
};

struct nodArbore
{
    Tree *info;
    treeNode *urm;
};

typedef struct
{
    Node *varf;
    int nrElemente;
}Stack;

typedef struct
{
    treeNode *varf;
    int nrElemente;
}treeStack;

typedef struct 
{
    Node *prim;
    Node *ultim;
    int nrElemente;
}Queue;

Queue postfixExprQueue;

int isEmpty(Stack S)
{
    if(S.nrElemente == 0)
        return 1;
    else
        return 0;
}

int isEmpty_treeStack(treeStack S)
{
    if(S.nrElemente == 0)
        return 1;
    else
        return 0;
}

// scoate elementul din varful stivei
void Pop(Stack *S)
{
    if (!isEmpty(*S))
    {
        Node *varf_nou;
        varf_nou = S->varf->urm;
        free(S->varf);
        S->varf = varf_nou;
        S->nrElemente--;
    }
}

// scoate elementul din varful stivei de arbori
void popTree(treeStack *S)
{
    if (!isEmpty_treeStack(*S))
    {
        treeNode *varf_nou;
        varf_nou = S->varf->urm;
        free(S->varf);
        S->varf = varf_nou;
        S->nrElemente--;
    }
}

// adauga un element la stiva, in varf (LIFO)
void Push(Stack *S, char element)
{
    Node* newNode;

    if (isEmpty(*S))
    {
        S->nrElemente = 1;
        Node *nod1;
        nod1 = (Node*)malloc(sizeof(Node));
        S->varf = nod1;
        S->varf->info = element;
        S->varf->urm = NULL;
    }
    else
    {
        S->nrElemente++;
        Node *newNode;
        newNode = (Node*)malloc(sizeof(Node));
        newNode->info = element;
        newNode->urm = S->varf;
        S->varf = newNode;
    }
}

// adauga un element la stiva de arbori, in varf (LIFO)
void pushTree(treeStack *S, Tree *element)
{
    treeNode *newNode;

    if (isEmpty_treeStack(*S))
    {
        S->nrElemente = 1;
        treeNode *nodArbore;
        nodArbore = (treeNode*)malloc(sizeof(treeNode));
        S->varf = nodArbore;
        S->varf->info = element;
        S->varf->urm = NULL;
    }
    else
    {
        S->nrElemente++;
        treeNode *nodArbore;
        nodArbore = (treeNode*)malloc(sizeof(treeNode));      
        newNode = nodArbore;
        newNode->info = element;
        newNode->urm = S->varf;
        S->varf = newNode;
    }
}

void initStack(Stack *S)
{
    S->varf = NULL;
    S->nrElemente = 0;
}

void initTreeStack(treeStack *S)
{
    S->varf = NULL;
    S->nrElemente = 0;
}

void initQueue(Queue *C)
{
    C->prim = NULL;
    C->ultim = NULL;
    C->nrElemente = 0;
}

int isEmptyQueue(Queue C)
{
    if(C.nrElemente == 0)
        return 1;
    else
        return 0;
}

// adauga un element la coada, dupa ultimul element (FIFO)
void Enqueue(Queue *C, char element)
{
    Node *newNode;

    if (isEmptyQueue(*C))
    {
        C->nrElemente = 1;
        Node* nod1;
        nod1 = (Node*)malloc(sizeof(Node));
        C->prim = nod1;
        C->prim->info = element;
        C->prim->urm = NULL;
        C->ultim = C->prim;
    }
    else
    {
        C->nrElemente++;
        Node* nod1;
        nod1 = (Node*)malloc(sizeof(Node));
        newNode = nod1;
        newNode->info = element;
        newNode->urm = NULL;
        C->ultim->urm = newNode;
        C->ultim = newNode;
    }
}

void fillPostfixExpr(Queue C)
{
    Node *nod_curent;
    nod_curent = C.prim;
    int i = 0;

    while (nod_curent != NULL)
    {
        postfixExpr[i++] = nod_curent->info;
        nod_curent = nod_curent->urm;
    }
}

//prioritatea operatorilor
int Priority(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(') {
        return 3;
    } else if (c == ')') {
        return 4;
    } else {
        return 5;
    }
}

// adauga la coada varful stivei si apoi scoate varful
void addToQueue(Queue *postfixExprQueue, Stack *S)
{
    Enqueue(postfixExprQueue, S->varf->info);
    Pop(S);
}

//adaugam in stiva operatorii
void addToStack(Stack *S, Queue *postfixExprQueue, char x, int i)
{
    Push(S, x); //altfel, este semn
}

int isOperator(char infixExpr[], int i)
{ // construirea notatie postfixate

    if (strchr("+-*/(),", infixExpr[i]))
        return 1;
    return 0;
}

int isOperator_string(char element[])
{ 
    if (strchr("+-*/", element[0]) && element[1] == '\0')
        return 1;
    return 0;
}

void infixToPostfix(char infixExpr[], Queue *postfixExprQueue)
{

    int i, lg = strlen(infixExpr), j = 0;
    char x;
    Stack S;
    initStack(&S);

    // verificam daca primul numar este negativ
    if (infixExpr[j] == '-')
    {
        Enqueue(postfixExprQueue, '-');
        j = j + 1;
    }

    // parcurgem expresia
    for (i = j; i < lg; i++)
    {
        x = infixExpr[i];
        if (!isOperator(infixExpr, i)) // verificam daca x este operand (ex: a,b,c,d,1,2,3)
            Enqueue(postfixExprQueue, x);
        else
        { 
            // exista operator(ex: +,-,*,/)
            if (x != '(' && infixExpr[i - 1] != ')')
                Enqueue(postfixExprQueue, ','); // punem o virgula intre operanzi

            if (x == ')')
            {
                /* daca elementul este o paranteza dreapta, extragem operatorii din
                stiva si ii adaugam la forma postfixata pana cand varful stivei
                ajunge la o paranteza stanga (care este extrasa, dar nu este adaugata
                la forma postfixata)*/
                while (S.varf->info != '(')
                {
                    addToQueue(postfixExprQueue, &S);
                    Enqueue(postfixExprQueue, ',');
                }

                Pop(&S);
            }
            else if (x != ',')
            {
                /* cat timp exista un alt operator O2 în varful stivei si prioritatea
                sa este mai mare sau egala decat cea a operatorului curent O1,
                adauga O2 la notatia postfixata si extrage O2 din stiva*/
                while (!isEmpty(S) && (S.varf->info != '(') && (Priority(S.varf->info) >= Priority(x)))
                {
                    addToQueue(postfixExprQueue, &S);
                    Enqueue(postfixExprQueue, ',');
                }
                addToStack(&S, postfixExprQueue, x, i); //adauga O1 in stiva
            }
        }
    }
    if (!isOperator(infixExpr, i - 1))
        Enqueue(postfixExprQueue, ',');

    while (S.nrElemente > 1)
    { //extragem toate elementele ramase in stiva si le adaugam la forma postfixata
        addToQueue(postfixExprQueue, &S);
        Enqueue(postfixExprQueue, ',');
    }

    addToQueue(postfixExprQueue, &S);
}

//adaugam notatia postfixata in stiva de arbori
void buildAST(Queue C, treeStack *S)
{
    int i = 0;
    Tree *newTree;
    char element[10];
    memset(element, '\0', 10); // reinitializare sir de caractere

    while (C.prim != NULL)
    {
        if (C.prim->info == ',')
        {
            if (!(isOperator_string(element)))
            { // este operand
                Tree* localTree;
                localTree = (Tree*)malloc(sizeof(Tree));
                newTree = localTree;
                strcpy(newTree->info, element);
                newTree->st = NULL;
                newTree->dr = NULL;
                pushTree(S, newTree);
                // aici newTree e mai de graba newNode
            }
            else
            { 
                // este operator (+,-,*,/)
                Tree* localTree;
                localTree = (Tree*)malloc(sizeof(Tree));
                newTree = localTree;
                strcpy(newTree->info, element);
                newTree->dr = S->varf->info;
                popTree(S);
                newTree->st = S->varf->info;
                popTree(S);
                pushTree(S, newTree);
            }
            memset(element, '\0', strlen(element));
            i = 0;
        }
        else
            element[i++] = C.prim->info;
        C.prim = C.prim->urm;
    }

    if (isOperator_string(element))
    {
        Tree* localTree;
        localTree = (Tree*)malloc(sizeof(Tree));
        newTree = localTree;
        strcpy(newTree->info, element);
        newTree->dr = S->varf->info;
        popTree(S);
        newTree->st = S->varf->info;
        popTree(S);
        pushTree(S, newTree);
    }

}
