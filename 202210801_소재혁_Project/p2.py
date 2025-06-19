

# 프로젝트 문제 2번
input = ")))()"

def problem2(input):
    """
    주어진 괄호 문자열을 '올바른 괄호 문자열'로 만들기 위해
    추가해야 할 최소 괄호의 개수를 계산합니다.
    """
    
    # result: 최종적으로 추가해야 하는 괄호의 총 개수를 저장할 변수
    # balance: 짝을 찾지 못한 열린 괄호 '('의 개수를 실시간으로 추적하는 변수
    result = 0
    balance = 0

    # 입력된 문자열의 각 문자를 처음부터 끝까지 순회합니다.
    for char in input:
        if char == '(':
            # 열린 괄호 '('를 만나면, 나중에 닫힌 괄호와 짝을 이룰 수 있으므로
            # balance를 1 증가시킵니다.
            balance += 1
        elif char == ')':
            # 닫힌 괄호 ')'를 만났을 때,
            if balance > 0:
                # 짝을 이룰 수 있는 열린 괄호가 남아있다면 (balance > 0),
                # 그 괄호와 짝을 맞춰주고 balance를 1 감소시킵니다.
                balance -= 1
            else:
                # 짝을 이룰 열린 괄호가 없다면 (balance == 0),
                # 이 닫힌 괄호 ')'를 올바르게 만들기 위해서는 문자열 맨 앞에
                # 열린 괄호 '('를 하나 추가해줘야 합니다.
                # 따라서 추가해야 할 괄호의 총개수인 result를 1 증가시킵니다.
                result += 1
    
    # 문자열 순회가 모두 끝난 후, balance에 남아있는 값은
    # 짝을 찾지 못하고 남아버린 열린 괄호 '('의 개수입니다.
    # 이들을 모두 닫아주기 위해 그 개수만큼 닫힌 괄호 ')'를
    # 문자열 맨 뒤에 추가해야 합니다.
    result += balance
    
    return result

# 함수 실행
result = problem2(input)

# 결과 확인
assert result == 3
print("정답입니다.")
print(f"계산된 결과 (추가할 최소 괄호 수): {result}")
