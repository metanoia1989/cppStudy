#include <cstdlib>
#include <numeric>
#include <cstring>
#include <iostream>
#include <string>

template<size_t frameLength, size_t checkSumSize = 1> struct FrameBase 
{
    static const int skLength = frameLength;

    void updateCheckSum() 
    {
        uint64_t sum = 0;
        static_assert((checkSumSize >= 1 && checkSumSize <= sizeof(sum) &&
            checkSumSize < frameLength), "FrameBase Size Error");

        auto data = reinterpret_cast<uint8_t *>(this);
        sum = std::accumulate(data, data + frameLength - checkSumSize, sum);

        //FIXME 暂时不知道原因， 但在mac,上release模式会优化掉， 导致最后校验和为雾
        std::cout <<  data << std::endl;; 
        std::cout << "'std::accumulate: " << sum << std::endl;; //加上这句打印sum,就会正常

        // memcpy(data + frameLength - checkSumSize, &sum, checkSumSize);
    }

    void update(const void *data) { memcpy(this, data, frameLength); }
};

int main(int argc, char const *argv[])
{
    /* code */
    FrameBase<10> frameBase;
    frameBase.updateCheckSum();

    return 0;
}
