#include<iostream>
#include<string>
using namespace std;

struct Node {
	int roll;
	string name;
	float marks;
	Node *next;

	Node() : roll(0), name(""), marks(0.0), next(nullptr) {}
	Node(int val, string str, float flo) : roll(val), name(str), marks(flo), next(nullptr) {}
	
	void display() {
		cout << roll << " || " << name << " || " << marks << endl;
	}
};

class Database {
	private: 
		Node *head;
		Node *current;
	public:
		Database() : head(nullptr), current(nullptr) {}

		void add(){
			Node *newNode = new Node();

			if (head == nullptr) {
				head = newNode;
				return;
			}

			current = head;
			newNode->next = current->next;
			current->next = newNode;
		}

		void add(int a, string b, float c){
			Node *newNode = new Node(a, b, c);

			if (head == nullptr) {
				head = newNode;
				return;
			}

			current = head;

			while(current->next != nullptr && current->next->roll < a) {
				current = current->next;
			}

			newNode->next = current->next;
			current->next = newNode;
		}

		void deleting(int a){
			if (head == nullptr) {
				return;
			}

			if (head->roll == a) {
				Node * temp = head;
				head = head->next;
				delete temp;
				return;
			}

			current = head;

			while(current->next != nullptr && current->next->roll < a) {
				current = current->next;
			}

			if (current->next == nullptr || current->next->roll != a) {
				return;
			}

			Node *temp = current->next;
			current->next = temp->next;
			delete temp;
		}

		// void deleting(float a){
		// 	if (head == nullptr) {
		// 		return;
		// 	}
  //
		// 	if (abs(head->marks - a) < 0.001f){
		// 		Node *temp = head;
		// 		head = head->next;
		// 		delete temp;
		// 		return;
		// 	}
  //
		// 	current = head;
  //
		// 	while(current->next != nullptr && abs(current->next->marks - a) >= 0.001f) {
		// 		current = current->next;
		// 	}
  //
		// 	if (current->next == nullptr) {
		// 		return;
		// 	}
  //
		// 	Node *temp = current->next;
		// 	current->next = temp->next;
		// 	delete temp;
		// }

		void ddisplay(int a) {
			current = head;
			int i = 1;

			while (current != nullptr && i < a) {
				current = current->next;
				i++;
			}

			current->next->display();
		}

		void ddisplay() {
			current = head;
			cout << "Roll No. || Name || Marks";
			while (current != nullptr) {
				current->display();
				current = current->next;
			}
		}
};

int main() {
	Database d;

	d.add();
	d.add();
	d.add(1, "a", 2.0);
	d.add();
	d.add();
	cout<<"";

	d.ddisplay(2);
}

