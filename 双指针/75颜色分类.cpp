//˫ָ�룬����0��2Ӧ�ڵ�λ��
class Solution {
	public:
	void sortColors(vector<int>& nums) {
		int n=nums.size();
		int p0=0,p2=n-1;
		//ֻҪָ������p2���˳�ѭ�� 
		for(int i=0; i<=p2; ++i) {
			//��2������p2����p2ǰ�ƣ���ʱi���Կ�����2������ѭ����飬��֤����2�����������棨�ƺ� 
			while(i<=p2 && nums[i]==2) {
				swap(nums[i],nums[p2]);
				p2--; 
			}
			//����0��ֱ�ӽ�����ǰ�棨p0��p2ֻ��һ������֤�ƺ󼴿ɣ� 
			if(nums[i]==0) {
				swap(nums[i],nums[p0]);
				p0++;
			}
		}
	}
};
