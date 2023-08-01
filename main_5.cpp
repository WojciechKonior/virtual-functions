#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
#include <deque>
class LRUCache : public Cache
{
public:
    LRUCache(int iCapacity){
        Cache::cp = iCapacity;
    }
    void set(int iKey, int iValue){
        if(mp.find(iKey)==mp.end())
        {
            Node* pNext = NULL;
            if(head!=NULL) pNext = head;

            head = new Node(NULL, pNext, iKey, iValue);
            if(head->next == NULL) tail = head;

            mp.insert({iKey, head});
            if(pNext != NULL) pNext->prev = head;
        }
        else
        {
            Node* curr = mp.find(iKey)->second;
            Node* pNext = NULL;
            if(head!=NULL && head!=curr) pNext = head;

            head = curr;
            head->next = pNext;
            if(pNext != NULL) pNext->prev = head;
        }

        if(mp.size()>cp){
            int tailKey = tail->key;
            Node *pPrev = mp.find(tailKey)->second->prev;
            mp.erase(mp.find(tailKey));
            tail = pPrev;
            tail->next = NULL;
        }
    }
    int get(int iKey){
        auto itr = mp.find(iKey);
        if(itr!=mp.end()) return itr->second->value;
        else return -1;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
