//
//  main.cpp
//  DS1-6
//
//  Created by Pragati  on 2/20/21.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;




void freq (ifstream &story)
{
    vector <string> words;
    string ch;
    
    
    while(story)
    {
        story >> ch;
        words.push_back(ch);
       
    }
    
    int size1 = words.size();
   
    
    sort(words.begin(), words.end());
   
    
    string temp = words[0];
    int n=1;
    int most = 0;
    string mostword;
    
    
    int ten[10];
    int t=0;
    int repeat=size1;
    
    string tenWords[10];
    
    while(t<10)
    {
        for(int i=1; i<size1; i++)
        {
            
            if (temp == words[i])
            {
                temp=words[i];
                n++;
            }
            else if (temp != words[i] && n<repeat)
            {
                if(most < n)
                {
                most=n;
                mostword = temp;
                }
                
                n=0;
                temp = words[i];
            }
            else
            {
                temp=words[i];
                n=0;
            }
        }
      
        repeat=most;
        ten[t]=most;
        
        tenWords[t]= mostword;
        
        most=0;
        t++;
        
    }
    cout<<endl;
    
    for(int i=0; i<10; i++)
    {
        cout<<(i+1)<< " = "<<ten[i]<<" word = "<<tenWords[i]<<endl;
    }
    
}

int main() {
    
    
    ifstream story1;
    
    
    story1.open("pandp11.txt");
    freq(story1);
  
   
        
    
    return 0;
}
