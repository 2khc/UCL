#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(long * num, size_t len);
long* reverseNum(long * num, size_t len);


int main(void)
{
    long num = 112398203;
    size_t len = sizeof(num);
    isPalindrome(&num, len);

    return 0;
}

bool isPalindrome(long * num, size_t len)
{
    reverseNum(num, len);


return true;
}

long* reverseNum(long * num, size_t len)
{
    long* reversedNum;

    do
    {
       printf("%i\n",*(reversedNum+len));// = *num;
       printf("%i\n",*num);
//       len--;
    }
    while (*num++);

}
