#include <iostream>
#include <map>
#include "wordcount.h"
#include "huffman.h"

using namespace std;

int main()
{
    string s;
    cout << "Masukan Kalimat yang akan diencode: ";
    getline(cin, s);
	int ns = len(s);
    string word_tmp = rmv_duplicate(s, ns);
    sortString(word_tmp);
	int *frek_tmp = frekuensi(word_tmp, s);

	map<char, int> result;
	for(int i=0; i<word_tmp.length(); i++){
		result[word_tmp[i]] = frek_tmp[i];
	}

	string word = sort(result);
	int *frek = banyak_kata(word, word_tmp, frek_tmp);

	print_data(word, frek);

	cout << "| Huffman code |";
	cout << "\n----------------------\n";
	HuffmanCodes(word_tmp, frek_tmp, word.length());

	cin.get();
    return 0;
}