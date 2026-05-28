#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

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

struct Stats{
    int count=0,missing=0;
    double mn=0,mx=0,mean=0;
};

bool readCSV1Col(const string& path, vector<double>& a, int& missing){
    ifstream fin(path);
    if(!fin) return false;
    string line;
    while(getline(fin,line)){
        if(isMissing(line)){
            missing++;
            continue;
        }
        try{
            a.push_back(stod(trim(line)));
        }catch(...){
            missing++; 
        }
    }
    return true;
}

Stats computeStats(const vector<double>& a,int miss){
    Stats s;
    s.count=a.size();
    s.missing=miss;
    if(a.empty()) return s;
    s.mn=s.mx=a[0];
    long double sum=0;
    for(double x:a){
        s.mn=min(s.mn,x);
        s.mx=max(s.mx,x);
        sum+=x;
    } s.mean=(double)(sum/a.size());
    return s;
}

int main(){
    vector<double>a;
    int miss=0;
    if(!readCSV1Col("data.csv",a,miss)){
        cerr<<"Cannot open data.csv\n";
        return 1;
    } auto s=computeStats(a,miss);
    ofstream fout("output.txt");
    if(!fout){
        cerr<<"Cannot open output.txt\n";
        return 1;
    }
    fout<<fixed<< setprecision(2);
    if(s.count==0) fout<<"count=0 / missing="<<s.missing<<" / min=N/A / max=N/A / mean=N/A";
    else fout<<"count="<<s.count<<" / missing="<<s.missing<<" / min="<<s.mn<<" / max="<<s.mx<<" / mean="<<s.mean;
}
