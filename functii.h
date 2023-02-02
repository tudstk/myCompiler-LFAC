#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
/*============================================================ Declarari =========================================================================================== */

int total_variabile = 0;
int total_functii = 0;
int total_clase = 0;
int parametri_expresie = 0;
char tipData[50];
char lista_parametri[256];
char lista_parametri_apel[256];
struct varNumeStruct
{
    int valoareInt;
    float valoareFloat;
    char valoareChar;
    char *valoareString;

    int isVect;  // 0 - NU | 1 - DA | 2 - Matrice
    int isConst; // 0 - NU | 1 - DA
    char *nume;
    char *tip_date;
    char *scope;
    char *valoare;
    int eInitializata;
    struct vector
    {
        char param_id[64];
    } elemente_vector[64];
    int lungime_vector;
    int elemente;
    struct matrice
    {
        char param_id[64];
    } elemente_matrice[64][64];
    int linii;
    int coloane;

} variabile[256];

struct functie
{
    char *nume;
    char *tip_date;
    int inClasa;
    struct parametru
    {
        char param_type[50];
        char param_id[50];
    } parametri[20];
    int nr_parametri;

} functii[64];

struct Clase
{
    char *nume;
    struct
    {
        char *nume;
        char *tip_date;
        char *valoareString;
    } campuri[20];
    struct functie functii[20];
    int numar_variabile;
    int numar_functii;
} clase[64];

extern int yylineno;

/*============================================================ Functii =========================================================================================== */

void adaugaID(char *id, char *id_data_type)
{
    variabile[total_variabile].nume = id;
    variabile[total_variabile].tip_date = id_data_type;
    total_variabile++;
}

void adaugaConstID_int(char *id, int val)
{
    variabile[total_variabile].nume = id;
    variabile[total_variabile].valoareInt = val;
    variabile[total_variabile].isConst = 1;
    total_variabile++;
}

int getConst(char *id)
{
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0)
        {
            if (variabile[i].isConst == 1)
                return 1;
            else
                return 0;
        }
    }
}

int verificareExistenta(char *id, char *scope)
{
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(scope, "main") == 0 && strcmp("global", variabile[i].scope) == 0) // variabila e declarata global deja
        {
            return 2;
        }
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(scope, variabile[i].scope) == 0) // duplicat
        {
            return 1;
        }
    }
    for (int i = 0; i < total_functii; i++)
    {
        if (strcmp(id, functii[i].nume) == 0)
            return 3; // exista o functie declarata cu id-ul acesta
    }
    for (int i = 0; i < total_clase; i++)
    {
        if (strcmp(id, clase[i].nume) == 0)
            return 4; // exista o clasa declarata cu id-ul acesta
    }
    return 0; // variabila nu este declarata
}

