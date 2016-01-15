an exmpale of how to use trie.

This article explains the Trie data structure and provides a sample implementation in C++.
Tries are used to index and search strings in a text.
Some examples of tries usage include, finding the longest prefix match in a routing table, auto complete of web addresses in browser etc.
Trie is a tree where each vertex represents a word or prefix.
The root represents an empty string.
Markers are used to indicate end of words.
A typical node in a trie includes the content (a char), marker for end of word and a collection of children.
An example of trie. (Using words Hello, Balloon, Ball) 

   ()
  /  \
 (H)  (B)
  |    |
 (E)  (A)
  |    |
 (L)  (L)
  |    |
 (L)  (L)*
  |    |
 (O)* (O)
       |
	    (O)
	     |
	    (N)*
- See more at: http://www.sourcetricks.com/2011/06/c-tries.html#.VMgyXv54qtE

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(char c, Node* child){mChildren[c] = child};
  

private:
    char mContent;
    bool mMarker;
    unordered_map<char, Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    bool searchWord(string s);
    void deleteWord(string s);
private:
    Node* root;
};

Node* Node::findChild(char c)
{
    if(mChildren.count(c) > 0) return mChildren[c];
    else return NULL;
}

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

void Trie::addWord(string s)
{
    Node* current = root;
    for ( int i = 0; i < s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( !child )
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(s[i], tmp);
        }
        current = current->findChild(s[i]);
    }
    current->setWordMarker();
}


bool Trie::searchWord(string s)
{
    Node* current = root;

  
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        return current->wordMarker();
  
}


// Test program
int main()
{
    Trie* trie = new Trie();
    trie->addWord("Hello");
    trie->addWord("Balloon");
    trie->addWord("Ball");

    if ( trie->searchWord("Hell") )
        cout << "Found Hell" << endl;

    if ( trie->searchWord("Hello") )
        cout << "Found Hello" << endl;

    if ( trie->searchWord("Helloo") )
        cout << "Found Helloo" << endl;

    if ( trie->searchWord("Ball") )
        cout << "Found Ball" << endl;

    if ( trie->searchWord("Balloon") )
        cout << "Found Balloon" << endl;

    delete trie;
}

OUTPUT:-
Found Hello
Found Ball
Found Balloon
- See more at: http://www.sourcetricks.com/2011/06/c-tries.html#.VMgyXv54qtE
