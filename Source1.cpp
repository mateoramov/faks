#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <malloc.h>
#define N 10000

/*struct _listNode;
struct _treeNode;

typedef struct _listNode * pos;
typedef struct _treeNode * node;

struct _listNode {
	int wordcounter;
	char firstletter;
	pos next;
	node tree;
};

struct _treeNode {
	char word[50];
	int wordscounter ;
	node left;
	node right;
};

void ReadFromFile(char*, pos);
void InsertLetterList(char, pos);
void InsertWordTree(char*, pos);
node InsertTree(char*, pos, node);
void PrintTree(node);
void PrintList(pos);

int main() {
	char filename[50] = "vjezba.txt";
	pos head=(pos)malloc(sizeof(struct _listNode));
	head->next = NULL;


	ReadFromFile(filename, head);
	head = head->next;
	while (head != NULL)
		PrintTree(head->tree);









	return 0;
}


void ReadFromFile(char* filename, pos L) 
{
	char rijec[50];
	FILE *fp=NULL;
	fopen_s(&fp, filename, "r+");
	if (fp == NULL)
		printf("datoteka u kurcu");
	else {
		while (!feof(fp)) {
			strset(rijec, NULL);
			fscanf_s(fp, "%s ", rijec,50);
			InsertLetterList(rijec[0], L);
			PrintList(L);
			InsertWordTree(rijec, L);
		}
	}
	fclose(fp);
}

void InsertLetterList(char c, pos L) 
{	
bool numba = true;
pos tmp = NULL;
pos prev=L;	
	if (L->next == NULL)
	{
			tmp = (pos)malloc(sizeof(struct _listNode));
			tmp->wordcounter = 0;
			tmp->tree = NULL;
			tmp->firstletter = c;
			tmp->next = L->next;
			L->next = tmp;
			numba = false;
	}
	
	while (L != NULL && numba ) {
		if (c > L->firstletter) {
			prev = L->next;;
			L = prev->next;
		}
		else if (c < L->firstletter){
			tmp = (pos)malloc(sizeof(struct _listNode));
			tmp->wordcounter = 0;
			tmp->tree = NULL;
			tmp->firstletter = c;
			tmp->next = prev->next;
			prev->next = tmp;
			numba = false;
		}
	
	}
}

void InsertWordTree(char* c, pos L) {
	pos tmp = L->next;
	while (tmp!=NULL&&tmp->firstletter != c[0])
		tmp = tmp->next;
	
	L->tree = InsertTree(c, L, tmp->tree);

}

node InsertTree(char* c, pos L, node T) {
	
	if (T == NULL) {
		T = (node)malloc(sizeof(struct _treeNode));
		strcpy(T->word, c);
		T->wordscounter = 1;
		T->left = NULL;
		T->right = NULL;
		L->wordcounter++;
	}
	else if (strcmp(c, T->word) < 0)
		T->left = InsertTree(c, L, T->left);
	else if (strcmp(c, T->word) > 0)
		T->right = InsertTree(c, L, T->right);
	else
		T->wordscounter++;

	return T;
}

void PrintTree(node T) {
	if(T != NULL) {
		PrintTree(T->left);
		printf("%s", T->word);
		PrintTree(T->right);
	}
}

void PrintList(pos P)
{
	if (P == NULL)
		printf("\r\nLista je prazna!\r\n");
	else
	{
		P = P->next;
		printf("\r\n\r\nU listi se nalaze : \r\n");
		while (P != NULL)
		{
			printf("\t%s %d\r\n", P->firstletter, P->wordcounter);
			P = P->next;
		}
	}
	printf("\r\n\r\n");
}
*/

/*
int *mystrstr(char*, char*);
int main() {
	char string1[50] = "abcdefgh";
	char string2[50] = "bcd";

	printf("%d",mystrstr(string1,string2));



	return 0;
}


int *mystrstr(char*s1, char*s2) {
	int i = 0;
	int j = 0;
	int br = 0;
	int brs2 = 0; 
	int k = 0;
	int *p=NULL;
	for (i; s2[i] != NULL;i++) {
		brs2++;
	}
	i = 0;
	for(i;s2[i]!=NULL;i++){	
		for (j=k; s1[j] != NULL; j++) {
			if (s2[i] != s1[j]) {
				k++;
				continue;
			}
			else {
				br++;
				k++;
				break;
			}
			

		}
	
	}
	if (brs2 == br) {
		*p = s1[k - brs2];
		return p;
	}
	else
		return 0;

}*/

