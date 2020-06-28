int N, M;//Assign N and M
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1}; //Grid Movements
bool ok(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; } //Grid Check-(0,0) based
