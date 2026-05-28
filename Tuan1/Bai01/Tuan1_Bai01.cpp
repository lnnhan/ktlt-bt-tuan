#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

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
    vector<string> res;
    string cell;
    stringstream ss(line);
    while(getline(ss,cell,',')) res.push_back(trim(cell));
    if(!line.empty()&&line.back()==',') res.push_back("");
    if(line.empty()) res.push_back("");
    return res;
}
    
bool readLines(const string& path, vector<string>& lines){
    ifstream fin(path);
    if(!fin) return false;
    string line;
    while(getline(fin,line)) lines.push_back(line);
    return true;
}

bool writeOutput(const string& path,int nonEmpty,int empty){
    ofstream fout(path);
    if(!fout) return false;
    fout<<"non_empty="<<nonEmpty<<" / empty="<<empty;
    return true;
}

int main(){
    vector<string> lines;
    if(!readLines("text.txt",lines)){ 
        cerr<<"Cannot open text.txt\n";
        return 1;
    } 
    int ne=0,em=0;
    for(auto &s:lines) trim(s).empty()?em++:ne++;
    if(!writeOutput("output.txt",ne,em)){
        cerr<<"Cannot open output.txt\n";
        return 1;
    }
    return 0;
}
