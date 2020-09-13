/*
Group words with same set of characters
Last Updated: 05-10-2018
Given a list of words with lower cases. Implement a function to find all Words that have the same unique character set .

Example:

Input: words[] = { "may", "student", "students", "dog",
                 "studentssess", "god", "cat", "act",
                 "tab", "bat", "flow", "wolf", "lambs",
                 "amy", "yam", "balms", "looped", 
                 "poodle"};
Output : 
looped, poodle, 
lambs, balms, 
flow, wolf, 
tab, bat, 
may, amy, yam, 
student, students, studentssess, 
dog, god, 
cat, act, 

All words with same set of characters are printed 
together in a line.
*/
/*
Approach is to use hashing 
I/P : ["eat","tea","tan","ate","nat","bat"]
O/P : [["bat"],["nat","tan"],["ate","eat","tea"]]
Sort every elemnt to check for anagram
Map looks something like this
| aet | -> eat -> tea -> ate
| ant | -> tan -> nat
| abt | -> bat

now take vector of vector of string to print result
eat -> tea -> ate
tan -> nat
bat
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        ios_base::sync_with_stdio(false);                             //code for faster input/output
        cin.tie(NULL);
        
        unordered_map<string,vector<string> > mymap;                  // Map for storing key value pair, where first sorted string is key and  remaining are added as link to it
        int n = strs.size();
        string temp;
        
        for(int i =0;i<n;++i)
        {
            temp = strs[i];                                          //store original string
            sort(strs[i].begin(),strs[i].end());                     //sort the string and now soterd string is key
            mymap[strs[i]].push_back(temp);                          //push original string, with the key as sorted element
        }
        
        vector<vector<string> > result;
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr)         //vector of vector of string to push second value in vector
            result.push_back(itr->second);
        
        return result;
    }
};
