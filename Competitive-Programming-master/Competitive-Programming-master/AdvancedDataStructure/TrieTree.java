static class Trie{ // Create class Trie Tree

        static final int MAX_CHAR = 26; // Set MAX_SIZE of Characters

        static class TrieNode{    // Create Node
            TrieNode []child = new TrieNode[MAX_CHAR]; // Create nodes of characters
            boolean isEnd ; // boolean to check if it is End of word
            TrieNode(){ // Constructor Fill with nulls
                isEnd = false;
                for(int i = 0 ; i < MAX_CHAR ; ++i){
                    child[i] = null;
                }
            }
        };

        static TrieNode root ; // Create node root
        
        Trie(){
            root = new TrieNode();
        }

        public void insert(String str){
            TrieNode TmpRoot = root;
            for(int i = 0 ; i < str.length() ; ++i){
                int index = str.charAt(i) - 'a';
                if(TmpRoot.child[index] == null){
                    TmpRoot.child[index] = new TrieNode();

                }
                TmpRoot = TmpRoot.child[index];
            }

            TmpRoot.isEnd = true;
        }

        public boolean isWord(String str){
            TrieNode TmpRoot = root;
            boolean check = true;
            for(int i = 0 ; i < str.length() ; ++i){
                int index = str.charAt(i) - 'a';
                 if(TmpRoot.child[index] == null)
                    check = false;
                TmpRoot = TmpRoot.child[index];
            }
            if(TmpRoot.isEnd == false)
                check = false;
            if(check){
                return true;
            }
            return false;
        }

        public boolean isPrefix(String str){
            TrieNode TmpRoot = root;
            boolean check = true;
            for(int i = 0 ; i < str.length() ; ++i){
                int index = str.charAt(i) - 'a';
                if(TmpRoot.child[index] == null)
                    check = false;
                TmpRoot = TmpRoot.child[index];
            }
            return check;
        }

    }
