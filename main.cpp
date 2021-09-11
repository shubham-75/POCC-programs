#include<bits/stdc++.h>
using namespace std;
  
const int MAX = 100;
  
class Node {
  
    string identifier, scope, type;
    int lineNo;
    Node* next;
  
public:
    Node()
    {
        next = NULL;
    }
  
    Node(string key, string value, string type, int lineNo)
    {
        this->identifier = key;
        this->scope = value;
        this->type = type;
        this->lineNo = lineNo;
        next = NULL;
    }
  
    void print()
    {
        cout << "Identifier's Name:" << identifier
             << "\nType:" << type
             << "\nScope: " << scope
             << "\nLine Number: " << lineNo << endl;
    }
    friend class SymbolTable;
};
  
class SymbolTable {
    Node* head[MAX];
  
public:
    SymbolTable()
    {
        for (int i = 0; i < MAX; i++)
            head[i] = NULL;
    }
  
    int hashf(string id); // hash function
    bool insert(string id, string scope,
                string Type, int lineno);
  
    string find(string id);
    bool modify(string id, string scope, string Type, int lineno);
    bool deleteRecord(string id);
};
bool SymbolTable::insert(string id, string scope,
                         string Type, int lineno)
{
    int index = hashf(id);
    Node* p = new Node(id, scope, Type, lineno);
  
    if (head[index] == NULL) {
        head[index] = p;
        cout << "\n"
             << id << " inserted\n"<<endl;
  
        return true;
    }
  
    else {
        Node* start = head[index];
        while (start->next != NULL)
            start = start->next;
  
        start->next = p;
        cout << "\n"
             << id << " inserted\n"<<endl;
  
        return true;
    }
  
    return false;
}
string SymbolTable::find(string id)
{
    int index = hashf(id);
    Node* start = head[index];
  
    if (start == NULL)
        return "-1";
  
    while (start != NULL) {
  
        if (start->identifier == id) {
            start->print();
            return start->scope;
        }
  
        start = start->next;
    }
  
    return "-1";
}
bool SymbolTable::modify(string id, string s, string t, int l)
{
    int index = hashf(id);
    Node* start = head[index];
    while (start != NULL) {
        if (start->identifier == id) {
            start->scope = s;
            start->type = t;
            start->lineNo = l;
            return true;
        }
        start = start->next;
    }
  
    return false; 
}
bool SymbolTable::deleteRecord(string id)
{
    int index = hashf(id);
    Node* tmp = head[index];
    Node* par = head[index];
    if (tmp == NULL) {
        return false;
    }
    if (tmp->identifier == id && tmp->next == NULL) {
        tmp->next = NULL;
        delete tmp;
        return true;
    }
  
    while (tmp->identifier != id && tmp->next != NULL) {
        par = tmp;
        tmp = tmp->next;
    }
    if (tmp->identifier == id && tmp->next != NULL) {
        par->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    else {
        par->next = NULL;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    return false;
}
int SymbolTable::hashf(string id)
{
    int asciiSum = 0;
  
    for (int i = 0; i < id.length(); i++) {
        asciiSum = asciiSum + id[i];
    }
  
    return (asciiSum % 100);
}
int main()
{
    SymbolTable st;
    string check;
    cout << "** SYMBOL_TABLE **\n";
      string id,findID,deleteID;
      string scope;
      string Type;
      int line;
    while(true){
        int n;
        cout<<"1:Insert\n2:Find\n3:Delete\n4:Modify\n5:Terminate Program\nEnter your choice(1-5):";
        cin>>n;                   
      switch(n){
      case 1:
        cout<<"Enter Identifier "<<endl;
        cin>>id;
        cout<<"Enter Scope of Identifier"<<endl;
        cin>>scope;
        cout<<"Enter Type of Identifier"<<endl;
        cin>>Type;
        cout<<"Enter line no of Identifier"<<endl;
        cin>>line;
        st.insert(id,scope,Type,line);
    break;
    case 2:
      cout<<"Enter the identifier you want to search:"<<endl;
      cin>>findID;
      check = st.find(findID);
       if (check == "-1")
        cout<<findID<<" Identifier is not present\n\n";
        break; 
     case 3:
      cout<<"Enter the identifier you want to delete:"<<endl;
      cin>>deleteID;
        if(st.deleteRecord(deleteID))
        cout <<deleteID <<"Identifier is deleted\n\n";
    else
        cout <<"\nFailed to delete\n\n";
        break;
    case 4: cout<<"Enter the id to modify:";
            cin>>findID;
         check = st.find(findID);
         if (check != "-1")
            {
                cout<<"\nEnter Identifier "<<endl;
                cin>>id;
                cout<<"Enter Scope of Identifier"<<endl;
                cin>>scope;
                cout<<"Enter Type of Identifier"<<endl;
                cin>>Type;
                cout<<"Enter line no of Identifier"<<endl;
                cin>>line;
                st.modify(id,scope,Type,line);
            }
        else
            cout<<"\nID not present\n";
    case 5: break;
    default:cout<<"Wrong choice!!\n";
      }
      if(n==5)
        break;
    }   
    return 0;
}