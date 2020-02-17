#include "curl.h"

class BetaCheck
{
    public:
    void BetaCheck(void);
    private: 
    void handleRcv(void* ptr, size_t size, size_t nmemb, void* userdata);
};