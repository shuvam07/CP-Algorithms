#include <bits/stdc++.h>
using namespace std;

/**** 
      If auto - completions exists, output all of 
      them in lexicographical order(lowercase) else 
      output "No  suggestions" without quotes.
       
****/

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;                       // represent end of word
};
 
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}
 
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
struct TrieNode *search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return NULL;
        pCrawl = pCrawl->children[index];
    }
    return pCrawl;
}

void dfs(struct TrieNode *curNode, string curString, vector<string> &res)
{
 for(int letter = 0; letter < ALPHABET_SIZE; letter++)
 {
  if(curNode->children[letter] != NULL)
  {
   string tmp = curString;
   tmp.push_back(letter + 'a');
   dfs(curNode->children[letter], tmp, res); 
  }
 }
 
 if(curNode->isEndOfWord)
  res.push_back(curString);
}
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  struct TrieNode *root= getNode();
  int n,q;
  cin>>n;
  while(n--)
  {
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    insert(root,s);
  }

  cin>>q;
  while(q--)
  {
    string s;
    cin>>s; 
    struct TrieNode *p = search(root,s);
    if(p==NULL)
    {
      cout <<"No suggestions\n"; 
      insert(root,s);
    }
    else
    {
      vector<string> res;
      dfs(p, s, res);
      sort(res.begin(), res.end());
      for(int i = 0, L = res.size(); i < L; i++)
      cout<<res[i]<<endl;
    }
  }

  return 0;
}