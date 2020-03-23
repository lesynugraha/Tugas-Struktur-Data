
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
/* Fungsi ini melakukan print dari isi linked list
Memulai dari node yang diberikan*/


void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 

  
// Code Driver 
int main() 
{ 
    Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
  
    // mengalokasikan 3 nodes di heap 
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 
  
    head->data = 3; // memberikan data ke node pertama 
    head->next = second; // melink node pertama dengan ke dua 
  
    second->data = 2; // memberikan data ke node kedua
    second->next = third; 
  
    third->data = 1; // memberikan data ke node ketiga 
    third->next = NULL; 
  
    printList(head); 
  
    return 0; 
} 
