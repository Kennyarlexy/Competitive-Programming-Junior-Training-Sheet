def modexp(X, n, mod):
    if n == 0:
        return 1

    temp = modexp(X, n//2, mod)
    res = temp*temp
    if n % 2 == 1:
        res *= X
    return res % mod

def gcd(A, B):
    if B == 0:
        return A
    return gcd(B, A % B)


T = int(input())
for t in range(T):
    A, B, N = [int(i) for i in input().split()]
    diff = A - B
    res = 0
    if diff == 0:
        res = (modexp(A, N, 1000000007) + modexp(B, N, 1000000007)) % 1000000007
    else:
        res = gcd(diff, (modexp(A, N, diff) + modexp(B, N, diff)) % diff) % 1000000007
    print(res)
