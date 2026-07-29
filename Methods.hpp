#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <random>

template <class AnyType>
std::vector<AnyType> InverseArray(std::vector<AnyType>& arr) {
	reverse(arr.begin(), arr.end());
	return arr;
}

template <class AnyType>
std::vector<AnyType> DeleteDuplicatesInArray(std::vector<AnyType>& arr) {
	std::unordered_set<AnyType> seen;
	seen.reserve(arr.size());
	auto new_end = std::remove_if(arr.begin(), arr.end(), [&seen](const AnyType& str) {
		return !seen.insert(str).second;
		});
	arr.erase(new_end, arr.end());
	return arr;
}

template <class AnyType>
std::vector<AnyType> SortNumbersOrWords(std::vector<AnyType>& arr, bool small_to_big) {
	if (small_to_big) {
		sort(arr.begin(), arr.end(), [](AnyType a, AnyType b) { return a < b; });
		return arr;
	}
	else {
		sort(arr.begin(), arr.end(), [](AnyType a, AnyType b) { return a > b; });
		return arr;
	}
}

template <class AnyType>
AnyType PickRandomFromArray(std::vector<AnyType>& arr) {
	static std::random_device my_device;
	static std::mt19937 gen(my_device());
	static std::uniform_int_distribution<int> borders(0, arr.size() - 1);
	int rand_number = borders(gen);
	return arr[rand_number];
}

template <class AnyType>
std::vector<AnyType> UniteWithoutDuplicates(std::vector<AnyType>& arr1, std::vector<AnyType>& arr2) {
	std::unordered_set<AnyType> unique_set;
	unique_set.reserve(arr1.size() + arr2.size());
	unique_set.insert(arr1.begin(), arr1.end());
	unique_set.insert(arr2.begin(), arr2.end());
	std::vector<AnyType> new_arr;
	for (auto& p : unique_set) {
		new_arr.push_back(p);
	}
	unique_set.clear();
	return new_arr;
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
		PrintError(1);
	}
}