int eDuplicat(char *id)
{
    id[strlen(id)-1] = '\0';
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0)
        {
            return 1;
        }
    }
    return 0;
}
char *verificareTip(char *id, char *scope)
{
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(scope, variabile[i].scope) == 0)
        {
            return variabile[i].tip_date;
        }
    }
}
int verificareTipExpresie(char *tipOp1, char *tipOp2)
{
    if (strcmp(tipOp1, tipOp2) == 0)
        return 1;
    else
        return 2;
}
int isInClass(char* id)
{
    for(int i = 0; i < total_functii; i++)
    {
        if(strcmp(id, functii[i].nume) == 0)
        {
            return functii[i].inClasa;
        }
    }
}
void declarareId(char *tip, char *id, char *scope, int isConst, int isVect)
{

    variabile[total_variabile].nume = id;
    variabile[total_variabile].isConst = isConst;
    variabile[total_variabile].scope = scope;
    variabile[total_variabile].valoareString = " ";
    variabile[total_variabile].valoareChar = ' ';
    variabile[total_variabile].tip_date = tip;
    variabile[total_variabile].isVect = isVect;
    if (strcmp(variabile[total_variabile].tip_date, "int") == 0)
    {
        variabile[total_variabile].valoare = "0";
    }
    else if (strcmp(variabile[total_variabile].tip_date, "float") == 0)
    {
        variabile[total_variabile].valoare = "0.0";
    }
    else if (strcmp(variabile[total_variabile].tip_date, "string") == 0)
    {
        variabile[total_variabile].valoare = " ";
    }
    else if (strcmp(variabile[total_variabile].tip_date, "char") == 0)
    {
        variabile[total_variabile].valoare = " ";
    }
     else if (strcmp(variabile[total_variabile].tip_date, "bool") == 0)
    {
        variabile[total_variabile].valoare = "0";
    }

    total_variabile++;
}
int isVector(char *id)
{
    for (int i = 0; i < total_variabile; i++)
        if (strcmp(variabile[i].nume, id) == 0)
            if (variabile[i].isVect == 1)
            {
                return 1;
            }
            else if (variabile[i].isVect == 2)
            {
                return 2;
            }
            else
            {
                return 0;
            }
                
}
int checkAssign(char *tipData, char *tipValoare)
{
    if (strcmp(tipData, tipValoare) == 0)
        return 1;
    else
        return 0;
}
char atoc(const char *str)
{
    if (str[0] == '\0')
    {
        fprintf(stderr, "Eroare la convertirea stringului '%s' intr-un caracter\n", str);
        return '\0';
    }
    else
    {
        return str[0];
    }
}
void declarareIdVal(char *tip, char *id, char *valoare, char *scope, int isConst, int isVect)
{
    variabile[total_variabile].nume = id;
    variabile[total_variabile].isConst = isConst;
    variabile[total_variabile].scope = scope;
    variabile[total_variabile].tip_date = tip;
    variabile[total_variabile].isVect = isVect;

    variabile[total_variabile].valoare = valoare;
    total_variabile++;
}
void asignare(char *id, char *valoare, char *scope)
{
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(scope, variabile[i].scope) == 0)
        {

            if (variabile[i].isConst == 0)
            {
                variabile[i].valoare = valoare;
                break;
            }
            else
            {
                printf("O variabila declarata const nu mai poate primi alta valoare, linia %d\n", yylineno);
                exit(1);
            }
        }
    }
}
int getScope(char *id)
{
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0)
        {
            if (strcmp(variabile[i].scope, "global") == 0)
                return 0;
            else if (strcmp(variabile[i].scope, "main") == 0)
                return 1;
        }
    }
    return -1;
}
void afisare()
{
    FILE *fp;

    fp = fopen("symbol_table.txt", "w");
    fprintf(fp, "Id - Tip - Scope - Valoare - Constant\n");
    for (int i = 0; i < total_variabile; i++)
    {

        fprintf(fp, "%s - %s - %s - ", variabile[i].nume, variabile[i].tip_date, variabile[i].scope);
        if (strstr(verificareTip(variabile[i].nume, variabile[i].scope), "int"))
        {
            fprintf(fp, "%d - ", atoi(variabile[i].valoare));
            // fprintf(fp, "%d - ", variabile[i].valoareInt);
        }
        else if (strstr(verificareTip(variabile[i].nume, variabile[i].scope), "float"))
        {
            fprintf(fp, "%f - ", atof(variabile[i].valoare));
            // fprintf(fp, "%f - ", variabile[i].valoareFloat);
        }
        else if (strstr(verificareTip(variabile[i].nume, variabile[i].scope), "string"))
        {
            fprintf(fp, "%s - ", variabile[i].valoare);
            // fprintf(fp, "%s - ", variabile[i].valoareString);
        }
        else if (strstr(verificareTip(variabile[i].nume, variabile[i].scope), "char"))
        {
            fprintf(fp, "%c - ", atoc(variabile[i].valoare));
            // fprintf(fp, "%c - ", variabile[i].valoareChar);
        }
        else if (strstr(verificareTip(variabile[i].nume, variabile[i].scope), "bool"))
        {
            if(strcmp(variabile[i].valoare, "0") == 0)
            {
                fprintf(fp, "%s - ", "false");
            }
            else if(strcmp(variabile[i].valoare, "1") == 0)
            {
                fprintf(fp, "%s - ", "true");
            }
            
            // fprintf(fp, "%c - ", variabile[i].valoareChar);
        }
        else
        {
            fprintf(fp, "0 - ");
        }
        fprintf(fp, "%d\n", variabile[i].isConst);
    }
    printf("Tabelul de simboluri a fost creat.\n");
    fclose(fp);
}

