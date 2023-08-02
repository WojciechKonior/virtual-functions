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
#include <iostream>
#include <list>
#define key first
#define val second
class LRUCache {
    int cp;
    map<int, list<pair<int, int> >::iterator> mp;
    list<pair<int, int> > lru;
public:
    LRUCache(int capacity) : cp(capacity){}
    void set(int key, int val) {
        if(mp.find(key) != mp.end()) {
            mp[key]->key = key;
            mp[key]->val = val;
        }
        else {
            lru.push_front({key, val});
            mp[key] = lru.begin();
            if(lru.size() > cp) {
                mp.erase(lru.back().key);
                lru.pop_back();
            }
        }
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            lru.push_front(*mp[key]);
            lru.erase(mp[key]);
            mp[key] = lru.begin();
            return mp[key]->val;
        }
        else
            return -1;
    }
};
// class LRUCache : public Cache
// {
// public:
//     LRUCache(int iCapacity){
//         Cache::cp = iCapacity;
//     }
//     void set(int iKey, int iValue){
//         if(mp.empty()) //if nothing is in mp
//         {
//             head = tail = new Node(NULL, NULL, iKey, iValue);
//             mp.insert({iKey, head});
//         }
//         else
//         {
//             auto itr = mp.find(iKey);
//             Node *curr;
//             if(itr != mp.end()) //if element exists
//             {
//                 curr = itr->second;
//                 if(curr!=head)
//                 {
//                     if(curr==tail)
//                     {
//                         //przypisz prev-sasiadowi null jako nexta
//                         curr->prev->next = NULL;

//                         //wpisz prev-sasiada do taila
//                         tail = curr->prev;
//                     }
//                     else
//                     {
//                         //przypisz sasiadom siebie nawzajem i pozegnaj sie
//                         curr->prev->next = curr->next;
//                         curr->next->prev = curr->prev;
//                     }
//                     //wpisz sobie heada jako next-sasiada
//                     curr->next = head;

//                     //wpisz siebie headowi jako prev-sasiada
//                     head->prev = curr;

//                     //ustaw sobie preva na null
//                     curr->prev = NULL;

//                     //wpisz sie do heada
//                     head = curr;
//                 }//if curr==head do nothing;
//             }
//             else //if element is new
//             {
//                 //ustaw nowego noda i zarejestruj sasiada nako nexta
//                 curr = new Node(NULL, head, iKey, iValue);

//                 //zaktualizuj sasiada (ustaw siebie jako preva)
//                 head->prev = curr;

//                 //wpisz element do head
//                 head = curr;

//                 //wpisz element do mapy
//                 mp.insert({iKey, head});

//                 //usun nadmiarowy ogon jesli trzeba
//                 if(mp.size()>cp)
//                 {
//                     //przepisz przedostatniego do nowego ogona
//                     Node* newTail = tail->prev;

//                     //usun stary ogon
//                     mp.erase(mp.find(tail->key));
//                     // delete tail;

//                     //zaktualizuj ogon
//                     tail = newTail;
//                     tail->next = NULL;
//                 }
//             }
//         }
//     }

//     int get(int iKey){
//         auto itr = mp.find(iKey);
//         if(itr!=mp.end()) return itr->second->value;
//         else return -1;
//     }
// };



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
