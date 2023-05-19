#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class list
{
	Node* START;
public:
	list();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};

list::list() {
	START = NULL;
}
void list::addNode()/*menambahkan sebuah node ke dalam list*/
{
	int nim;
	char nm[20];
	cout << "\nmemasukkan nomor mahasiswa: ";
	cin >> nim;
	cout << "\nmasukkan nama: ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nduplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nduplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current->next;
	}
	/*jika loop diatas dieksekusi, previous dan current akan menempati pisisi dimana*/
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool list::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
bool list::delNode(int nim)/*menghapus node dari dalam list*/
{
	Node* current, * previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

/*chek apakah node yang di maksud ada didalam list atau tidak*/
