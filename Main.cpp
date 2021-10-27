#include <iostream>
#include "../Par_Queue/ParQ.h"
#include "Dialog.h"
#pragma comment (lib,"../Par_Queue/Debug/Par_Queue")
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


using namespace p3;
int main() {
	int l=1;
	elem* mas = new elem[1];
	try {
		init(mas, l);
	}
	catch (const std::bad_alloc& ba) {
		std::cout << "Error:" << ba.what() << std::endl;
	}
    Que q(l, mas);
	elem a;
	int num = 0;
	int m;
	while (num != 7) {
		num = dialog(a,m);
		ch(a,m,num,q);
	}
	delete[] mas;
	_CrtDumpMemoryLeaks();
	return 0;
}