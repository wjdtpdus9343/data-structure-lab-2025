# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    # 평균 계산: 리스트 총합을 개수로 나눈 값
    mean = sum(input) // len(input)

    # 중앙값 계산: 정렬 후 가운데 값 선택
    sorted_input = sorted(input)
    median = sorted_input[len(input) // 2]

    # 결과를 저장할 리스트 생성
    result = [0, 0]
    result[0] = mean
    result[1] = median
    return result

result = problem1(input)

# 출력 형식: 평균, 중앙값을 각각 한 줄씩 출력
print(result[0])
print(result[1])
