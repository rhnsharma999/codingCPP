class Solution {
public:

// https://medium.com/@hazemu/finding-the-median-of-2-sorted-arrays-in-logarithmic-time-1d3f2ecbeb46
// tushar roy's video on youtube;
    
    double solve(vector<int> &a, vector<int> &b){
        if(a.size() > b.size()) return solve(b,a);
        
        int x = a.size();
        int y = b.size();
        
        int l = 0;
        int r = x;
        
        while(l <= r){
            int partitionX = ( l + r ) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            cout <<partitionX <<" " <<partitionY <<endl;
            
            
            int leftMaxX = partitionX <= 0 ? INT_MIN : a[partitionX - 1];
            int leftMaxY = partitionY <= 0 ? INT_MIN : b[partitionY - 1];
            
            int rightMinX = partitionX == x ? INT_MAX : a[partitionX];
            int rightMinY = partitionY == y ? INT_MAX : b[partitionY];
            
            if(leftMaxX <= rightMinY && leftMaxY <= rightMinX){
                if((x + y ) % 2 == 0){
                    return ((max(leftMaxX, leftMaxY) + min(rightMinX, rightMinY)) * 1.0) / 2;
                }
                else{
                    return max(leftMaxX, leftMaxY);
                }
            } 
            else if(leftMaxX > rightMinY){
                r = partitionX - 1;
            }
            else{
                l = partitionX + 1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() > 0){
            int middle = nums2.size() / 2;
            if(nums2.size() & 1){
                return 1.0 * nums2[middle];
            }
            else return (1.0 * (nums2[middle] + nums2[middle - 1])) / 2;
        }
        else if(nums1.size() > 0 && nums2.size() == 0){
            int middle = nums1.size() / 2;
            if(nums1.size() & 1){
                return 1.0 * nums1[middle];
            }
            else{
                return (1.0 * (nums1[middle] + nums1[middle - 1])) / 2;
            }
        }
        return solve(nums1, nums2);
    }
};