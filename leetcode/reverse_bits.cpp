class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int j = 0; j < 32; j++){
            m = m << 1;
            m = m + (n & 1);
            n = n >> 1;
        }
        return m;
    }
};