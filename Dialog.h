#ifndef DIALOG_H
#define DIALOG_H

namespace p3 {
	class Que;
	template <class T>
	int getNum(T& a, const char* text) {
		bool flag = false;
		std::cout << text << std::endl;
		do {
			if (flag == true) {
				std::cout << "Error, try again:";
				flag = false;
			}
			std::cin >> a;
			if (std::cin.eof() || std::cin.bad()) {
				return -1;
			}
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				flag = true;
			}

		} while (flag == true);
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return 0;
	}
	struct elem;
	int dialog(elem& el,int& len);
	void ch(elem& el, int& len, int num, Que& q);
	void init(elem*& el, int& len);
}
#endif // !DIALOG_H

