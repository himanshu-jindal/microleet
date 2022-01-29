//Take the top card of the deck, reveal it, and take it out of the deck.
//If there are still cards in the deck then put the next top card of the deck at the bottom of the //deck
//cards should be revealed in increasing order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int count=0,j=0;
        int n = deck.size();
        
        sort(deck.begin(), deck.end());
        
        vector<int> result(n,0);
        
        result[0] = deck[0];
        
        j=1;
        while(j<n){
    
            for(int i=1; i<n; i++){
                
                if(result[i] == 0){
                    
                    if(count == 1){
                        result[i] = deck[j];
                        j++;
                        count=0;
                    }
                    else
                        count++;
                    
                }
                
                
                
                
            }
            
        }
        
        return result;
        
    }
};
