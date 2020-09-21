#include<stdio.h>
#include<algorithm>
#include<vector>

void Grow();
void Spring();
void Automn();
void Winter();
void printTree();

int N=0, M=0, K=0;
int A[10][10];
int Nutrient[10][10];

std::vector<int> MAP[10][10];
 
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 

int main() {
	int x, y, z;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%d", &A[i][j]);
			Nutrient[i][j] = 5;
		}
	}

	for(int i=0; i<M; i++) {
		scanf("%d %d %d", &x, &y, &z); //z=나이
		MAP[x-1][y-1].push_back(z);
	}

	// printTree();
	for(int i=0; i<K; i++) {
		Grow();
		// printTree();
	}

	int Result=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if (MAP[i][j].size() == 0) continue;
			Result += MAP[i][j].size();
			//printf("RESULT : %d\n", Result);

		}
	}
	printf("%d", Result);
}

void Grow(){
	Spring();
	Automn();
	Winter();
	return;
}

void Spring(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) {
			if(MAP[i][j].size() != 0) {
				sort(MAP[i][j].begin(), MAP[i][j].end());
				std::vector<int> Temp;
				int dieTree = 0;

				for(int k=0; k<MAP[i][j].size(); k++){
					if (MAP[i][j][k] <= Nutrient[i][j])
					{
						Nutrient[i][j] -= MAP[i][j][k];
						Temp.push_back(MAP[i][j][k]+1);
					} else {
						dieTree += MAP[i][j][k]/2;
					} 
				}
				MAP[i][j].clear();
				for(int k=0; k<Temp.size(); k++){
					MAP[i][j].push_back(Temp[k]);
				}
				Nutrient[i][j] += dieTree;
			}
		}
	}
	return;
}

void Automn(){
	int i, j, k;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if (MAP[i][j].size() == 0) continue;
			for(k=0; k<MAP[i][j].size(); k++) {
				if((MAP[i][j][k] % 5) == 0){
					for(int a=0; a<8; a++){
						int nx = i+dx[a];
						int ny = j+dy[a];
						if(nx>=0 && ny>=0 && nx<N && ny<N) {
							MAP[nx][ny].push_back(1);
						}
					}

				}
			}
		}
	}
	return;
}

void Winter(){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++) {
			Nutrient[i][j] += A[i][j];
		}
	}
	return;
}

void printTree(){
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++){
			if (MAP[i][j].size() == 1) {
				printf("%d ", MAP[i][j][0]);
			} else {
				printf("(");
				for(int k=0; k<MAP[i][j].size(); k++){
					printf("%d ", MAP[i][j][k]);
				}
				printf(")");
			}
		}
		printf("\n");
	}
	printf("\n");
	return;
}
