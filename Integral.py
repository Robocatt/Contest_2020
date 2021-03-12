import math 
def fun(phi):
    funans = I*R/10000000.0*abs(L*math.cos(phi)-R)/(L**2+R**2*math.cos(phi))/math.sqrt(L**2+R**2-2.0*L*R*math.cos(phi))
    return funans
def function_integral():
    n = math.pi / dphi
    i=2
    while i<=n:
        phi = (i-1)*dphi
        integral+=fun(phi)*dphi
        i+=1
    return 2.0*integral

print('Input I, R, L, dphi (I advise you not to make dphi too small,not smaller than 10^(-8))')
I,R,L,dphi=list(map(float,input().split(' ')))
print(I,R,L,dphi,sep='\n')
print(function_integral())