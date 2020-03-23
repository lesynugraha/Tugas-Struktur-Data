#include <iostream>
using namespace std;


  
// double link list node
struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};


  
//memasukan node di awal list
void insert_front(struct Node** head, int new_data)
{
   // mengalokasikan memori untuk node baru
   struct Node* newNode = new Node;
  
   // memberikan data untuk node baru
   newNode->data = new_data;
  
   // node baru adalah head, dan sebelumnya adalah null, karena kita menambah di node awal
   newNode->next = (*head);
   newNode->prev = NULL;
  
   // head sebelumnya sekarang adalah node baru
   if ((*head) != NULL)
   (*head)->prev = newNode;
  
   // head menunjuk ke node baru
   (*head) = newNode;
}



/* diberikan sebuah node sebagai prev_node, memasukan node baru setelah node yang telah diberikan */



void insert_After(struct Node* prev_node, int new_data)
{
   //melakukan pemeriksaan bila prev_node null
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
}
   // mengalokasikan mmemory untuk node baru
   struct Node* newNode = new Node;
  
   // memberikan data untuk node baru
   newNode->data = new_data;
  
   //mengatur next dari newnode menjadi next dari node sebelumnya
   newNode->next = prev_node->next;
  
   // mengatur next dari node sebelumnya menjadi node baru
   prev_node->next = newNode;
  
   //sekarang mengatur node baru sebelunya menjadi node sebelumnya
   newNode->prev = prev_node;
  
   // mengatur prex dari node baru menjadi next dari node
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}
  
// memasukan node baru di akhir list
void insert_end(struct Node** head, int new_data)
{
   // mengalokasikan memory untuk node
   struct Node* newNode = new Node;
  
   struct Node* last = *head; // mengatur node terakhir menjadi head
  
   //mengatur data untuk node baru
   newNode->data = new_data;
  
   //node baru adalah node yang terakhir, jadi mengatur next dari node baru menjadi null
   newNode->next = NULL;
  
   // cek jika listnya kosong, jika iya, membuat node dari head
   if (*head == NULL) {
   newNode->prev = NULL;
   *head = newNode;
    return;
}
  
// jika tidak, mentranverse list ke node terakhir
while (last->next != NULL)
last = last->next;
  
// mengatur next dari last ke node baru
last->next = newNode;
  
//mengatur last menjadi prev dari node baru
newNode->prev = last;
return;
}
  
// Fungsi ini memprint isi dari linked list dimulai dari node yang telah diberikan
void displayList(struct Node* node) {
   struct Node* last;
  
   while (node != NULL) {
      cout<<node->data<<"<==>";
      last = node;
      node = node->next;
   }
   if(node == NULL)
   cout<<"NULL";
   }
  
// program utama
int main() {
   /* Mulai dengan list kosong */
   struct Node* head = NULL;
  
   // Insert 40 sebagai node terakhir
   insert_end(&head, 40);
  
   // insert 20 di bagian head
   insert_front(&head, 20);
  
   // Insert 10 di awal.
   insert_front(&head, 10);
  
   // Insert 50 di akhir.
   insert_end(&head, 50);
  
   // Insert 30, setelahr 20.
   insert_After(head->next, 30);
  
   cout<<"Doubly linked list adalah sebagai berikut : "<<endl;
   displayList(head);
   return 0;
}
