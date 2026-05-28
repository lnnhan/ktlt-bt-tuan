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

int main(){
    ifstream fc("config.txt");
    if(!fc){
        cerr<<"Cannot open config.txt\n";
        return 1;
    }
    double lo,hi;
    fc>>lo>>hi;
    ifstream fin("data.csv");
    if(!fin){
        cerr<<"Cannot open data.csv\n";
        return 1;
    } 
    ofstream fout("filtered.csv"); 
    if(!fout){
        cerr<<"Cannot open filtered.csv\n";
        return 1;
    }
    string line; 
    int kept=0,dropped=0;
    while(getline(fin,line)){ 
        auto c=splitCSV(line);
        if(c.size()<2 || isMissing(c[1])){
            dropped++; 
            continue;
        }
        double v=stod(c[1]); 
        if(lo<=v && v<=hi){
            fout<<c[0]<<","<<v<<"\n"; 
            kept++;
        } 
        else dropped++; 
    }
    fout<<"kept="<<kept<<" / dropped="<<dropped<<"\n"; 
}
