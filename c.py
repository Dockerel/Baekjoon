import math as m

def dist(vec):
    d=0
    for i in range(len(vec)):
        d+=(vec[i]**2)
    return d**0.5

def c_s(vec1, vec2):
    inner_product=0
    for i in range(len(vec1)):
        inner_product+=(vec1[i]*vec2[i])
    inner_product/=dist(vec1)
    inner_product/=dist(vec2)
    return inner_product

v1=[3.06,2.0,1.30,0]
v2=[2.76,1.85,0,0]
v3=[2.30,2.04,1.78,2.58]
print(c_s(v1,v2))
print(c_s(v1,v3))
print(c_s(v2,v3))