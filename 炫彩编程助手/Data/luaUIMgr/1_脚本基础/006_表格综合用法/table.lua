

tb={
x=1,
y=2,
ff = function (a,b)
	return a+b;
end
}

print(tb.ff(tb.x,tb.y));



--����

tab ={};

tab.x = 3;
tab.y  = 2;
tab.sub = function (a,b)
	return a-b;
end

print( tab.sub(tab.x,tab.y) );

--����һ��д��

function tab.add(a,b)
	return a+b;
end

print(tab.add(tab.x,tab.y));

--�߼�����

ff={
x =10;
y =11;
};

function ff:Get()
	--ֻҪ�� �� ���������������һ�� self,�Ϳ��������������
	return self.x + self.y;
end


print("��ӵ�ֵ: ",ff:Get());