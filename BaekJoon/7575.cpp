#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
void input();
void printVector();
void findPattern();
int find();
void printA();

int N, K;
int M[1001];
std::vector<int> v[1001];
std::vector<int> a;

int main() {
   input();
   findPattern();
}

void input(){
   scanf("%d%d", &N, &K);
   int a;
   for (int i=1; i<=N; i++) {
      scanf("%d", &M[i]);
      for(int j=0; j<M[i]; j++) {
         scanf("%d", &a);
         v[i].push_back(a);
      }
   }
}

void printVector() {
   for(int i=1; i<=N; i++) {
      for(int j=0; j<v[i].size(); j++){
         printf("%d ", v[i][j]);
      }
      printf("\n");
   }
}

void findPattern(){
   for(int i=0; i<v[1].size()-K+1; i++){
      a.clear();
      for(int j=0; j<K; j++) {
         a.push_back(v[1][i+j]);
      }
      if(find() == 1){
         printf("YES");
         return;
      };
   }
   printf("NO");
   return;
}

int find(){
   int count = 0;
   int total = 0;
   int totalN = 0;
   for(int i=1; i<=N; i++) {
      total = 0;
      for(int j=0; j<v[i].size()-K+1; j++) {
         count = 1;
         for(int k=0; k<K; k++) {
            if(a[k] != v[i][j+k]) {
               count = 0;
               break;
            }
         }
         if(count == 1){
            total = 1;
            break;
         }
         count = 1;
         for(int k=0; k<K; k++) {
            if(a[K-k-1] != v[i][j+k]){
               count = 0;
               break;
            }
         }
         if(count == 1) {
            total = 1;
            break;
         }
      }
      if(total != 1) {
         break;
      } else {
         totalN++;
      }
   }
   if(totalN == N) {
      return 1;
   }
   return 0;
}

void printA(){
   for(int i=0; i<a.size(); i++){
      printf("%d ->", a[i]);
   }
   printf("\n");
}