char *itoa(int number)
{
    char *buffer = (char *)malloc(30);
    snprintf(buffer, sizeof(buffer), "%d", number);
    return buffer;
}
char *ftoa(float number)
{
    size_t buffer_size = 60;
    char *buffer = (char *)malloc(60);
    snprintf(buffer, buffer_size, "%f", number);
    return buffer;
}
char *ctoa(char c)
{
    char *buffer = (char *)malloc(2);
    buffer[0] = c;
    buffer[1] = '\0';
    return buffer;
}

//             FUNCTII              //

void adauga_parametru(char *id, char *paramType, char *paramID)
{
    for (int i = 0; i < total_functii; i++)
    {
        if (functii[i].nume == id)
        {
            strcpy(functii[i].parametri[functii[i].nr_parametri].param_type, paramType);
            strcpy(functii[i].parametri[functii[i].nr_parametri].param_id, paramID);
            functii[i].nr_parametri++;
        }
    }
}

void declara_functie(char *data_type, char *id, int inclasa)
{
    for (int i = 0; i < total_functii; i++)
    {
        if (strcmp(functii[i].nume, id) == 0)
        {
            {
                printf("[Linia %d] Exista o functie cu acelasi nume deja declarata!\n", yylineno);
                exit(1);
            }
        }
    }
    functii[total_functii].nume = id;
    functii[total_functii].tip_date = data_type;
    functii[total_functii].nr_parametri = 0;
    functii[total_functii].inClasa = inclasa;
    char *p;
    p = strtok(lista_parametri, " ");
    while (p != NULL)
    {
        strcpy(functii[total_functii].parametri[functii[total_functii].nr_parametri].param_type, p);
        p = strtok(NULL, " ");
        for (int i = 0; i < functii[total_functii].nr_parametri; i++)
            if (strcmp(functii[total_functii].parametri[i].param_id, p) == 0)
            {
                printf("[Linia %d] Redeclararea unui parametru in antetul aceleasi functii nu este posibila!\n", yylineno);
                exit(1);
            }
        strcpy(functii[total_functii].parametri[functii[total_functii].nr_parametri].param_id, p);
        p = strtok(NULL, " ");
        functii[total_functii].nr_parametri++;
    }
    total_functii++;
}

int verificaClasa(char *id)
{
    for (int i = 0; i < total_clase; i++)
    {
        if (strcmp(clase[i].nume, id) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void afiseazaVariabileClasa()
{

    for (int i = 0; i < total_clase; i++)
    {
        for (int j = 0; j < clase[i].numar_variabile; j++)
        {
            printf("%s\n", clase[i].campuri[j].nume);
        }
    }
}

int verificaCamp_clasa(char *id_clasa, char *id_camp, char *tip)
{

    char *dataType;
    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id_clasa, variabile[i].nume) == 0)
        {
            dataType = variabile[i].tip_date;
            break;
        }
    }
    for (int i = 0; i < total_clase; i++)
    {
        if (strcmp(clase[i].nume, dataType) == 0)
        {
            for (int j = 0; j < clase[i].numar_variabile; j++)
            {
                if (strcmp(id_camp, clase[i].campuri[j].nume) == 0)
                {
                    if (strcmp(tip, clase[i].campuri[j].tip_date) == 0)
                        return 1;
                    else
                        return -1;
                }
            }
            return 0;
        }
    }
}

