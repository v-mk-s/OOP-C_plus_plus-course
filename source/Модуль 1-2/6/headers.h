int **create(int *m, int *n); // создание матрицы
void input(int m, int n, int **pp); // ввод матрицы
void output(int m, int n, int **pp); // вывод матрицы
void delete2(int m, int **pp); // удаление матрицы
void deleteStr(int *m, int *n, int **pp); // удаление строки
void deleteCol(int *m, int *n, int **pp); // удаление столбца
// переписать delete2 проверка в аутпуте на null если 1x1