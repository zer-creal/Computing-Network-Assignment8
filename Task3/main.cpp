#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 题目要求定义的结构体
struct Fragment {
	// 报文长度 16 - 单位字节
	uint16_t length;
	// 偏移量 13 - 单位8字节
	uint16_t offset;
};

// 获取单个包的分片
vector<Fragment> fragmentOne(const Fragment& frag, int mtu) {
	vector<Fragment> res;


	int headerlen = 20;
	int data_len = frag.length - headerlen;
	int offset = frag.offset;
	
	int maxdata_len = (mtu - headerlen) / 8 * 8;
	Fragment temp;
	while (data_len) {
		int send_data = min(data_len, maxdata_len);
		temp.length = send_data + headerlen;
		temp.offset = offset;
		offset+=send_data / 8;
		data_len -= send_data;
		res.push_back(temp);
	}
	return res;
}

// 目标函数
vector<Fragment>  fragmentPacket(int  packetLength, const  vector<int>& pathMTUs) {
	vector<Fragment> res;

	Fragment temp;
	temp.length = packetLength;
	temp.offset = 0;
	res.push_back(temp);
	
	for (const auto& mtu : pathMTUs) {
		vector<Fragment> R;
		for (auto& f : res) {
			vector<Fragment>arr = fragmentOne(f, mtu);
			R.insert(R.end(), arr.begin(), arr.end());
		}
		res.swap(R);
	}

	return res;
}

int main() {
	// 测试 10000 包长， 路径为三个 mtu : 500, 300， 200
	vector<Fragment> result = fragmentPacket(10000, { 500, 400, 200 });

	cout << "res" << endl;
	for (auto& f : result) {
		cout << "length: " << f.length << "  offset:"  << f.offset << endl;
	}
	return 0;
}