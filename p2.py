# 프로젝트 문제 2번
# 입력 예시 1
input1 = ")))()"
# 입력 예시 2
input2 = ")(()"

def problem2(input):
    # 올바른 괄호 쌍을 만들기 위해 앞뒤로 필요한 괄호 개수 계산
    
    open_needed = 0  # 왼쪽 괄호가 필요한 개수
    balance = 0      # 현재 열린 괄호 개수 (짝 맞춘 상태 추적)

    for char in input:
        if char == '(':
            balance += 1  # 열린 괄호 추가
        else:  # char == ')'
            if balance > 0:
                balance -= 1  # 짝 맞는 열린 괄호가 있으므로 닫아줌
            else:
                open_needed += 1  # 짝이 없는 닫힌 괄호 → 앞에 '('가 필요함

    result = open_needed + balance  # 앞에 필요한 ( + 뒤에 필요한 )
    return result

# 첫 번째 입력 예시 실행
result1 = problem2(input1)
print(result1)

# 두 번째 입력 예시 실행
result2 = problem2(input2)
print(result2)
