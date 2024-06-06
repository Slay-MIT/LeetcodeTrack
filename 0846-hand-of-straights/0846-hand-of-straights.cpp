class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0){
            return false;
        }
        map<int,int> card;
        for(int i=0; i<hand.size(); i++){
            card[hand[i]]++;
        }

        while(!card.empty()){
            int current = card.begin() -> first;
            for(int i=0; i<groupSize; i++){
                //if it was 0 from the beginning then it didn't exist, hence false
                if(card[current + i] == 0){
                    return false;
                }
                card[current + i]--;
                //basically, check if it became 0 after you subtracted
                if(card[current + i] < 1){
                    //remove all consecutive cards in the group of cards
                    card.erase(current + i);
                }
            }
        }
        return true;

    }
};