void declara_clasa(char *id, char *listaCampuri)
{
    if (verificaClasa(id) == 1)
    {
        printf("[Linia %d] Exista o clasa cu acelasi nume deja declarata!\n", yylineno);
        exit(1);
    }
    clase[total_clase].numar_variabile = 0;
    clase[total_clase].nume = id;
    char *p;
    char *tip;
    char *idCamp;
    char *valoare;
    tip = strtok(listaCampuri, " ");
    while (p)
    {
        if (tip == NULL)
            break;
        clase[total_clase].campuri[clase[total_clase].numar_variabile].tip_date = (char *)malloc(strlen(tip) + 1);
        strcpy(clase[total_clase].campuri[clase[total_clase].numar_variabile].tip_date, tip);
        idCamp = strtok(NULL, " ");
        for (int i = 0; i < clase[total_clase].numar_variabile; i++)
            if (strcmp(clase[total_clase].campuri[i].nume, idCamp) == 0)
            {
                printf("Redeclararea unui camp in aceeasi clasa nu este posibila, clasa %s!\n", clase[total_clase].nume);
                exit(1);
            }
        clase[total_clase].campuri[clase[total_clase].numar_variabile].nume = (char *)malloc(strlen(idCamp) + 1);
        strcpy(clase[total_clase].campuri[clase[total_clase].numar_variabile].nume, idCamp);

        valoare = strtok(NULL, " ");
        if (strcmp(valoare, "$") != 0)
        {
            clase[total_clase].campuri[clase[total_clase].numar_variabile].valoareString = (char *)malloc(strlen(valoare) + 1);
            strcpy(clase[total_clase].campuri[clase[total_clase].numar_variabile].valoareString, valoare);
        }
        tip = strtok(NULL, " ");
        clase[total_clase].numar_variabile++;
    }
    total_clase++;
}
void declara_vector(char *id, char *tip, int size, char *lista_elemente_vector, char *scope, int isConst, int isVector)
{
    for (int i = 0; i < total_variabile; i++)
        if (strcmp(variabile[i].nume, id) == 0)
        {
            printf("[Linia %d] Exista deja o variabila cu numele %s declarata!\n", yylineno, id);
            exit(1);
        }

    variabile[total_variabile].elemente = 0;
    variabile[total_variabile].nume = id;
    variabile[total_variabile].tip_date = tip;
    variabile[total_variabile].valoare = "0";
    variabile[total_variabile].isConst = isConst;
    variabile[total_variabile].isVect = isVector;
    variabile[total_variabile].scope = scope;
    variabile[total_variabile].lungime_vector = size;
    char *p, newString[256];
    strcpy(newString, lista_elemente_vector);
    p = strtok(newString, " ");
    while (p)
    {
        if (strcmp(p, tip) == 0)
        {
            p = strtok(NULL, " ");
            if (variabile[total_variabile].elemente < size)
            {
                strcpy(variabile[total_variabile].elemente_vector[variabile[total_variabile].elemente].param_id, p);
                variabile[total_variabile].elemente++;
            }
            else
            {
                printf("[Linia %d] Ati depasit spatiul alocat de memorie al vectorului, acesta are dimensiunea %d\n", yylineno, size);
                exit(1);
            }
        }
        else
        {
            printf("[Linia %d] Elementele dintr-un vector trebuie sa aibe acelasi tip ca acesta,in cazul de fata %s\n", yylineno, tip);
            exit(1);
        }
        p = strtok(NULL, " ");
    }

    total_variabile++;
}
void declara_matrice(char *id, char *tip, int linii, int coloane, char *lista_elemente_matrice, char *scope, int isConst, int isVector)
{
    for (int i = 0; i < total_variabile; i++)
        if (strcmp(variabile[i].nume, id) == 0)
        {
            printf("[Linia %d] Exista deja o variabila cu numele %s declarata!\n", yylineno, id);
            exit(1);
        }

    variabile[total_variabile].elemente = 0;
    variabile[total_variabile].nume = id;
    variabile[total_variabile].tip_date = tip;
    variabile[total_variabile].valoare = "0";
    variabile[total_variabile].isConst = isConst;
    variabile[total_variabile].isVect = isVector;
    variabile[total_variabile].scope = scope;
    variabile[total_variabile].linii = linii;
    variabile[total_variabile].coloane = coloane;
    int lines = 0, col = 0;
    char *p, newString[256];
    strcpy(newString, lista_elemente_matrice);
    p = strtok(newString, " ");
    while (p)
    {
        
        if (strcmp(p, tip) == 0)
        {   
            p = strtok(NULL, " ");
            strcpy(variabile[total_variabile].elemente_matrice[lines][col].param_id,p);
            col++;
            if(col>variabile[total_variabile].linii)
            {
                printf("[Linia %d] Ati declarat prea multe coloane, matricea %s poate avea maxim %d coloane!\n", yylineno,id,linii);
                exit(1);
            }
            
        }
        else if (strcmp(p, "int") != 0 && strcmp(p, "float") != 0 && strcmp(p, "char") != 0 && strcmp(p, "string") != 0)
        {
            col=0;
            lines++;
            if(lines>variabile[total_variabile].linii)
            {
                printf("[Linia %d] Ati declarat prea multe linii, matricea %s poate avea maxim %d linii!\n", yylineno,id,coloane);
                exit(1);
            }
        }
        else
        {
            printf("[Linia %d] Elementele dintr-o matrice trebuie sa aibe acelasi tip ca aceasta,in cazul de fata %s\n", yylineno, tip);
            exit(1);
        }
        p = strtok(NULL, " ");
    }
    total_variabile++;
}
void afisare_vector()
{
    for (int i = 0; i < total_variabile; i++)
        if (variabile[i].isVect == 1)
        {
            printf("vector = %s\n", variabile[i].nume);
            printf("elemente = %d\n", variabile[i].elemente);
            for (int j = 0; j < variabile[i].elemente; j++)
                printf("variabila = %s ", variabile[i].elemente_vector[j].param_id);
            printf("\n");
        }
}
void afisare_matrice()
{
    for (int i = 0; i < total_variabile; i++)
        {   
            
            if (variabile[i].isVect == 2)
        {
            printf("vector = %s\n", variabile[i].nume);
            printf("elemente = %d\n", variabile[i].elemente);
            for(int l=0; l < variabile[i].linii; l++)
            {for (int j = 0; j < variabile[i].coloane; j++)
                printf("variabila = %s ", variabile[i].elemente_matrice[l][j].param_id);
            printf("\n");
            }
        }
        }
}
int verificaDuplicat_functie(char *id)
{
    for (int i = 0; i < total_functii; i++)
    {
        if (strcmp(id, functii[i].nume) == 0)
            return 1;
    }
    return 0;
}

