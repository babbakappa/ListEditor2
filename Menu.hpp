#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>

std::string colors = "0 - черный\n1 - синий\n2 - зеленый\n3 - голубой\n4 - красный\n5 - лиловый\n6 - желтый\n7 - белый\n8 - серый\n9 - светло-синий\nA - светло-зеленый\nB - светло-голубой\nC - светло-красный\nD - светло-лиловый\nE - светло-желтый\nF - ярко-белый\n";

//Устанавливает русскую кодировку (cp1251 Windows)
void SetRussianEncode() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

//Установка всех настроек
void SetColorsFromFile() {
	std::ifstream fin("settings.txt");
	if (fin.is_open() == false) {
		std::cout << "Файла настроек не существует!\n";
		return;
	}

	char first_p, second_p;
	fin >> first_p >> second_p;
	char final_comm[9] = "color   ";
	final_comm[6] = first_p;
	final_comm[7] = second_p;

	system(final_comm);
}

//Взятие массива из ввода с клавиатуры
template <class AnyType>
void TakeArrayFromInput(std::vector<AnyType>& arr) {
	int size;
	std::cout << "Введите размер списка: ";
	std::cin >> size;
	std::cin.ignore();

	if (size < 0) {
		std::cout << "Ошибка!\n";
		std::cin.get();
		return;
	}
	else if (size == 0) {
		std::cout << "Список пуст!\n";
		std::cin.get();
		return;
	}

	std::cout << "\nВводите элементы:\n";
	for (int i = 0; i < size; i++) {
		AnyType temp;
		if (std::cin >> temp) {
			arr.push_back(temp);
		} 
		else {
			std::cout << "Ошибка!\n";
		}
		
	}
}

//Взятие массива из файла
template <class AnyType>
void TakeArrayFromFile(std::vector<AnyType>& arr) {
	std::cout << "Введите ссылку на файл: ";
	std::string filepath;
	std::getline(std::cin, filepath);

	std::ifstream fin(filepath);
	AnyType temp;
	while (fin >> temp) {
		arr.push_back(temp);
	}

	fin.close();
}

//Вывод любового массива на экран
template <class AnyType>
void PrintAnyArray(std::vector<AnyType> arr) {
	system("cls");
	std::cout << "Список:\n";
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << "\n";
	}
	system("pause");
	system("cls");
}

//Вывод меню на экран
void PrintMenu(std::string& ch) {
	std::cout << "1.Удалить дубликаты из списка\n";
	std::cout << "2.Объединить два списка без дубликатов\n";
	std::cout << "3.Реверснуть список\n";
	std::cout << "4.Сортировать слова\n";
	std::cout << "5.Сортировать числа\n";
	std::cout << "6.Выбрать рандомный элемент из списка\n\n";
	std::cout << "0.Выход\n\n";
	std::cout << "-1.Изменить цвет текста или фона\n";
	std::cout << "-2.О программе\n\n";
	std::cout << "Выбор: ";
	std::cin >> ch;
	std::cin.ignore();
}

//Запрос откуда взять массив
void AskWhereToTake(std::string& chc) {
	system("cls");
	std::cout << "Откуда взять список?\n\n";
	std::cout << "1.Введу сам\n";
	std::cout << "2.Из файла\n";
	std::cout << "Выбор: ";
	std::cin >> chc;
	std::cin.ignore();
	system("cls");
}

//Запрос куда вывести массив
void AskWhereToPut(std::string& chc) {
	system("cls");
	std::cout << "Куда вывести список?\n\n";
	std::cout << "1.На экран\n";
	std::cout << "2.В файл\n";
	std::cout << "Выбор: ";
	std::cin >> chc;
	std::cin.ignore();
	system("cls");
}

//Вывод заголовка
void PrintHead() {
	std::cout << "#      #  #### #####   ##### ####  # #####  ###  #### \n";
	std::cout << "#      # #       #     #     #   # #   #   #   # #   #\n";
	std::cout << "#      #  ###    #     ##### #   # #   #   #   # #### \n";
	std::cout << "#      #     #   #     #     #   # #   #   #   # #  # \n";
	std::cout << "#####  # ####    #     ##### ####  #   #    ###  #   #\n";
	std::cout << "\n\n\n";
}

//Установка цветов с ввода с клавиатуры
void SetColorsFromInput() {
	system("cls");
	std::cout << "Что хотите поменять?\n\n";
	std::cout << "1.Цвет текста\n";
	std::cout << "2.Цвет фона\n";
	std::cout << "Выбор: ";
	char ch;
	char t = '0';
	char b = '0';
	std::cin >> ch;
	system("cls");
	std::cout << colors << "\n";
	std::cout << "Выбор: ";
	if (ch == '2') {
		std::cin >> t;
	}
	else if (ch == '1') {
		std::cin >> b;
	}
	else {
		std::cout << "Ошибка!\n";
		system("pause");
		return;
	}
	char final_comm[9] = "color   ";
	final_comm[6] = t;
	final_comm[7] = b;

	system(final_comm);
	system("cls");
	std::cout << "Изменения применены\n";
	system("pause");
	system("cls");

	std::ofstream fout("settings.txt");
	fout << t << "\n" << b;
	fout.close();
}

//Сохранить любой массив в файл
template <class AnyType>
void SaveAnyArrayToFile(std::vector<AnyType> arr) {
	std::cout << "Введите ссылку на файл: ";
	std::string filepath;
	std::getline(std::cin, filepath);

	std::ofstream fout(filepath);
	for (auto p : arr) {
		fout << p << "\n";
	}

	fout.close();
}

void PrintError(int code) {
	system("cls");
	if (code == 1) {
		std::cout << "Введен неверный вариант!\n";
	}
	system("pause");
	system("cls");
}