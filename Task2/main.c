#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define IP_ADDR_SIZE 32
enum Type{A,B,C,D};

// 目标函数
int classwise(unsigned char* ip) {
	uint32_t type = 0;
	for (int i = 0;i < IP_ADDR_SIZE;i++) {
		type = (type << 1) + (uint32_t)(ip[i] - '0');
	}
	if (type >= 16777216L && type <= 2130706431L) return A;
	
	if (type >= 2147483648L && type <= 3221225471L) return B;
	 
	if (type >= 3221225472L && type <= 3758096383L) return C;

	if (type >= 3758096384L && type <= 4026531839L) return D;
	else return -1;
}

unsigned char* get_ip_info(uint32_t x) {
	unsigned char* res = (unsigned char*)malloc(IP_ADDR_SIZE * sizeof(unsigned char));
	for (int i = 0;i < IP_ADDR_SIZE;i++) {
		res[IP_ADDR_SIZE - i - 1] = (x >> i) & 0x01 ? '1' : '0';
	}
	return res;
}

int main() {
	//测试B类地址 ： 172.16.0.1  -- > 十六进制 0xAC100001
	uint32_t test = 0xAC100001;
	
	unsigned char* temp = get_ip_info(test);
	int res = classwise(temp);
	if (res == B) printf("yes");
	else printf("no");
	free(temp);
	return 0;
}