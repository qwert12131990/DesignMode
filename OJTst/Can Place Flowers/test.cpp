class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flag = 0;
        
        for(int i=0; i<flowerbed.size(); i++){
            if (flag == 0 && flowerbed[i] == 0){
                if (n>0){
                    n--;
                    flag = 1;
                }
            }
            else if (flag == 1 && flowerbed[i] == 1){
                n++;
                flag = 1;
            }
            else if (flag == 1 && flowerbed[i] == 0){
                flag = 0;
            }
            else if (flag == 0 && flowerbed[i] == 1){
                flag = 1;
            }else if (flag == 0 && n==0){
                break;
            }
        }
        return n == 0;
    }
};