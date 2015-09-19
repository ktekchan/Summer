#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	struct Node* next;
};

void Print(Node* head){

	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp = head;

	while (temp != NULL){
		cout << temp->data << "-->";
		temp = temp->next;
	}

	cout << endl;
	return;

}

struct Node* InsertTail(Node* head, int data){

	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp = head;

	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (temp == NULL){
		temp = newNode;
		head = temp;
	}
	
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
	
		if (temp->next == NULL){
			temp->next = newNode;
		}
	}

	return head;
}

struct Node* InsertHead(Node* head, int data){

	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp = head;

	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = temp;
	head = newNode;

	return head;
}

struct Node* InsertPos(Node* head, int data, int pos){


	Node* prev;
	Node* curr;
	prev = (Node*)malloc(sizeof(Node));
	curr = (Node*)malloc(sizeof(Node));
	prev = head;


	if (pos == 0){
		head = InsertHead (head, data);
	}

	else {
		int posCount = 0;
		curr = prev->next;

		Node* newNode;
		newNode = (Node*)malloc(sizeof(Node));	
		newNode->data = data;

		while (posCount != pos-1){
			prev = prev->next;
			curr = curr->next;
			posCount++;
		}

		newNode->next = curr;
		prev->next = newNode;
	}
	return head;
}

struct Node* DeletePos(Node* head, int pos){

	int posCount = 0;
	if (head == NULL){
		cout << "Empty list\n";
	}

	else if(pos == 0){
		head = head->next;
	}

	else{

		Node* temp = (Node*)malloc(sizeof(Node));
		temp = head;

		while(posCount != pos-1){
			temp = temp->next;
			posCount++;
		}
	
		temp->next = temp->next->next;
	}

	return head;
}

void ReversePrint(Node* head){

	if (head == NULL){
		cout << endl;
		return;
	}
	ReversePrint(head->next);
	cout << head->data << "-->" ;
	
	return;
}

struct Node* Reverse(Node* head){

	Node* ret = (Node*)malloc(sizeof(Node));
	ret = head;

	if(head == NULL)
		return ret;
	else if(head->next == NULL){
		return ret;
	}
	else {
		ret = Reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return ret;
	}
}

struct Node* ReverseMiddle(Node* head, int start, int end){

   Node* ret = (Node*)malloc(sizeof(Node));
   ret = head;

   Node* prev = head;
   Node* curr = head;
   Node* rhead = head;
   Node* rprev = NULL;

   int count = 1;
   int i;

   if (head==NULL)
      ret = NULL;
   if (head->next == NULL)
      ret = head;
   else{
      while(count<start){
         prev = curr;
         curr = curr->next;
         count++;
      }

      rprev = prev;
      rhead = curr;

      while(count<(end+1) && curr!=NULL){
         Node *next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         count++;
      }

      rprev->next = prev;
      rhead->next = curr;
   }

   if(start==1)
      ret = prev;

   return ret;
}



int main(){

	int opt, data, pos;
   int start, end;
	cout << "-------------Menu----------------\n";
	cout << "1. Print\n";
	cout << "2. Insert node at tail\n";
	cout << "3. Insert node at head\n"; 
	cout << "4. Insert node at a position\n";
	cout << "5. Delete node from position\n";
	cout << "6. Print Reverse\n";
	cout << "7. Reverse list\n";
   cout << "8. Reverse list from the middle\n";
	cout << "9. Exit\n";


	struct Node* head;
	head = (Node*)malloc(sizeof(Node));
	head = NULL;
	
	struct Node* rhead;
	rhead = (Node*)malloc(sizeof(Node));

	do{

		cout << "Enter option: ";
		cin >> opt;

		switch(opt){
		
			case 1:
			Print(head);
			break;
	
			case 2: 
			cout << "Enter data: ";
			cin >> data;
			head = InsertTail(head,data);
			break;

			case 3:
			cout << "Enter data: ";
         cin >> data;
	      head = InsertHead(head,data);
			break;

			case 4:
			cout << "Enter data: ";
			cin >> data;
			cout << "Enter position: ";
			cin >> pos;
			head = InsertPos(head,data,pos);
			break;

			case 5:
			cout << "Enter position: ";
			cin >> pos;
			head = DeletePos(head,pos);
			break;

			case 6:
			ReversePrint(head);
			break;

			case 7:
			head = Reverse(head);
			break;

         case 8:
         cout << "Enter start position: ";
         cin >> start;
         cout << "Enter end position: ";
         cin >> end;
         head = ReverseMiddle(head, start, end);

			case 9:
			break;
			
			default:
			cout << "Invalid option\n";
         exit(0);
			break;
		}

	} while(opt!=9);

	return 0;

}
