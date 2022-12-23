#include<bits/stdc++.h>
using namespace std;
class MyListNode {
public:
    pair<char,int> data;
    MyListNode* next;
  
    MyListNode()
    {
		data.second=0;
        next = NULL;
    }
  
    MyListNode(pair<char,int> data)
    {
        this->data.first = data.first;
        this->data.second=data.second;
		this->next = NULL;
    }
};

class Linkedlist {
    MyListNode* head;
	MyListNode* tail;
  
public:
    
    Linkedlist() { 
        head = NULL;
	    tail = NULL; 
    }
    void insertNode(pair<char,int> data);
    void printList();
	
    MyListNode* gethead(){
		return head;
	}
	
    MyListNode* gettail(){
		return tail;
	}
};

void Linkedlist::insertNode(pair<char,int> data)
{
    
    MyListNode* newNode = new MyListNode(data);
    if (head == NULL) {
        head = newNode;
		tail=head;
        return;
    }
    tail->next = newNode;
	tail=tail->next;

}

void Linkedlist::printList()
{
    MyListNode* temp = head;
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data.first << " " << temp->data.second;
        temp = temp->next;
    }

}
class MyListNode1 {
public:
    pair<unsigned char,string> data;
    MyListNode1* next;
  
    MyListNode1()
    {
        next = NULL;
    }
  
    MyListNode1(pair<unsigned char,string> data)
    {
        this->data.first = data.first;
        this->data.second=data.second;
		this->next = NULL;
    }
};

class Linkedlist1 {
    MyListNode1* head;
	MyListNode1* tail;
  
public:
    Linkedlist1() { 
        head = NULL;
		tail = NULL; 
        }

    void insertNode(pair<unsigned char,string> data);
    void printList();

	MyListNode1* gethead(){
		return head;
	}
	MyListNode1* gettail(){
		return tail;
	}
};

void Linkedlist1::insertNode(pair<unsigned char,string> data)
{
    
    MyListNode1* newNode = new MyListNode1(data);
  
    if (head == NULL) {
        head = newNode;
		tail=head;
        return;
    }

    tail->next = newNode;
	tail=tail->next;

}

void Linkedlist1::printList()
{
    MyListNode1* temp = head;
  
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    while (temp != NULL) {
        //cout << temp->data.first << " " << temp->data.second;
        temp = temp->next;
    }
}
class Hash1
{
    public:
	int BUCKET; 
    Linkedlist1 *table;
	Hash1(int V); 
	void insertItem(pair<unsigned char,string>x);
    void SearchItem(pair<unsigned char,string>x);
    void SearchItem2(pair<unsigned char,string> x);
	int hashFunction(unsigned char key) {
		return key % BUCKET;
	}
	string Value(unsigned char key);
	void displayHash();
};

Hash1::Hash1(int b)
{
	this->BUCKET = b;
    table = new Linkedlist1[BUCKET];
}

void Hash1::insertItem(pair<unsigned char,string> x)
{
	int index = hashFunction(x.first);
    table[index].insertNode(x);
}

string Hash1::Value(unsigned char key){
    int index = hashFunction(key);
    MyListNode1* i = table[index].gethead();
    while(i!=NULL){

        if (i->data.first == key){
            return i->data.second;
        }
        i=i->next;
    }
    return "";
}


void Hash1::SearchItem(pair<unsigned char,string> x)
{
    int index = hashFunction(x.first);
    MyListNode1* i = table[index].gethead();
    while(i!=NULL){
        if (i->data.first == x.first){
            i->data.second=x.second;
            break;
        }
        i=i->next;
    }

    if (i == NULL){
        insertItem(x);
    }
	
}
void Hash1::SearchItem2(pair<unsigned char,string> x)
{
    int index = hashFunction(x.first);
    MyListNode1* i = table[index].gethead();
    while(i!=NULL){
        if (i->data.first == x.first){
            break;
        }
        i=i->next;
    }

    if (i == NULL){
        insertItem(x);
    }
    
}

void Hash1::displayHash() {
    for (int i = 0; i < BUCKET; i++) {

        MyListNode1* x = table[i].gethead();
        while(x!=NULL){
            cout<<x->data.first<<" "<<x->data.second<<endl;
            x=x->next;
        }
        
    }
}

class Hash
{   public:
	int BUCKET;	
    Linkedlist *table;
	Hash(int V); 
    void insertItem(pair<char,int>x);
    void SearchItem(pair<char,int>x);
    int hashFunction(char key) {
		
		return (key % BUCKET);
	}

	int Value(char key);
	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new Linkedlist[BUCKET];
}

