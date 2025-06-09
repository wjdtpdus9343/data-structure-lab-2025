# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0

    from collections import deque

    # 이동 방향: 위, 왼, 오, 아래 (우선순위 기준)
    dx = [-1, 0, 0, 1]
    dy = [0, -1, 1, 0]

    # BFS로 먹을 수 있는 벌집 탐색
    def bfs(sx, sy, size):
        visited = [[-1] * N for _ in range(N)]
        queue = deque()
        queue.append((sx, sy))
        visited[sx][sy] = 0
        edible = []

        while queue:
            x, y = queue.popleft()
            for d in range(4):
                nx, ny = x + dx[d], y + dy[d]
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[nx][ny] == -1 and forest[nx][ny] <= size:
                        visited[nx][ny] = visited[x][y] + 1
                        queue.append((nx, ny))
                        if 0 < forest[nx][ny] < size:
                            edible.append((visited[nx][ny], nx, ny))

        edible.sort()  # 거리, 행, 열 순으로 정렬
        return edible

    # 시뮬레이션
    while True:
        targets = bfs(bear_x, bear_y, bear_size)
        if not targets:
            break

        dist, nx, ny = targets[0]
        time += dist
        honeycomb_count += 1
        forest[nx][ny] = 0
        bear_x, bear_y = nx, ny

        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0

    result = time
    return result

result = problem3(input)
print(result)
