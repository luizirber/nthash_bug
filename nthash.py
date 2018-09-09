import sys

h = {
    'A': 0x3c8bfbb395c60474,
    'C': 0x3193c18562a02b4c,
    'G': 0x20323ed082572324,
    'T': 0x295549f54be24456,
    'N': 0,
}

rc = {
    'A': 0x295549f54be24456,
    'C': 0x20323ed082572324,
    'G': 0x3193c18562a02b4c,
    'T': 0x3c8bfbb395c60474,
    'N': 0,
}

def rol(x, k):
    return ((x << k % 64) & (2 ** 64 - 1) |
           ((x & (2 ** 64 - 1)) >> (64 - (k % 64))))

def f(s, idx, k):
    out = 0
    for i, v in enumerate(s[idx: idx+k], 1):
        out ^= rol(h[v], k - i)
    return out

def r(s, idx, k):
    out = 0
    for i, v in enumerate(reversed(s[idx: idx+k]), 1):
        out ^= rol(rc[v], k - i)
    return out

def nthash(s, k):
    fval = f(s, 0, k)
    rval = r(s, 0, k)
    return min(fval, rval), fval, rval

hval, fval, rval = nthash(sys.argv[1], len(sys.argv[1]))
print('NTC64 0x{:0>16x}'.format(hval))
print("fhVal 0x{:0>16x}".format(fval))
print("rhVal 0x{:0>16x}".format(rval))
