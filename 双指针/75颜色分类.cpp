//双指针，代表0和2应在的位置
class Solution {
	public:
	void sortColors(vector<int>& nums) {
		int n=nums.size();
		int p0=0,p2=n-1;
		//只要指针遇到p2就退出循环 
		for(int i=0; i<=p2; ++i) {
			//将2交换到p2处，p2前移，此时i处仍可能是2，继续循环检查，保证所有2都交换到后面（善后） 
			while(i<=p2 && nums[i]==2) {
				swap(nums[i],nums[p2]);
				p2--; 
			}
			//遇到0，直接交换到前面（p0和p2只需一个来保证善后即可） 
			if(nums[i]==0) {
				swap(nums[i],nums[p0]);
				p0++;
			}
		}
	}
};
