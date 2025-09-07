from collections import deque

n = int(input())

q = deque()  # curr_emoji, curr_clipboard, curr_time
q.append((1, 0, 0))

dp = [[0] * 1004 for _ in range(1004)]  # dp[curr_emoji][curr_clipboard] = 방문 여부
dp[1][0] = 1

while q:

    curr_emoji, curr_clipboard, curr_time = q.popleft()

    if curr_emoji == n:
        print(curr_time)
        exit(0)

    for i in range(3):

        match i:
            case 0:
                updated_clipboard, updated_emoji = curr_emoji, curr_emoji
            case 1:
                updated_emoji, updated_clipboard = (
                    curr_emoji + curr_clipboard,
                    curr_clipboard,
                )
            case 2:
                updated_emoji, updated_clipboard = curr_emoji - 1, curr_clipboard

        try:
            if dp[updated_emoji][updated_clipboard]:
                continue
            dp[updated_emoji][updated_clipboard] = 1
            q.append((updated_emoji, updated_clipboard, curr_time + 1))
        except:
            continue
