假设有一个数组，它的第i个元素是一支给定的股票在第i天的价格。如果你最多只允许完成一次交易(例如,一次买卖股票),设计一个算法来找出最大利润。

i,j两个指针都从头开始
若a[j]>=a[i]则j继续往后找差距更大的
若a[i]>a[j]则i肯定不是目标，i往后找更小的数作为i

class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        i=0
        j=0
        ans=0
        while i<len(prices):
            if prices[j]>=prices[i]:
                ans=max(ans,prices[j]-prices[i]);
                j+=1
                if j>=len(prices):
                    break
            else:
                i+=1
        return ans      
