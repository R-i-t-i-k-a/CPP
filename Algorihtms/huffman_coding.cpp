#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>

	using namespace std;

	struct HuffmanNode
	{
		char data;
		unsigned frequency;
		HuffmanNode *left;
		HuffmanNode *right;

		HuffmanNode(char data, unsigned frequency)
		{
			this->data = data;
			this->frequency = frequency;
			left = right = nullptr;
		}
	};

	struct CompareNodes
	{
		bool operator()(HuffmanNode *left, HuffmanNode *right)
		{
			return left->frequency > right->frequency;
		}
	};

	void generateHuffmanCodes(const string &input);
	void printHuffmanCodes(HuffmanNode * root, string code);

	int main(){
		string input;
		cout << "Enter a string: ";
		cin >> input;

		generateHuffmanCodes(input);

		return 0;
	}

	void generateHuffmanCodes(const string &input){
		map<char, int> frequencyMap;

		// Calculate character frequencies
		for (char c : input)
		{
			frequencyMap[c]++;
		}

		// Create a priority queue for Huffman nodes
		priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> minHeap;

		// Create a Huffman node for each character and add it to the minHeap
		for (const auto &pair : frequencyMap)
		{
			minHeap.push(new HuffmanNode(pair.first, pair.second));
		}

		// Build the Huffman tree
		while (minHeap.size() > 1)
		{
			HuffmanNode *left = minHeap.top();
			minHeap.pop();

			HuffmanNode *right = minHeap.top();
			minHeap.pop();

			HuffmanNode *mergedNode = new HuffmanNode('s', left->frequency + right->frequency);
			mergedNode->left = left;
			mergedNode->right = right;

			minHeap.push(mergedNode);
		}

		// Traverse the Huffman tree and print codes
		HuffmanNode *root = minHeap.top();
		string code = "";
		cout << "Huffman Codes:\n";
		printHuffmanCodes(root, code);
	}

	void printHuffmanCodes(HuffmanNode * root, string code)
	{
		if (!root)
			return;

		if (root->data != 's')
		{
			cout << root->data << ": " << code << "\n";
		}

		printHuffmanCodes(root->left, code + "0");
		printHuffmanCodes(root->right, code + "1");
	}