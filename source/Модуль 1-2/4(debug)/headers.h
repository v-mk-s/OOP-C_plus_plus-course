void input(int size, double *p1, const char *vectorName); // ввод вектора
void output(int size, double *p1, const char *vectorName); // вывод вектора
double *sum(int size, double *p1, double *p2); // сумма векторов
double *dif(int size, double *p1, double *p2); // разность векторов
double innerproduct(int size, double *p1, double *p2); // скалярное произведение векторов
double length(int size, double *p1); // длина вектора
double vectorAngle(int size, double *p1, double *p2); // угол межу векторами
double *vectorProduct(int size, double *p1, double *p2); // векторное произведение
double areaParallelogram(int size, double *p1, double *p2); // площадь параллелограмма
void vectorDelete(int size, double **pp); // удаление динамических векторов с указателем на двумерный динамический массив
// удаление динамических векторов, n - количество указателей, указатели ...
void vectorDelete(int n, ...);