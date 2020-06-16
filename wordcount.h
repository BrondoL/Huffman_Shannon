#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int len(string s){
    int i = 0;
    int n = 0;
    while(s[i]!='\0'){
        n++;
        i++;
    }
    return n;
}

string toLower(string s, int n){
    string hasil;
    for (int i=0; i<n; i++){
        hasil += tolower(s[i]);
    }
    return hasil;
}

bool isThere(char s, char x[]){
    bool cek = false;
    int n = len(x);
    for(int i=0; i<n; i++){
        if(x[i] == s){
            cek = true;
            break;
        }
    }
    return cek;
}

void sortString(string &str)
{
   sort(str.begin(), str.end());
}

string rmv_duplicate(string s, int n){
    s = toLower(s, n);
    char z[26] = "";
    int j=0;
    for (int i=0; i<n; i++){
        if(!isThere(s[i], z)){
            z[j] = s[i];
            j++;
        }
    }
    return z;
}

int *frekuensi(string hasil, string s){
    int *frek_tmp = new int[255];
    for (int i=0; i<hasil.length(); i++){
        int c = 0;
        for (int j=0; j<s.length(); j++){
            if(hasil[i]==s[j])
                c++;
        }
		frek_tmp[i] = c;
    }

    return frek_tmp;
}

bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second < b.second;
}
string sort(map<char, int>& M)
{
    vector<pair<char, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), cmp);
    string word;
    for (auto& it : A) {
        word += it.first;
    }
    return word;
}

int *banyak_kata(string word, string word_tmp, int frek_tmp[]){
    int *frek = new int[255];
    int index[word.length()];
    for(int i=0; i<word.length(); i++){
        for(int j=0; j<word_tmp.length(); j++){
            if(word[i]==word_tmp[j])
                index[i] = j;
        }
    }
    for(int i=0; i<word.length(); i++){
        frek[i] = frek_tmp[index[i]];
    }
    return frek;
}

void print_data(string word, int frek[]){
    cout << "Huruf = {";
    for(int i=0; i<word.length(); i++){
        if(i+1!=word.length())
            cout << word[i] << " ,";
        else
            cout << word[i];
    }
    cout << "}" << endl;

    cout << "Frekuensi = {";
    for(int i=0; i<word.length(); i++){
        if(i+1!=word.length())
            cout << frek[i] << " ,";
        else
            cout << frek[i];
    }
    cout << "}" << endl << endl;
}