/*
Даны два списка целых чисел:
a0, a1, ..., an - 1(|ai| <= 100)
и b0, b1, ..., bm−1(| bi| <= 100).
Проверить, все ли элементы одного из списков принадлежат другому ?

 Автор: Котов М.В.
 Дата: 11.09.2020
 Предмет: Практикум по программированию
*/
const int n = 10;


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

struct List {
	int info;
	List *next;
	List *pred;
};

void createRandomList(List *&head, List *&tail, int n) {
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;
	List *last = head;

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		List *p;
		p = new List;
		p->info = rand() % 200 - 100;
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
	}
	return;
}

void printList(List *head, List *tail) {
	List *p;
	p = head;
	p = p->next;
	while (p != tail) {
		cout << p->info << "\t";
		p = p->next;
	}
	cout << endl;
	return;
}

void sortList(List *&aHead, List *&aTail) {
	//сортировка 
	List *p;
	for (int i = 0; i < n - 1; i++) {
		p = aHead;
		for (int j = i; j < n - 1; j++) {
			p = p->next;
		}

		while (p->next != aTail) {
			if (p->info > p->next->info) {

				List *pP = p->pred;
				List *tempB = p->next;
				//связали next
				p->pred->next = p->next;
				p->next = tempB->next;
				tempB->next = p;

				//связали pred
				p->pred = tempB;
				tempB->pred = pP;
				p->next->pred = p;

				//*tempB->next = *tempA;

				//tempA->next = tempB->next;
				//tempA->pred = tempB;
				//tempB->next->pred = tempA;

				//tempB->pred = p->pred;
				//tempB->next = tempA;
				//p = tempB;			//
				//p->next = tempA;


				//p->pred = tempB->pred;
				//p->pred->next = p;	//

				//cout << "Массив после " << i << " сортиовки" << endl;
				//printList(aHead, aTail);
				p = p->pred;
			}

			p = p->next;
		}
	}

}



int main() {
	setlocale(LC_ALL, "RUS");
	List *aHead = NULL, *aTail = NULL;//список А
	List *bHead = NULL, *bTail = NULL;//список А



	createRandomList(aHead, aTail, n);
	createRandomList(bHead, bTail, n);

	//исходный массив
	printList(aHead, aTail);
	sortList(aHead, aTail);

	//отсортированный массив
	printList(aHead, aTail);



	return 0;
}