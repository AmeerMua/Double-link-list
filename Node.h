class Node
{
private:
	int data;
	Node* next;
	Node* prev;

public:
	Node();
	Node(int);
	void setData(int);
	void setNext(Node* );
	void setPrev(Node* );
	int getData();
	Node* getNext();
	Node* getPrev();


};
