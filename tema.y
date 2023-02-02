%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "functii.h"
#include "EvalAST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yylex();
int yyerror(char* s);
extern char tipData[50];
extern char parametri[50];
char listaVarClasa[256];
extern char lista_parametri[256];
extern char lista_parametri_apel[256];
char vectorType[256];
char lista_elemente_vector[256];
char lista_elemente_matrice[512];
char param[50];
char valoareStringChar[256];
char valoareStringChar2[256];
char valoareStringChar3[256];
char functieId[100];
int isBoolExpression;
int linii=0;
%}

%union {
  int intVal;
  char* strVal;
  float floatVal;
  char charVal;
  int boolVal;
}

%token ASSIGN MAIN 
%token <strVal>   TIP
%token <strVal>   TIP_BOOL
%token <intVal>   INT
%token <floatVal> FLOAT
%token <charVal>  CHAR
%token <boolVal>  BOOL
%token <strVal>   ID
%token <strVal>  STRING

/* %token PRINT PRIVATE PUBLIC FUNCTION PRINT_SIMBOLURI PRINT_FUNCTII */
%token EVAL TYPEOF DOT 
%token ADD SUB MULT DIV AND OR GT GEQ LT LEQ EQQ NEQ
%token IF ELSE WHILE FOR DO
%token CONST CLASS
%type <strVal> expresie_matematica expresie NUMAR_INT  expresie_bool expresie_bool_exclusiv parametri parametru NUMAR_FLOAT 
%type <strVal> apel_functie_parametri apel_functie apel_functie_expr
%left ADD SUB 
%left GT GEQ LT LEQ EQQ NEQ 
%right MULT DIV
%left AND OR


%start program
%%
/* ============================================================ Start =========================================================================================== */

program : global main 
        | main
        ;

/* ============================================================ Global =========================================================================================== */

global : bloc_global 
       ;

bloc_global : secventa_instructiuni_global 
            ;

secventa_instructiuni_global : secventa_instructiuni_global declaratie_globala
                             | declaratie_globala
                             | secventa_instructiuni_global atribuire
                             | atribuire
                             | clasa 
                             | secventa_instructiuni_global clasa
                             ;   
