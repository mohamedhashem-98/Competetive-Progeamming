#include <bits/stdc++.h>

using namespace std;
struct TrieNode{
  struct TrieNode * children[26];
  bool isEnd ;
};

struct TrieNode * getNode(void){
   struct TrieNode * Tmp = new TrieNode;
   Tmp->isEnd = false;
   for(int i = 0 ; i < 26 ; ++i)
    Tmp->children[i] = NULL;
   return Tmp;
};

void Insert(struct TrieNode * root , string s){
   struct TrieNode * t = root;
   for(int i = 0  ; i <  s.size() ; ++i){
        int index = s[i] - 'a';
        if(t->children[index] == NULL){
            t->children[index] = getNode();
        }
        t = t->children[index];
   }
   t->isEnd = true;
}
bool search_Prefix(struct TrieNode * root , string s){
   struct TrieNode * t = root;
   for(int i = 0  ; i <  s.size() ; ++i){
        int index = s[i] - 'a';
        if(t->children[index] == NULL){
            return false;
        }
        t = t->children[index];
   }
   return true;
}
bool search_Word(struct TrieNode * root , string s){
   struct TrieNode * t = root;
   for(int i = 0  ; i <  s.size() ; ++i){
        int index = s[i] - 'a';
        if(t->children[index] == NULL){
            return false;
        }
        t = t->children[index];
   }
   return (t!=NULL && t->isEnd == true);
}
bool isempty(struct TrieNode * root){
  for(int i = 0 ; i < 26 ; ++i){
    if(root->children[i])
        return false;
  }
  return true;
}
TrieNode * Delete(struct TrieNode * root , string s , int depth=0){
     if(!root)
       return NULL;
    if(depth == s.size()){
        root->isEnd = false;
        if(isempty(root)){
            delete(root);
            root = NULL;
        }
        return root;
    }
    int index = s[depth] - 'a';
    root->children[index] = Delete(root->children[index] , s , depth+1);

    if(isempty(root) && root->isEnd == false){
        delete(root);
        root = NULL;
    }
    return root;
}
int main()
{
     struct TrieNode * root = getNode();

    return 0;
}
