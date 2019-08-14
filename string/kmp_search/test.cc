extern "C"
{
#include "kmpSearch.h"
}


void test0()
{
    char pattern[] = "ABABCABAAC";    
    const int len = 10;
    int prefix[len] = {0};
    prefix_table(pattern, prefix, len);
    move_prefix_table(prefix, len);

    for(int i=0;i != len; ++i)
    {
        printf("%d\n", prefix[i]);
    }
}

int main()
{
    char text[] = "hello world how are you? hello too";
    char pattern[] = "how";
    kmp_search(text, pattern);
    return 0;
}

