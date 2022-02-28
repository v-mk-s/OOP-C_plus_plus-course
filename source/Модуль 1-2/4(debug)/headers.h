void input(int size, double *p1, const char *vectorName); // ���� �������
void output(int size, double *p1, const char *vectorName); // ����� �������
double *sum(int size, double *p1, double *p2); // ����� ��������
double *dif(int size, double *p1, double *p2); // �������� ��������
double innerproduct(int size, double *p1, double *p2); // ��������� ������������ ��������
double length(int size, double *p1); // ����� �������
double vectorAngle(int size, double *p1, double *p2); // ���� ���� ���������
double *vectorProduct(int size, double *p1, double *p2); // ��������� ������������
double areaParallelogram(int size, double *p1, double *p2); // ������� ���������������
void vectorDelete(int size, double **pp); // �������� ������������ �������� � ���������� �� ��������� ������������ ������
// �������� ������������ ��������, n - ���������� ����������, ��������� ...
void vectorDelete(int n, ...);