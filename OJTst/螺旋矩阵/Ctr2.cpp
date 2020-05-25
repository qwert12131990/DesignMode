class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int y=matrix.size();
            int x=y?matrix[0].size():0;
            int size=x*y;
            int w0=0,w1=x-1,h0=0,h1=y-1;
            int i=0,j=0;
            bool right=true;
            bool left=false;
            bool top=false;
            bool bottom=false;
            vector<int> rslt(size, 0);
    
            for(int m=0; m<size; m++)
            {
                        rslt[m]=matrix[j][i];
                        cout<<i<<":"<<j<<"_"<<matrix[j][i]<<endl;
                        cout<<"\t"<<w0<<":"<<w1<<":"<<h0<<":"<<h1<<endl;
            
                        if (right==true)
                        {
                                        i++;
                                        if(i>w1)
                                        {
                                                            right=false;bottom=true;
                                                            j++;i=w1;
                                                            h0++;
                                                        }
                                        continue;
                                    }
                        if (left==true)
                        {
                                        i--;
                                        if(i<w0)
                                        {
                                                            left=false;top=true;
                                                            j--;i=w0;
                                                            h1--;
                                                        }
                                        continue;
                                    }
            
                        if (bottom==true)
                        {
                                        j++;
                                        if(j>h1)
                                        {
                                                            bottom=false;left=true;
                                                            i--;j=h1;
                                                            w1--;
                                                        }
                                        continue;
                                    }
                        if (top==true)
                        {
                                        j--;
                                        if(j<h0)
                                        {
                                                            top=false;right=true;
                                                            i++;j=h0;
                                                            w0++;
                                                        }
                                        continue;
                                    }
                    }
    
            return rslt;
        }
};


/*
 *
 * 优势：克服扁形问题
 * 缺点：代码冗长
