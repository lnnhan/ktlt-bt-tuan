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
    vector<string> res;
    string cell; 
    stringstream ss(line);
    while(getline(ss,cell,',')) res.push_back(trim(cell));
    if(!line.empty()&&line.back()==',') res.push_back("");
    if(line.empty()) res.push_back("");
    return res;
}

bool isNum(const string& s){
    char* e=nullptr;
    string t=trim(s);
    if(t.empty()) return false; 
    strtod(t.c_str(),&e);
    return *e=='\0';
}

int main(){
    ifstream fin("data.csv");
    if(!fin){
        cerr<<"Cannot open data.csv\n";
        return 1;
    }
    string line;
    if(!getline(fin,line)){
        cout<<"has_header=0"; 
        return 0;
    }
    auto c=splitCSV(line);
    bool header=true;
    for(auto &x:c) if(isNum(x)) header=false;
    cout<<"has_header="<<(header?1:0);
    if(header){
        cout<<"\ncolumns=";
        for(size_t i=0;i<c.size();++i){
            if(i) cout<<",";
            cout<<c[i]; 
        }
    }
}
