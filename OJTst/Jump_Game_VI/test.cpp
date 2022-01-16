class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> path(n, 0);
        
        
        for(int i=0; i<n; i++){
            aux[arr[i]].push_back(i);
            visited.push_back(0);       
        }
        
        visited[0] = 1;
        return minJumps_detail(arr, path, 0, 0);
    }
    
    int minJumps_detail(vector<int>& arr, vector<int>& path, int i, int lasti){
        int n = arr.size();
        int rslt = 1000000000;
        
        int    j = max(i-1, 0);
        int endj = min(i+1, n-1);
        vector<int> visitor;
        //cout<<"i:"<<i<<endl;
        //cout<<"lasti:"<<lasti<<endl;
        //cout<<"range:"<<j<<" "<<endj<<endl;
        
        if (i == n-1 || n == 0){
            //cout<<"trigger n-1"<<endl;
            return 0;
        }
        if (path[i] != 0 && path[i] != rslt){
            //cout<<"jian zhi:"<<i<<" "<<path[i]<<endl;
            return path[i];
        }
        for( ; j<=endj; j++){
            //cout<<"jth:"<<j<<endl;
            if (i == j){
                for(int k=0; k<aux[arr[i]].size(); k++){
                    int m = aux[arr[i]][k];
                    //cout<<"mth:"<<m<<endl;                    
                    if (i != m && m != lasti && visited[m] == 0){
                        //cout<<"m:"<<m<<endl; 
                        visitor.push_back(m);
                    }
                }
            }
            else if (i !=j && lasti != j && visited[j] == 0){
                //zcout<<"j:"<<j<<endl;
                visitor.push_back(j);
            }
        }
        
        for(int j=0; j<visitor.size(); j++){
            cout<<"visitor:"<<visitor[j]<<endl;
            visited[visitor[j]] = 1;
            rslt = min(1 + minJumps_detail(arr, path, visitor[j], i), rslt);
            visited[visitor[j]] = 0;
            cout<<"rslt:"<<rslt<<endl;
        }
        
        //path[i] = rslt;
        //cout<<"path["<<i<<"]:"<<path[i]<<endl;
        
        return rslt;
    }
    
private:
    map<int, vector<int>> aux;
    vector<int> visited;
    
};