/*struct student;
typedef struct student *pos;

struct student{
	char ime[50];
	char prezime[50];
	int bodovi;
};


int ReadNumStud(char*);
int ReadFromFile(char*, pos);

int main() {
	char filename[50];
	int brojstudenata = 0;
	int i = 0;
	int maxbrojbodova = 0;
	pos student = NULL;

	printf("upisite naziv datoteke iz koje ucitavate studente:");
	scanf_s("%s", filename, 50);
	brojstudenata = ReadNumStud(filename);
	student = (pos)malloc(brojstudenata * sizeof(struct student));
	maxbrojbodova = ReadFromFile(filename, student);
	printf("\n");
	for (i; i < brojstudenata; i++) {
		printf("%s %s %d %d %f", student[i].ime, student[i].prezime, student[i].bodovi, maxbrojbodova, (((float)student[i].bodovi / maxbrojbodova) * 100));
		printf("\n");
	}


	return 0;
}

int ReadNumStud(char *filename) {
	char buffer[256];
	int BR = 0;
	FILE*fp;
	fopen_s(&fp, filename, "r");
	if (!fp)
		printf("Datoteka nije otvorena");
	else {
		while (!feof(fp)) {
			memset(buffer,0, 256);
			fgets(buffer, 256, fp);
			if (strlen(buffer) != 0)
				BR++;
		}
		fclose(fp);
	}
	return BR;
}

int ReadFromFile(char* filename, pos P) {
	int maxbod = 0;
	FILE*fp;
	fopen_s(&fp, filename, "r");
	if (!fp)
		printf("datoteka nije otvorena");
	else {
		while (!feof(fp)) {
			fscanf_s(fp,"%s %s %d", P->ime, 50, P->prezime, 50, &P->bodovi);
			if (P->bodovi > maxbod)
				maxbod = P->bodovi;
			P++;
		}
		fclose(fp);
	}
	return maxbod;
}
*/

/*struct tocka;
struct poligon;
typedef struct tocka *pok;
typedef struct poligon *poli;

struct tocka {
	int x;
	int y;
};

struct poligon {
	int broj;
	pok niz;
};

poligon* novi_poligon(int *niz_x, int *niz_y, int n);
int RNG(int min, int max);

int main() {
	int n=0;
	int *niz1;
	int *niz2;
	int i = 0;
	poli poligon;
	printf("upisi duljinu niza:");
	scanf_s("%d", &n);
	niz1 = (int*)malloc(sizeof(int)*n);
	niz2 = (int*)malloc(sizeof(int)*n);
	for (i; i < n; i++) {
		niz1[i] = RNG(10, 100);
		niz2[i] = RNG(10, 100);
	}

	poligon = novi_poligon(niz1, niz2, n);
	i = 0;
	printf("\nparovi brojeva u poligonu su:\n");
	for (i; i < n; i++) {
		printf("%d", poligon->niz[i].x);
		printf("\t%d\n", poligon->niz[i].y);
	}

	return 0;
}

poligon* novi_poligon(int *niz_x, int *niz_y, int n) {
	poli P;
	P = (poli)malloc(sizeof(struct poligon));
	P->niz = (pok)malloc(sizeof(struct tocka)*n);
	int i = 0;
	for (i; i < n; i++) {
		P->niz[i].x = niz_x[i];
		P->niz[i].y = niz_y[i];
	}
	return P;
}

int RNG(int min, int max) {
	return rand() % (max - min) + min;
}
*/

/*struct student;
typedef struct student *pok;
struct student {
	char ime[128];
	char prezime[128];
	int bodovi;
};

int citaj(char*);
int zapisi(char*, pok);


int main() {
	pok studenti;
	char filename[128];
	int brojstudenata = 0;
	int maxbod = 0;
	int i = 0;
	printf("upisi ime datoteke;");
	scanf_s("%s", filename, 128);
	brojstudenata = citaj(filename);
	studenti = (pok)malloc(sizeof(struct student)*brojstudenata);
	maxbod = zapisi(filename, studenti);
	printf("\nstudenti u vasoj datoteci su:\n");
	for (i; i < brojstudenata; i++) {
		printf("%s %s %d %d %f\n", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, maxbod, (((float)studenti[i].bodovi / maxbod) * 100));
		
	}






	return 0;
}

int citaj(char*filename) {
	FILE *fp;
	char buffer[256];
	int brojac = 0;
	fopen_s(&fp,filename, "r");
	if (fp==NULL)
		printf("datoteka nije otvorena");
	else {
		while (!feof(fp)) {
			memset(buffer, 0, 256);
			fgets(buffer, 256, fp);
			if (strlen(buffer) != 0)
				brojac++;
		}
		fclose(fp);
	}
	return brojac;
}

int zapisi(char*filename, pok P) {
	FILE*fp=NULL;
	int maxbodovi = 0;
	fopen_s(&fp, filename, "r");
	if (!fp)
		printf("datoteka nije otvorena");
	else {
		while (!feof(fp)) {
			fscanf_s(fp, "%s %s %d", P->ime, 128, P->prezime, 128, &P->bodovi);
			if (P->bodovi > maxbodovi)
				maxbodovi = P->bodovi;
			P++;
		}
		fclose(fp);
	}
	return maxbodovi;
}

*/

