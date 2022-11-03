#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *next;
};
struct node *head = 0, *temp, *newnode;

// insertion of node
void insertion() {
  int choice;
  newnode = (struct node *)malloc(sizeof(struct node));
  cout << "Enter data for node = ";
  cin >> newnode->data;
  newnode->next = NULL;

  if (head == 0) {
    head = temp = newnode;
  } else {
    temp->next = newnode;
    temp = newnode;
  }
  cout << "Do you want to continue (0,1)" << endl;
  cin >> choice;
  if (choice == 1) {
    insertion();
  }
}

// insertion at last

void insertion_at_last() {
  newnode = (struct node *)malloc(sizeof(struct node));
  cout << "Enter data for node";
  cin >> newnode->data;
  newnode->next = 0;
}

// display of node
void display() {
  temp = head;
  while (temp != 0) {
    cout << "Data is : " << temp->data << endl;
    temp = temp->next;
  }
}

// serching
void serching() {
  int serch, found = 0;
  cout << "Enter data to serch ";
  cin >> serch;
  if (head == 0) {
    cout << "Linked list is Empty " << endl;
  } else {
    temp = head;
    while (temp != 0) {
      if (temp->data == serch) {
        cout << "data is present in linked list " << endl;
        found = 1;
        break;
      } else {
        temp = temp->next;
      }
      if (found == 0) {
        cout << "Data is not present" << endl;
      }
    }
  }
}

// deletion from starting
void deletion_from_starting() {
  int choice;
  if (head == 0) {
    cout << "Linked list is empty " << endl;
  } else {
    temp = head;
    head = temp->next;
    free(temp);
  }
  cout << "Do you  want to display Elements after deletion (0,1)" << endl;
  cin >> choice;
  if (choice == 1) {
    display();
  }
}

// deletion from end
void delete_at_end() {
  int choice;
  struct node *prev;
  while (temp->next != 0) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = 0;
  cout << "Do you  want to display Elements after deletion (0,1)" << endl;
  cin >> choice;
  if (choice == 1) {
    display();
  }
}

// is linked list is empty
void is_empty() {
  if (head == 0) {
    cout << "Linked list is Empty " << endl;
  } else {
    cout << "Linked list in not Empty" << endl;
  }
};

int main() {
  char choice;
  cout << "Welcome to linked list" << endl;

  cout << "switches are following "<<endl;
  cout << "For insert node press (A)"<<endl;
  cout << "For display node press (B)"<<endl;
  cout << "For deletion_from_starting node press (C)"<<endl;
  cout << "For serching node press (D)"<<endl;
  cout << "For deletion_at_end node press (E)"<<endl;
  cout << "For is_empty_node node press (F)"<<endl;

  cin >> choice;
  choice = tolower(choice);
  switch (choice) {
  case 'a':
    insertion();
    break;

  case 'b':
    display();
    break;

  case 'c':
    deletion_from_starting();
    break;

  case 'd':
    serching();
    break;

  case 'e':
    delete_at_end();
    break;

  case 'f':
    // is_empty();
    break;
  }
  return 0;
}
