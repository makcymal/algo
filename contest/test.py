#!/usr/bin/env python

import re
from sys import argv
from subprocess import run

if argv[1].endswith('.cpp'):
  proc = run(f'g++ {argv[1]} -o {argv[1]}.o -g -O1 -Wall -Wextra',shell=True,check=True)
  if proc.stdout:
    print(proc.stdout)
  cmd = f'./{argv[1]}.o'
else:
  cmd = f'/usr/bin/env python {argv[1]}'

file = open('test.conf').read()
pat = re.compile(r'\\in\n(.+?)\\out\n(.+?)\\end', flags=re.MULTILINE | re.DOTALL)
strip = lambda s: "\n".join([si.strip() for si in s.split("\n") if si.strip()])

for match in pat.finditer(file):
  inp = strip(match.groups()[0])
  exp = strip(match.groups()[1])
  obs = strip(run(cmd, input=inp, capture_output=True, text=True, check=True).stdout)
  if exp != obs:
    print(f'\n--INPUT--\n{inp}')
    print(f'\n--EXPECTED--\n{exp}')
    print(f'\n--OBSERVED--\n{obs}')
    break
else:
  print('All tests passed!')
