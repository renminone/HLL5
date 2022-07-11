#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus"); //Включение локализации.
	FILE* fpin = NULL;
	fopen_s(&fpin, "h5.txt", "w");

	int s;
	printf("Введите количество строк: "); //Определение количества строк
	scanf_s("%d", &s);
	int* data = malloc(s * sizeof(int)); //Резервация места в памяти для динамического массива.

	size_t i;
	for (i = 0; i < s; i++) //Ввод эдементов массива.
		scanf_s("%d", &data[i]);

	int* ptr = data;
	for (i = 0; i < s; i++, ptr++)
	{
		if (!(*ptr < 0))
		{
			char line[5];
			_itoa_s(*ptr, line, 5, 10);
			static int q = 0;
			for (size_t i = 0; i < *ptr; i++)
			{
				fprintf(fpin, "%c", line[q]);
				q++;
				if (line[q] == '\0')
					q = 0;
			}
			fprintf(fpin, "\n");
		}
		else
			fprintf(fpin, "\n");
	}

	fclose(fpin);
	free(data);

	system("pause > nul");
	return 0;
}