/*
typedef struct rijecnik;
typedef struct rijecnik* pok;
struct rijecnik {
	char *rijec;
	int br;
	pok next;
};

void lista(pok, char*);
void PrintList(pok);
void ReturnFromFile(char*, pok);

int main() {
	/*
	//The C library function double atof(const char *str) converts the string argument str to a floating-point number (type double).
	char str[20];
	double var;

	strcpy(str, "914567999");
	var = atof(str);
	printf("%f", var);

	strcpy(str, "nekosmece");
	var = atof(str);
	printf("\n%f", var);
	

	/*
	//The C library function int atoi(const char *str) converts the string argument str to an integer(type int).
	char str[20];
	int var;

	strcpy(str, "0989964");
	var = atoi(str);
	printf("%d", var);

	strcpy(str, "nekosmece");
	var = atoi(str);
	printf("\n%d", var);
	

	/*
	//The C library function double strtod(const char *str, char **endptr) converts the string pointed to by the argument 
	//str to a floating-point number (type double). If endptr is not NULL, a pointer to the character after the last character 
	//used in the conversion is stored in the location referenced by endptr.
	double var;
	char str[50];
	char *ptr;

	strcpy(str, "9797878 fuck off");
	var = strtod(str, &ptr);
	printf("number part of a string is: %f, string is %s\n", var, ptr);
	
	char filename[50] = "studenti.txt";
	pok rijecnik;
	rijecnik = (pok)malloc(sizeof(struct rijecnik));
	rijecnik->next = NULL;
	ReturnFromFile(filename, rijecnik);


	return 0;
}

void ReturnFromFile(char*filename, pok P) {
	char buffer[50];
	FILE *fp;
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
		printf("datoteka nije otvorena");
	else {
		while (!feof(fp)) {
			strset(buffer, NULL);
			fscanf_s(fp, "%c", buffer, 50);
			lista(P, buffer);

			}
		}
	PrintList(P->next);
	}

void lista(pok P,char *buffer) {
	pok q;
	while (P != NULL) {
		if (P->next == NULL) {
			q = (pok)malloc(sizeof(struct rijecnik));
			q->rijec = (char*)malloc(50 * sizeof(char));
			q->rijec = buffer;
			q->br = 1;
			q->next = P->next;
			P->next = q;
			P = P->next;
			break;
		}
		else if (strcmp(buffer, P->next->rijec) < 0) {
			q = (pok)malloc(sizeof(struct rijecnik));
			q->rijec = (char*)malloc(50 * sizeof(char));
			q->rijec = buffer;
			q->br = 1;
			q->next = P->next;
			P->next = q;
			P = P->next;
			break;

		}
		else if (strcmp(buffer, P->next->rijec) == 0) {
			P->next->br++;
			P = P->next;
			break;
		}
		else 
			P = P->next;
	}

}

void PrintList(pok P) {
	while (P != NULL) {
		printf("%s %d", P->rijec, P->br);
		P = P->next;
	}

}

*/

/*
typedef struct
{
	void *p;
	int prioritet;
}clan;
typedef struct
{
	clan *niz;
	int br;
}gomila;
gomila *create()
{
	gomila *niz = (gomila*)malloc(N * sizeof(gomila));
	niz->niz = (clan*)malloc(N * sizeof(clan));
	//niz->niz->prioritet = (int*)malloc(N * sizeof(int));
	return niz;
}
void obrisi(gomila *s)
{
	free(s->niz);
	free(s);
}
void popravi_prema_vrhu(gomila *s, int n, int br2)
{
	if (s->br == 0 || s->br-br2==0)
		exit;
	else {
		int r = s->niz[(s->br-1-br2) ].prioritet;
		if (r < n)
		{
			int temp = s->niz[(s->br - 1-br2)].prioritet;
			s->niz[(s->br - 1-br2)] = s->niz[s->br-br2];
			s->niz[s->br-br2].prioritet = temp;
			br2++;
			popravi_prema_vrhu(s, s->niz[(s->br-br2)].prioritet,br2);
		}
	}
}
/*void popravi_prema_vrhu2(gomila *s, int n, int br2)
{
	if (s->br-1 == 0 || s->br-1 - br2 == 0)
		exit;
	else {
		int r = s->niz[((s->br - 1) / 2) - br2].prioritet;
		if (r < n)
		{
			int temp = s->niz[((s->br - 1) / 2) - br2].prioritet;
			s->niz[((s->br - 1 )/2 )- br2] = s->niz[s->br - 1 - br2];
			s->niz[s->br - 1 - br2].prioritet = temp;
			br2++;
			popravi_prema_vrhu2(s, s->niz[(s->br - 1 - br2)].prioritet, br2);
		}
	}
}
void dodaj(gomila *s, int element)
{
	int br2 = 0;
	s->niz[s->br].prioritet = element;
	popravi_prema_vrhu(s, s->niz[s->br].prioritet,br2);
	s->br++;
}
void main()
{
	gomila *arr = create();
	arr->br = 0;
	dodaj(arr, 5);
	dodaj(arr, 13);
	dodaj(arr, 44);
	dodaj(arr, 1);
	dodaj(arr, 69);
	dodaj(arr, 199);
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", arr->niz[i].prioritet);
	}
}
*/


int i = 2;
void fun(int j) {
	static int i = 5;
	printf("%2d%2d", i++, j);
}

int fun(int *x, int i) {
	int r;
	r = *x + i / 2 + *(x + i / 2);
	return r;
}
int main(void) {
	int x = 2;
	int y = 4;
	int z = 10;
	if (x < 3 && (y >= 5 || z == 15)) {
		printf("C program");
	}
	return 0;
}