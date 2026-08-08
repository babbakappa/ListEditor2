#include "Menu.hpp"
#include "Methods.hpp"
#include <iostream>

int main() {
	SetRussianEncode();
	SetColorsFromFile();
	
	std::string mainchoice, subchoice, subchoice2;

	do {
		std::vector<std::string> StringArr1;
		std::vector<std::string> StringArr2;
		std::vector<double> DoubleArr;

		std::vector<std::string> StringResultArr;
		std::vector<double> DoubleResultArr;
		std::string OneResult;

		PrintHead();
		PrintMenu(mainchoice);

		if (IfOptionExistsInMain(mainchoice) == false) {
			PrintError(ERR_INCORRECT_OPTION);
			continue;
		}

		//Блок обработки запросов -1, -2 и 0

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

		//Выход из программы
		else if (mainchoice == "0") {
			break;
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
				PrintError(ERR_INCORRECT_OPTION);
				continue;
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
				PrintError(ERR_INCORRECT_OPTION);
				continue;
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
				PrintError(ERR_INCORRECT_OPTION);
				continue;
			}
		}
		
		
		//Проверка неудач
		
		//Для чисел
		if (mainchoice == "5") {
			if (DoubleArr.empty()) {
				continue;
			}
		}

		//Для двух массивов
		else if (mainchoice == "2") {
			if (StringArr1.empty() || StringArr2.empty()) {
				continue;
			}
		}

		//Для одного массива
		else {
			if (StringArr1.empty()) {
				continue;
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

		//Сортировка слов

		else if (mainchoice == "4") {
			bool bullshit = false;
			AskBTSOrSTB(bullshit);
			StringResultArr = SortNumbersOrWords(StringArr1, bullshit);
		}

		//Сортировка чисел
		else if (mainchoice == "5") {
			bool bullshit = false;
			AskBTSOrSTB(bullshit);
			DoubleResultArr = SortNumbersOrWords(DoubleArr, bullshit);
		}

		//Выбор рандома из массива
		else if (mainchoice == "6") {
			OneResult = PickRandomFromArray(StringArr1);
		}

		//Блок вывода массива
		
		//Для чисел
		if (mainchoice == "5") {
			AskWhereToPut(subchoice2);
			if (subchoice2 == "1") {
				PrintAnyArray(DoubleResultArr);
			}
			else if (subchoice2 == "2") {
				SaveAnyArrayToFile(DoubleResultArr);
			}
			else {
				PrintError(ERR_INCORRECT_OPTION);
			}
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
			AskWhereToPut(subchoice2);
			if (subchoice2 == "1") {
				PrintAnyArray(StringResultArr);
			}
			else if (subchoice2 == "2") {
				SaveAnyArrayToFile(StringResultArr);
			}
			else {
				PrintError(ERR_INCORRECT_OPTION);
			}
		}

	} while (mainchoice != "0");
	system("cls");
	std::cout << "Завершение работы...\n";
}