#include <iostream>
#include "Dialog.h"
#include "../Par_Queue/ParQ.h"
#pragma comment (lib,"../Par_Queue/Debug/Par_Queue")

namespace p3 {
	int dialog(elem& el, int& len) {
		int a;
		int help;
		const char* opt[] = { "1.Add Par", "2.Add Que" ,"3.Show Elem","4.Show Queue","5.Del Elem","6.Check", "7.Exit"};
		for (int i = 0; i < 7; i++) {
			std::cout << opt[i] << std::endl;
		}
		std::cout << "Choose one option" << std::endl;
		help = getNum(a, "int");
		if (help == -1) { return 7; }
		if ((a < 1 || a>7)) {
			std::cout << "Error, try again" << std::endl;
		}
		while (a < 1 || a>7) {
			help = getNum(a, "int");
			if (help == -1) { return 7; }
			if ((a < 1 && a>8)) {
				std::cout << "Error, try again" << std::endl;
			}
		}
		if (a == 1) {
			std::cout << "Enter element:" << std::endl;
			std::cin >> el;
			return 1;
		}
		if (a == 2) {
			help = getNum(len, "int");
			if (help == -1) { return 7; }
			return a;
		}
		else { return a; }
	}
	void ch(elem& el, int& a, int num, Que& q) {
		if (num == 1) {
			try {
				q += el;
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return;
		}
		if (num == 2) {
		    q.Set_l(a);
			try {
				std::cin >> q;
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return;
		}
		if (num == 3) {
			try {
				q.Get_Elem();
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return;
		}
		if (num == 4) {
			try {
				std::cout << q << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return;
		}
		if (num == 5) {
			try {
				q.DelElem(el);
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
				return;
			}
			std::cout << "Deleted Element:" << el << std::endl;
			return;
		}
		if (num == 6) {
			const char* s;
			s=q.Ch(q);
			std::cout << s << std::endl;
			return;
		}
	}
	void init(elem*& mas, int& l) {
		int h = 0;
		std::cout << "\nEnter len?\n1.yes\n2.no" << std::endl;
		while (h < 1 || h>2) {
			getNum(h, "int");
			if (h == 1) {
				std::cout << "enter len" << std::endl;
				getNum(l, "int");
				l = abs(l);
				delete[] mas;
				mas = new elem[l];
				for (int i = 0; i < l; i++) {
					std::cout << "Enter element:" << std::endl;
					std::cin >> mas[i];
				}
				break;
			}
		}
	
	
	}
}