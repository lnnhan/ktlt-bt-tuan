#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <set>

using namespace std;
string trim(const string& s){ 
    size_t b=s.find_first_not_of(" \t\r\n");
    if(b==string::npos) return "";
    size_t e=s.find_last_not_of(" \t\r\n");
    return s.substr(b,e-b+1);
}

string lowerStr(string s){
    for(char &c:s) c=(char)tolower((unsigned char)c); 
    return s;
}

bool isMissing(string s){
    s=lowerStr(trim(s));
    return s.empty()||s=="na"||s=="nan"||s=="n/a";
}

vector<string> splitCSV(const string& line){
    vector<string> res; string cell;
    stringstream ss(line);
    while(getline(ss,cell,',')) res.push_back(trim(cell));
    if(!line.empty()&&line.back()==',') res.push_back(""); 
    if(line.empty()) res.push_back("");
    return res; 
}

int main(){
    ifstream fin("words.txt");
    if(!fin){
        cerr<<"Cannot open words.txt\n";
        return 1;
    }
    string w;
    long long total=0;
    set<string> uni;
    while(fin>>w){
        total++;
        uni.insert(w);
    }
    cout<<"total_words="<<total<<" / unique_words="<<uni.size();
}
