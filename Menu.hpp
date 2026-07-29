#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#define ERR_INCORRECT_OPTION 1
#define ERR_FILE_DOES_NOT_EXIST 2
#define ERR_INCORRECT_SIZE 3
#define ERR_INCORRECT_TYPE 4

std::string colors = "0 - черный\n1 - синий\n2 - зеленый\n3 - голубой\n4 - красный\n5 - лиловый\n6 - желтый\n7 - белый\n8 - серый\n9 - светло-синий\nA - светло-зеленый\nB - светло-голубой\nC - светло-красный\nD - светло-лиловый\nE - светло-желтый\nF - ярко-белый\n";

void PrintError(int code) {
	system("cls");
	if (code == ERR_INCORRECT_OPTION) {
		std::cout << "Введен неверный вариант!\n";
	}
	else if (code == ERR_FILE_DOES_NOT_EXIST) {
		std::cout << "Не существует такого файла!\n";
	}
	else if (code == ERR_INCORRECT_SIZE) {
		std::cout << "Неверный размер массива!\n";
	}
	else if (code == ERR_INCORRECT_TYPE) {
		std::cout << "Неверный тип данных!\n";
	}
	system("pause");
	system("cls");
}

//Устанавливает русскую кодировку (cp1251 Windows)
void SetRussianEncode() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

//Установка всех настроек
void SetColorsFromFile() {
	std::ifstream fin("settings.txt");
	if (fin.is_open() == false) {
		PrintError(ERR_FILE_DOES_NOT_EXIST);
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

	if (size < 0 || size == 0) {
		PrintError(ERR_INCORRECT_SIZE);
		return;
	}

	std::cout << "Вводите элементы:\n";
	for (int i = 0; i < size; i++) {
		AnyType temp;
		if (std::cin >> temp) {
			arr.push_back(temp);
		} 
		else {
			PrintError(ERR_INCORRECT_TYPE);
			return;
		}
		
	}
	std::cin.ignore();
}

//Взятие массива из файла
template <class AnyType>
void TakeArrayFromFile(std::vector<AnyType>& arr) {
	std::cout << "Введите ссылку на файл: ";
	std::string filepath;
	std::getline(std::cin, filepath);

	std::ifstream fin(filepath);
	if (fin.is_open() == false) {
		PrintError(ERR_FILE_DOES_NOT_EXIST);
		return;
	}
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
		PrintError(ERR_INCORRECT_OPTION);
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

void AskBTSOrSTB(bool& a) {
	std::string b;
	system("cls");
	std::cout << "Отсортировать от большего к меньшему или наоборот?\n";
	std::cout << "1.От большего к меньшему\n";
	std::cout << "2.От меньшего к большему\n";
	std::getline(std::cin, b);
	if (b == "1") {
		a = true;
	}
	else if (b == "2") {
		a = false;
	}
	else {
		PrintError(ERR_INCORRECT_OPTION);
	}
}