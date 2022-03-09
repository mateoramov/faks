
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>




void Merge(int A[], int p, int q, int r)
{
	int k = 0;
	int j = 0;
	int i = 0;

	int *B = (int*)malloc(r * sizeof(int));

	i = k = p;
	j = q + 1;

	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= q)
		B[k++] = A[i++];
	while (j <= r)
		B[k++] = A[j++];

	for (i = p; i <= r; i++)
		A[i] = B[i];
}


void MergeSort(int A[], int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}



void BubbleSort(int size, int A[])
{
	int i, j, temp;
	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (A[i] > A[j]) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}


int main()
{

	FILE  *file1, *file2;
	char c;
	int vrijeme1, vrijeme2, i, size;

	srand((unsigned)time(NULL));//vezivanje rand generatora sa sistemskim vremennom

	printf("Unesi velicinu niza\n");
	scanf("%d", &size);


	//generiranje niza
	int *A = (int*)malloc(size * sizeof(int));
	for (i = 0; i<size; i++)
		A[i] = rand();


	vrijeme1 = GetTickCount();
	BubbleSort(size, A);
	vrijeme2 = GetTickCount();
	printf("Vrijeme izvrsavanja bubble sorta je:%d\n", vrijeme2 - vrijeme1);

	//ispis rezultata u file
	file1 = fopen("OutputBubble.txt", "w");
	for (i = 0; i<size; i = i++)
		fprintf(file1, "%d\n", A[i]);
	fclose(file1);

	//ponovo generiramo niz random brojeva
	for (i = 0; i<size; i++)
		A[i] = rand();


	vrijeme1 = GetTickCount();
	MergeSort(A, 0, size-1);
	vrijeme2 = GetTickCount();
	printf("Vrijeme izvrsavanja merge sorta je:%d\n", vrijeme2 - vrijeme1);
	//ispis rezultata u file
	file2 = fopen("OutputMerge.txt", "w");
	for (i = 0; i<size; i = i++)
		fprintf(file2, "%d\n", A[i]);
	fclose(file2);

	free(A);
	return 0;

}


