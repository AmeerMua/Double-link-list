
#include "Linklist.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	Node *ans=NULL;
	Linklist list1;
	list1.insertAtTail(10);
	list1.insertAtTail(15);
	list1.insertAtHead(5);
	list1.insertAtTail(7);
	list1.insertAtTail(19);
	list1.insertAtTail(20);
	list1.insertAtTail(25);
	list1.insertAtTail(30);
	list1.insertAtTail(16);
	
	list1.display();
	list1.insertAtTarget(7 , 9);
	cout<<endl;
	list1.display();
	ans=list1.searchtarget(25);
	cout<<endl;
	cout<<ans->getData();
	getch();
	return 0;
}