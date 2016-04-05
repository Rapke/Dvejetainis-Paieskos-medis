#include<iostream>
using namespace std;

struct BstNode    /// Struktura
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data)    /// Sukasi ratu ir kuria nodus
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root,int data)
{
    if(root == NULL)   /// tuscias medis
    {
        root = GetNewNode(data);
    }
    /// i desine
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    /// kaire
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

bool Search(BstNode* root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left,data); /// iesko kaireje
    }
    else
    {
        return Search(root->right,data); /// iesko desineje
    }
}

void Preorder(struct BstNode *root) {

	if(root == NULL) return;

	cout<<root->data<<endl;
	Preorder(root->left); /// kairi
	Preorder(root->right); /// desini
}

void Inorder(BstNode* root)
{
    if(root == NULL) return;

    Inorder(root->left); /// desini

    cout<<root->data<<endl;
    Inorder(root->right); /// kairi
}

void Postorder(BstNode *root)
{
    if(root == NULL) return;

    Postorder(root->left); /// kairi
    Postorder(root->right); /// desini
    cout<<root->data<<endl;
}

BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct BstNode* Delete(struct BstNode *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data); /// Jieskoma skaiciaus
	else if (data > root->data) root->right = Delete(root->right,data);

	else {
		/// be vaiku
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		/// vienas vaikas
		else if(root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		/// du vaikai
		else {
			struct BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

int main()
{
    BstNode* root = NULL;
    cout<<"Kokio dydzio medis?"<<endl;
    int did;
    cin >> did;
    int sk;
    for(int i=0; i<did; i++)
    {
        cout<<"Ivesk "<<i+1<<" elementa: ";
        cin >> sk;
        root = Insert(root, sk);
    }


int number;
while(number != 0)
    {
    cout<<"Pasirinkite veiksma?"<<endl;
    cout<<"1- elemento paieska"<<endl;
    cout<<"2- Infix atspausdinimas"<<endl;
    cout<<"3- Postfix atspausdinimas"<<endl;
    cout<<"4- Prefix atspausdinimas"<<endl;
    cout<<"5- Skaiciaus iterpimas"<<endl;
    cout<<"6- Skaiciaus trinimas"<<endl;
    cout<<"0- isjungti programa"<<endl;

    cin >> number;
      switch(number)
    {
    case 0: break;
    case 1:
        cout<<"Iveskite numeri kurio ieskote\n";
        cin>>number;
        if(Search(root,number) == true) cout<<"Yra\n";
        else cout<<"Nera\n";
        break;
    case 2:
        cout<<"----"<<endl;
        Inorder(root);
        break;
    case 3:
        cout<<"----"<<endl;
        Postorder(root);
        break;
    case 4:
        cout<<"----"<<endl;
        Preorder(root);
        break;
    case 5:
        cout<<"----"<<endl;
        cout<<"Koki skaiciu norite irasyti?"<<endl;
        cin >> sk;
        root = Insert(root,sk);
        break;
    case 6:
        cout<<"----"<<endl;
        cout<<"Koki skaiciu norite istrinti?"<<endl;
        cin >> sk;
        root = Delete(root,sk);
        break;
    default:
        cout<<"----"<<endl;
        cout<<"Tokio pasirinkimo nera"<<endl;
        cout<<"----"<<endl;
    }
    }
}
