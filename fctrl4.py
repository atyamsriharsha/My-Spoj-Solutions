def L(n):
	a=[1,1,2,6,4]
	powers=[6,2,4,8]
	y=n//5
	if(n<5):	return a[n]
	if not (y):	p=1
	else:		p=powers[y%4]
	return (L(y)*L(n%5)*p)%10
while 1:
	try:	x=input()
	except:	break;
	print L(x)
	