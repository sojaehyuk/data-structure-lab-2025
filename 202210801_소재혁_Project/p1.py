

# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    
    # 리스트의 평균을 계산합니다 (나눗셈 후 소수점 버림).
    mean = sum(input) // len(input)
    
    # 중앙값을 찾기 위해 리스트를 오름차순으로 정렬합니다.
    sorted_input = sorted(input)
    
    # 정렬된 리스트의 가운데 위치(인덱스)를 찾습니다.
    middle_index = len(sorted_input) // 2
    
    # 가운데 위치의 값을 중앙값으로 가져옵니다.
    median = sorted_input[middle_index]
    
    # 결과를 [평균, 중앙값] 형태의 리스트로 만듭니다.
    result = [mean, median]
    
    # 최종 결과 리스트를 반환합니다.
    return result

# 함수를 실행하고 결과를 변수에 저장합니다.
result = problem1(input)

# 결과가 예상과 일치하는지 확인합니다.
assert result == [34, 30]

# 확인이 완료되면 성공 메시지를 출력합니다.
print("정답입니다.")
print(result)

