// 
//You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
//Write a method to set all bits between 
//i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).


int update_bits(int n, int m, int i, int j){
    int ret = (1 << i) -1;
    ret &= n;
    return ((n>>(j+1)) << (j+1)) | (m<<i) | ret;
}

int update_bits1(int n, int m, int i, int j){
    int max = ~0;   //全为1
    int left = max - ((1 << j+1) - 1);
    int right = ((1 << i) -1);
    int mask = left | right;
    return (n & mask) | (m << i);
}