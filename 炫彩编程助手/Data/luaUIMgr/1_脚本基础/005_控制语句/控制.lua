
local a = 1;
local b = 2;

if a>b then
	print("a > b");
else	
	print("a < b");
end


--�����÷�
local c,d=2,1;
if c>d then
	print("c > d");
else	
	print("c < d");
end


--��չ�Ķ�
maxRepetCount = 10;  --���ִ�д���
stepSize = 1;        --ÿ��iҪ�ӵ�ֵ
for i=1,maxRepetCount,stepSize do
	print(i);
end


maxCount = 10;
start = 1;
repeat
	print(start);
	start=start+1;	
until start > maxCount


while start > 0 do
	print(start);
	start=start-1;
end