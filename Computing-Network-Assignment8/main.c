/*
*  完成 IP地址 & 网络掩码 = 网络号的操作
*/
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#define IP_ADDR_SIZE 32 

// 这里的char 单位均是代表bit，也就是一个uchar单元存储一个bit， 当然实际生产不是这样，为了生成方便作的简化（实际是写到后面才发现）
 
// 要求函数 - 正确返回0 反之返回 -1 ，大端模式： 低索引对应高位
int  is_in_net(unsigned  char* ip, unsigned  char* netip, unsigned  char* mask) {
	for (int i =0;i < IP_ADDR_SIZE;i++) {
		if (mask[i] == '1') {
			if (ip[i] != netip[i]) return -1;
		}
		else break;
	}
	return 0;
}

// 16进制数 转 uchar[32] 的函数
unsigned char* get_ip_info(uint32_t x) {
	unsigned char* res = (unsigned char*)malloc(IP_ADDR_SIZE * sizeof(unsigned char));
	for (int i = 0;i < IP_ADDR_SIZE;i++) {
		res[IP_ADDR_SIZE - i - 1] = (x >> i) & 0x01 ? '1' : '0';
	}
	return res;
}

int main() {
	//  -- 匹配 -- 测试
	uint32_t ip = 0x0A10050A;
	uint32_t netip = 0x0A100000;
	uint32_t mask = 0xFFFFFF00;

	unsigned char* cip = get_ip_info(ip);
	unsigned char* cnetip = get_ip_info(netip);
	unsigned char* cmask = get_ip_info(mask);
	int res = is_in_net(cip, cnetip, cmask);

	if (res) printf("yes");
	else printf("no");
	free(cip);
	free(cnetip);
	free(cmask);
	return 0;
}