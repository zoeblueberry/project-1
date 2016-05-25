//
//  main.c
//  test
//
//  Created by 王颖 on 16/5/25.
//  Copyright © 2016年 王颖. All rights reserved.
//

#include <stdio.h>
int main(int argc, char const *argv[])
{
    static const int A = 10000;
    const int M = 1;
    static int n = 0;
    static int nRds = 1;
    static int nPosX = 0;
    static int nPosY = 0;
    static int bodX = A;
    static int bodY = A;
    static int bodR = A / 2;
    static int nMaxRds = 0;
    static int nBestPosX = 0;
    static int nBestPosY = 0;
    static bool isBeyond = false;
    static int step = 10;
    static int rdsR[M];
    static int posXR[M];
    static int posYR[M];
    while (n < M)
    {
        nPosX = 0;
        nPosY = 0;
        nMaxRds = 0;
        nBestPosX = 0;
        nBestPosY = 0;
        
        if (n == 0)
        {
            nMaxRds = A/2;
            nBestPosX = A/2;
            nBestPosY = A/2;
            rdsR[n] = nMaxRds;
            posXR[n] = nBestPosX;
            posYR[n] = nBestPosY;
        }
        else
        {
            // 求出第 n 个圆的最大半径 和 位置
            for ( nPosX = 0; nPosX <= A; nPosX+=step)
            {
                for ( nPosY = 0; nPosY <= A; nPosY+=step)
                {
                    isBeyond = false;
                    nRds = 0;
                    while(nRds <= bodRds && !isBeyond)
                    {
                        if ((nRds > nPosX) || (nRds > nPosY) || (A < nPosX + nRds) || (A < nPosY + nRds))
                        {
                            isBeyond = true;
                            break;
                        }
                        for (int i = 0; i < n; ++i)
                        {
                            if ((nRds + rdsR[i]) * (nRds + rdsR[i]) >
                                (nPosX - posXR[i]) * (nPosX - posXR[i]) + (nPosY - posYR[i]) * (nPosY - posYR[i]))
                            {
                                isBeyond = true;
                                break;
                            }
                        }
                        if (nRds > nMaxRds)
                        {
                            nMaxRds = nRds;
                            nBestPosX = nPosX;
                            nBestPosY = nPosY;
                        }
                        nRds+=step;
                    }
                }
            }
        }
        rdsR[n] = nMaxRds;
        posXR[n] = nBestPosX;
        posYR[n] = nBestPosY;
        bodRds = nMaxRds;
        
        step = nMaxRds/1000;
        if (step < 5)
        {
            step = 5;
        }
        ++n;
    }
    printf("***********************************************************************************************************.\n");
    for (int i = 0; i < M; i++)
    {
        printf("第%d个圆的半径是：%d, 圆心是：(%d, %d).\n", i, rdsRecord[i], positionXRecord[i], positionYRecord[i]);
    }
    return 0;
}