void afisare_functii()
{
    FILE *fp;
    fp = fopen("functions_table.txt", "w");
    fprintf(fp, "type  -  id  -  params\n\n");
    for (int i = 0; i < total_functii; i++)
    {
        fprintf(fp, "%s | ", functii[i].tip_date);
        fprintf(fp, "%s | ", functii[i].nume);
        for (int j = 0; j < functii[i].nr_parametri; j++)
        {
            fprintf(fp, "%s  ", functii[i].parametri[j].param_type);
            fprintf(fp, "%s  * ", functii[i].parametri[j].param_id);
        }
        fprintf(fp, "\n");
    }
    printf("Tabelul de functii a fost creat.\n");
    fclose(fp);
}
int verificareTipInt(char *valoare)
{
    int i;
    for (i = 0; i < strlen(valoare); i++)
    {
        if (!isdigit(valoare[i]) && valoare[i] != '.')
        {
            return -1;
        }
        if (valoare[i] == '.')
        {
            return 0;
        }
    }
    return 1;
}
char *determinareTip(char *valoare)
{
    int intRezultat = verificareTipInt(valoare);
    if (intRezultat == 1)
    {
        return "int";
    }
    else if (intRezultat == 0)
    {
        return "float";
    }

    if (strcmp(valoare, "char") == 0)
    {
        return "char";
    }

    if (strcmp(valoare, "string") == 0)
    {
        return "string";
    }

    return "unknown";
}
char* returnValStringChar(char* id)
{
    for (int i = 0; i < total_variabile; i++)
        if (strcmp(id, variabile[i].nume) == 0)
            return variabile[i].valoare;
}
char *returnValue(char *id, char *scope, int size1, int size2)
{

    for (int i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(scope, variabile[i].scope) == 0)
        {
            if (strcmp(variabile[i].tip_date, "char") == 0)
                return "char";
            else if (strcmp(variabile[i].tip_date, "string") == 0)
                return "string";
            else
            {
                if (variabile[i].isVect == 1)
                {
                    if (size1 >= variabile[i].lungime_vector)
                    {
                        printf("[Linia %d] Pozitia elementului pe care incercati sa-l accesati este in afara vectorului!\n", yylineno);exit(1);
                    }
                    else
                        return variabile[i].elemente_vector[size1].param_id;
                }
                if (variabile[i].isVect == 2)
                {
                    if (size1 >= variabile[i].linii || size2 >=variabile[i].coloane)
                    {
                        printf("[Linia %d] Pozitia elementului pe care incercati sa-l accesati este in afara matricii!\n", yylineno);exit(1);
                    }
                    else
                    {
                        return variabile[i].elemente_matrice[size1][size2].param_id;
                    }
                        
                }
                
            }
            return variabile[i].valoare;
        }
    }
    return NULL;
}
void parsaraAntetApel(char *lista_parametri_apel, int *numar_param)
{
    char *p, newString[256];
    int i = 0;
    strcpy(newString, lista_parametri_apel);
    p = strtok(newString, " ");
    while (p)
    {
        p = strtok(NULL, " ");
        i++;
    }
    *numar_param = i;
}
int getTipFunctie(char nume[256])
{
    for(int i=0;i<total_functii;i++)
        if(strcmp(functii[i].nume,nume)==0)
            {
                if(strcmp(functii[i].tip_date,"float")==0)
                    return 1;
                else if(strcmp(functii[i].tip_date,"int")==0)
                    return 2;
                else if(strcmp(functii[i].tip_date,"char")==0)
                    return 3;
                else if(strcmp(functii[i].tip_date,"string")==0)
                    return 4;
            }
}
int vericareAntetApelFunctie(char *id, char *lista_parametri_apel)
{
    int numar_paramApel = 0;
    for (int i = 0; i < total_functii; i++)
    {
        if (strcmp(functii[i].nume, id) == 0)
        {

            parsaraAntetApel(lista_parametri_apel, &numar_paramApel);
            if (functii[i].nr_parametri == numar_paramApel)
            {
                if (numar_paramApel == 0)
                    return 1;
                else
                {
                    char *p, newString[256];
                    int j = 0;
                    strcpy(newString, lista_parametri_apel);
                    p = strtok(newString, " ");
                    while (p)
                    {
                        if (strcmp(functii[i].parametri[j].param_type, p) != 0)
                        {
                            printf("[Linia %d] Valoarea parametrului %d din apel este diferita de cea din declaratia functiei %s\n", yylineno, j + 1, id);
                            exit(1);
                        }
                        p = strtok(NULL, " ");
                        j++;
                    }
                    return 1;
                }
            }
            else
            {
                printf("[Linia %d] Apelul functiei %s trebuie sa contina acelasi numar de parametri ca in declaratia acesteia!\n", yylineno, id);
                exit(1);
            }
            return 1;
        }
    }
    return 0;
}
char *valoareId(char *id)
{
    strcpy(id,id+1);
    id[strlen(id)-1]='\0';
    for (int i = 0; i < total_variabile; i++) {
        if (strcmp(variabile[i].nume, id) == 0) {
            char *val = (char *) malloc(strlen(variabile[i].valoare) + 1);
            strcpy(val, variabile[i].valoare);
            return val;
        }
    }
    return NULL;
}
char* valVarAst(char *id)
{
    for (int i = 0; i < total_variabile; i++) {
        if (strcmp(variabile[i].nume, id) == 0) {
            char *val = (char *) malloc(strlen(variabile[i].valoare) + 1);
            strcpy(val, variabile[i].valoare);
            return val;
        }
    }
    return NULL;
}
char *tipId(char *id)
{
    for (int i = 0; i < total_variabile; i++)
        if (strcmp(variabile[i].nume, id) == 0)
            return variabile[i].tip_date;
}
int verificareTipIntId(char *id, int scope)
{
    int i;
    char *stringScope;
    if (scope == 0)
        stringScope = "global";
    else if (scope == 1)
        stringScope = "main";
    for (i = 0; i < total_variabile; i++)
    {
        if (strcmp(id, variabile[i].nume) == 0 && strcmp(stringScope, variabile[i].scope) == 0)
        {
            if (strcmp(variabile[i].tip_date, "int") == 0)
                return 1;
            else if (strcmp(variabile[i].tip_date, "float") == 0)
                return 0;
            else
                return -1;
        }
    }
}
