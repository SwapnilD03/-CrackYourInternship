class Solution {
public:
    string getLine(vector<string>& words, int maxWidth,int spaceEachSlot,int extraSpaces,int i ,int j){
        string line="";
        for(int k=i;k<j;k++){
            line+=words[k];
            if(k==j-1){
                continue;
            }
            for(int space=1;space<=spaceEachSlot;space++){
                line+=" ";
            }
            if(extraSpaces>0){
                line+=" ";extraSpaces--;
            }
        }

        while(line.length()<maxWidth){
            line+=" ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> ans;
         int n=words.size();
         int i=0;
         while(i<n){
            int lettersCount=words[i].length();int slotCount=0;
            int j=i+1;
            while(j<n && words[j].length()+1+lettersCount+slotCount<=maxWidth){
                lettersCount+=words[j].length();
                j++;slotCount++;
            }

            int remSpaces=maxWidth-lettersCount;
            int spaceEachSlot=(slotCount==0)?0:remSpaces/slotCount;
            int extraSpaces=(spaceEachSlot==0)?0:remSpaces%slotCount;
            if(j==n){
                extraSpaces=0;
                spaceEachSlot=1;
            }

            string line=getLine(words,maxWidth,spaceEachSlot,extraSpaces,i,j);
            ans.push_back(line);
            i=j;
         }
         return ans;
    }
};
