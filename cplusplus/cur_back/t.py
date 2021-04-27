#!/usr/bin/env python3
# coding: utf-8


from random import randint

res = []
for i in range(10):
    res.append(str(randint(1,9)))

print(" ".join(res))
