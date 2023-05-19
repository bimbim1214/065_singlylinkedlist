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
	