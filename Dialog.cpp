#include <iostream>
#include "Dialog.h"
#include "../Par_Queue/ParQ.h"
#pragma comment (lib,"../Par_Queue/Debug/Par_Queue")

namespace p3 {
	int dialog(elem& el, int& len) {
		int a;
		int help;
		const char* opt[] = { "1.Add Par", "2.Add Elem" ,"3.Show Elem","4.Show Queue","5.Del Elem","6.Check", "7.Exit","8.Add Que"};
		for (int i = 0; i < 8; i++) {
			std::cout << opt[i] << std::endl;
		}
		std::cout << "Choose one option" << std::endl;
		help = getNum(a, "int");
		if (help == -1) { return 7; }
		if ((a < 1 || a>8)) {
			std::cout << "Error, try again" << std::endl;
		}
		while (a < 1 || a>8) {
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
			std::cin >> el;
			return 2;
		}
		if (a == 3) { return a; }
		if (a == 4) { return a; }
		if (a == 5) { return a; }
		if (a == 6) { return a; }
		if (a == 8) { 
			help = getNum(len, "int");
			if (help == -1) { return 7; }
			return a;
		}
		return 7;
	}
	void ch(elem& el, int& a, int num, Que& q) {
		if (num == 1) {
			try {
				q.New_mem(0);
			}
			catch (const std::bad_alloc& ba) {
				std::cout << "Error:" << ba.what() << std::endl;
			}
			try {
				q += el;
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			return;
		}
		if (num == 2) {
			try {
				q.New_mem(0);
			}
			catch (const std::bad_alloc& ba) {
				std::cout << "Error:" << ba.what() << std::endl;
			}
			try {
				q.AddElem(el);
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
			q.Ch(q.Check());
			return;
		}
		if (num == 8) {
			try {
				q.New_mem(a);
			}
			catch (const std::bad_alloc& ba) {
				std::cout << "Error:" << ba.what() << std::endl;
			}
			try {
				std::cin >> q;
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
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