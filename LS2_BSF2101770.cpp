#include <iostream>
using namespace std;



struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insert(int val) {
    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* curr_node = head;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}


void deleteNode(int val) {
    if (head == NULL) {
        cout << "Linked list Is Empty" << endl;
        return;
    }

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }


    Node* curr_node = head;
    while (curr_node->next != NULL && curr_node->next->data != val) {
        curr_node = curr_node->next;
    }

    if (curr_node->next == NULL) {
        cout << "Sorry Value is Not Present " << endl;
        return;
    }

    Node* temp = curr_node->next;
    curr_node->next = temp->next;
    delete temp;
}


void show() {
	cout<<"Values In The Linked List Are : "<<endl;
    Node* curr_node = head;
    while (curr_node != NULL) {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}


int countNodes() {
    int count = 0;
    Node* curr_node = head;
    while (curr_node != NULL) {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}


bool isFull() {
    Node* new_node = new Node;
    if (new_node == NULL) {
        return true;
    } else {
        delete new_node;
        return false;
    }
}


bool isEmpty() {
    return head == NULL;
}


void printEven() {
	cout<<"Even Numbers Are :  "<<endl;
        Node* temp = head;
        while (temp != NULL) {
        if (temp->data % 2 == 0) {
         cout << temp->data << " " << endl;
        } 
         temp = temp->next;
        }
    }
    
    
void printOdd() {
	cout<<"Odd Numbers Are :  "<<endl;
        Node* temp = head;
        while (temp != NULL) {
        if (temp->data % 2 != 0) {
         cout << temp->data << " " << endl;
        } 
         temp = temp->next;
        }
    }






int main() {
    int choice, val,ch;
        cout<<"**************************************"<<endl;
        cout << "1. Inserting Values In Linked List" << endl;
        cout << "2. Deleting Values In Linked List" << endl;
        cout << "3. Displaying Linked List" << endl;
        cout << "4. Check Linked List Is Empty" << endl;
        cout << "5. Check Linked List Is Full" << endl;
        cout << "6. Displaying Even Numbers" << endl;
        cout << "7. Displaying Odd Numbers" << endl;
        cout << "8. Exit " << endl;
        cout<<"**************************************"<<endl;

do {
	cout << "Please Enter Choice To Perform Operation : "<<endl;
    cin >> choice;

    switch (choice) {
    case 1:{
    cout << "Please Insert Values : ";
    cin >> val;
    insert(val);
    break;
}
            
case 2:
{				
	cout << "Please Enter Values To Delete : ";
	cin >> val;
	deleteNode(val);
	break;
}

case 3:
{	
	show();
    break;
}


case 4:
{
    if (isEmpty()) {
    cout << "Linked list is Empty" << endl;
    } 
	else {
    cout << "Linked list is Not Empty" << endl;
    }
    break;
}


case 5:
{
    if (isFull()) {
        cout << "Linked list is Full" << endl;
    }
	else {
    cout << "Linked list is Not Full" << endl;
    }
    break;
}


case 6 :
{
    printEven();
    break;
}


case 7 :
{
    printOdd();
    break;
}
			
case 8:
{

	cout<<"*********************"<<endl;
	cout<<"THANKS FOR COMPILING"<<endl;
	cout<<"********************"<<endl;
		exit (0);
	break;
}

	default:
	cout<<"****************************"<<endl;
	cout<<"Sorry Inavalid Question No."<<endl;
	cout<<"****************************"<<endl;
	
	}
	
	} while (ch != 8);
	return 0;
}