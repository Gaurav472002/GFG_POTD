class Solution
{
    public:
        int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3) {
            int t[n1+1][n2+1][n3+1];
            
            for(int i = 0; i < n1+1; i++) {
                for(int j = 0; j < n2+1; j++) {
                    for(int k = 0; k < n3+1; k++) {
                        if(i == 0 || j == 0 || k == 0) {
                            t[i][j][k] = 0;
                        } else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                            t[i][j][k] = 1 + t[i-1][j-1][k-1];
                        } else {
                            t[i][j][k] = max({t[i-1][j][k], t[i][j-1][k], t[i][j][k-1]});
                        }
                    }
                }
            }
            
            
            return t[n1][n2][n3];
        }
};