void Hash::insertItem(pair<char,int> x)
{
	int index = hashFunction(x.first);
	table[index].insertNode(x);
}

int Hash::Value(char key){
    int index = hashFunction(key);
    MyListNode* i = table[index].gethead();
    while(i!=NULL){
       
        if (i->data.first == key){
            return i->data.second;
            
        }
        i=i->next;
    }
    return -1;
}

void Hash::SearchItem(pair<char,int> x)
{

    int index = hashFunction(x.first);
    MyListNode* i = table[index].gethead();
    while(i!=NULL){

        if (i->data.first == x.first){
            i->data.second++;
            break;
        }
        i=i->next;
    }

    if (i == NULL){
        insertItem(x);
    }
	
}

void Hash::displayHash() {

for (int i = 0; i < BUCKET; i++) {
    MyListNode* x = table[i].gethead();
    while(x!=NULL){
        cout<<x->data.first<<" "<<x->data.second<<endl;
        x=x->next;
    }
}

}
Hash freq_map(100);
Hash1 huff_codes(100);
Hash1 huff_codes2(100);

struct Node{
    char c;
    int freq;
    Node* left;
    Node* right;
    Node(char a, int b){
        left=nullptr;
        right=nullptr;
        c=a;
        freq=b;
    }
    Node(char a){
        c=a;
        left=nullptr;
        right=nullptr;
    }
};

class MinHeap{
    public:
    Node** v;
    int size;
    int capacity;
    MinHeap(int c){
        size=0;
        capacity=c;
        v = new Node*[c];
        
    }
    int left(int i){
        return (2*i+1);
    }
    int right(int i){
        return (2*i+2);
    }
    int parent(int i){
        return (i-1)/2;
    }
    
    void push(Node* x){
        if(size==capacity)return;
        size++;
        v[size-1]=x;
        for(int i=size-1; i!=0 && v[parent(i)]->freq>v[i]->freq;){
            Node* temp=v[i];
            v[i]=v[parent(i)];
            v[parent(i)]=temp;
            i=parent(i);

        }
    }
    void minHeapify(int i){
        int lt=left(i);
        int rt=right(i);
        int smallest=i;
        if(lt<size && v[lt]->freq<v[i]->freq){
            smallest=lt;
        }
        if(rt<size && v[rt]->freq<v[smallest]->freq){
            smallest=rt;
        }
        if(smallest!=i){
            Node* temp=v[smallest];
            v[smallest]=v[i];
            v[i]=temp;
            minHeapify(smallest);
        }
    }
    Node* pop(){
        if(size==1){
            size--;
            return v[0];
        }
        Node* temp=v[size-1];
        v[size-1]=v[0];
        v[0]=temp;
        size--;
        minHeapify(0);
        return v[size];
    }
    Node* top(){
        return v[0];
    }
    void BuildHeap(){
        for(int i=(size-2)/2;i>=0;i--){
            minHeapify(i);
        }
    }
};

void readFile(string filename){
   
    char c;
    ifstream ipfile;
    ipfile.open(filename, ios::in);
    while(ipfile.get(c)){
        
        freq_map.SearchItem({c,1});

    }
    
    ipfile.close();
    
}
void get_huff_code(Node* root,string s){
    
    if(root==nullptr){
        return;
    }
    if(root->c!=char(188)){

        huff_codes.SearchItem2({root->c,s});
        
    }
    get_huff_code(root->left,s+"0");
    get_huff_code(root->right,s+"1");
}

void makehufftree(Hash fmp){
    
    MinHeap pq(1000);
    string temp;
    Node *leftnode, *rightnode, *nnode;
    
    for (int i = 0; i < fmp.BUCKET; i++) {
        MyListNode* x = fmp.table[i].gethead();
        while(x!=NULL){
    
            pq.push(new Node(x->data.first,x->data.second));
            x=x->next;
        }
    }
    
    pq.push(new Node(char(129),1));
    while(pq.size!=1){

        leftnode=pq.top();
        pq.pop();
        rightnode=pq.top();
        pq.pop();
        nnode = new Node(char(188),leftnode->freq+rightnode->freq);
        pq.push(nnode);
        nnode->left=leftnode;
        nnode->right=rightnode;

    }
    
    get_huff_code(pq.top(),temp);
    return;
    
}

