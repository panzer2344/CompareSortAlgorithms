#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define size0 100000

long int sravn_b, obmen_b,
		 sravn_v, obmen_v,
		 sravn_p, obmen_p;

clock_t time_v_s, time_b_s,
		time_v_e, time_b_e,
		time_p_s, time_p_e;

int i, j;
int InitArray[size0];
int WorkArray[size0];
int IsGenerated = 0;
int IsSort = 0;

int LineSearch(int elem, int arr[], int len)
{
	for (i = 0; i < len; i++)
		if (elem == arr[i]) return i;
	return -1;
}

int BinarySearch(int elem, int arr[], int len)
{
	int l, r, m;
	l = 0; r = len;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == elem) return m;
		else if (elem > arr[m]) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

void Generate(int arr[], int len)
{
	if (!IsGenerated) IsGenerated = 1;
	IsSort = 0;

	for (i = 0; i < len; i++)
	{
		arr[i] = rand() % 100;
		//printf("WorkArray[%d] =  %d\n", i, WorkArray[i]);
	}
}

void Copy_array(int iarr[], int arr[], int len)
{
	for (i = 0; i < len; i++)
		arr[i] = iarr[i];
}

void Print(int arr[], int len)
{
	if (len > 40) return;
	printf("\n");
	for (i = 0; i < len; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}

void InsertSort(int arr[], int len)
{
	sravn_b = 0, obmen_b = 0,
	sravn_v = 0, obmen_v = 0,
	sravn_p = 0, obmen_p = 0;

	int a1, pos = 0;

	time_p_s = clock();
	for (i = 1; i < len; i++)
	{
		pos = -1;
		for (j = i - 1; j >= 0; j--)
		{
			sravn_p++;
			if (arr[i] > arr[j])
			{
				pos = j;
				break;
			}
		}
		a1 = arr[i];
		for (j = i - 1; j > pos; j--)
		{
			obmen_p++;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = a1;
	}
	time_p_e = clock();

	IsSort = 1;
}

void ChoiseSort(int arr[], int len)
{
	sravn_b = 0, obmen_b = 0,
	sravn_v = 0, obmen_v = 0,
	sravn_p = 0, obmen_p = 0;

	int a, min_pos, min = INT_MAX;
	time_v_s = clock();

	for (i = 0; i < len - 1; i++)
	{
		min = INT_MAX;
		for (j = i; j < len; j++)
		{
			sravn_v++;
			if (arr[j] < min)
			{
				min_pos = j;
				min = arr[j];
			}
		}
		obmen_v++;
		a = arr[i];
		arr[i] = min;
		arr[min_pos] = a;
	}
	time_v_e = clock();
	
	IsSort = 1;
}
void BubbleSort(int arr[], int len)
{
	sravn_b = 0, obmen_b = 0,
	sravn_v = 0, obmen_v = 0,
	sravn_p = 0, obmen_p = 0;

	int l, a;
	time_b_s = clock();
	//time2 = time(time);
	//time2 = (int)__TIME__;
	//time2 = (int)_getsystime;
	//time

	for (l = len; l > 0; l--)
	{
		for (i = 0; i < l - 1; i++)
		{
			sravn_b++;
			if (arr[i] > arr[i + 1])
			{
				obmen_b++;
				a = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = a;
			}
		}
	}
	
	time_b_e = clock();
	
	IsSort = 1;
}

void main()
{
	int b=-1;
	int elemForSearch;
	int searchResult = -1;
	int size;

	printf("\t **************************\n");
	printf("\t*\t\t\t   *\n");
	printf("\t* COMPARE SORT ALGORITHMS  *\n");
	printf("\t*\t\t\t   *\n");
	printf("\t *************************\n");

	printf("\tPrint size of array: ");
	scanf_s("%d", &size);

	printf("\n\tpress any button...");
	_getch();

	while(b)
	{
		system("cls");

		printf(" *************************\n");
		printf("* Bubble sort - 1\t *\n");
		printf("* Choose sort - 2\t *\n");
		printf("* Insert  sort - 3\t *\n");
		printf("* Compare algorithms - 4 *\n");
		printf("* Generate array - 5\t*\n");
		printf("* Line search - 6   \t*\n");
		printf("* Binary search - 7 \t*\n");
		printf("* Resize array - 8  \t*\n");
		printf("* Exit - 0\t\t *\n");
		printf(" ************************\n");
		printf("YOUR CHOISE: ");

		scanf_s("%d", &b);

		if (!IsGenerated) Generate(InitArray, size);

		switch (b)
		{
		case 1:
			Copy_array(InitArray, WorkArray, size);
			Print(WorkArray, size);

			BubbleSort(WorkArray, size);
			time_b_e -= time_b_s;

			Print(WorkArray, size);

			printf("BubbleSort: Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_b_e / CLOCKS_PER_SEC, obmen_b, sravn_b);
			printf("\nPress any button...\n");
			_getch();
			break;
		case 2:
			Copy_array(InitArray, WorkArray, size);
			Print(WorkArray, size);

			ChoiseSort(WorkArray, size);
			time_v_e -= time_v_s;

			Print(WorkArray, size);

			printf("Choose:  Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_v_e / CLOCKS_PER_SEC, obmen_v, sravn_v);
			printf("\nPress any button...\n");
			_getch();
			break;
		case 3:
			Copy_array(InitArray, WorkArray, size);
			Print(WorkArray, size);

			InsertSort(WorkArray, size);
			time_p_e -= time_p_s;

			Print(WorkArray, size);

			printf("Insert sort:  Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_p_e / CLOCKS_PER_SEC, obmen_p, sravn_p);
			printf("\nPress any button...\n");
			_getch();
			break;
		case 4:
			Print(WorkArray, size);

			Copy_array(InitArray, WorkArray, size);
			BubbleSort(WorkArray, size);
			time_b_e -= time_b_s;
			printf("BubbleSort: Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_b_e / CLOCKS_PER_SEC, obmen_b, sravn_b);
			Print(WorkArray, size);

			Copy_array(InitArray, WorkArray, size);
			ChoiseSort(WorkArray, size);
			time_v_e -= time_v_s;
			printf("Choose:  Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_v_e / CLOCKS_PER_SEC, obmen_v, sravn_v);
			Print(WorkArray, size);

			Copy_array(InitArray, WorkArray, size);
			InsertSort(WorkArray, size);
			time_p_e -= time_p_s;
			printf("Insert:  Time = %lf, Obmen = %ld, Sravn = %ld\n", (double)time_p_e / CLOCKS_PER_SEC, obmen_p, sravn_p);
			Print(WorkArray, size);

			printf("\nPress any button...\n");
			_getch();
			break;
		case 5:
			Generate(InitArray, size);
			break;
		case 6:
			Print(WorkArray, size);
			printf("\n\n\t\t Print elem which you want to find: ");
			scanf_s("%d", &elemForSearch);

			if ((searchResult = LineSearch(elemForSearch, WorkArray, size)) != -1)
				printf("\nElem: '%d' place in %d\n", elemForSearch, searchResult);
			else printf("Can't find\n");

			printf("\nPress any button...\n");
			_getch();
			break;
		case 7:
			if (!IsSort)
			{
				printf("Please, make sort\n");
				break;
			}

			Print(WorkArray, size);
			printf("\n\n\t\t Print elem which you want to find: ");
			scanf_s("%d", &elemForSearch);

			if ((searchResult = BinarySearch(elemForSearch, WorkArray, size)) != -1)
				printf("\nElem: '%d' place in %d\n", elemForSearch, searchResult);
			else printf("Can't find\n");

			printf("\nPress any button...\n");
			_getch();
			break;
		case 8:
			printf("\t\tPrint size of array: ");
			scanf_s("%d", &size);
		default:
			break;
		}
	}
	system("cls");
	printf("GOODBYE!!!\n");
	
}