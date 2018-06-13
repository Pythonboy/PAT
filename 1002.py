'''
时间：2018/6/6 21点35分
作者：楼浩然

1002 写出这个数 (20)（20 分）
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100^。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
'''

def num(i):
	sum = 0;
	for j in i:
		sum+=int(j);
	return str(sum);
	
if __name__=="__main__":
	N = input();
	res = num(str(N));
	dic = {"1":"yi","2":"er","3":"san","4":"si","5":"wu","6":"liu","7":"qi","8":"ba",'9':'jiu',"0":"lin"}
	re = [];
	for i in res:
		re.append(dic[i]);
	print(len(re));
	print(" ".join(re));
	