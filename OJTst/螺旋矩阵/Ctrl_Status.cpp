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
        int status;
        //status:
        //0:right
        //1:left
        //2:bottom
        //3:top
        vector<int> rslt(size, 0);

        for(int m=0; m<size; m++)
        {
            rslt[m]=matrix[j][i];
            cout<<i<<":"<<j<<"_"<<matrix[j][i]<<endl;
            cout<<"\t"<<w0<<":"<<w1<<":"<<h0<<":"<<h1<<endl;

            switch(status)
            {
                case 0: //0:right
                    i++;
                    if(i>w1)
                    {
                        status=2;
                        j++;i=w1;
                        h0++;
                    }
                    break;
                case 1: //1:left
                    i--;
                    if(i<w0)
                    {
                        status=3;
                        j--;i=w0;
                        h1--;
                    }
                    break;
                case 2: //2:bottom
                    j++;
                    if(j>h1)
                    {
                        status=1;
                        i--;j=h1;
                        w1--;
                    }
                    break;
                case 3: //3:top
                    j--;
                    if(j<h0)
                    {
                        status=0;
                        i++;j=h0;
                        w0++;
                    }
                    break;
                default:
                    break;
            }
        }

        return rslt;
    }
};