void write_to_file(string ipfile,string opfile){
   
    char c;
    string to_write;
    ifstream ipstream;
    ofstream opstream;
    opstream.open(opfile,ios::out);
    ipstream.open(ipfile,ios::in);

    
    for (int i = 0; i < huff_codes.BUCKET; i++) {
    MyListNode1* x = huff_codes.table[i].gethead();
        while(x!=NULL){
            opstream << x->data.first << char(189) << x->data.second << char(190);
            x=x->next;
        }
	}

    opstream << char(191);

    while (ipstream.get(c)){
        to_write+=huff_codes.Value(c);
    }

    ipstream.close();
    unsigned char x=129;
    to_write+=huff_codes.Value(x);
    unsigned long rem = (to_write.size()-1)%8;
    
    for(int i=0;i<8-rem;i++){
        to_write+='0';
    }
    
    stringstream ss(to_write);

    while(ss.good()){
        bitset<8>bits;
        ss>>bits;
        char ch=char(bits.to_ulong());
        opstream << ch;
    }

    opstream.flush();
    opstream.close();
  
}
Node* buildHufftreeDec(){
    //huff_codes2.displayHash();
    Node *rootNode = new Node(char(188));
        Node *previousNode;

        for (int i = 0; i < huff_codes2.BUCKET; i++) {
            MyListNode1* item = huff_codes2.table[i].gethead();
            while(item!=NULL){
            
                previousNode = rootNode;
                Node *newNode = new Node(item->data.first);
                string characterCode = item->data.second;
                for (int i = 0; i < characterCode.size(); ++i)
                {
                    if (characterCode[i] == '0')
                    {
                        if (i == characterCode.size() - 1)
                            previousNode->left=newNode;
                        else
                        {
                            if (previousNode->left==nullptr)
                            {
                                previousNode->left=new Node(char(188));
                                previousNode = previousNode->left;
                            }
                            else{
                                previousNode = previousNode->left;
                            }
                                    
                        }
                    }
                        else
                        {
                            if (i == characterCode.size() - 1)
                                previousNode->right=newNode;
                            else
                            {
                                if (previousNode->right==nullptr)
                                {
                                    previousNode->right=new Node(char(188));
                                    previousNode = previousNode->right;
                                }
                                else{
                                    previousNode = previousNode->right;
                                }
                                    
                            }
                        }
                    }
                
                
                item=item->next;
            }
	
        }
    
        return rootNode;

}

void decompressToFile(string codeString, Node *rootNode, string decompressedFileName)
    {
        ofstream outputStream;
        outputStream.open(decompressedFileName, ios::out);
        Node *traversingPointer = rootNode;
        
        for (int i = 0; i < codeString.size() + 1; ++i)
        {
            if (codeString[i] == '0')
                traversingPointer = traversingPointer->left;
            else
                traversingPointer = traversingPointer->right;

            if (traversingPointer->c != char(188))
            {
                if (traversingPointer->c == char(129))
                    break;
                outputStream << traversingPointer->c;
                traversingPointer = rootNode;
            }
        }
        
        outputStream.flush();
        outputStream.close();
    }

void decompress(string cmpfile,string newfile){
    char c;
    string to_write;
    ifstream ipstream;
    ipstream.open(cmpfile, ios_base::in | ios::binary);
    char ch;
    ipstream.get(ch);
    char key=ch;
    
    while (ch != char(191))
        {
            if (ch == char(189))
            {
                ipstream.get(ch);
                while (ch != char(190))
                {

                    string val=huff_codes2.Value(key);
                    val=val+ch;
                    huff_codes2.SearchItem({key,val});
                    ipstream.get(ch);
                }
            }
            else
                key = ch;
            ipstream.get(ch);
        }
        do
        {
            c = ipstream.get();
            if (ipstream.eof()==true){
                break;
            }
            bitset<8> bits(c);
            to_write += bits.to_string();
        } while (!ipstream.fail());


        Node* rootNode=buildHufftreeDec();
        decompressToFile(to_write,rootNode, newfile);   
}

int main(){
    BACK:
    cout<<"Welcome to File-Compressor Program"<<endl;
    cout<<"Enter Mode-> 1. Compress  2. Decompress"<<endl;
    int ch;
    cin>>ch;
    
    if(ch==1){
        string filename;
        cout<<"Enter File Name You Want To Compress: ";
        cin>>filename;
        readFile(filename);
        makehufftree(freq_map);
        write_to_file(filename,"output.txt");
        cout<<"File Compression Successfull"<<endl;

    }
    else if(ch==2){
        string filename1;
        cout<<"Enter File Name You Want To Decompress: ";
        cin>>filename1;
        int pos=filename1.find(".");

        decompress(filename1,filename1.substr(0,pos)+"compressed.txt");
        cout<<"File De-Compression Successfull"<<endl;
    }
    else{
        cout<<"wrong choice please enter again";
        goto BACK;
    }
    return 0;
}