#include "Menu.hpp"
#include "Methods.hpp"
#include <iostream>

int main() {
	SetColorsFromFile();
	SetRussianEncode();
	
	std::string mainchoice, subchoice, underchoice;

	do {
		std::vector<std::string> StringArr1;
		std::vector<std::string> StringArr2;
		std::vector<double> DoubleArr;

		std::vector<std::string> StringResultArr;
		std::vector<double> DoubleResultArr;
		std::string OneResult;

		PrintHead();
		PrintMenu(mainchoice);


		//Блок обработки запросов -1 и -2

		//Изменение цветов
		if (mainchoice == "-1") {
			SetColorsFromInput();
			continue;
		}

		//Информация о программе
		else if (mainchoice == "-2") {
			system("cls");
			std::cout << "Пока ничего нет...:)\n";
			system("pause");
			system("cls");
			continue;
		}


		//Блок взятия массива
		
		//Для чисел
		if (mainchoice == "5") {
			AskWhereToTake(subchoice);
			if (subchoice == "1") {
				TakeArrayFromInput(DoubleArr);
			}
			else if (subchoice == "2") {
				TakeArrayFromFile(DoubleArr);
			}
			else {
				PrintError(1);
			}
		}
		
		//Для двух массивов
		else if (mainchoice == "2") {
			AskWhereToTake(subchoice);
			if (subchoice == "1") {
				TakeArrayFromInput(StringArr1);
				TakeArrayFromInput(StringArr2);
			}
			else if (subchoice == "2") {
				TakeArrayFromFile(StringArr1);
				TakeArrayFromFile(StringArr2);
			}
			else {
				PrintError(1);
			}
		}

		//Для одного массива
		else {
			AskWhereToTake(subchoice);
			if (subchoice == "1") {
				TakeArrayFromInput(StringArr1);
			}
			else if (subchoice == "2") {
				TakeArrayFromFile(StringArr1);
			}
			else {
				PrintError(1);
			}
		}

		
		//Блок обработки массивов

		//Удаление дубликатов из массива
		if (mainchoice == "1") {
			StringResultArr = DeleteDuplicatesInArray(StringArr1);
		}

		//Объединение двух массивов
		else if (mainchoice == "2") {
			StringResultArr = UniteWithoutDuplicates(StringArr1, StringArr2);
		}

		//Реверс массива
		else if (mainchoice == "3") {
			StringResultArr = InverseArray(StringArr1);
		}

		//Сортировка чисел
		else if (mainchoice == "4") {
			bool bullshit;
			AskBTSOrSTB(bullshit);
			if (bullshit == true || bullshit == false) {
				DoubleResultArr = SortNumbersOrWords(DoubleArr, bullshit);
			}
			else {
				continue;
			}
		}

		//Сортировка слов
		else if (mainchoice == "5") {
			bool bullshit;
			AskBTSOrSTB(bullshit);
			if (bullshit == true || bullshit == false) {
				StringResultArr = SortNumbersOrWords(StringArr1, bullshit);
			}
			else {
				continue;
			}
		}

		//Выбор рандома из массива
		else if (mainchoice == "6") {
			OneResult = PickRandomFromArray(StringArr1);
		}

		//Обработка ошибки ввода
		else {
			if (mainchoice != "0") {
				PrintError(1);
			}
		}


		//Очистка массивов заранее для оптимизации
		DoubleArr.clear();
		StringArr1.clear();
		StringArr2.clear();


		//Блок вывода массива
		
		//Для чисел
		if (mainchoice == "5") {
			PrintAnyArray(DoubleResultArr);
		}

		//Для одного результата
		else if (mainchoice == "6") {
			system("cls");
			std::cout << OneResult << "\n";
			system("pause");
			system("cls");
		}

		//Для всего остального
		else {
			PrintAnyArray(StringResultArr);
		}

	} while (mainchoice != "0");
	system("cls");
	std::cout << "Завершение работы...\n";
}