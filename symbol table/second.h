#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string identifier, type, scope;
    int lineno;
    void insert(string id, string sc, string t,int l)
    {
        identifier = id;
        type = t;
        scope = sc;
        lineno = l;
    }
};