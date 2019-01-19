
#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int i, j;
    int maxContain = 0;
    int curContain;
    for (i = 0; i < heightSize-1; i++) {
        for (j = i+1; j < heightSize; j++) {
            curContain = (j - i) * (height[i]<height[j]?height[i]:height[j]);
            if (curContain > maxContain)
                maxContain = curContain;
        }
    }
    return maxContain;
}

int main(int argc, char *argv[])
{
    int height[]={1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(height, sizeof(height)/sizeof(int)));
}
