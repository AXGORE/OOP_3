#ifndef PARQ_H
#define PARQ_H
#include <iostream>
#include <fstream>


namespace p3 {
	class elem {
		int a;
		char b;
	public:
		elem() {
			a = 0;
			b = ' ';
		}
		void Set_elem(int e,char m) {
			a = e;
			b = m;
		}
		friend std::istream& operator>> (std::istream& is, elem& mas) {	
		is >> mas.a;
		is >> mas.b;
		return is;
		}
		friend std::ostream& operator<< (std::ostream& os, elem& mas) {
			os << " " << mas.a << " " << mas.b << std::endl;
			return os;
		}
	};

	class Que {
	    int l;
		int len;
		elem* mas;
	public:
		Que() {
			mas = new elem[1];
			len = 1;
			for (int i = 0; i < len; i++) {
			 mas[i].Set_elem(0,' ');
			}
		}
		Que(int a, elem* mass) {
			this->mas = new elem[a];
			this->len = a;
			for (int i = 0; i < a; i++) {
				this->mas[i] = mass[i];
			}
		};
		Que(const Que& q):l(q.l),len(q.len) {
			mas = new elem[l];
			for (int i = 0; i < l; i++) {
				mas[i] = q.mas[i];
			}
		}
		Que(Que& q) :l(q.l), len(q.len), mas(q.mas) {
			q.mas = nullptr;
		}
		Que& operator +=(const elem& a) {
			 if (len >= l) { throw std::out_of_range("Queue is full"); }
			 mas[len] = a;
			 len++;
			 return *this;
		 }
		friend std::istream& operator>> (std::istream& is, Que& q) {
			//if (q.len >= q.l) { throw std::out_of_range("Queue is full"); }
			for (int i = q.len; i < q.l; i++) {
				is >> q.mas[i];
				q.len++;
			}
			return is;
		}
		friend std::ostream& operator<< (std::ostream& os, Que& q) {
			if (q.len == 0) { throw std::out_of_range("Queue is empty"); }
			for (int i = 0; i < q.len; i++) {
				os << q.mas[i];
			}
			return os;
		}
		void AddElem(elem el);
		void DelElem(elem& a);
		void Get_Elem() const;
		bool Check() const; // преобразование в bool (bool x(que))
		void Ch(bool x) const;
		void New_mem(int a);
		~Que() {
			delete[] this->mas;
		}
	};


}

#endif
