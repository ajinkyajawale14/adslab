//Program for Dictinary Implementation using BST
#include <iostream>
using namespace std;
class node
{
public:
	string w,m;
	node *left,*right;
	node()
	{
		w="w";
		m="m";
		left=right=NULL;
	}
};
class dict
{
	node *root;
public:
	dict()
{
		root=NULL;
}
	void create()
	{
		node *newnode=new node;
		cout<<"Enter Word"<<endl;
		cin>>newnode->w;
		cout<<"Enter Meaning" <<endl;
		cin>>newnode->m;
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			insert(root,newnode);
		}
	}
	void insert(node *temp,node *newnode)
	{
		node *parent;
		while(temp!=NULL)
		{
			parent=temp;
			if(newnode->w < temp->w)
			{
			    temp=temp->left;
			}
			else
				temp=temp->right;
		}
		if(newnode->w < parent->w)
		{
			parent->left=newnode;
		}
		else
		{
			parent->right=newnode;
		}
	}
	void display()
	{
	         if(root==NULL)
	         {
	            cout<<"No Words to Display";
	         }
	         else
		 inorder(root);
	}
	void inorder(node *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<"\n"<<temp->w<<"";
			cout<<"==>"<<temp->m;
			inorder(temp->right);
		}
	}
	void search();
	node* searchstring(node* temp,string s1);
	void deletenode();
	node* delnode(node* temp,string ds);
	void modify();
	//node* modtree(node* temp,string mw,string mm);
	node* maxtree(node* temp);
	node* mintree(node* temp);
};
void dict::search(){
	string key;
	cout<<"which key want to search"<<endl;
	cin>>key;
	node* stemp;
	stemp=searchstring(root,key);
	if(stemp!=NULL){
		cout<<"key found "<<stemp->w<<endl;
	}
	else
		cout <<"key not found"<<endl;

}
node* dict::searchstring(node* temp,string s1){
	int count =0;
	while(temp!=NULL){
		count++;
	if(s1==temp->w){
		return temp;
	}
	else
		if(s1<=temp->w){
			temp=temp->left;
		}
		else if(s1>=temp->w){
			temp=temp->right;
		}
		else {
			return NULL;
		}
	}return temp;
	cout<<"	comparisions "<<count <<endl;
}
	void dict::deletenode(){
	string del;
	cout<<"enter the element want to delete"<<endl;
	cin>>del;
	delnode(root,del);
	cout<<"dictionary after delete"<<endl;
	inorder(root);
}
	node* dict::delnode(node* root,string del){
if(root==NULL)
	cout<<"there is no tree"<<endl;
else if(root->w>del){
		root->left=delnode(root->left,del);
}
else if (root->w<del){
	root->right=delnode(root->right,del);
}
else{
	if(root->left && root->right){
		//replace largest in the left subtree
		node* temp=maxtree(root-> left);
		root->w=temp->w;
		root->m=temp->m;
		root->left=delnode(root->left,root->w);
	}
	else{
	node*temp=root;
	if(root->left==NULL)
		root=root->right;
	if(root->right==NULL)
		root=root->left;
	delete temp;
	}
	}
}
	node * dict::maxtree(node*temp){
		while(temp->right!=NULL)
			temp=temp->right;
		return temp;
	}
	void dict::modify(){
		string modkey,m1,mw1;
			cout<<"which word want to modify"<<endl;
			cin>>modkey;
			cout<<"new word and meaning"<<endl;
					cin>>mw1;
					cin>>m1;
			node* mtemp;
			mtemp=searchstring(root,modkey);
			mtemp->w=mw1;
			mtemp->m=m1;

			cout<<mtemp->w<<endl;
			cout<<mtemp->m<<endl;
			inorder(root);
	}

int main()
{
	dict d;
	int ch;
	do
	{
	   cout<<"\n ==============MENU=============";
	   cout<<"\n 1.Create \n 2.Display \n 3.Search \n 4.Delete \n 5.Modify \n 6.Exit";
	   cout<<"\n \n Enter Choice";
	   cin>>ch;
	   switch(ch)
	   {
	   case 1:d.create();
	          break;
	   case 2:d.display();
	          break;
	   case 3:d.search();
	   	   	   break;
	   case 4:d.deletenode();
	   	   break;
	   case 5:d.modify();
	   break;
	   case 6:cout<<"\n Wrong Choice";
	   }
	}while(ch<6);
}

