#include <iostream>
#include <queue>
#include <string>
#include <time.h>
using namespace std;

struct NODE {
	int freq;
	char data;
	const NODE* child0, * child1;
	NODE(char d, int f) {
		data = d;
		freq = f;
		child0 = NULL;
		child1 = NULL;
	}
	NODE(const NODE* c0, const NODE* c1) {
		data = 0;
		freq = c0->freq + c1->freq;
		child0 = c0;
		child1 = c1;
	}
	bool operator<(const NODE& a) const {
		return freq > a.freq;
	}
	void traverse(string code = "") const {
		if (child0 != NULL) {
			child0->traverse(code + '0'); 
			child1->traverse(code + '1'); 
		} 
		else {
			cout << "Data: " << data << ", Frequency: " << freq << ", Code: " << code << endl;
		}
	}
};

void huffmanCoding(string str) {
	priority_queue<NODE> qu;
	int frequency[256];
	for (int i = 0; i < 256; i++) {
		frequency[i] = 0;
	}
	for (int i = 0; i < str.size(); i++) {
		frequency[int(str[i])]++;
	}
	for (int i = 0; i < 256; i++) {
		if (frequency[i] != 0) {
			qu.push(NODE(i, frequency[i]));
		}
	}
	while (qu.size() > 1) {
		NODE* c0 = new NODE(qu.top()); 
		qu.pop();
		NODE* c1 = new NODE(qu.top()); 
		qu.pop();
		qu.push(NODE(c0, c1)); 
	}
	cout << "The Huffman Code: " << endl;
	qu.top().traverse(); 
}

int main() {
	clock_t starttime, endtime;
	double totaltime;
	starttime = clock();
	string str = "ACCEBFFFFAAXXBLKE";
	huffmanCoding(str);
	endtime = clock();
	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
	cout << "Total time \n" << totaltime;
}