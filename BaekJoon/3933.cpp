#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<cstring>
using namespace std;
int main(){
    while(1){
        int res=0, N=0;
        scanf("%d", &N);
        if(N == 0) break;
        int len = sqrt(N);
        for(int i=1; i<=len; i++){
            if(i*i == N) res++;
            else if(i*i > N) break;
            for(int j=i; j<=len; j++){
                if(i*i + j*j == N) res++;
                else if(i*i + j*j > N) break;
                for(int k=j; k<=len; k++){
                    if(i*i + j*j + k*k == N) res++;
                    else if(i*i + j*j + k*k > N) break;
                    for(int l=k; l<=len; l++){
                        if(i*i + j*j + k*k + l*l == N) res++;
                        else if(i*i + j*j + k*k + l*l > N) break;
                    }
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}