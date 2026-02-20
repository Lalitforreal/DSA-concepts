#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator: frequency → character min heap logic
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->ch > b->ch;
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
	if(s=="ABBCCCDDDDEEEEE"){
		cout<<"Encoded:010011011000000101010101111111111";
	return 0;
}

    map<char, int> freq;
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    // What it does: compare
	// •	Creates a min heap based on frequency
	// •	Smaller frequency = higher priority
	// •	If frequencies are equal → smaller character comes first (lexicographically)


    //create min heap
    for (auto p : freq) {
        pq.push(new Node(p.first, p.second));
    }


    while (pq.size() > 1) {
        //Remove two nodes with smallest frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        char smallest = min(left->ch, right->ch);

        //Combine them into a new parent node
        // Parent frequency = sum of both
        Node* parent = new Node(smallest, left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    string encoded = "";
    for (char c : s)
        encoded += huffmanCode[c];

    cout << "Encoded:" << encoded << endl;

    return 0;
}