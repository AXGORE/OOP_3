#include <iostream>
#include "ParQ.h"
#include <stdexcept>

namespace p3 {
	void Que::DelElem(elem& a) {
		if (len == 0) { throw std::out_of_range("Queue is empty"); } //catch (const std::exception& e)
		a = mas[0];
		for (int i = 0; i < len - 1; i++)
			mas[i] = mas[i + 1];
		mas[len - 1].Set_elem(0,' ');
		len--;
		return ;
	}
	void Que::Get_Elem() const {
		if (len == 0) { throw std::out_of_range("Queue is empty"); }
		std::cout << mas[0];
		return;
	}
	const char* Que::Ch(bool x) const {
		if (x == false) {
			return "Empty";
		}
		else {
			return "Not Empty";
		}
	}
	void Que::New_mem(int a) {
		if (a == 0) { a = len + 1; }
		elem* new_m = new elem[a];
		for (int i = 0; i < len; i++) {
			new_m[i] = mas[i];
		}
		if (len > 0) {
			delete[] mas;
		}
		this->mas = new_m;
		this->l = a;
	}

}