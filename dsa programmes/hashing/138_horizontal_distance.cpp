#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *left, *right;
    node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << endl;
    inorder(root->left);
    inorder(root->right);
}

//to store key int 
//to store the vertical nodes 
map<int,vector<int>>m;

//this program build a tree and vertically stores indx value at the map function and then prints them

node *build_tree(node *root, vector<int> v, int idx,int hd=0)
{
    //if arr is out of bound
    if (idx >= v.size())
    {
        return NULL;//return null
    }
    else{
    root = new node(v[idx]);//make a new node and store the value in current root
    m[hd].push_back(v[idx]);//store value of index in map acording to its vertical order
    
    }
    

    root->left = build_tree(root->left, v, 2 * idx+1,hd-1);//build left tree
    root->right = build_tree(root->right, v, 2 * idx+2,hd+1);//build right tree
    return root;//return the nodes to the previous recursive calls
}

//void horizontal_distance(node* root)
int main()
{

    node *root = NULL;

    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    root=build_tree(root,v,0);

    inorder(root);

    cout<<"vertical order print "<<endl;
    map<int,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" ";
        vector<int>::iterator it_v;
        for(it_v=it->second.begin();it_v!=it->second.end();it_v++){
            cout<<*it_v<<" ";
        }

        cout<<endl;
    }
}