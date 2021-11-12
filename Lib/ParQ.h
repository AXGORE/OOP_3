#ifndef PARQ_H
#define PARQ_H
#include <iostream>
#include <fstream>


namespace p3 {
	class elem {
		int a;
		char b;
	public:
		int Getint() const { return a; }
		char Getchar() const { return b; }
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
		friend std::ostream& operator<< (std::ostream& os,const elem& mas) {
			os << " " << mas.a << " " << mas.b << std::endl;
			return os;
		}
	};

	class Que {
	    int l;
		int len;
		elem* mas;
	public:
		int GetLen()const { return len; }
		int Getl()const { return l;}
		void Set_l(int a) { l = a; }
		elem* Getq() const { return mas; }
			Que() {
			mas = new elem[1];
			len = 1;
			l = 1;
			for (int i = 0; i < len; i++) {
			 mas[i].Set_elem(0,' ');
			}
		}
		Que(int a, elem* mass) {
			this->mas = new elem[a];
			this->len = a;
			this->l = a;
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
		Que(Que& q) :l(q.l), len(q.len) {
			if (mas != nullptr) { delete[] mas; }
			mas = q.mas;
			q.mas = nullptr;
			q.l = 0;
			q.len = 0;
		}
		Que& operator +=(const elem& a) {
			elem* new_m = new elem[len+1];
			for (int i = 0; i < len; i++) {
				new_m[i] = mas[i];
			}
			if (len > 0) {
				delete[] mas;
			}
			this->mas = new_m;
			this->l = len+1;
			 if (len >= l) { throw std::out_of_range("Queue is full"); }
			 mas[len] = a;
			 len++;
			 return *this;
		 }
		friend std::istream& operator>> (std::istream& is,  Que& q) {
			q.New_mem(q.l);
			for (int i = q.len; i < q.l; i++) {
				is >> q.mas[i];
				q.len++;
				
			}
			
			return is;
		}
		friend std::ostream& operator<< (std::ostream& os, const Que& q) {
			if (q.len == 0) { throw std::out_of_range("Queue is empty"); }
			for (int i = 0; i < q.len; i++) {
				os << q.mas[i];
			}
			//std::cout << __FUNCSIG__ << std::endl;
			return os;
		}
		 operator bool () const {
			if (len == 0) { return false; }
			else { return true; }
		}
		 Que& operator =(const Que& q) {
			 if (&q == this) { return *this; }
			 if (mas != nullptr) {
				 delete[] mas;
			 }
			 mas = new elem[q.l];
			 for (int i = 0; i < q.l; i++) {
				 mas[i] = q.mas[i];
			 }
			 l = q.l;
			 len = q.len;
			 return *this;
		 }
		 Que& operator =(Que& q) {
			 if (&q == this) { return *this; }
			 mas = q.mas;
			 l = q.l;
			 len = q.len;
			 q.mas = nullptr;
			 q.l = 0;
			 q.len = 0;
			 return *this;
		 }
		void DelElem(elem& a);
		void Get_Elem() const;
		const char* Ch(bool x) const;
		void New_mem(int a);
		~Que() {
			delete[] this->mas;
		}
	};


}

#endif
