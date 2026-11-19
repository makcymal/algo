#!/usr/bin/env python3

import os, re, sys, subprocess as sp

src = sys.argv[1]
exe = f'./{src}.exe'
if src.endswith('.cpp'):
  flags = ('-std=c++17 -g -O1 -pedantic -Wall -Wextra -Wno-sign-compare '
           '-fsanitize=address,undefined -fno-sanitize-recover=undefined '
           '-D_GLIBCXX_DEBUG').split()
  if sp.run(['g++', *flags, src, '-o', exe]).returncode:
    sys.exit(1)
  cmd = [exe]
else:
  cmd = [sys.executable, src]

env = dict(os.environ, ASAN_OPTIONS='detect_leaks=0')
text = open('test.conf').read()
norm = lambda s: '\n'.join(si.strip() for si in s.split('\n') if si.strip())
explain = lambda c: str(c) + {-6: ' abort', -11: 'segfault', -8: ' div by 0'}.get(c, '')

for i, m in enumerate(re.finditer(r'\\in\n(.+?)\\out\n(.+?)\\end', text, re.S), 1):
  inp, exp = norm(m.group(1)) + '\n', norm(m.group(2))
  try:
    r = sp.run(cmd, input=inp, stdout=sp.PIPE, text=True, timeout=10, env=env)
  except sp.TimeoutExpired:
    print(f'TEST {i}: TL')
    break
  obs = norm(r.stdout)
  if r.returncode or obs != exp:
    print(f'TEST {i}: ' + (f'RE ({explain(r.returncode)})' if r.returncode else 'WA'))
    print('--INPUT--', inp, '--EXPECTED--', exp, '--OBSERVED--', obs, sep='\n')
    break
else:
  print('All tests passed!')
