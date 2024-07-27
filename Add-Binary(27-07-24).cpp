class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        char carry='0';
        int i=a.length()-1;
        int j=b.length()-1;

        while(i>=0 && j>=0){
            char sum;
            if(carry=='0'){
                if(a[i]=='0' && b[j]=='0'){
                    sum='0';carry='0';
                }
                else if(a[i]=='0' && b[j]=='1'){
                    sum='1';carry='0';
                }
                else if(a[i]=='1' && b[j]=='0'){
                    sum='1';carry='0';
                }
                else{
                    sum='0';carry='1';
                }
            }
            else{
                if(a[i]=='0' && b[j]=='0'){
                    sum='1';carry='0';
                }
                else if(a[i]=='0' && b[j]=='1'){
                    sum='0';carry='1';
                }
                else if(a[i]=='1' && b[j]=='0'){
                    sum='0';carry='1';
                }
                else{
                    sum='1';carry='1';
                }
            }

            ans=sum+ans;
            i--;j--;
        }

        while(i>=0){
            if(carry=='0'){
                ans=a[i]+ans;
            }
            else{
                if(a[i]=='0'){
                    ans='1'+ans;
                    carry='0';
                }
                else{
                    ans='0'+ans;
                    carry='1';
                }
            }
            i--;
        }

        while(j>=0){
            if(carry=='0'){
                ans=b[j]+ans;
            }
            else{
                if(b[j]=='0'){
                    ans='1'+ans;
                    carry='0';
                }
                else{
                    ans='0'+ans;
                    carry='1';
                }
            }
            j--;
        }

        if(carry=='1'){
            ans='1'+ans;
        }

        return ans;
    }
};
