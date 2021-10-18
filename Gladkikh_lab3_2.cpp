#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef bool (*sort_criteria) (int, int); 

void array_output(int* mas, int size) {	
	cout << "Массив размером " << size << ":\n";
	for (int i = 0; i < size; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}

void array_input(int* mas, int size) {	
	cout << "введите элементы массива в строчку через пробел:\n";
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
	}
}

int sum_chet(int param) {
	int sum = 0;
	bool chet = false;
	while (param != 0) {	
		if (chet) sum += param % 10;	
		chet = !chet;					
		param /= 10;
	}
	return sum;
}

bool criteria_chet(int param1, int param2) {
	return sum_chet(param1) > sum_chet(param2); 
}

void sort(int* mas, int size, sort_criteria func) { 
	int temp;										
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (func(mas[j], mas[j + 1])) {
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
}

bool sort_last(int param1, int param2) {
	if (param1 % 10 > param2 % 10) return true;
	else if (param1 % 10 == param2 % 10) return param1 < param2;
	else return false;
}

int* create(int& size) {
	while (true) {
		cout << "Введите размер массива: ";
		cin >> size;
		if (size > 0 && size <= 1000) break;
		else cout << "Ошибка. Повторите ввод. n должно быть больше 0 и меньше 1000\n";
	}
	int* mas = new int[size];
	return mas;
}

void free(int* mas) {
	delete[] mas;
}

int main(int argc, char** argv) {
	system("chcp 65001 > nul");
	int n = 0;
	int* mas = NULL;
	char option;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Ввод матрицы\n"
			<< "2. Вывод матрицы\n"
			<< "3. Сортировка по сумме цифр, стоящих на четных местах\n"
			<< "4. Отсортировать массив вначале по возрастанию последней цифры,\n   а при совпадении последних цифр - по убыванию\n"
			<< "5. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case '1':
			mas = create(n);
			array_input(mas, n);
			break;
		case '2':
			if (n != 0) array_output(mas, n);
			break;
		case '3':
			sort(mas, n, criteria_chet);
			array_output(mas, n);
			break;
		case '4':
			sort(mas, n, sort_last);
			break;
		case '5':
			if (n != 0) free(mas);
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}