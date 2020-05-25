ass Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int y=matrix.size();
            int x=y?matrix[0].size():0;
            int size=x*y;
            int w0=0,w1=x-1,h0=0,h1=y-1;
            int i=0,j=0;
            bool wflag=true;
            vector<int> rslt(size, 0);
    
            for(int m=0; m<size; m++)
            {
                        
                        cout<<i<<":"<<j<<"_"<<matrix[j][i]<<endl;
                        cout<<w0<<":"<<w1<<":"<<h0<<":"<<h1<<endl;
                        if (wflag==true)
                        {
                                        if (j==h0)
                                        {
                                                            i++;
                                                        }
                                        if (j==h1)
                                        {
                                                            i--;
                                                        }
                        
                                        if (i>w1)
                                        {
                                                            i=w1;
                                                            wflag=false;
                                                            h0++;
                                                            j++;
                                                        }
                        
                                        if (i<w0)
                                        {
                                                            i=w0;
                                                            wflag=false;
                                                            h1--;
                                                            j--;
                                                        }
                                        continue;
                                    }
            
                        if (wflag==false)
                        {
                                        if (i==w1)
                                        {
                                                            j++;
                                                        }
                                        if (i==w0)
                                        {
                                                            j--;
                                                        }
                                            
                                        if(j>h1)
                                        {
                                                            j=h1;
                                                            wflag=true;
                                                            w1--;
                                                            i--;
                                                        }
                        
                                        if (j<h0)
                                        {
                                                            j=h0;
                                                            wflag=true;
                                                            w0++;
                                                            i++;
                                                        }
                                        continue;
                                    }
            
                        
                    }
    
            return rslt;
        }
};

/*
 *该类题目：旋转遍历方阵内的所有元素
 *控制
 *
 *缺点：
 *1、h1,w1作为标记当前方阵的size，还同时兼顾当前旋转遍历的方向
 *2、遇到扁形（h1==h0,或者w1==w0）情况，出现死循环
 *[
   [1, 2, 3, 4],
   [5, 6, 7, 8],
   [9,10,11,12]
  ]
 *
 *
 *
 */
