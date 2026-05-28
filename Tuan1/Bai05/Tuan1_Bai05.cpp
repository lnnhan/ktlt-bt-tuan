#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <map> 

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

string rankOf(double total){
    if(total>=24) return "Gioi";
    if(total>=18) return "Kha"; 
    if(total>=12) return "Trung binh";
    return "Yeu"; 
}

int main(){
    ifstream fin("scores.csv");
    if(!fin){
        cerr<<"Cannot open scores.csv\n";
        return 1;
    }
    ofstream fout("result.csv");
    if(!fout){
        cerr<<"Cannot open result.csv\n";
        return 1;
    }
    string line;
    map<string,int> cnt;
    fout<<"id,total,rank\n";
    while(getline(fin,line)){
        auto c=splitCSV(line);
        if(c.size()<4) c.resize(4);
        string id=trim(c[0]).empty()?"UNKNOWN":trim(c[0]);
        double total=0;
        for(int i=1;i<=3;i++) if(!isMissing(c[i])) total+=stod(c[i]);
        string r=rankOf(total);
        cnt[r]++;
        fout<<id<<","<<fixed<<setprecision(2)<<total<<","<<r<<"\n";
    }
    fout<<"summary,Gioi="<<cnt["Gioi"]<<";Kha="<<cnt["Kha"]<<";Trung binh="<<cnt["Trung binh"]<<";Yeu="<<cnt["Yeu"]<<"\n";
}
