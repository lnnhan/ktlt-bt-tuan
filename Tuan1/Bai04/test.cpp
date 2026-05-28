#include <iostream>
#include <string>
#include <vector>
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

int main(){
    vector<string> tests = {"10", "20", "N/A", "15", "30", "na", "25", "12", "NaN", "18", ""};
    for(const auto& t : tests){
        cout<<"["<<t<<"] -> "<<(isMissing(t)?"MISSING":"OK")<<"\n";
    }
}
