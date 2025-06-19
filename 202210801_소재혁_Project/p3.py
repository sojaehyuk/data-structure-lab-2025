

# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

from collections import deque

def problem3(input):
    N = len(input) # 숲의 크기를 입력으로부터 동적으로 결정
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    
    # forest 리스트를 input 리스트로 초기화 (깊은 복사)
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치(9)를 찾고, 해당 위치를 빈 공간(0)으로 만듭니다.
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0

    while True:
        # 1. 탐색(BFS): 현재 위치에서 먹을 수 있는 모든 벌집을 찾습니다.
        # 큐에는 (x좌표, y좌표, 거리)를 저장합니다.
        q = deque([(bear_x, bear_y, 0)])
        visited = [[False] * N for _ in range(N)] # 방문 기록용 2차원 리스트
        visited[bear_x][bear_y] = True
        
        edible_honeycombs = [] # 먹을 수 있는 벌집 후보 리스트

        # 이동 방향은 '상, 좌, 우, 하' 순으로 정의합니다.
        # BFS 탐색 시 거리, 행, 열 순서로 후보를 정렬하므로 이 순서는 최종 결과에 영향을 주지 않습니다.
        dx = [-1, 0, 0, 1]
        dy = [0, -1, 1, 0]

        while q:
            x, y, dist = q.popleft()
            
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                
                # 이동 조건: (1) 숲 경계 내부, (2) 미방문, (3) 곰이 지나갈 수 있는 크기
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny] and forest[nx][ny] <= bear_size:
                    visited[nx][ny] = True
                    q.append((nx, ny, dist + 1))
                    
                    # 먹이 조건: (1) 빈 공간이 아니고(>0), (2) 곰의 크기보다 작음
                    if 0 < forest[nx][ny] < bear_size:
                        # 후보 리스트에 (거리, 행, 열) 튜플로 추가합니다.
                        edible_honeycombs.append((dist + 1, nx, ny))
        
        if not edible_honeycombs: # BFS 탐색 후 먹을 수 있는 벌집이 없으면 시뮬레이션을 종료합니다.
            break
            
        edible_honeycombs.sort()   # 파이썬의 sort()는 튜플의 요소 순으로 자동 정렬(거리 -> 행 -> 열 순서로 정렬됨)
        
        dist_to_target, target_x, target_y = edible_honeycombs[0] 
        
        # 3. 실행: 곰의 상태를 갱신합니다.
        time += dist_to_target
        honeycomb_count += 1
        
        # 곰 성장 로직
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0
            
        # 곰 위치를 갱신하고, 먹은 벌집을 숲에서 제거(빈 공간으로 만듦)합니다.
        bear_x, bear_y = target_x, target_y
        forest[bear_x][bear_y] = 0
        
    return time

result = problem3(input)

assert result == 14
print("정답입니다.")
print(f"계산된 결과 (총 걸린 시간): {result}")
