class Solution {
    void Func(int[] nums, List<Integer> temp, List<List<Integer>> res, int start)
    {
        res.add(new ArrayList<>(temp));
        for(int i=start; i<nums.length; i++)
        {
            if(i > start && nums[i] == nums[i - 1])
                continue;
            temp.add(nums[i]);
            Func(nums, temp, res, i+1);
            temp.remove(temp.size() - 1);
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        Func(nums, temp, res, 0);
        return res;
    }
}