declaratie_globala : TIP ID ';' {if(verificareExistenta($2,"global") == 0) declarareId($1,$2,"global",0,0);
                              else if(verificareExistenta($2,"global") == 3)
                               {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else if(verificareExistenta($2,"global") == 4)
                               {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                             }
                   | TIP_BOOL ID ';'  
                                   {
                                        if(verificareExistenta($2,"global") == 0) declarareId($1,$2,"global",0,0);
                                        else if(verificareExistenta($2,"global") == 3)
                                        {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else if(verificareExistenta($2,"global") == 4)
                                        {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }       
                   | TIP_BOOL ID ASSIGN BOOL ';'  {
                                        if(verificareExistenta($2,"global") == 0) declarareIdVal($1,$2,itoa($4), "global",0,0);
                                        else if(verificareExistenta($2,"global") == 3)
                                        {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else if(verificareExistenta($2,"global") == 4)
                                        {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                        else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }  

                   | TIP ID ASSIGN expresie ';' {
                                             if(verificareExistenta($2,"global") == 0) 
                                                            {
                                                                 if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           if(checkAssign(verificareTip($2,"main"),"bool")==1)
                                                                           {
                                                                                asignare($2, $4, "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                 else if(strcmp($1,"string")==0)
                                                                 {
                                                                      if(strcmp($4,"string")==0)
                                                                      {
                                                                           bzero(valoareStringChar2,256);
                                                                           strcpy(valoareStringChar2,valoareStringChar);
                                                                           declarareIdVal($1,$2,valoareStringChar2,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else if(strcmp($1,"char")==0)
                                                                 {
                                                                      if(strcmp($4,"char")==0)
                                                                      {
                                                                           strcpy(valoareStringChar3,valoareStringChar);
                                                                           declarareIdVal($1,$2,valoareStringChar3,"main",0,0);
                                                                      }
}
                                                                      else
                                                                      {
                                                                           int tip1=0;
                                                                           if(strcmp($1,"int")==0)
                                                                                tip1 = 1;
                                                                           else if(strcmp($1,"float")==0)
                                                                                tip1 = 0;
                                                                           int tip2 = verificareTipInt($4);
                                                                           if (tip1 != tip2) 
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      
                                                                 else
                                                                 { 
                                                                      declarareIdVal($1,$2,$4,"global",0,0);
                                                                 }
                                                                      }
                                                            }
                                                            else if(verificareExistenta($2,"global") == 3)
                                                            {
                                                                 printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else if(verificareExistenta($2,"global") == 4)
                                                            {
                                                                 printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else 
                                                            {
                                                                 printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                                            }
                                                       }
                    | TIP ID ASSIGN CHAR ';'   {
                                             if(verificareExistenta($2,"global") == 0) 
                                             {    
                                                  if(checkAssign($1,"char")==1)
                                                  {
                                                       declarareIdVal($1,$2,ctoa($4),"global",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta($2,"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($2,"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                             } 
                   | TIP ID ASSIGN STRING ';' {if(verificareExistenta($2,"global") == 0) 
                                             {    
                                                  if(checkAssign($1,"string")==1)
                                                  {
                                                       declarareIdVal($1,$2,$4,"global",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta($2,"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($2,"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                             
                                           }
                   | CONST TIP ID ';' {printf("[Linia %d] Unei variabile declarata const trebuie sa-i fie asociata o valoare.\n",yylineno); exit(1);}
                   | CONST TIP ID ASSIGN expresie ';'{    
                                                                 if(verificareExistenta($3,"global") == 0) 
                                                                 {
                                                                      int tip1=0;
                                                                      if(strcmp($2,"int")==0)
                                                                           tip1 = 1;
                                                                      else if(strcmp($2,"float")==0)
                                                                           tip1 = 0;
                                                                      int tip2 = verificareTipInt($5);
                                                                      if (tip1 != tip2) 
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      { 
                                                                           declarareIdVal($2,$3,$5,"global",1,0);
                                                                      }
                                                                 }
                                                                 else if(verificareExistenta($3,"global") == 3)
                                                                 {
                                                                      printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else if(verificareExistenta($3,"global") == 4)
                                                                 {
                                                                      printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else 
                                                                 {
                                                                      printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno);
                                                                      exit(1);
                                                                 }
                                                  }
                   | CONST TIP ID ASSIGN STRING ';'{if(verificareExistenta($3,"global") == 0)
                                                  {if(checkAssign($2,"string")==1)
                                                  {
                                                        declarareIdVal($2,$3,$5,"global",1,0);
                                                  }
                                                  else 
                                                  {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                                  } 
                                                  else if(verificareExistenta($3,"global") == 3)
                                                  {
                                                       printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }
                                                  else if(verificareExistenta($3,"global") == 4)
                                                  {
                                                       printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }                                                             
                                           else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
                   | CONST TIP ID ASSIGN CHAR ';'   {
                                                  if(verificareExistenta($3,"global") == 0) 
                                             {    
                                                  if(checkAssign($2,"char")==1)
                                                  {
                                                       declarareIdVal($2,$3,ctoa($5),"global",1,0);
                                                  }
                                                  else 
                                                       {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                       }
                                             }
                                             else if(verificareExistenta($3,"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($3,"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }                                                     
                   | TIP ID '[' INT ']' ';'     {if(verificareExistenta($2,"global") == 0) declara_vector($2,$1,$4,lista_elemente_vector,"global",0,1);
                                              else if(verificareExistenta($2,"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                             else if(verificareExistenta($2,"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
                | TIP ID '[' INT ']' '[' INT ']' ';'{if(verificareExistenta($2,"global") == 0) declara_matrice($2,$1,$4,$7,lista_elemente_matrice,"global",0,2);
                                              else if(verificareExistenta($2,"global") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else if(verificareExistenta($2,"global") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
                |  TIP ID '[' INT ']' ASSIGN '{' elemente_vector '}' ';' {declara_vector($2,$1,$4,lista_elemente_vector,"main",0,1); lista_elemente_vector[0]='\0';}
                |  TIP ID '[' INT ']''[' INT ']' ASSIGN '{'  matrice  '}' ';' {declara_matrice($2,$1,$4,$7,lista_elemente_matrice,"main",0,2); linii=0;lista_elemente_matrice[0]='\0';}
                | declaratie_functie 
                ;  

/* ============================================================ Clasa =========================================================================================== */

clasa : CLASS ID '{' secventa_instructiuni_clasa '}' ';' {  
                                                                      if(verificareExistenta($2,"main") == 0)
                                                                      { 
                                                                           declara_clasa($2,listaVarClasa);  
                                                                           bzero(listaVarClasa,256);
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 4)
                                                                      {
                                                                           printf("[Linia %d] O clasa cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
      | CLASS ID '{' secventa_instructiuni_clasa '}'  {printf("[Linia %d] Lipseste ';' la finalul clasei!\n",yylineno); exit(1);}
      ;

secventa_instructiuni_clasa : secventa_instructiuni_clasa declaratii_clasa
                            | declaratii_clasa                     
                            ;

declaratii_clasa : TIP ID ';' {strcat(listaVarClasa,$1);strcat(listaVarClasa," ");strcat(listaVarClasa,$2);strcat(listaVarClasa," ");strcat(listaVarClasa,"$ ");}
                 | TIP ID ASSIGN expresie ';'{int tip1=0;
                                             if(strcmp($1,"int")==0)
                                             tip1 = 1;
                                             else if(strcmp($1,"float")==0)
                                             tip1 = 0;
                                             int tip2 = verificareTipInt($4);
                                             if (tip1 != tip2) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,$1);strcat(listaVarClasa," ");strcat(listaVarClasa,$2);strcat(listaVarClasa," ");strcat(listaVarClasa,$4);strcat(listaVarClasa," ");}
                 | TIP ID ASSIGN CHAR ';'{
                                             if (strcmp($1,"char")!=0) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,$1);strcat(listaVarClasa," ");strcat(listaVarClasa,$2);strcat(listaVarClasa," ");strcat(listaVarClasa,itoa($4));strcat(listaVarClasa," ");}
                 | TIP ID ASSIGN STRING ';'{
                                             if (strcmp($1,"string")!=0) 
                                             {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n", yylineno);
                                             exit(1);
                                             }
                                             strcat(listaVarClasa,$1);strcat(listaVarClasa," ");strcat(listaVarClasa,$2);strcat(listaVarClasa," ");strcat(listaVarClasa,$4);strcat(listaVarClasa," ");}
                 | TIP ID '(' parametri ')' '{' bloc_functie '}' {
                                                                      if(verificareExistenta($2,"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie($2) == 0)
                                                                      {    
                                                                           
                                                                           declara_functie($1, $2, 1);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                   | TIP ID '(' ')' '{' bloc_functie '}'         {
                                                                      if(verificareExistenta($2,"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie($2) == 0)
                                                                      {    
                                                                           lista_parametri[0] = '\0'; 
                                                                           declara_functie($1, $2, 1);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                   ;


/* ============================================================ Functie =========================================================================================== */

declaratie_functie :  TIP ID '(' parametri ')' '{' bloc_functie '}' {
                                                                      if(verificareExistenta($2,"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie($2) == 0)
                                                                      {    
                                                                           
                                                                           declara_functie($1, $2, 0);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                   | TIP ID '(' ')' '{' bloc_functie '}'         {
                                                                      if(verificareExistenta($2,"main") == 0)
                                                                      {
                                                                           if(verificaDuplicat_functie($2) == 0)
                                                                      {    
                                                                           lista_parametri[0] = '\0'; 
                                                                           declara_functie($1, $2, 0);  
                                                                           lista_parametri[0] = '\0';   
                                                                      }
                                                                      }
                                                                      else if(verificareExistenta($2,"main") == 3)
                                                                      {
                                                                           printf("[Linia %d] O functie cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] O variabila cu acest nume a fost declarata anterior.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                   ;
parametri : parametru {strcpy(lista_parametri,param);$$=lista_parametri;}
          |  parametri '|' parametru {strcat(lista_parametri," ");strcat(lista_parametri,param);$$=lista_parametri;}
          ;

parametru : TIP ID {strcpy(param,$1);strcat(param," ");strcat(param,$2);}
          ;
bloc_functie : bloc_functie secventa_instructiuni_functie
             | secventa_instructiuni_functie
             | instructiuni_control
             | bloc_functie instructiuni_control
             ;
secventa_instructiuni_functie : TIP ID ';' 
                              | TIP ID ASSIGN expresie ';'
                              | TIP_BOOL ID ';'
                              | TIP_BOOL ID ASSIGN BOOL ';'
                              | TIP ID ASSIGN STRING ';'
                              | TIP ID ASSIGN CHAR ';'
                              ;

apel_functie : ID '(' ')' ';' {                        strcpy(functieId, $1);
                                                       lista_parametri_apel[0]='\0';
                                                       if(vericareAntetApelFunctie($1,lista_parametri_apel)==0)
                                                        {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                   lista_parametri_apel[0]='\0';
                                                     }
             | ID '(' apel_functie_parametri ')' ';' { strcpy(functieId, $1);
                                                       if(vericareAntetApelFunctie($1,lista_parametri_apel)==0)
                                                       {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                                       lista_parametri_apel[0]='\0';
                                                     }
             ;
apel_functie_parametri : expresie {strcpy(lista_parametri_apel,determinareTip($1)); strcat(lista_parametri_apel," ");$$=lista_parametri_apel;}
                       | CHAR     {strcpy(lista_parametri_apel,"char");             strcat(lista_parametri_apel," ");$$=lista_parametri_apel;}
                       | STRING   {strcpy(lista_parametri_apel,"string");           strcat(lista_parametri_apel," ");$$=lista_parametri_apel; }
                       | apel_functie_parametri '|' CHAR     {strcat(lista_parametri_apel,"char");             strcat(lista_parametri_apel," ");$$=lista_parametri_apel;}
                       | apel_functie_parametri '|' STRING   {strcat(lista_parametri_apel,"string");           strcat(lista_parametri_apel," ");$$=lista_parametri_apel;}
                       | apel_functie_parametri '|' expresie {strcat(lista_parametri_apel,determinareTip($3)); strcat(lista_parametri_apel," ");$$=lista_parametri_apel;}
                       | apel_functie
                       | apel_functie_parametri '|' apel_functie
                       ;
apel_functie_expr : ID '(' ')'  {    
                                                      lista_parametri_apel[0]='\0';
                                                       if(vericareAntetApelFunctie($1,lista_parametri_apel)==0)
                                                        {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                   lista_parametri_apel[0]='\0';
                                                        $$=$1;
                                                     }
             | ID '('  apel_functie_parametri ')'  { 
                                                       if(vericareAntetApelFunctie($1,lista_parametri_apel)==0)
                                                       {printf("[Linia %d]Pentru a putea apela o functie, aceasta trebuie sa fi fost declarata!\n", yylineno);
    exit(1);}
                                                       lista_parametri_apel[0]='\0';
                                                       $$=$1;
                                                     }
             ;
/*============================================================ Main =========================================================================================== */

main : MAIN '(' ')' bloc_main 
     | MAIN bloc_main {printf("[Linia %d]Eroare lipsesc ().\n",yylineno);exit(1);}
     ; 

bloc_main : '{' secventa_instructiuni_main '}'
          ;

secventa_instructiuni_main : secventa_instructiuni_main declaratie_main 
                           | secventa_instructiuni_main atribuire 
                           | declaratie_main
                           | atribuire
                           | secventa_instructiuni_main instructiuni_control 
                           | instructiuni_control
                           | apel_functie
                           | secventa_instructiuni_main apel_functie
                           ;

declaratie_main : TIP ID ';' {if(verificareExistenta($2,"main") == 0) declarareId($1,$2,"main",0,0);
                              else if(verificareExistenta($2,"main") == 3)
                               {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else if(verificareExistenta($2,"main") == 4)
                               {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                             }
                | TIP_BOOL ID ';' {
                                   if(verificareExistenta($2,"main") == 0) declarareId($1,$2,"main",0,0);
                                   else if(verificareExistenta($2,"main") == 3)
                                   {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else if(verificareExistenta($2,"main") == 4)
                                   {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
                | TIP_BOOL ID ASSIGN BOOL ';'
                                   {
                                   if(verificareExistenta($2,"main") == 0) declarareIdVal($1,$2,itoa($4),"main",0,0);
                                   else if(verificareExistenta($2,"main") == 3)
                                   {printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else if(verificareExistenta($2,"main") == 4)
                                   {printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);}
                                   else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                   }
                | TIP ID ASSIGN expresie ';' {    
                                                            if(verificareExistenta($2,"main") == 0) 
                                                            {
                                                                 if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           char idType[69];
                                                                           if(checkAssign(verificareTip($2,"main"),"bool")==1)
                                                                           {
                                                                                asignare($2, $4, "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                 else if(strcmp($1,"string")==0)
                                                                 {
                                                                      if(strcmp($4,"string")==0)
                                                                      {
                                                                           bzero(valoareStringChar2,256);
                                                                           strcpy(valoareStringChar2,valoareStringChar);
                                                                           declarareIdVal($1,$2,valoareStringChar2,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else if(strcmp($1,"char")==0)
                                                                 {
                                                                      if(strcmp($4,"char")==0)
                                                                      {
                                                                           strcpy(valoareStringChar3,valoareStringChar);
                                                                           declarareIdVal($1,$2,valoareStringChar3,"main",0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                 int tip1=0;
                                                                 if(strcmp($1,"int")==0)
                                                                      tip1 = 1;
                                                                 else if(strcmp($1,"float")==0)
                                                                      tip1 = 0;
                                                                 int tip2 = verificareTipInt($4);
                                                                 if (tip1 != tip2) 
                                                                 {
                                                                      printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                 }
                                                                 else
                                                                 { 
                                                                      declarareIdVal($1,$2,$4,"main",0,0);
                                                                 }
                                                                 }
                                                            }
                                                            else if(verificareExistenta($2,"main") == 3)
                                                            {
                                                                 printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }
                                                            else if(verificareExistenta($2,"main") == 4)
                                                            {
                                                                 printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                            }   
                                                            else 
                                                            {
                                                                 printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                                            }
 
               
                | TIP ID ASSIGN STRING ';' {
                                             if(verificareExistenta($2,"main") == 0) 
                                             {    
                                                  if(checkAssign($1,"string")==1)
                                                  {
                                                       declarareIdVal($1,$2,$4,"main",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta($2,"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($2,"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                           }
                | TIP ID ASSIGN CHAR ';' {
                                             if(verificareExistenta($2,"main") == 0) 
                                             {    
                                                  if(checkAssign($1,"char")==1)
                                                  {
                                                       declarareIdVal($1,$2,ctoa($4),"main",0,0);
                                                  }
                                                  else 
                                                  {
                                                       printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }
                                             }
                                             else if(verificareExistenta($2,"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($2,"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else 
                                             {
                                                  printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);
                                             }
                                           }
                | CONST TIP ID ASSIGN expresie ';'   {    
                                                                 if(verificareExistenta($3,"main") == 0) 
                                                                 {
                                                                      int tip1=0;
                                                                      if(strcmp($2,"int")==0)
                                                                           tip1 = 1;
                                                                      else if(strcmp($2,"float")==0)
                                                                           tip1 = 0;
                                                                      int tip2 = verificareTipInt($5);
                                                                      if (tip1 != tip2) 
                                                                      {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      else
                                                                      { 
                                                                           declarareIdVal($2,$3,$5,"main",1,0);
                                                                      }
                                                                 }
                                                                 else if(verificareExistenta($3,"main") == 3)
                                                                 {
                                                                      printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else if(verificareExistenta($3,"main") == 4)
                                                                 {
                                                                      printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                                 }
                                                                 else 
                                                                 {
                                                                      printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno);
                                                                      exit(1);
                                                                 }
                                                  }
                | CONST TIP ID ASSIGN CHAR ';'   {
                                                  if(verificareExistenta($3,"main") == 0) 
                                             {    
                                                  if(checkAssign($2,"char")==1)
                                                  {
                                                       declarareIdVal($2,$3,ctoa($5),"main",1,0);
                                                  }
                                                  else 
                                                       {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                       }
                                             }
                                             else if(verificareExistenta($3,"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else if(verificareExistenta($3,"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                             }
                                             else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }                                                     
                | CONST TIP ID ASSIGN STRING ';'{if(verificareExistenta($3,"main") == 0)
                                                  {if(checkAssign($2,"string")==1)
                                                  {
                                                        declarareIdVal($2,$3,$5,"main",1,0);
                                                  }
                                                  else 
                                                  {
                                                            printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                                  }

                                                  } 
                                                  else if(verificareExistenta($3,"main") == 3)
                                                  {
                                                       printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }
                                                  else if(verificareExistenta($3,"main") == 4)
                                                  {
                                                       printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); exit(1);
                                                  }            
                                           else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);}
                                           }
                | TIP ID '[' INT ']' ';'     {if(verificareExistenta($2,"main") == 0) declara_vector($2,$1,$4,lista_elemente_matrice,"main",0,1);
                                              else if(verificareExistenta($2,"main") == 3)
                                             {
                                                  printf("[Linia %d] Exista o functie cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                             else if(verificareExistenta($2,"main") == 4)
                                             {
                                                  printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                  exit(1);
                                             }
                                              else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                             }
                | TIP ID '[' INT ']' '[' INT ']' ';' { 
                                                       if(verificareExistenta($2,"main") == 0) declara_matrice($2,$1,$4,$7,lista_elemente_matrice,"main",0,2);
                                                       else if(verificareExistenta($2,"main") == 3)
                                                       {
                                                            printf("[Linia %d] Exista o functie cu acleasi nume ca variabila pe care incercati sa o declarati!\n",yylineno); 
                                                            exit(1);
                                                       }
                                                       else if(verificareExistenta($2,"main") == 4)
                                                       {
                                                            printf("[Linia %d] Exista o clasa cu acelasi nume ca variabila pe care incercati sa o declarati!\n",yylineno);
                                                            exit(1);
                                                       }
                                                       else {printf("[Linia %d] Variabila a fost declarata deja.\n",yylineno); exit(1);} 
                                                     }
                | ID DOT ID ASSIGN expresie ';'             {
                                                                 if(verificareExistenta($1, "main") == 1 || verificareExistenta($1, "main") == 2)
                                                                 {    
                                                                       int tip_expr = verificareTipInt($5);
                                                                           char *tip;
                                                                           if(tip_expr==0)
                                                                                tip = "float";
                                                                           else
                                                                                tip = "int";
                                                                       if(verificaCamp_clasa($1, $3,tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa($1, $3,tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, $1); 
                                                                      exit(1);
                                                                 }
                                                            }
                | ID DOT ID ASSIGN CHAR ';'             {
                                                                 if(verificareExistenta($1, "main") == 1 || verificareExistenta($1, "main") == 2)
                                                                 {    
                                                                           char *tip;
                                                                           tip = "char";
                                                                       if(verificaCamp_clasa($1, $3,tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa($1, $3,tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, $1); 
                                                                      exit(1);
                                                                 }
                                                            }
                | ID DOT ID ASSIGN STRING ';'             {
                                                                 if(verificareExistenta($1, "main") == 1 || verificareExistenta($1, "main") == 2)
                                                                 {    
                                                                           char *tip;
                                                                           tip = "string";
                                                                       if(verificaCamp_clasa($1, $3,tip) == -1)
                                                                      {
                                                                           printf("[Linia %d] Tipul campului %s caruia incercati sa-i asignati o valoare este diferit de tipul valorii!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                      else if(verificaCamp_clasa($1, $3,tip) == 0)
                                                                      {
                                                                           printf("[Linia %d] Nu se poate realiza accesarea campului %s deoarece acesta nu exista in clasa!\n",yylineno, $3);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                      printf("[Linia %d] Nu exista o variabila declarata cu id-ul %s.\n", yylineno, $1); 
                                                                      exit(1);
                                                                 }
                                                            }
                | EVAL '(' STRING ')' ';'   {   int g=0;
                                                char EvalVerificare[256];
                                                strcpy(EvalVerificare,$3);
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                  if(strchr(".",EvalVerificare[i]) && strchr("+-/*",EvalVerificare[i])!=0)
                                                  {
                                                       printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip float in expresie\n",yylineno);
                                                       exit(1);
                                                  }
                                                  else if(strchr(".",EvalVerificare[i]) && strchr("+-/*",EvalVerificare[i])==0)
                                                  {
                                                       printf("Eval (%s) este : %s\n",$3,$3);
                                                       g=1;
                                                  }
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("''",EvalVerificare[i]))
                                                {printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip char in expresie\n",yylineno);
                                                 exit(1);}
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("""",EvalVerificare[i]))
                                                {printf("[Linia %d]Eval poate evalua doar expresii de tip int, in cazul de fata aveti o valoare de tip string in expresie\n",yylineno);
                                                 exit(1);}
                                                
                                                for(int i = 0; i<strlen(EvalVerificare);i++)
                                                    if(strchr("+-/*",EvalVerificare[i]))
                                                        {AST($3);g=1;break;}
                                                    if(g==0)
                                                    {   
                                                        char *val;      
                                                        val=valoareId(EvalVerificare);
                                                        printf("Eval (%s) este : %s\n",EvalVerificare,val);                                         
                                                    }
        
                                                
                                                
        
                                            }
                | TIP ID ASSIGN EVAL '(' STRING ')' ';'
                | ID ASSIGN EVAL '(' STRING ')' ';'

                | TYPEOF '(' expresie ')' ';' {   char type[256];
                                                                                if(strcmp($3,"string")==0)
                                                                                    strcpy(type,"string");
                                                                                else if(strcmp($3,"char")==0)
                                                                                    strcpy(type,"char");
                                                                                else
                                                                            {
                                                                                int tipNr;
                                                                                tipNr = verificareTipInt($3);
                                                                                if(tipNr==0)
                                                                                    strcpy(type,"float");
                                                                                else if(tipNr==1)
                                                                                    strcpy(type,"int");
                                                                            }
                                                                                printf("TypeOf la linia %d = %s\n",yylineno,type);
                                                                                }
                | TYPEOF '(' STRING ')' ';' {printf("TypeOf la linia %d = string\n",yylineno);}
                | TYPEOF '(' BOOL ')' ';' {printf("TypeOf la linia %d = bool\n",yylineno);}
                | TYPEOF '(' CHAR ')' ';' {printf("TypeOf la linia %d = char\n",yylineno);}
                | ID ID ';'                                 {
                                                                 if(verificaClasa($1) == 1)
                                                                 {
                                                                      if(verificareExistenta($2, "main") == 0)
                                                                      {
                                                                           declarareId($1, $2, "main", 0,0);
                                                                      }
                                                                      else
                                                                      {
                                                                           printf("[Linia %d] Numele acestei variabile este deja folosit in program!\n",yylineno);
                                                                           exit(1);
                                                                      }
                                                                 }
                                                                 else
                                                                 {
                                                                     printf("[Linia %d] Nu exista o clasa cu acest nume: %s\n",yylineno, $1);exit(1);
                                                                 }
                                                            }
                | TIP ID '[' INT ']' ASSIGN '{' elemente_vector '}' ';' {declara_vector($2,$1,$4,lista_elemente_vector,"main",0,1); lista_elemente_vector[0]='\0';}
                | TIP ID '[' INT ']''[' INT ']' ASSIGN '{'  matrice  '}' ';' {declara_matrice($2,$1,$4,$7,lista_elemente_matrice,"main",0,2); linii=0;lista_elemente_matrice[0]='\0';}
                ;
matrice : '{' elemente_vector '}' {strcpy(lista_elemente_matrice,lista_elemente_vector);strcat(lista_elemente_matrice,itoa(linii)); strcat(lista_elemente_matrice," ");linii++; }
        | matrice ',' '{' elemente_vector '}' {strcat(lista_elemente_matrice,lista_elemente_vector); strcat(lista_elemente_matrice,itoa(linii));strcat(lista_elemente_matrice," ");linii++; }
        ;
elemente_vector :  elemente_vector ',' INT    {strcat(lista_elemente_vector,"int");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,itoa($3));strcat(lista_elemente_vector," ");}
                |  INT                        {strcpy(lista_elemente_vector,"int");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,itoa($1));strcat(lista_elemente_vector," ");}
                |  elemente_vector ',' FLOAT  {strcat(lista_elemente_vector,"float");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ftoa($3));strcat(lista_elemente_vector," ");}
                |  FLOAT                      {strcpy(lista_elemente_vector,"float");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ftoa($1));strcat(lista_elemente_vector," ");}
                |  elemente_vector ',' CHAR   {strcat(lista_elemente_vector,"char");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ctoa($3));strcat(lista_elemente_vector," ");}
                |  CHAR                       {strcpy(lista_elemente_vector,"char");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,ctoa($1));strcat(lista_elemente_vector," ");}
                |  elemente_vector ',' STRING {strcat(lista_elemente_vector,"string");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,$3);strcat(lista_elemente_vector," ");}
                |  STRING                     {strcpy(lista_elemente_vector,"string");strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,$1);strcat(lista_elemente_vector," ");}
                |  elemente_vector ',' ID     {strcat(lista_elemente_vector,tipId($3));strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,valoareId($3));strcat(lista_elemente_vector," ");}
                |  ID                         {strcpy(lista_elemente_vector,tipId($1));strcat(lista_elemente_vector," ");strcat(lista_elemente_vector,valoareId($1));strcat(lista_elemente_vector," ");}         
       ;

atribuire : ID ASSIGN expresie ';' {                                  if(getScope($1)!=-1)
                                                                      {
                                                                      if(isBoolExpression == 1)
                                                                      {
                                                                           isBoolExpression = 0;
                                                                           if(checkAssign(verificareTip($1,"main"),"bool")==1)
                                                                           {
                                                                                asignare($1, $3, "main");
                                                                           }
                                                                           else
                                                                           {
                                                                                printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                      }
                                                                      else{
                                                                      int tip1 = verificareTipIntId($1,getScope($1));
                                                                      int tip2 = verificareTipInt($3);
                                                                      if (tip1 != tip2) {
                                                                      printf("[Linia %d] Nu pot exista atribuiri intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                      }
                                                                      else
                                                                      {    if(getScope($1) == 0)
                                                                           asignare($1,$3,"global");
                                                                           else if(getScope($1) == 1)
                                                                           asignare($1,$3,"main");
                                                                      }
                                                                      }
                                                                      }
                                                                      else 
                                                                      {
                                                                           printf("[Linia %d] Variabila nu a fost declarata.\n",yylineno); exit(1);
                                                                      } 
                                   }
          | ID ASSIGN expresie {printf("[Linia %d] Lipseste ';' de la finalul expresiei\n",yylineno);exit(1);}
          | ID ASSIGN STRING ';'{if(verificareExistenta($1,"main") == 1) 
                                    {if(checkAssign(verificareTip($1,"main"),"string")==1) //daca imi gaseste variabila declarata in main
                                        asignare($1,$3,"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta($1,"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip($1,"global"),"string")==1) //daca imi gaseste variabila declarata global
                                             asignare($1,$3,"global");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
          | ID ASSIGN CHAR ';'{if(verificareExistenta($1,"main") == 1) 
                                    {if(checkAssign(verificareTip($1,"main"),"char")==1) //daca imi gaseste variabila declarata in main
                                        asignare($1,ctoa($3),"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta($1,"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip($1,"global"),"char")==1) //daca imi gaseste variabila declarata global
                                             asignare($1,ctoa($3),"global");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
          | ID ASSIGN BOOL ';'{if(verificareExistenta($1,"main") == 1) 
                                    {if(checkAssign(verificareTip($1,"main"),"bool") == 1) //daca imi gaseste variabila declarata in main
                                        asignare($1,itoa($3),"main");
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                    }
                                    else if(verificareExistenta($1,"main") == 2) 
                                   {
                                        if(checkAssign(verificareTip($1,"global"),"bool")==1)
                                        {
                                             //daca imi gaseste variabila declarata global
                                             printf("itoa drc: %s\n", itoa($3));
                                             asignare($1,itoa($3),"global");
                                        } 
                                        else
                                        {
                                             printf("[Linia %d] Nu pot exista asignari intre tipuri de date diferite.\n",yylineno); exit(1);
                                        }
                                   } 
                                   else
                                   {
                                        printf("[Linia %d] Variabila careia incercati sa-i atribuiti o valoare nu a fost declarata.\n",yylineno);exit(1);
                                   }
                                   }
                    | ID DOT apel_functie    {
                                                  
                                                  if(verificareExistenta($1,"main") == 1) 
                                                  {
                                                       if(isInClass(functieId) == 0)
                                                       {
                                                            printf("[Linia %d] Functia pe care incercati sa o accesati nu face parte din clasa.\n",yylineno);
                                                       }

                                                  }
                                                  else
                                                  {
                                                       printf("[Linia %d] Variabila %s nu a fost declarata.\n",yylineno, $1);
                                                  }

                                             }
     
          ;
/*============================================================ Expresii =========================================================================================== */

expresie : expresie_matematica {$$=$1;}
         | expresie_bool {isBoolExpression = 1; $$=$1;}
         ;

expresie_matematica : expresie_matematica ADD expresie_matematica  {
                                                                      int tip1 = verificareTipInt($1);
                                                                      int tip2 = verificareTipInt($3);
                                                                      
                                                                      if (tip1 != tip2) {
                                                                      printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                      exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf($1, "%d", atoi($1) + atoi($3));
                                                                           $$ = $1;
                                                                      }
                                                                      else if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf($1, "%f", atof($1) + atof($3));
                                                                           $$ = $1;
                                                                      }
                                                                      else if(strcmp($1,$3)!=0)
                                                                      {
                                                                           printf("[Linia %d] Eroare semantica, nu pot exista operatii intre tipuri de caractere diferite!\n",yylineno);
                                                                           exit(1);
                                                                      }
                                                                   
                                                                 }
                    | expresie_matematica SUB expresie_matematica  {
                                                                      int tip1 = verificareTipInt($1);
                                                                      int tip2 = verificareTipInt($3);
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf($1, "%d", atoi($1) - atoi($3));
                                                                           $$ = $1;
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf($1, "%f", atof($1) - atof($3));
                                                                           $$ = $1;
                                                                      }
                                                                    }
                    | expresie_matematica MULT expresie_matematica {
                                                                      int tip1 = verificareTipInt($1);
                                                                      int tip2 = verificareTipInt($3);
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           sprintf($1, "%d", atoi($1) * atoi($3));
                                                                           $$ = $1;
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           sprintf($1, "%f", atof($1) * atof($3));
                                                                           $$ = $1;
                                                                      }
                                                                   }
                    | expresie_matematica DIV expresie_matematica {
                                                                      int tip1 = verificareTipInt($1);
                                                                      int tip2 = verificareTipInt($3);
                                                                      if (tip1 != tip2) {
                                                                           printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                                                           exit(1);
                                                                      }
                                                                      if (tip1 == 1) { //dacă ambele valori sunt întregi, efectuăm operația întreagă
                                                                           if (atoi($3) == 0) { //verificăm dacă divizorul este diferit de 0
                                                                                printf("[Linia %d] Impartire la 0.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                           sprintf($1, "%d", atoi($1) / atoi($3));
                                                                           $$ = $1;
                                                                      }
                                                                      if (tip1 == 0) { //dacă ambele valori sunt zecimale, efectuăm operația zecimală
                                                                           if (atof($3) == 0.0) { //verificăm dacă divizorul este diferit de 0.0
                                                                                printf("[Linia %d] Impartire la 0.\n", yylineno);
                                                                                exit(1);
                                                                           }
                                                                           sprintf($1, "%f", atof($1) / atof($3));
                                                                           $$ = $1;
                                                                      }
                                                                   }

                    
                    | '(' expresie_matematica ')' {$$ = $2;}
                    | NUMAR_INT {$$ = $1;}
                    | NUMAR_FLOAT {$$ = $1;}
                    | ID {
                         
                         if (verificareExistenta($1, "main") == 1 ){
                         if(isVector($1)==1)
                              {printf("[Linia %d] Utilizarea gresita a unui vector, formatul este id[size]!\n",yylineno);exit(1);}
                         if(isVector($1)==2)
                              {printf("[Linia %d] Utilizarea gresita a unei matrici, formatul este id[size][size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue($1,"main",0,0);
                         
                         strcpy(valoareStringChar,returnValStringChar($1));
                    
                         strcpy($$,returnVal);
                         } 
                         else if(verificareExistenta($1, "main") == 2 )
                         {
                            char* returnVal;
                              returnVal = returnValue($1,"global",0,0);
                              strcpy(valoareStringChar,returnValStringChar($1));  
                              strcpy($$,returnVal);  
                         }
                         else {printf("[Linia %d]Variabila %s nu a fost declarata\n",yylineno,$1);exit(1);}}
                    | ID '[' INT ']' {if (verificareExistenta($1, "main") == 1 ){

                         if(isVector($1)==0)
                              {printf("[Linia %d] Aceasta variabila nu este un vector!\n",yylineno);exit(1);}
                         if(isVector($1)==2)
                              {printf("[Linia %d] Utilizarea gresita a unei matrici, formatul este id[size][size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue($1,"main",$3,0);
                         strcpy($$,returnVal);} 
                         else if(verificareExistenta($1, "main") == 2 ){
                            char* returnVal;
                         returnVal = returnValue($1,"global",$3,0);
                         strcpy($$,returnVal);  
                         }
                         else {printf("[Linia %d]Vectorul %s nu a fost declarata\n",yylineno,$1);exit(1);}}
                    | ID '[' INT ']' '[' INT ']' {if (verificareExistenta($1, "main") == 1 ){
                         if(isVector($1)==0)
                              {printf("[Linia %d] Aceasta variabila nu este o matrice!\n",yylineno);exit(1);}
                         if(isVector($1)==1)
                              {printf("[Linia %d] Utilizarea gresita a unui vector, formatul este id[size]!\n",yylineno);exit(1);}
                         char* returnVal;
                         returnVal = returnValue($1,"main",$3,$6);
                         strcpy($$,returnVal);} 
                         else if(verificareExistenta($1, "main") == 2 ){
                            char* returnVal;
                         returnVal = returnValue($1,"global",$3,$6);
                         strcpy($$,returnVal);  
                         }
                         else {printf("[Linia %d]Vectorul %s nu a fost declarata\n",yylineno,$1);exit(1);}}
                    | apel_functie_expr  {
                                          if(getTipFunctie($1)==1)strcpy($$,"0.0");
                                          else if(getTipFunctie($1)==2)strcpy($$,"0");
                                          else if(getTipFunctie($1)==3)strcpy($$,"char");
                                          else if(getTipFunctie($1)==4)strcpy($$,"string");
                                         } 
                    ;
//sub_expresie_mat : NUMAR ADD NUMAR {strcpy(tipData1,tipData);} {if(verificareTipExpresie(tipData2,tipData1) ==0){printf("Eroare");exit(1);}}
  //               ;


NUMAR_INT : INT {$$=itoa($1);} 
          ;
NUMAR_FLOAT : FLOAT {$$=ftoa($1);} 
          ;

/* NUMAR : INT {$$=itoa($1); strcpy(tipData,"int");}
      | FLOAT {$$=ftoa($1); strcpy(tipData,"float");}
      ; */
expresie_bool : expresie GT expresie  { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) > atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) > atof($3));}
                                       }
              | expresie LT expresie  { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) < atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) < atof($3));}
                                       }
              | expresie EQQ expresie { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) == atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) == atof($3));}
                                       }
              | expresie NEQ expresie { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) != atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) != atof($3));}
                                       }
              | expresie GEQ expresie { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) >= atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) >= atof($3));}
                                       }
              | expresie LEQ expresie { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1)  <= atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) <= atof($3));}
                                       } 
              | '(' expresie_bool ')' {$$=$2;}
              | '(' expresie_bool_exclusiv ')' {$$=$2;}
              ;
expresie_bool_exclusiv : expresie_bool AND expresie_bool { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) && atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) && atof($3));}
                                       }
                       | expresie_bool OR expresie_bool  { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) || atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) || atof($3));}
                                       }
                       | expresie_bool_exclusiv AND  expresie_bool_exclusiv { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) && atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) && atof($3));}
                                       }
                       | expresie_bool_exclusiv OR expresie_bool_exclusiv { 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) || atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) || atof($3));}
                                       }
                       | expresie_bool_exclusiv OR expresie_bool{ 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) || atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) || atof($3));}
                                       }    
                                                            
                       | expresie_bool_exclusiv AND expresie_bool{ 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                       if(tip1 == 1)
                                        {$$= itoa(atoi($1) && atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) && atof($3));}
                                       }
                       | expresie_bool OR expresie_bool_exclusiv{ 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) || atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) || atof($3));}
                                       }
                       | expresie_bool AND expresie_bool_exclusiv{ 
                                        int tip1 = verificareTipInt($1);
                                        int tip2 = verificareTipInt($3);
                                        if (tip1 != tip2) {
                                              printf("[Linia %d] Nu pot exista operatii intre tipuri de date diferite.\n", yylineno);
                                              exit(1);
                                                          }
                                        if(tip1 == 1)
                                        {$$= itoa(atoi($1) && atoi($3));}
                                        else if(tip1 == 0)
                                        {$$= ftoa(atof($1) && atof($3));}
                                       }
                       ;

/*============================================================ Instructiuni_Control =========================================================================================== */

instructiuni_control : control_if
                     | control_while
                     | control_for
                     ;
control_if: IF '(' expresie_bool ')' bloc_main 
          | IF '(' expresie_bool_exclusiv ')' bloc_main 
          | IF '(' expresie_bool ')' bloc_main ELSE bloc_main 
          | IF '(' expresie_bool_exclusiv ')' bloc_main ELSE bloc_main 
          ;
control_while : WHILE '(' expresie_bool ')' DO bloc_main 
              | WHILE '(' expresie_bool_exclusiv ')' DO bloc_main 
              ;
control_for : FOR '(' ID ASSIGN expresie_matematica ';' expresie_bool ';' ID ASSIGN expresie_matematica ')'  {
                                                       if(verificareExistenta($3,"main") == 0)
                                                            {printf("[Linia %d] Variabila %s din for nu a fost declarata.\n",yylineno,$3);exit(1);}
                                                       } bloc_main
            ;
/*============================================================ int main =========================================================================================== */

%%
int erori=0;
int yyerror(char * s){
     erori++;
     printf("eroare: %s la linia:%d\n",s,yylineno);
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
     if(erori==0)
     {
          printf("Programul este corect sintatic!\n\n");
          afisare();
          afisare_functii();
          //afisare_vector();
          //afisare_matrice();
 
     }
     else
     {printf("Programul nu este corect sintatic!\n\n");}
     
     
}
