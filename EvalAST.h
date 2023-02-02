#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include "AST.h"

int evalAST(Tree *a)
    {
        if (a != NULL)
        {
            if (strstr(a->info, "+"))
            {   
                return evalAST(a->st) + evalAST(a->dr);
            }
            if (strstr(a->info, "-"))
            {
                return evalAST(a->st) - evalAST(a->dr);
            }
            if (strstr(a->info, "*"))
            {
                return evalAST(a->st) * evalAST(a->dr);
            }
            if (strstr(a->info, "/"))
            {
                return evalAST(a->st) / evalAST(a->dr);
            }       
            else if (strchr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", a->info[0]))
            {   
                for(int i=0;i<total_variabile;i++)
                    if(eDuplicat(a->info)!=1)
                    {
                        
                        printf("Variabila %s din apelul functiei Eval() nu a fost declarata\n",a->info);
                        exit(1);   
                    } 
                    else
                    {               
                    if(strcmp(tipId(a->info),"int")==0)
                        {   
                                char* valoare;
                                valoare = valVarAst(a->info);
                                return atoi(valoare);
                        }
                    else if(strcmp(tipId(a->info),"string")==0)
                    {               
                       printf("Eval poate evalua doar o expresie de tip int, in cazul de fata variabila %s este de tip string\n",a->info);
                       exit(1);
                    }
                    else if(strcmp(tipId(a->info),"char")==0)
                    {               
                       printf("Eval poate evalua doar o expresie de tip int, in cazul de fata variabila %s este de tip char\n",a->info);
                       exit(1);
                    }
                    else if(strcmp(tipId(a->info),"float")==0)
                    {               
                       printf("Eval poate evalua doar o expresie de tip int, in cazul de fata variabila %s este de tip float\n",a->info);
                       exit(1);
                    }
               }
     
            }
            return atoi(a->info);
        }
    }
void AST(char* expression)
    {
        // convertirea din notatia infixata in cea postfixata:
        // - parcurgem expresia caracter cu caracter, de la stanga la dreapta
        // - daca intalnim un operand (2, 3, a, b), il adaugam la coada
        // - daca intalnim un operator(+, -, *, /), il adaugam pe stiva  si il comparam cu operatorii existenti deja
        // - in cazul in care operatorul curent are prioritatea mai mare sau egala decat cel/cei din varful stivei, il adaugam in stiva
        // - daca prioritatea operatorului curent este mai mica, extragem toti operatorii cu prioritate mai mare si ii adaugam in coada, pana cand operatorul curent poate fi adaugat in stiva
        // - daca intalnim o paranteza stanga, o adaugam in stiva, daca intalnim o paranteza dreapta, extragem operatorii din stiva si ii adaugam in coada, pana cand intalnim paranteza stanga, care este apo eliminata din stiva

        strcpy(infixExpr, expression+1);
        infixExpr[strlen(infixExpr)-1] = '\0';

        initQueue(&postfixExprQueue);
        infixToPostfix(infixExpr, &postfixExprQueue);
        fillPostfixExpr(postfixExprQueue); // nu e prea relevanta

        treeStack S;
        initTreeStack(&S);
        buildAST(postfixExprQueue, &S);

        int rezultat = evalAST(S.varf->info);
        printf("Eval (%s) este : %d\n",infixExpr,rezultat);
        
    }

