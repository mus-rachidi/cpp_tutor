#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  // first insert function version (single parameter):
  std::pair<char,int> p;
  p = std::make_pair('a',100) ;
  mymap.insert ( p );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second == false) 
  {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}

// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Node {
   public:
  int key;
  Node *left;
  Node *right;
  int height;
};


// Node *newNode(int key) {
//   Node *node = new Node();
//   node->key = key;
//   node->left = NULL;
//   node->right = NULL;
//   node->height = 1;
//   return (node);
// }

// Node *insertNode(Node *node, int key) {
//   if (node == NULL)
//     return (newNode(key));
//   if (key < node->key)
//     node->left = insertNode(node->left, key);
//   else if (key > node->key)
//     node->right = insertNode(node->right, key);
//   else
//     return node;
//   return node;
// }

// int main() 
// {
//     Node *root = NULL;
//     root = insertNode(root, 1);
//     root = insertNode(root, 2);
//     root = insertNode(root, 3);
// }