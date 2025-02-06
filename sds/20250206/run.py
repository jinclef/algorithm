# input.txt 파일 생성
with open("input.txt", "w") as f:
    for n in range(6, 1000001, 2):
        f.write(f"{n}\n")
    f.write("0\n")  # 종료 조건 추가
