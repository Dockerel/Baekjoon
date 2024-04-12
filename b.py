def VBEncodeNumber(n):
    bytes_array = []
    while True:
        bytes_array.insert(0, n % 128)
        if n < 128:
            break
        n //= 128
    bytes_array[-1] += 128
    return bytes_array

# 예시: 숫자 824을 인코딩
encoded_bytes = VBEncodeNumber(824)
print("Encoded bytes:", encoded_bytes)
