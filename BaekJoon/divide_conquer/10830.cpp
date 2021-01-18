#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
matrix multiple(matrix A, matrix B);
matrix power(matrix A, long long N);
void printMatrix(matrix A);

int main(){
    long long N, B, x;
    cin >> N >> B;
    matrix mat;
    mat.resize(N);
    for(int i=0; i<N; i++){
        mat[i].resize(N);
        for(int j=0; j<N; j++){
            cin >> x;
            mat[i][j] = x;
        }
    }    
    printMatrix(power(mat, B));
}

matrix power(matrix A, long long N) {
    if(N == 1) return A;
    else if(N % 2) return multiple(A, power(A, N-1));
    else return power(multiple(A, A), N/2);
}

matrix multiple(matrix A, matrix B) {
    matrix res;
    int N = A.size();
    res.resize(N);
    for(int i=0; i<N; i++) res[i].resize(N);
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            long long cnt = 0;
            for(int j=0; j<N; j++){
                cnt += (A[k][j] * B[j][i]) % 1000;
            }
            res[k][i] = cnt % 1000;
        }
    }
    return res;
}

void printMatrix(matrix A) {
    int N = A.size();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j]%1000 << " ";
        }
        cout << endl;
    }
    return;
}