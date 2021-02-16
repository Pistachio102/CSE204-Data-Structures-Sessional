#include <bits/stdc++.h>

using namespace std;

class HeapNode
{
public:
    char ch;
    int freq;
    HeapNode* left;
    HeapNode* right;

    HeapNode(int freq) : freq(freq) { ch = '&'; left = right = NULL; }
    HeapNode(char ch, int freq) : ch(ch), freq(freq) { left = right = NULL; }

    bool isLeaf() { return (ch!='&'); }
};

class Greater
{
public:
    bool operator()(HeapNode* left, HeapNode* right)
    {
        return  (left->freq > right->freq);
    }
};

void huffmanCodePrint(HeapNode *root, char code[], int idx)
{
    if(root->left!=NULL) {
        code[idx] = '0';
        huffmanCodePrint(root->left, code, idx+1);
    }

    if(root->right!=NULL) {
        code[idx] = '1';
        huffmanCodePrint(root->right, code, idx+1);
    }
    if(root->isLeaf()) {
        cout << "\t\t" << root->ch << " : ";
        for (int i = 0; i < idx; ++i) {
            cout << code[i];
        }
        cout << endl;
    }

}

HeapNode* huffmanCoding(int n, char data[], int freq[])
{
    HeapNode *tempNew, *tempL, *tempR;

    priority_queue<HeapNode*, vector<HeapNode*>, Greater> minHeap;


    for (int i = 0; i < n; ++i) {
        minHeap.push(new HeapNode(data[i],freq[i]));
    }

    while (minHeap.size() != 1) {

        if(minHeap.size()<1){
            cout << "Error!" << endl;
            return NULL;
        }

        tempL = minHeap.top(); minHeap.pop();
        tempR = minHeap.top(); minHeap.pop();

        tempNew = new HeapNode(tempL->freq + tempR->freq);
        tempNew->left = tempL;
        tempNew->right = tempR;

        minHeap.push(tempNew);

    }

    char code[n] = {};

    huffmanCodePrint(minHeap.top(),code,0);
}


int main(void)
{
    cout << "\t####\tHUFFMAN CODING\t####\t\n\n";

    int n;
    cin >> n;

    char data[n];
    int freq[n];

    for(int i=0; i<n; i++) {
        cin >> data[i] >> freq[i];
    }

    huffmanCoding(n, data, freq);

    return 0;
}
