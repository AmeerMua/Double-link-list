
#include"Linklist.h"
#include<iostream>

using namespace std;
//////////////////////////////////////////// Node Class ////////////////////////////////////////////

Node::Node() 
{
    data = -1;
    next = NULL;
    prev = NULL;
}

Node::Node(int data) 
{
    this->data = data;
    next = NULL;
    prev = NULL;
}


void Node::setData(int data) 
{
    this->data = data;
}

void Node::setNext(Node* next) 
{
    this->next = next;
}

void Node::setPrev(Node* prev) 
{
    this->prev = prev;
}

int Node::getData() 
{
    return data;
}

Node* Node::getNext() 
{
    return next;
}


Node* Node::getPrev() 
{
    return prev;
}

//////////////////////////////////////////// Linklist ////////////////////////////////////////////
Linklist::Linklist() 
{
    head = NULL;
    tail = NULL;
}

bool Linklist::isEmpty() 
{
    return head == NULL;
}

void Linklist::insertAtTail(int data) 
{
    Node* temp = new Node(data);
    if (isEmpty()) 
	{
        head = temp;
        tail = temp;
    } 
	else 
	{
        tail->setNext(temp);
        temp->setPrev(tail);  
        tail = temp;
    }
}

void Linklist::insertAtHead(int data) 
{
    Node* temp = new Node(data);
    if (isEmpty()) 
	{
        head = temp;
        tail = temp;
    } else 
	{
        temp->setNext(head);
        head->setPrev(temp);  
        head = temp;
    }
}

void Linklist::display() 
{
    Node* temp = head;
    while (temp != NULL) 
	{
        cout << temp->getData() << "\t";
        temp = temp->getNext();
    }
    cout << endl;
}

Node* Linklist::searchtarget(int toFind) 
{
    Node* temp = head;
    while (temp != NULL) 
	{
        if (temp->getData() == toFind) 
		{
            return temp;
        }
        temp = temp->getNext();
    }
    return NULL;
}

void Linklist::insertAtTarget(int target, int value) 
{
    if (isEmpty()) 
	{
        cout << "List is empty" << endl;
        return;
    }

    Node* targetNode = searchtarget(target);
    if (targetNode == NULL) 
	{
        cout << "Not found" << endl;
        return;
    }


    if (targetNode == tail) 
	{
        insertAtTail(value);
    }

	else 
	{    
		Node* temp = new Node(value);
        temp->setNext(targetNode->getNext());
        temp->setPrev(targetNode); 
        
		if (targetNode->getNext() != NULL) 
		{
            targetNode->getNext()->setPrev(temp);
        }
        targetNode->setNext(temp);
    }
}

void Linklist::removeNode (int toRemove)
{
	Node* targetNode = head;
	Node* prev = NULL;

	while(targetNode != NULL)	
	{
		if (targetNode->getData() == toRemove)
		{
			break;
		}
	else
		{
			prev= targetNode;
			targetNode = targetNode->getNext();

		}
	}
	if (targetNode== NULL)
	{
		cout<<"NOT found"<<endl;
		return;
	}
	else
	{
	if (targetNode == head)
	{
		head = head ->getNext();
		targetNode ->setNext (NULL); // yeh wali line delink kare giy
		delete targetNode;
	}
	else if (targetNode == tail)
	{
		tail = prev;
		tail->setNext(NULL);
		delete targetNode;
	
	}
	else
	{
		prev ->setNext(targetNode->getNext());
		targetNode->setNext(NULL);
		delete targetNode;
		
	}
}

}
