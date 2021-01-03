/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
​
class Solution {
public:
    
    int mp(MountainArray& mountainArr, int start, int end) {
        if(start >= end)
            return start;
        int mid = (start + end) / 2;
        if(mountainArr.get(mid) < mountainArr.get(mid+1)) {
            return mp(mountainArr, mid+1, end);
        }
        else
            return mp(mountainArr, start, mid);
        }
​
    int bs(int target, MountainArray& mountainArr, int start, int end) {
        if(start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if(mountainArr.get(mid) == target){
            return mid;
        }
        else if(mountainArr.get(mid) > target) {
            return bs(target, mountainArr, start, mid-1);
        }
        else
            return bs(target, mountainArr, mid+1, end);
    }
    
    int revBin(int target, MountainArray& mountainArr, int start, int end) {
        if(start > end)
            return -1;
        int mid = (start + end) / 2;
        if(mountainArr.get(mid) == target) {
            return mid;
        }
        else if(mountainArr.get(mid) > target) {
            return revBin(target, mountainArr, mid+1, end);
        }
        else
            return revBin(target, mountainArr, start, mid-1);
    }
​
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int midpoint = mp(mountainArr, 0, n-1);
        int leftIndex = bs(target, mountainArr, 0, midpoint);
        if(leftIndex != -1)
            return leftIndex;
        return revBin(target, mountainArr, midpoint+1, n-1);
    }
};
