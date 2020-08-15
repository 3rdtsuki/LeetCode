This is a classical instance,one of the best solution is dp
java version,O(n),1ms,44.6mb

class Solution {
    public int maxSubArray(int[] nums) {
        int ans=-0xffff;
        int sum=0;
        for(int i=0;i<nums.length;++i){
            sum+=nums[i];
            ans=Math.max(sum,ans);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
}

Second,divide and conquer version,O(nlogn),3ms,46.4mb

class Solution {
    public int mSA(int[] nums,int left,int right){
        if (right==left){
            return nums[left];
        }
        int i,j,mid=(left+right)>>1;
        int sum=0,ans=-0xffff;
        for(i=mid;i>=left;--i){
            sum+=nums[i];
            ans=Math.max(sum,ans);
        }
        sum=ans;  //update sum!
        for(j=mid+1;j<=right;++j){
            sum+=nums[j];
            ans=Math.max(sum,ans);
        }
        return Math.max(Math.max(mSA(nums,left,mid),mSA(nums,mid+1,right)),ans);
    }
    public int maxSubArray(int[] nums) {
        return mSA(nums,0,nums.length-1);
    }
}
