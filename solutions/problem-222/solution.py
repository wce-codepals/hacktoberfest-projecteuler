from math import sqrt

dPipe = 50 # mm
nBalls = 21

for dSphere in range(30,50+1):
  tmp = dSphere**2 - (dPipe-dSphere)**2
  x = sqrt(tmp)
  result = dSphere + x * (nBalls - 1)
  print('d={:d} mm : length={:d} um'.format(dSphere,round(result*1e6)))
