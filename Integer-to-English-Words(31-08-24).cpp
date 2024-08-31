class Solution {
public:
    string get_String(int n,map<int,string> &ones,map<int,string> &tens){
        vector<string> ans;
        int hundreds=n/100;
        if(hundreds!=0){
            ans.push_back(ones[hundreds]+" Hundred");
        }
        int lastTwo=n%100;
        if(lastTwo>=20){
           int ten=lastTwo/10;
           int one=lastTwo%10;
           ans.push_back(tens[ten*10]);
           if(one!=0){
            ans.push_back(ones[one]);
           }
        }
        else if(lastTwo!=0){
            ans.push_back(ones[lastTwo]);
        }
        string res="";
        for(auto s:ans){
            res+=s+" ";
        }
        return res.substr(0,res.size()-1);
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";

        map<int,string> ones={
            {1,"One"},
            {2,"Two"},
            {3,"Three"},
            {4,"Four"},
            {5,"Five"},
            {6,"Six"},
            {7,"Seven"},
            {8,"Eight"},
            {9,"Nine"},
            {10,"Ten"},
            {11,"Eleven"},
            {12,"Twelve"},
            {13,"Thirteen"},
            {14,"Fourteen"},
            {15,"Fifteen"},
            {16,"Sixteen"},
            {17,"Seventeen"},
            {18,"Eighteen"},
            {19,"Nineteen"}
        };
        map<int,string> tens={
            {20,"Twenty"},
            {30,"Thirty"},
            {40,"Forty"},
            {50,"Fifty"},
            {60,"Sixty"},
            {70,"Seventy"},
            {80,"Eighty"},
            {90,"Ninety"}
        };
        
        vector<string> postfix={""," Thousand"," Million"," Billion"};
        int i=0;
        vector<string> res;
        while(num){
            int digits=num%1000;
            string s=get_String(digits,ones,tens);
            if(s!=""){
                s=s+postfix[i];
                res.push_back(s);
            }
            num/=1000;i++;
        }
        reverse(res.begin(),res.end());
        string ans="";
        for(auto s:res){
             ans+=s+" ";
        }
        return ans.substr(0,ans.size()-1);
    }
};
