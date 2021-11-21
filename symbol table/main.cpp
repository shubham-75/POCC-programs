#include <bits/stdc++.h>
#include "second.h"
using namespace std;
int main()
{
    system("CLS");
    map<string, vector<node>> m;
    node x, y;
    vector<node> v;
    int sizeoftype;
    cout << "***----------------------SYMBOL_TABLE------------------****\n";
    string id, findID, deleteID;
    string scope;
    string Type;
    int lineno;
    string scope2;
    while (true)
    {
        int n;
        cout << "1:Insert\n2:Find\n3:Delete\n4:Modify\n5:Display\n6:Terminate:\nEnter your choice(1-6):";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter Identifier:" << endl;
            cin >> id;
            cout << "Enter Scope of Identifier:" << endl;
            cin >> scope;
            cout << "Enter Type of Identifier:" << endl;
            cin >> Type;
            cout<<"Enter line number:"<<endl;
            cin>>lineno;
            x.insert(id, scope, Type,lineno);
            if (m.find(id) == m.end())
            {
                m[id].push_back(x);
            }
            else if (Type!="variable" or (m[id][0].scope!=scope and m[id][1].scope!=scope))
            {
                m[id].push_back(x);
            }
            else
                cout << "Already present identifier with same scope " << endl;
            break;
        case 2:
            cout << "Enter the identifier you want to search:" << endl;
            cin >> findID;
            if (m.find(findID) != m.end())
            {
                cout<<"Identifier\tScope\tType\tLine Number\n";
                for (auto p : m[findID])
                {
                    cout <<"\t"<<p.identifier<<"\t"<<p.scope<<"\t"<<p.type<<
                    "\t"<<p.lineno<<endl;
                }
            }
            else
                cout << findID << "identifier is not Found !" << endl;
            break;
        case 3:
            cout << "Enter the identifier you want to delete:" << endl;
            cin >> deleteID;
            if (m.find(deleteID) != m.end())
            {
                if(m[deleteID][0].type=="variable")
                {
                    cout<<"Enter the scope from where you want to delete:\n";
                    cin>>scope2;
                    if (m[deleteID][0].scope == scope2)
                    {
                        y = m[deleteID][1];
                        m.erase(deleteID);
                        m[deleteID].push_back(y);
                    }
                    else if (m[deleteID][1].scope == scope2)
                    {
                        y = m[deleteID][0];
                        m.erase(deleteID);
                        m[deleteID].push_back(y);
                    }

                }
                else
                {
                    cout<<"Enter the line number which you want to delete:\n";
                    cin>>lineno;
                    int itr;
                    bool flag=true;
                    for(itr=0;itr<m[deleteID].size();itr++)
                        {
                            if(m[deleteID][itr].lineno==lineno)
                               {
                                   m[deleteID].erase(m[deleteID].begin()+itr);
                                   flag = false;
                                   break;
                               } 
                        }
                    if(flag)
                     cout << "\nFailed to delete\n\n";   
                }
    
            }
            else
                cout << "\nFailed to delete\n\n";
            break;
        case 4:
            cout << "Enter the id to modify:";
            cin >> findID;
            if (m.find(findID) == m.end())
            {
                cout << "\nID not present\n";
            }
            else
            {
                if(m[findID][0].type=="variable")
                    { 
                        cout << "Enter scope  of Identifier which you want to modify :";
                        cin >> scope2;
                        cout << "\nEnter Identifier:" << endl;
                        cin >> id;
                        cout<<"Enter line number:\n";
                        cin>>lineno;
                        Type="variable";
                        x.insert(id,scope2,Type,lineno);
                        if (m[findID][0].scope == scope2)
                            {
                        m[id].push_back(x);
                        y = m[findID][1];
                        m.erase(findID);
                        m[findID].push_back(y);
                            }
                    else if (m[findID][1].scope == scope2)
                        {
                        m[id].push_back(x);
                        y = m[findID][0];
                        m.erase(findID);
                        m[findID].push_back(y);
                        }

                    }
                else
                {
                        cout << "\nEnter Identifier:" << endl;
                        cin >> id;
                        cout << "Enter Scope of Identifier:" << endl;
                        cin >> scope;
                        cout<<"Enter line number:\n";
                        cin>>lineno;
                        Type = m[findID][0].type;
                        x.insert(id,scope,Type,lineno);
                        for(int i=0;i<m[findID].size();i++)
                        {
                            if(m[findID][i].lineno==lineno)
                                {
                                    m[findID][i].identifier = x.identifier;
                                    m[findID][i].lineno = x.lineno;
                                    m[findID][i].scope = x.scope;
                                    m[findID][i].type = x.type;
                                }
                        }
                    
                }
               
            }
            break;
        case 5:
            cout<<"Identifier\tScope\tType\tLine Number\n";

            for (auto x : m)
            {
                v = x.second;
                for (auto p : v)
                {
                    cout <<"\t"<<p.identifier<<"\t"<<p.scope<<"\t"<<p.type<<
                    "\t"<<p.lineno<<endl;
                }
                cout << endl;
            }
            break;
        case 6:
            break;
        default:
            break;
        }
        if (n == 6)
            break;
    }
    return 0;
}
